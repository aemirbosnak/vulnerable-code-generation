//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: irregular
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAX 100

char expression[MAX];
int top=-1;

void push(char c)
{
    if(top>=MAX-1)
        printf("\nStack Overflow");
    else
    {
        top++;
        expression[top]=c;
    }
}

char pop()
{
    if(top<0)
        printf("\nStack Underflow");
    else
        return expression[top--];
}

void main()
{
    int i,j,n,choice;
    char c;
    printf("\n\t\t Scientific Calculator\n");
    while(1)
    {
        printf("\n\n1.Basic Operations\n2.Trigonometric Functions\n3.Logarithmic Functions\n4.Factorial\n5.Exit");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the two numbers:");
                scanf("%d%d",&n,&n);
                printf("\nEnter the operator(+,-,*,/):");
                scanf(" %c",&c);
                push(c);
                push(n);
                push(n);
                break;
            case 2:
                printf("\nEnter the angle in degrees:");
                scanf("%d",&n);
                if(n<0)
                    n=n*(-1);
                switch(n)
                {
                    case 0:
                        printf("\nResult: 1.000000");
                        break;
                    case 45:
                        printf("\nResult: 0.707107");
                        break;
                    case 90:
                        printf("\nResult: 0.000000");
                        break;
                    case 180:
                        printf("\nResult: -0.707107");
                        break;
                    default:
                        printf("\nResult: %0.6lf",sin(n*3.14159/180));
                }
                break;
            case 3:
                printf("\nEnter the number:");
                scanf("%d",&n);
                if(n==0)
                    printf("\nResult: Undefined");
                else if(n==1)
                    printf("\nResult: 0.000000");
                else
                    printf("\nResult: %0.6lf",log(n));
                break;
            case 4:
                printf("\nEnter the number:");
                scanf("%d",&n);
                if(n<0)
                    printf("\nResult: Undefined");
                else
                    printf("\nResult: %d",factorial(n));
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    }
}

int factorial(int n)
{
    int i,result=1;
    for(i=1;i<=n;i++)
    {
        result*=i;
    }
    return result;
}