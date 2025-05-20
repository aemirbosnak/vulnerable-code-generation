//FormAI DATASET v1.0 Category: Game ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NUMBER 1000

// Function to generate random Number
int generateRand() {
    return (rand() % (MAX_NUMBER - 1)) + 1;
}

int main() {
    bool playAgain = true;

    printf("Welcome to the Guessing Game!\n");
    printf("I'm thinking of a number between 1 and %d, can you guess it?\n", MAX_NUMBER);
    
    while (playAgain) {
        int randomNumber = generateRand();
        int guessCount = 0;
        int guess = 0;
        
        printf("You can guess up to 10 times.\n");
        
        while (guessCount < 10) {
            printf("Guess #%d: ", guessCount + 1);
            scanf("%d", &guess);
            guessCount++;
            
            if (guess == randomNumber) {
                printf("Congratulations! You guessed it in %d attempts.\n", guessCount);
                
                // Ask if they want to play again
                char playAgainResponse;
                printf("Do you want to play again? (y/n): ");
                scanf(" %c", &playAgainResponse);
                
                if (playAgainResponse == 'n' || playAgainResponse == 'N') {
                    playAgain = false;
                }
                
                break;
                
            } else if (guess < randomNumber) {
                printf("Try higher. ");
            } else if (guess > randomNumber) {
                printf("Try lower. ");
            }
        }
        
        if (guessCount == 10) {
            printf("Sorry, you couldn't guess the number. It was %d\n", randomNumber);
            
            // Ask if they want to play again
            char playAgainResponse;
            printf("Do you want to play again? (y/n): ");
            scanf(" %c", &playAgainResponse);
            
            if (playAgainResponse == 'n' || playAgainResponse == 'N') {
                playAgain = false;
            }
        }
    }
    
    printf("Thanks for playing our Guessing Game!\n");
    
    return 0;
}