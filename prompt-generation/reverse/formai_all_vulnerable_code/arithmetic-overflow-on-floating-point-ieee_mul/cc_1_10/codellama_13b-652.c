//Code Llama-13B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: grateful
/*
 * Scientific Calculator Implementation in C
 *
 * This program allows the user to perform various mathematical operations
 * such as addition, subtraction, multiplication, and division, as well
 * as trigonometric functions and logarithmic functions.
 *
 * Author: [Your Name]
 * Date: [Current Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the functions used in the program
void displayMenu();
double getValue(const char *);
double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);
double sin(double);
double cos(double);
double tan(double);
double log(double);

int main() {
    // Declare variables
    double num1, num2, result;
    char op;

    // Display the menu
    displayMenu();

    // Get the user input
    scanf("%c", &op);
    scanf("%lf", &num1);
    scanf("%lf", &num2);

    // Perform the operation
    switch (op) {
        case '+':
            result = add(num1, num2);
            break;
        case '-':
            result = subtract(num1, num2);
            break;
        case '*':
            result = multiply(num1, num2);
            break;
        case '/':
            result = divide(num1, num2);
            break;
        case 's':
            result = sin(num1);
            break;
        case 'c':
            result = cos(num1);
            break;
        case 't':
            result = tan(num1);
            break;
        case 'l':
            result = log(num1);
            break;
        default:
            printf("Invalid operation.\n");
            return 1;
    }

    // Display the result
    printf("Result: %lf\n", result);

    return 0;
}

// Function definitions
void displayMenu() {
    printf("Welcome to the Scientific Calculator\n");
    printf("-----------------------------------\n");
    printf("+ : Addition\n");
    printf("- : Subtraction\n");
    printf("* : Multiplication\n");
    printf("/ : Division\n");
    printf("s : Sine\n");
    printf("c : Cosine\n");
    printf("t : Tangent\n");
    printf("l : Logarithm\n");
    printf("-----------------------------------\n");
}

double getValue(const char *str) {
    return atof(str);
}

double add(double num1, double num2) {
    return num1 + num2;
}

double subtract(double num1, double num2) {
    return num1 - num2;
}

double multiply(double num1, double num2) {
    return num1 * num2;
}

double divide(double num1, double num2) {
    return num1 / num2;
}

double sin(double num) {
    return sin(num);
}

double cos(double num) {
    return cos(num);
}

double tan(double num) {
    return tan(num);
}

double log(double num) {
    return log(num);
}