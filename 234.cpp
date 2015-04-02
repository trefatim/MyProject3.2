#include <iostream>
#include <string>

using namespace std;

struct Stack
{
	int i;
	Stack *pNext;
};
/*! Добавление элемента в стек.
 * \param [in] pick − указатель на вершину.
 * \param [in] p − указатель на добавляемый элемент.
*/
void add(Stack *&pick, Stack *p)
{
	p->pNext=pick;
	pick=p;
}
/*! Удаление элемента из стека.
 * \param [in] pick − указатель на вершину.
 */
void del(Stack *&pick)
{
	pick=pick->pNext;
}

//!Функция main
int main()
{
	int n, k=0, value;//!<кол-во действий, счетчик, значение элемента
	string mode;//!<операция над очередью
	Stack *p, *pick=NULL;
	cout<<"n="; cin>>n;
	while (k!=n)
	{
		cout<<"mode=";
		fflush(stdin);
		getline(cin,mode);
		if(mode=="add")
		{
			cin>>value;
			p=new Stack;
			p->i=value;
			p->pNext=NULL;
			add(pick,p);
			k++;
		}
		else if(mode=="del")
		{
			del(pick);
			k++;
		}
		else
		{
			cout<<"wrong";
		}
	}
	p=pick;
	while(p!=NULL)
	{
		cout<<p->i<<" ";
		p=p->pNext;
	}
	system("pause");
	return 0;
}
