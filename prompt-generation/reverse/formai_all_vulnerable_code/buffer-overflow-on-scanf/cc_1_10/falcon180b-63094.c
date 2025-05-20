//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: thoughtful
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {

    // Declare variables
    double num1, num2, result;
    char operation;

    // Seed random number generator
    srand(time(NULL));

    // Generate two random numbers
    num1 = rand() % 100;
    num2 = rand() % 100;

    // Print the two numbers
    printf("Random numbers: %lf, %lf\n", num1, num2);

    // Ask user for operation
    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &operation);

    // Perform operation and print result
    switch(operation) {
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
            if(num2 == 0) {
                printf("Error: Division by zero\n");
                return 1;
            }
            result = num1 / num2;
            break;
        default:
            printf("Error: Invalid operation\n");
            return 1;
    }

    // Print result
    printf("Result: %lf\n", result);

    return 0;
}