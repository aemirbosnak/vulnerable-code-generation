//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main()
{
    char op;
    double num1, num2, result;

    printf("Cyberpunk Calculator\n");
    printf("--------------------\n");

    printf("Enter the operator (+,-,*,/,sin,cos,tan,sqrt): ");
    scanf("%c",&op);

    if(op=='+' || op=='-' || op=='*' || op=='/')
    {
        printf("Enter first number: ");
        scanf("%lf", &num1);
        printf("Enter second number: ");
        scanf("%lf", &num2);

        if(op=='+')
        {
            result=num1+num2;
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
        }
        else if(op=='-')
        {
            result=num1-num2;
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
        }
        else if(op=='*')
        {
            result=num1*num2;
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
        }
        else if(op=='/')
        {
            result=num1/num2;
            printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
        }
    }

    else if(op=='sin' || op=='cos' || op=='tan' || op=='sqrt')
    {
        printf("Enter the number: ");
        scanf("%lf", &num1);

        if(op=='sin')
        {
            result=sin(num1);
            printf("sin(%.2lf) = %.2lf\n", num1, result);
        }
        else if(op=='cos')
        {
            result=cos(num1);
            printf("cos(%.2lf) = %.2lf\n", num1, result);
        }
        else if(op=='tan')
        {
            result=tan(num1);
            printf("tan(%.2lf) = %.2lf\n", num1, result);
        }
        else if(op=='sqrt')
        {
            result=sqrt(num1);
            printf("sqrt(%.2lf) = %.2lf\n", num1, result);
        }
    }

    else
    {
        printf("Invalid Operator!\n");
    }

    printf("--------------------\n");
    printf("Thank you for using Cyberpunk Calculator!\n");
}