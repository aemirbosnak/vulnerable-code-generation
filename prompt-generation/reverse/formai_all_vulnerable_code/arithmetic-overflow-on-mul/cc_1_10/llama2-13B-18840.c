//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUMBER 1000000
#define MIN_NUMBER 1

int main() {
    int number, operation, choice;
    char input[100];

    // Initialize variables
    number = 0;
    operation = 0;
    choice = 0;

    // Menu for the user to choose an operation
    printf("Welcome to Arithmetic Land!\n");
    printf("Please choose an operation (+, -, *, /, or %).\n");
    scanf("%d", &choice);

    // Get the first number from the user
    printf("Enter the first number: ");
    fgets(input, 100, stdin);
    sscanf(input, "%d", &number);

    // Get the second number from the user
    printf("Enter the second number: ");
    fgets(input, 100, stdin);
    sscanf(input, "%d", &operation);

    // Perform the operation
    switch (choice) {
        case 1: // +
            number = number + operation;
            break;
        case 2: // -
            number = number - operation;
            break;
        case 3: // *
            number = number * operation;
            break;
        case 4: // /
            number = number / operation;
            break;
        case 5: // %
            number = number % operation;
            break;
        default:
            printf("Invalid input. Please try again.\n");
            break;
    }

    // Print the result
    printf("Result: %d\n", number);

    // Ask the user if they want to play again
    printf("Do you want to play again? (y/n): ");
    scanf(" %c", &input);

    return 0;
}