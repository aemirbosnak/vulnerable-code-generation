//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 100
#define MAX_OPERATIONS 10

// Global variables
int num1 = 0, num2 = 0, result = 0;
char operation = '+';

// Function prototypes
void get_input(void);
void perform_operation(void);
void display_result(void);

int main(void) {
    srand(time(NULL));

    // Welcome message
    printf("Welcome to the Arithmetic Game!\n");

    // Main game loop
    while (1) {
        // Get input from user
        get_input();

        // Perform operation
        perform_operation();

        // Display result
        display_result();

        // Check if user wants to exit
        if (num1 == 0 && num2 == 0) {
            break;
        }
    }

    return 0;
}

// Function: get_input
void get_input(void) {
    int choice;

    // Print menu options
    printf("Choose an operation (+, -, *, /): ");
    printf("Enter a number: ");

    // Read user input
    scanf("%d%c%d", &num1, &operation, &num2);

    // Check if user entered a valid operation
    if (operation != '+' && operation != '-' && operation != '*' && operation != '/') {
        printf("Invalid operation. Try again.\n");
        get_input();
    }
}

// Function: perform_operation
void perform_operation(void) {
    switch (operation) {
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
            result = num1 / num2;
            break;
        default:
            printf("Invalid operation. Try again.\n");
            get_input();
            break;
    }
}

// Function: display_result
void display_result(void) {
    printf("Result: %d\n", result);
}