//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 100
#define MIN_INPUT 1
#define POWER_LIMIT 10

typedef struct {
    int num;
    char op;
} operation;

operation operations[] = {
    {1, '+'},
    {2, '-'},
    {3, '*'},
    {4, '/'},
    {5, '^'}
};

int main() {
    int input, i, j, result;
    char op;

    // Initialize input and output
    printf("Welcome to the Arithmetic Game!\n");
    printf("Enter a number: ");
    scanf("%d", &input);
    printf("Enter an operation (+, -, *, /, or ^): ");
    scanf(" %c", &op);

    // Check if the input is valid
    if (input < MIN_INPUT || input > MAX_INPUT) {
        printf("Invalid input. Please enter a number between %d and %d.\n", MIN_INPUT, MAX_INPUT);
        return 1;
    }

    // Check if the operation is valid
    for (i = 0; i < sizeof(operations) / sizeof(operation); i++) {
        if (op == operations[i].op) {
            break;
        }
    }

    if (i == sizeof(operations) / sizeof(operation)) {
        printf("Invalid operation. Please enter a valid operation (+, -, *, /, or ^).\n");
        return 1;
    }

    // Perform the operation
    switch (op) {
        case '+':
            result = input + operations[i].num;
            break;
        case '-':
            result = input - operations[i].num;
            break;
        case '*':
            result = input * operations[i].num;
            break;
        case '/':
            result = input / operations[i].num;
            break;
        case '^':
            result = pow(input, operations[i].num);
            break;
        default:
            printf("Invalid operation. Please enter a valid operation (+, -, *, /, or ^).\n");
            return 1;
    }

    // Print the result
    printf("Result: %d\n", result);

    // Ask the user if they want to play again
    printf("Do you want to play again? (y/n): ");
    scanf(" %c", &op);

    if (op == 'y') {
        main();
    } else {
        printf("Goodbye!.\n");
        return 0;
    }

    return 0;
}