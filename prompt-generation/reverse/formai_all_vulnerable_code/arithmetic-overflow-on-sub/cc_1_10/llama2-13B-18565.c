//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COIN_VALUE 100
#define MAX_GUESSES 6

// Global variables
int score = 0;
int guesses_left = MAX_GUESSES;
int coin_flip = 0;

// Function to generate a random coin flip result
void roll_the_coin() {
    coin_flip = rand() % 2;
}

// Function to update the score and guesses left based on the coin flip
void update_score() {
    if (coin_flip == 0) {
        score += COIN_VALUE;
    } else {
        guesses_left--;
    }
}

int main() {
    // Initialize the game
    printf("Welcome to the coin toss game! \n");
    printf("You have %d guesses left.\n", guesses_left);

    // Game loop
    while (guesses_left > 0) {
        // Roll the coin
        roll_the_coin();

        // Update the score and guesses left
        update_score();

        // Print the current state of the game
        printf("You have %d guesses left. Your current score is %d.\n", guesses_left, score);

        // Ask the player for their next guess
        printf("What's your next guess? (1 or 2): ");
        int guess = getchar() - '0';

        // Check if the player guessed correctly
        if (guess == coin_flip) {
            printf("Correct! You won %d coins!\n", COIN_VALUE);
            score += COIN_VALUE;
        } else {
            printf("Incorrect. You lost a guess.\n");
            guesses_left--;
        }
    }

    // Print the final score
    printf("Your final score is %d coins!\n", score);

    return 0;
}