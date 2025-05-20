//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NUMBER_OF_OPERATIONS 10
#define MAX_NUMBER_OF_OPERANDS 5

// Function to perform an arithmetic operation
void perform_operation(int *operands, int num_operands, int operation) {
    int result = 0;

    switch (operation) {
        case '+':
            result = operands[0] + operands[1];
            break;
        case '-':
            result = operands[0] - operands[1];
            break;
        case '*':
            result = operands[0] * operands[1];
            break;
        case '/':
            result = operands[0] / operands[1];
            break;
        case '%':
            result = operands[0] % operands[1];
            break;
        default:
            printf("Invalid operation\n");
            return;
    }

    // Print the result
    printf("Result: %d\n", result);
}

int main() {
    int num_operations = 0;
    int num_operands = 0;
    int operations[MAX_NUMBER_OF_OPERATIONS][MAX_NUMBER_OF_OPERANDS];
    int operands[MAX_NUMBER_OF_OPERANDS];

    // Read the operations and operands from the user
    printf("Enter the operations and operands, separated by spaces:\n");
    while (num_operations < MAX_NUMBER_OF_OPERATIONS && num_operands < MAX_NUMBER_OF_OPERANDS) {
        char operation;
        int operand1, operand2;

        printf("Enter an operation (+, -, *, /, %): ");
        scanf(" %c", &operation);

        printf("Enter operand 1: ");
        scanf("%d", &operand1);

        printf("Enter operand 2: ");
        scanf("%d", &operand2);

        operations[num_operations][num_operands] = operation;
        operands[num_operands] = operand1;
        num_operands++;

        if (num_operations < MAX_NUMBER_OF_OPERATIONS - 1) {
            printf("Enter another operation: ");
            scanf(" %c", &operation);
        }

        num_operations++;
    }

    // Perform the operations
    for (int i = 0; i < num_operations; i++) {
        perform_operation(operations[i], num_operands, operations[i][0]);
    }

    return 0;
}