//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: active
#include<stdio.h>

int main()
{
    int a,b,c;
    char operator;

    printf("Enter the operator: + - * / ^ \n");
    scanf("%c",&operator);

    printf("Enter the first operand: \n");
    scanf("%d",&a);

    printf("Enter the second operand: \n");
    scanf("%d",&b);

    switch(operator)
    {
        case '+':
            c=a+b;
            printf("Result: %d\n",c);
            break;

        case '-':
            c=a-b;
            printf("Result: %d\n",c);
            break;

        case '*':
            c=a*b;
            printf("Result: %d\n",c);
            break;

        case '/':
            if(b==0)
            {
                printf("Error! Division by zero\n");
            }
            else
            {
                c=a/b;
                printf("Result: %d\n",c);
            }
            break;

        case '^':
            c=a^b;
            printf("Result: %d\n",c);
            break;

        default:
            printf("Invalid operator\n");
            break;
    }

    return 0;
}