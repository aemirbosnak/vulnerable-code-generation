//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 100

// Function prototypes
void display_menu();
void handle_error(const char *message);
int get_operation();
float perform_operation(int operation, float num1, float num2);
void clear_input_buffer();

int main() {
    int operation;
    float num1, num2;

    while (1) {
        display_menu();
        operation = get_operation();

        if (operation == 5) {
            printf("Exiting the calculator. Goodbye!\n");
            break;
        }

        printf("Enter first number: ");
        if (scanf("%f", &num1) != 1) {
            handle_error("Invalid input for the first number. Exiting.");
            clear_input_buffer();
            continue;
        }

        printf("Enter second number: ");
        if (scanf("%f", &num2) != 1) {
            handle_error("Invalid input for the second number. Exiting.");
            clear_input_buffer();
            continue;
        }

        float result = perform_operation(operation, num1, num2);
        if (result != -1) {
            printf("Result: %.2f\n", result);
        }
        clear_input_buffer();
    }

    return 0;
}

void display_menu() {
    printf("\nSimple Calculator Menu:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
    printf("Choose an operation (1-5): ");
}

void handle_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
}

int get_operation() {
    int operation;
    if (scanf("%d", &operation) != 1) {
        clear_input_buffer();
        handle_error("Invalid selection. Please enter a number between 1 and 5.");
        return -1;
    }

    if (operation < 1 || operation > 5) {
        handle_error("Invalid selection. Please enter a number between 1 and 5.");
        return -1;
    }

    return operation;
}

float perform_operation(int operation, float num1, float num2) {
    float result;
    switch (operation) {
        case 1:
            return num1 + num2; // Addition
        case 2:
            return num1 - num2; // Subtraction
        case 3:
            return num1 * num2; // Multiplication
        case 4:
            if (num2 == 0) {
                handle_error("Division by zero is not allowed.");
                return -1;
            }
            return num1 / num2; // Division
        default:
            handle_error("Unexpected operation.");
            return -1;
    }
}

void clear_input_buffer() {
    while (getchar() != '\n'); // Clear the input buffer
}