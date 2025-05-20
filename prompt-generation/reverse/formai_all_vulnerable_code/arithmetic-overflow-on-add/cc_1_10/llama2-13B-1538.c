//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_OPERATIONS 10
#define MAX_NUM_DIGITS 10

// Structure to store operation and number values
typedef struct {
    char operation;
    int number;
} operation_t;

// Function to read and store operation and number values
void get_operation_number(operation_t *op_num) {
    char operation;
    int number;

    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &operation);

    if (operation == '+') {
        printf("Enter first number: ");
        scanf("%d", &number);
    } else if (operation == '-') {
        printf("Enter first number: ");
        scanf("%d", &number);
        number *= -1;
    } else if (operation == '*') {
        printf("Enter first number: ");
        scanf("%d", &number);
    } else if (operation == '/') {
        printf("Enter first number: ");
        scanf("%d", &number);
        if (number == 0) {
            printf("Error: cannot divide by zero\n");
            return;
        }
    }

    op_num->operation = operation;
    op_num->number = number;
}

// Function to perform arithmetic operations
void perform_operation(operation_t *op_num1, operation_t *op_num2) {
    int result;

    switch (op_num1->operation) {
        case '+':
            result = op_num1->number + op_num2->number;
            break;
        case '-':
            result = op_num1->number - op_num2->number;
            break;
        case '*':
            result = op_num1->number * op_num2->number;
            break;
        case '/':
            result = op_num1->number / op_num2->number;
            break;
        default:
            printf("Invalid operation\n");
            return;
    }

    printf("Result: %d\n", result);
}

int main() {
    operation_t op_num1, op_num2;

    // Perform up to MAX_OPERATIONS operations
    for (int i = 0; i < MAX_OPERATIONS; i++) {
        get_operation_number(&op_num1);
        get_operation_number(&op_num2);
        perform_operation(&op_num1, &op_num2);

        // Display result and ask user to continue
        printf("Result: %d\n", op_num1.number);
        printf("Do you want to continue? (y/n): ");
        char cont = getchar();

        if (cont == 'n' || cont == 'N') {
            break;
        }
    }

    return 0;
}