//Falcon2-11B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define the operation types
    enum OperationType {
        ADD, SUBTRACT, MULTIPLY, DIVIDE
    };
    
    // Initialize variables
    double number1 = 0.0;
    double number2 = 0.0;
    double result = 0.0;
    int operationType;
    
    // Get the first number
    printf("Enter the first number: ");
    scanf("%lf", &number1);
    
    // Get the operation type
    printf("Enter the operation type (+, -, *, /): ");
    scanf(" %d", &operationType);
    
    // Get the second number
    printf("Enter the second number: ");
    scanf("%lf", &number2);
    
    // Perform the operation
    switch(operationType)
    {
        case ADD:
            result = number1 + number2;
            break;
        case SUBTRACT:
            result = number1 - number2;
            break;
        case MULTIPLY:
            result = number1 * number2;
            break;
        case DIVIDE:
            if(number2 == 0.0) // Prevent division by zero
            {
                printf("Error: Division by zero is not allowed.\n");
                return 1;
            }
            result = number1 / number2;
            break;
        default:
            printf("Error: Invalid operation type.\n");
            return 1;
    }
    
    // Print the result
    printf("The result is: %.2lf\n", result);
    
    return 0;
}