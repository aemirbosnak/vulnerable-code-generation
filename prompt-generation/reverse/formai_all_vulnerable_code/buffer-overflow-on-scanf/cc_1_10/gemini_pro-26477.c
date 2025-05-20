//GEMINI-pro DATASET v1.0 Category: Educational ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to play a round of the game
void play_round(int *score) {
    // Generate a random number between 1 and 10
    int target = random_number(1, 10);

    // Get the player's guess
    int guess;
    printf("Guess a number between 1 and 10: ");
    scanf("%d", &guess);

    // Check if the player's guess is correct
    if (guess == target) {
        printf("Correct! You win 1 point.\n");
        *score += 1;
    } else {
        printf("Incorrect. The correct number was %d.\n", target);
    }
}

// Function to play the game
void play_game() {
    // Initialize the player's score
    int score = 0;

    // Play 10 rounds of the game
    for (int i = 0; i < 10; i++) {
        play_round(&score);
    }

    // Print the player's final score
    printf("Your final score is %d.\n", score);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Play the game
    play_game();

    return 0;
}