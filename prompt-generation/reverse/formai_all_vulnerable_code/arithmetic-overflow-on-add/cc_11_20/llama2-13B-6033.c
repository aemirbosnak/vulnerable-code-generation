//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_OPERANDS 10
#define MAX_NUMBER 10000

int main() {
    int operands[MAX_OPERANDS];
    int numbers[MAX_OPERANDS];
    char op;
    int result;

    // Initialize operands and numbers arrays
    for (int i = 0; i < MAX_OPERANDS; i++) {
        operands[i] = 0;
        numbers[i] = 0;
    }

    // Get the first operand from the user
    printf("Enter the first operand: ");
    scanf("%d", &numbers[0]);

    // Get the second operand from the user
    printf("Enter the second operand: ");
    scanf("%d", &numbers[1]);

    // Get the operation from the user
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &op);

    // Perform the operation
    switch (op) {
        case '+':
            result = numbers[0] + numbers[1];
            break;
        case '-':
            result = numbers[0] - numbers[1];
            break;
        case '*':
            result = numbers[0] * numbers[1];
            break;
        case '/':
            result = numbers[0] / numbers[1];
            break;
        default:
            printf("Invalid operation\n");
            return 1;
    }

    // Print the result
    printf("Result: %d\n", result);

    // Get the next operand from the user
    printf("Enter the next operand: ");
    scanf("%d", &numbers[2]);

    // Repeat the operation until the user enters 0
    while (numbers[2]) {
        // Perform the operation
        switch (op) {
            case '+':
                result = result + numbers[2];
                break;
            case '-':
                result = result - numbers[2];
                break;
            case '*':
                result = result * numbers[2];
                break;
            case '/':
                result = result / numbers[2];
                break;
            default:
                printf("Invalid operation\n");
                return 1;
        }

        // Print the result
        printf("Result: %d\n", result);

        // Get the next operand from the user
        printf("Enter the next operand: ");
        scanf("%d", &numbers[3]);
    }

    return 0;
}