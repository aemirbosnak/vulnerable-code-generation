//Code Llama-13B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the calculator functions
double add(double x, double y) {
    return x + y;
}

double subtract(double x, double y) {
    return x - y;
}

double multiply(double x, double y) {
    return x * y;
}

double divide(double x, double y) {
    return x / y;
}

double square(double x) {
    return x * x;
}

double sqrt(double x) {
    return sqrt(x);
}

// Define the main function
int main() {
    // Get the user input
    double x, y;
    char operation;
    printf("Enter the first number: ");
    scanf("%lf", &x);
    printf("Enter the second number: ");
    scanf("%lf", &y);
    printf("Enter the operation (+, -, *, /, sqrt, square): ");
    scanf(" %c", &operation);

    // Perform the operation
    double result;
    switch (operation) {
        case '+':
            result = add(x, y);
            break;
        case '-':
            result = subtract(x, y);
            break;
        case '*':
            result = multiply(x, y);
            break;
        case '/':
            result = divide(x, y);
            break;
        case 'sqrt':
            result = sqrt(x);
            break;
        case 'square':
            result = square(x);
            break;
        default:
            printf("Invalid operation");
            return 1;
    }

    // Print the result
    printf("The result is: %lf\n", result);
    return 0;
}