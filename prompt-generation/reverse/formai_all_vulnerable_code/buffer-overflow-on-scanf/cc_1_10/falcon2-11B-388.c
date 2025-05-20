//Falcon2-11B DATASET v1.0 Category: Error handling ; Style: curious
#include <stdio.h>
#include <setjmp.h>

int main() {
    jmp_buf env;

    // Save the current program state
    if (setjmp(env) == 0) {
        // Loop to prompt the user for input, handle the input, and check for errors
        int guesses = 0;
        while (1) {
            printf("Please enter a lucky number between 1 and 100: ");
            int number;
            scanf("%d", &number);

            // Check if the input is a valid number
            if (number < 1 || number > 100) {
                printf("Invalid input. Please enter a number between 1 and 100.\n");
                continue;
            }

            // Check if the guess is too high, too low, or correct
            if (number == 100) {
                printf("Congratulations! You guessed the lucky number!\n");
                break;
            } else if (number > 100) {
                printf("Too high!\n");
            } else {
                printf("Too low!\n");
            }

            // Increment the number of guesses taken
            guesses++;

            // Check if the user wants to try again
            printf("Do you want to try again? (y/n): ");
            char response;
            scanf(" %c", &response);
            if (response!= 'y') {
                printf("Thanks for playing!\n");
                break;
            }
        }

        // Display the final result
        printf("You took %d guesses to find the lucky number!\n", guesses);
    }

    // Display a goodbye message
    printf("Goodbye!\n");

    return 0;
}