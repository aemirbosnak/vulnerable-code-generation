//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 100
#define MAX_OPERATIONS 100

int main()
{
    int numbers[MAX_NUMBERS];
    int operations[MAX_OPERATIONS];
    int num_operations = 0;
    int num_numbers = 0;
    int i, j, k;
    int choice;
    int num1, num2;
    int result;
    int valid_operation = 0;

    srand(time(NULL));

    // Generate random numbers
    for (i = 0; i < MAX_NUMBERS; i++)
    {
        numbers[i] = rand() % 100;
    }

    // Perform arithmetic operations
    while (num_operations < MAX_OPERATIONS)
    {
        printf("Enter an arithmetic operation (+, -, *, /): ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                result = num1 + num2;
                printf("Result: %d\n", result);
                break;

            case 2:
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                result = num1 - num2;
                printf("Result: %d\n", result);
                break;

            case 3:
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                result = num1 * num2;
                printf("Result: %d\n", result);
                break;

            case 4:
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                if (num2 == 0)
                {
                    printf("Error: Division by zero\n");
                }
                else
                {
                    result = num1 / num2;
                    printf("Result: %d\n", result);
                }
                break;

            default:
                printf("Invalid operation\n");
        }

        num_operations++;
    }

    return 0;
}