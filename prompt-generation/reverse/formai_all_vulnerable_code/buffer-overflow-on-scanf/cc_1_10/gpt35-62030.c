//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number in a specific range
int generateRandomNumber(int lower, int upper){
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main(){
    int num, guess, attempt=1, playAgain=1;
    char c;

    // Seed the random number generator with current time
    srand(time(0));

    printf("\n--- Welcome to the Guessing Game! ---");

    while(playAgain){
        // Generate a random number between 1 and 100
        num = generateRandomNumber(1, 100);

        printf("\n\nGuess the number between 1 and 100: ");

        while(1){
            // Read the user input
            scanf(" %d", &guess);

            if(guess == num){
                // If user guessed the number
                printf("\nCongratulations! You guessed the number in %d attempts.\n", attempt);
                break;
            } else if(guess < num){
                printf("\nToo low, try again: ");
            } else {
                printf("\nToo high, try again: ");
            }

            attempt++;
        }

        // Check if user wants to play again
        printf("\n\nWould you like to play again? (Type Y for Yes or any other key to exit): ");
        scanf(" %c", &c);

        if(c == 'y' || c == 'Y'){
            playAgain = 1;
            attempt = 1; // Reset the number of attempts
        } else {
            playAgain = 0;
        }
    }

    return 0;
}