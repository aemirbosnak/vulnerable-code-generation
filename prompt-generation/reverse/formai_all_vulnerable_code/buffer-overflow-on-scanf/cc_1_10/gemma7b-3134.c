//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void main()
{
    char op;
    float num1, num2, result;
    int i, flag = 0, choice;

    printf("Enter 1 for basic calculator, 2 for scientific calculator: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter operator (+, -, *, /): ");
            scanf(" %c", &op);

            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);

            switch (op)
            {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    if (num2 == 0)
                    {
                        printf("Cannot divide by zero\n");
                        flag = 1;
                    }
                    else
                    {
                        result = num1 / num2;
                    }
                    break;
                default:
                    printf("Invalid operator\n");
                    flag = 1;
            }

            if (flag == 0)
            {
                printf("The result is: %.2f\n", result);
            }
            break;

        case 2:
            // Scientific calculator code
            break;

        default:
            printf("Invalid choice\n");
            flag = 1;
    }

    if (flag == 0)
    {
        printf("Thank you for using the calculator!\n");
    }

    return;
}