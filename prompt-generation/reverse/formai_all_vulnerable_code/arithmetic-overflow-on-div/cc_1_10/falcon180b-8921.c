//Falcon-180B DATASET v1.0 Category: Syntax parsing ; Style: relaxed
#include <stdio.h>

// Define a function to print a message
void print_message(char* message) {
    printf("%s\n", message);
}

// Define a function to add two numbers
int add_numbers(int a, int b) {
    return a + b;
}

// Define a function to multiply two numbers
int multiply_numbers(int a, int b) {
    return a * b;
}

// Define a function to divide two numbers
int divide_numbers(int a, int b) {
    if (b == 0) {
        printf("Error: division by zero\n");
        return 0;
    }
    return a / b;
}

// Define a function to calculate the square of a number
int square_number(int a) {
    return a * a;
}

// Define a function to calculate the cube of a number
int cube_number(int a) {
    return a * a * a;
}

int main() {
    // Print a welcome message
    print_message("Welcome to the C Syntax Parsing Example Program!");

    // Prompt the user to enter two numbers
    int num1, num2;
    printf("Enter two numbers separated by a space: ");
    scanf("%d %d", &num1, &num2);

    // Calculate the sum, difference, product, quotient, square, and cube of the two numbers
    int sum = add_numbers(num1, num2);
    int difference = num1 - num2;
    int product = multiply_numbers(num1, num2);
    int quotient = divide_numbers(num1, num2);
    int square = square_number(num1);
    int cube = cube_number(num1);

    // Print the results
    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", difference);
    printf("Product: %d\n", product);
    printf("Quotient: %d\n", quotient);
    printf("Square: %d\n", square);
    printf("Cube: %d\n", cube);

    return 0;
}