//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 100
#define MAX_OPERATIONS 10

// Function to perform math operations
void do_math(int num1, int num2, char operation) {
    int result;

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
            printf("Invalid operation\n");
            return;
    }

    printf("Result: %d\n", result);
}

int main() {
    int num1, num2, operations[MAX_OPERATIONS];
    char operation;

    // Initialize variables
    srand(time(NULL));
    num1 = rand() % MAX_NUM;
    num2 = rand() % MAX_NUM;
    operations[0] = '+';

    // Prompt user for math operations
    printf("Welcome to Math Land!\n");
    printf("You have been given the following numbers: %d and %d\n", num1, num2);
    printf("Now, choose an operation to perform:\n");

    // Get user input
    scanf("%c", &operation);

    // Perform math operations
    do_math(num1, num2, operation);

    // Ask user for another operation
    printf("Would you like to perform another operation? (y/n)\n");

    // Get user input
    char response;
    scanf(" %c", &response);

    // Repeat math operations while user wants to continue
    while (response == 'y' || response == 'Y') {
        // Get another math operation from user
        scanf("%c", &operation);

        // Perform math operations
        do_math(num1, num2, operation);

        // Ask user for another operation
        printf("Would you like to perform another operation? (y/n)\n");
        scanf(" %c", &response);
    }

    return 0;
}