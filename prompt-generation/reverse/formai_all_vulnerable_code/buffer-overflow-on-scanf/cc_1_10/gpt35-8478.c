//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* A terminal-based art game: Guess the hidden number! */

int main() {

    /* Seed random number generator */
    srand(time(0)); 

    /* Set up game variables */
    int hidden_num = rand() % 100; // generate number between 0-99
    int guess;
    int num_guesses = 0;

    /* Print game instructions */
    printf("Welcome to Guess the Hidden Number! \n");
    printf("Try to guess the number between 0-99. \n");
    printf("You will receive hints after each guess. \n");
    printf("Enter your guess: \n");

    /* Main game loop */
    while(1) {

        /* Get user input */
        scanf("%d", &guess);

        /* Check if guess is correct */
        if(guess == hidden_num) {
            printf("You guessed the correct number! Congratulations! \n"); 
            break; // exit game loop
        }

        /* Provide hint */
        if(guess < hidden_num) {
            printf("The hidden number is higher! \n");
        }
        else {
            printf("The hidden number is lower! \n");
        }

        /* Increment number of guesses */
        num_guesses++;

        /* Check if player has exceeded maximum number of guesses */
        if(num_guesses >= 10) {
            printf("You have exceeded the maximum number of guesses. Game over! \n");
            break; // exit game loop
        }

        /* Prompt user for next guess */
        printf("Enter your next guess: \n");

    }

    /* End the program */
    printf("Thank you for playing Guess the Hidden Number! \n");
    return 0;
}