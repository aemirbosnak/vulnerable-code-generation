//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number_of_operations = 0;
    int operand_1 = 0;
    int operand_2 = 0;
    char operator = '\0';

    printf("Welcome to the Mathematical Adventure Game!\n");
    printf("Please enter the number of operations you want to perform: ");
    scanf("%d", &number_of_operations);

    for (int i = 0; i < number_of_operations; i++)
    {
        printf("Enter the first operand: ");
        scanf("%d", &operand_1);

        printf("Enter the operator (+, -, *, /): ");
        scanf(" %c", &operator);

        printf("Enter the second operand: ");
        scanf("%d", &operand_2);

        switch (operator)
        {
            case '+':
                printf("The result is: %d\n", operand_1 + operand_2);
                break;
            case '-':
                printf("The result is: %d\n", operand_1 - operand_2);
                break;
            case '*':
                printf("The result is: %d\n", operand_1 * operand_2);
                break;
            case '/':
                if (operand_2 == 0)
                {
                    printf("Cannot divide by zero!\n");
                }
                else
                {
                    printf("The result is: %d\n", operand_1 / operand_2);
                }
                break;
            default:
                printf("Invalid operator.\n");
                break;
        }
    }

    printf("Thank you for playing the Mathematical Adventure Game!\n");

    return 0;
}