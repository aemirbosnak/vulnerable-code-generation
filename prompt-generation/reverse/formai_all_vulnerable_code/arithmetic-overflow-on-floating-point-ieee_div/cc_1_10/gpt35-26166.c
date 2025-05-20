//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

// function to add two numbers
double add(double x, double y) {
    return x + y;
}

// function to subtract two numbers
double subtract(double x, double y) {
    return x - y;
}

// function to multiply two numbers
double multiply(double x, double y) {
    return x * y;
}

// function to divide two numbers
double divide(double x, double y) {
    if (y == 0) {
        printf("Error: Division by zero not allowed\n");
        exit(1);
    }
    return x / y;
}

// function to receive user input
double get_input() {
    double input;
    printf("Enter a number: ");
    scanf("%lf", &input);
    return input;
}

int main() {
    // get user input
    double num1 = get_input();
    double num2 = get_input();

    // add the two numbers
    double sum = add(num1, num2);
    printf("%.2lf + %.2lf = %.2lf\n", num1, num2, sum);

    // subtract the two numbers
    double difference = subtract(num1, num2);
    printf("%.2lf - %.2lf = %.2lf\n", num1, num2, difference);

    // multiply the two numbers
    double product = multiply(num1, num2);
    printf("%.2lf * %.2lf = %.2lf\n", num1, num2, product);

    // divide the two numbers
    double quotient = divide(num1, num2);
    printf("%.2lf / %.2lf = %.2lf\n", num1, num2, quotient);

    return 0;
}