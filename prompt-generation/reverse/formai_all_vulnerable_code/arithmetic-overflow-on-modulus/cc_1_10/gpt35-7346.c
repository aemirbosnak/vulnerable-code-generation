//FormAI DATASET v1.0 Category: Calculator ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    printf("Welcome to the Calculator program! I hope you have your math hat on.\n\n");
    printf("Please enter the first number: ");

    double num1;
    scanf("%lf", &num1);

    printf("Please enter the second number: ");

    double num2;
    scanf("%lf", &num2);

    printf("\n");

    int result;

    printf("What do you want to do with these numbers? Choose from these options:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Modulus\n");
    printf("Enter the number corresponding to the operation you want to perform: ");

    int operation;
    scanf("%d", &operation);

    switch (operation) 
    {
        case 1:
            result = num1 + num2;
            printf("%.2lf + %.2lf = %.2d\n", num1, num2, result);
            break;
        case 2:
            result = num1 - num2;
            printf("%.2lf - %.2lf = %.2d\n", num1, num2, result);
            break;
        case 3:
            result = num1 * num2;
            printf("%.2lf * %.2lf = %.2d\n", num1, num2, result);
            break;
        case 4:
            if (num2 != 0)
            {
                result = num1 / num2;
                printf("%.2lf / %.2lf = %.2d\n", num1, num2, result);
            }
            else
            {
                printf("Looks like you forgot your math rules-division by zero is not allowed! Now I have to crash, oops!\n");
                exit(0);
            }
            break;
        case 5:
            result = ((int) num1) % ((int) num2);
            printf("%.2lf %% %.2lf = %d (modulus)\n", num1, num2, result);
            break;
        default:
            printf("Yikes, you entered a crazy number! Are you even human? I'll just shut myself down now, bye!\n");
            exit(0);
    }

    printf("\nI hope you had fun using my calculator program. Until next time, keep calculating!\n");

    return 0;
}