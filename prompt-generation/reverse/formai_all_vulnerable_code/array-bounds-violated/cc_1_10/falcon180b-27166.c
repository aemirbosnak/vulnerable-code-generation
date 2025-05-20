//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#define PI 3.14159265358979323846
#define MAX 1000
char expression[MAX];
int top=-1;
double stack[MAX];
double precedence(char op)
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
void push(double value)
{
    if(top==MAX-1)
        printf("\nStack Overflow");
    else
    {
        top++;
        stack[top]=value;
    }
}
double pop()
{
    if(top==-1)
        printf("\nStack Underflow");
    else
    {
        double value=stack[top];
        top--;
        return value;
    }
}
double perform_operation(char op)
{
    double right=pop();
    double left=pop();
    switch(op)
    {
        case '+':
            push(left+right);
            break;
        case '-':
            push(left-right);
            break;
        case '*':
            push(left*right);
            break;
        case '/':
            if(right==0)
            {
                printf("\nDivision by zero is not allowed");
                exit(0);
            }
            push(left/right);
            break;
        case '^':
            push(pow(left,right));
            break;
        default:
            printf("\nInvalid operation");
    }
}
int main()
{
    printf("\nEnter the expression: ");
    scanf("%s",expression);
    int i=0;
    while(expression[i]!='\0')
    {
        if(isalnum(expression[i]))
        {
            push(expression[i]-'0');
        }
        else if(expression[i]=='+' || expression[i]=='-' || expression[i]=='*' || expression[i]=='/' || expression[i]=='^')
        {
            while(!isalnum(expression[i]) && expression[i]!='\0')
                i++;
            while(isalnum(expression[i]))
                i++;
            perform_operation(expression[i]);
        }
        else if(expression[i]=='(')
        {
            push(0);
        }
        else if(expression[i]==')')
        {
            while(stack[top]!=0)
            {
                perform_operation('+');
            }
            pop();
        }
        else if(expression[i]=='.')
        {
            push(0);
        }
        else if(expression[i]=='s' || expression[i]=='S')
        {
            push(sin(stack[top]));
        }
        else if(expression[i]=='c' || expression[i]=='C')
        {
            push(cos(stack[top]));
        }
        else if(expression[i]=='t' || expression[i]=='T')
        {
            push(tan(stack[top]));
        }
        else if(expression[i]=='l' || expression[i]=='L')
        {
            push(log(stack[top]));
        }
        else if(expression[i]=='n' || expression[i]=='N')
        {
            push(sqrt(stack[top]));
        }
        i++;
    }
    while(top!=-1)
    {
        printf("\n%.2lf",pop());
        if(top!=-1)
            printf(" ");
    }
    return 0;
}