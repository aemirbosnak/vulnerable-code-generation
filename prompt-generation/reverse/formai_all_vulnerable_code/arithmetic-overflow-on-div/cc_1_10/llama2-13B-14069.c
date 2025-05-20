//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_OPERATIONS 10
#define MAX_NUM_DIGITS 10

// Global variables
int num1 = 0, num2 = 0, result = 0;
char operation = '+';

// Function to read input from user
void get_input() {
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &operation);
}

// Function to perform arithmetic operation
void perform_operation() {
    if (operation == '+') {
        result = num1 + num2;
    } else if (operation == '-') {
        result = num1 - num2;
    } else if (operation == '*') {
        result = num1 * num2;
    } else if (operation == '/') {
        result = num1 / num2;
    }
}

int main() {
    int i, j, k;
    char input;

    // Initialize the program
    srand(time(NULL));

    // Perform arithmetic operations dynamically
    for (i = 0; i < MAX_OPERATIONS; i++) {
        get_input();
        perform_operation();

        // Display the result
        printf("Result: %d\n", result);

        // Get the user's input for the next operation
        printf("Enter the next operation (+, -, *, /): ");
        scanf(" %c", &input);
    }

    return 0;
}