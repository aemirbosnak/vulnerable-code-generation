//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_OPERATIONS 100
#define MAX_NUMBERS 20

struct number {
    int value;
    char symbol;
};

int main(void) {
    struct number numbers[MAX_NUMBERS];
    int operations[MAX_OPERATIONS];
    int i, j;

    // Initialize numbers and operations
    for (i = 0; i < MAX_NUMBERS; i++) {
        numbers[i].value = 0;
        numbers[i].symbol = '+';
    }
    for (j = 0; j < MAX_OPERATIONS; j++) {
        operations[j] = 0;
    }

    // Read operations and numbers from standard input
    while (1) {
        char op;
        int num1, num2;

        printf("Enter operation (%c to quit): ", ' ');
        scanf(" %c", &op);
        if (op == 'q') break;

        printf("Enter first number: ");
        scanf("%d", &num1);
        printf("Enter second number: ");
        scanf("%d", &num2);

        // Perform operation
        switch (op) {
            case '+':
                numbers[0].value = num1 + num2;
                break;
            case '-':
                numbers[0].value = num1 - num2;
                break;
            case '*':
                numbers[0].value = num1 * num2;
                break;
            case '/':
                numbers[0].value = num1 / num2;
                break;
            default:
                printf("Invalid operation\n");
                continue;
        }

        // Print result
        printf("Result: %d\n", numbers[0].value);
    }

    // Print final result
    if (numbers[0].value != 0) {
        printf("Final result: %d\n", numbers[0].value);
    } else {
        printf("No operations were performed\n");
    }

    return 0;
}