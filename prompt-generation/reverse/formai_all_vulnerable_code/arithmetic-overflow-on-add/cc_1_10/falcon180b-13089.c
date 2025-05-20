//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

void push(char stack[],int *top,char element)
{
    if(*top>=MAX-1)
        printf("\nStack Overflow");
    else
        *(stack+(*top)++)=element;
}

char pop(char stack[],int *top)
{
    if(*top<0)
        printf("\nStack Underflow");
    else
        return *(stack+--(*top));
}

int precedence(char op)
{
    switch(op)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

void infix_to_postfix(char infix[],char postfix[],int *top)
{
    char stack[MAX];
    int i=0;
    push(stack,'$',0);
    *top=-1;
    while(infix[i])
    {
        if(isalnum(infix[i]))
            postfix[++(*top)]=infix[i];
        else if(infix[i]=='(')
            push(stack,'(',0);
        else if(infix[i]==')')
        {
            while(pop(stack,top)!='(');
        }
        else
        {
            while(precedence(infix[i])<=precedence(pop(stack,top)))
                postfix[++(*top)]=pop(stack,top);
            push(stack,infix[i],0);
        }
        i++;
    }
    while(*top>=0)
        postfix[++(*top)]=pop(stack,top);
    postfix[++(*top)]='\0';
}

void postfix_evaluation(char postfix[],int *top)
{
    char stack[MAX];
    int i=0,j=0,k,result=0;
    push(stack,'$',0);
    while(postfix[i])
    {
        if(isalnum(postfix[i]))
        {
            printf("\nEnter the value of %c : ",postfix[i]);
            scanf("%d",&result);
            push(stack,result,0);
        }
        else
        {
            k=pop(stack,top);
            j=pop(stack,top);
            switch(postfix[i])
            {
                case '+':
                    result=j+k;
                    break;
                case '-':
                    result=j-k;
                    break;
                case '*':
                    result=j*k;
                    break;
                case '/':
                    if(k==0)
                    {
                        printf("\nDivision by zero error");
                        exit(0);
                    }
                    else
                        result=j/k;
                    break;
                case '^':
                    result=pow(j,k);
                    break;
            }
            push(stack,result,0);
        }
        i++;
    }
    printf("\nResult : %d",pop(stack,top));
}

int main()
{
    char infix[MAX],postfix[MAX];
    int top=-1;
    printf("\nEnter the infix expression : ");
    scanf("%s",infix);
    infix_to_postfix(infix,postfix,&top);
    printf("\nPostfix expression : ");
    for(int i=0;postfix[i]!='\0';i++)
        printf("%c ",postfix[i]);
    printf("\n");
    postfix_evaluation(postfix,&top);
    return 0;
}