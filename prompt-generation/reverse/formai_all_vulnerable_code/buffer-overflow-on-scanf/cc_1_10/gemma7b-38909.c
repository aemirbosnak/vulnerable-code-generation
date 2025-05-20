//Gemma-7B DATASET v1.0 Category: Error handling ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBER 10

int main()
{
    int number;
    char operation;
    double result = 0.0;

    printf("Enter an operation (+, -, *, /): ");
    scanf("%c", &operation);

    printf("Enter a number: ");
    scanf("%d", &number);

    switch (operation)
    {
        case '+':
            if (number > MAX_NUMBER)
            {
                printf("Error: Number exceeds maximum limit of %d.", MAX_NUMBER);
                return 1;
            }
            result = (double)number + result;
            break;
        case '-':
            if (number < 0)
            {
                printf("Error: Number is less than 0.");
                return 1;
            }
            result = (double)number - result;
            break;
        case '*':
            if (number == 0)
            {
                printf("Error: Cannot divide by 0.");
                return 1;
            }
            result = (double)number / result;
            break;
        case '/':
            if (number == 0)
            {
                printf("Error: Cannot divide by 0.");
                return 1;
            }
            result = (double)number * result;
            break;
        default:
            printf("Error: Invalid operation.");
            return 1;
    }

    printf("The result is: %.2lf", result);

    return 0;
}