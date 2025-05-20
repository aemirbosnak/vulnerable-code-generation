//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM 100
#define MAX_OPERATIONS 5

// Structure to hold the numbers and operations
typedef struct {
    int num1;
    int num2;
    char operation;
} arithmetic_data_t;

// Function to perform arithmetic operations
void perform_arithmetic_operations(arithmetic_data_t *data) {
    int result;

    // Check for invalid input
    if (data->num1 < 0 || data->num2 < 0) {
        printf("Invalid input. Please enter positive numbers.\n");
        return;
    }

    // Perform the operation
    switch (data->operation) {
        case '+':
            result = data->num1 + data->num2;
            break;
        case '-':
            result = data->num1 - data->num2;
            break;
        case '*':
            result = data->num1 * data->num2;
            break;
        case '/':
            result = data->num1 / data->num2;
            break;
        default:
            printf("Invalid operation. Please enter a valid operation (+, -, *, /).\n");
            return;
    }

    // Print the result
    printf("Result: %d\n", result);
}

int main() {
    // Create a menu for the user to select operations
    char menu[] = "Select an operation (+, -, *, /): ";
    char operation;

    do {
        printf("%s", menu);
        scanf(" %c", &operation);

        // Create a new arithmetic_data_t struct to hold the numbers and operation
        arithmetic_data_t data = {0};

        // Ask the user for the numbers
        printf("Enter number 1: ");
        scanf(" %d", &data.num1);

        printf("Enter number 2: ");
        scanf(" %d", &data.num2);

        // Store the operation in the struct
        data.operation = operation;

        // Perform the arithmetic operations
        perform_arithmetic_operations(&data);
    } while (operation != 'q');

    return 0;
}