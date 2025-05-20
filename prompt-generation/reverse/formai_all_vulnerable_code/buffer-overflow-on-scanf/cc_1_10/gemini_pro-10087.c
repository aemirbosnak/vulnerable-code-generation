//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Let's play a little game of math!

    // First, let's generate two random numbers between 1 and 100.
    int num1 = rand() % 100 + 1;
    int num2 = rand() % 100 + 1;

    // Now, let's ask the user to perform a mathematical operation on these numbers.
    // We'll give them three options: addition, subtraction, and multiplication.
    printf("Welcome to the Math Game!\n");
    printf("We've generated two random numbers for you: %d and %d.\n", num1, num2);
    printf("What mathematical operation would you like to perform on these numbers?\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    
    // Get the user's choice.
    int choice;
    scanf("%d", &choice);

    // Perform the operation based on the user's choice.
    int result;
    switch (choice) {
        case 1:
            result = num1 + num2;
            break;
        case 2:
            result = num1 - num2;
            break;
        case 3:
            result = num1 * num2;
            break;
        default:
            printf("Invalid choice. Please choose a valid option (1, 2, or 3).\n");
            return 1;
    }

    // Print the result.
    printf("The result of the operation is: %d\n", result);

    // Ask the user if they want to play again.
    printf("Would you like to play again? (y/n)\n");
    char answer;
    scanf(" %c", &answer);

    // If the user wants to play again, restart the game.
    if (answer == 'y' || answer == 'Y') {
        main();
    } else {
        printf("Thanks for playing! Goodbye!\n");
    }

    return 0;
}