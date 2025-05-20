//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int i = 0;
    float num1, num2, result;

    printf("Welcome to the Scientific Calculator!\n");

    // Get the first number
    printf("Enter the first number: ");
    scanf("%f", &num1);

    // Get the operator
    printf("Enter the operator (+, -, *, /): ");
    scanf("%s", buffer);

    // Get the second number
    printf("Enter the second number: ");
    scanf("%f", &num2);

    // Calculate the result
    switch (buffer[0])
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
                printf("Error: division by zero is not allowed.\n");
            }
            else
            {
                result = num1 / num2;
            }
            break;
        default:
            printf("Invalid operator.\n");
            break;
    }

    // Display the result
    if (result != -1)
    {
        printf("The result is: %.2f\n", result);
    }

    return 0;
}