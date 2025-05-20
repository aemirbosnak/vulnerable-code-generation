//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_range(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to roll a six-sided die
int roll_die() {
    return rand_range(1, 6);
}

// Function to roll a pair of six-sided dice
int roll_pair() {
    return roll_die() + roll_die();
}

// Function to play a game of Yahtzee
void play_yahtzee() {
    int dice[5];
    int rerolls = 2;
    int score = 0;

    // Roll the dice for the first time
    for (int i = 0; i < 5; i++) {
        dice[i] = roll_die();
    }

    // Print the initial roll
    printf("Initial roll: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", dice[i]);
    }
    printf("\n");

    // Loop through the two rerolls
    for (int r = 0; r < rerolls; r++) {
        // Get the indices of the dice to reroll
        int indices[5];
        printf("Enter the indices of the dice to reroll (1-5, separated by spaces): ");
        scanf("%d %d %d %d %d", &indices[0], &indices[1], &indices[2], &indices[3], &indices[4]);

        // Reroll the selected dice
        for (int i = 0; i < 5; i++) {
            if (indices[i] > 0 && indices[i] <= 5) {
                dice[i] = roll_die();
            }
        }

        // Print the new roll
        printf("New roll: ");
        for (int i = 0; i < 5; i++) {
            printf("%d ", dice[i]);
        }
        printf("\n");
    }

    // Calculate the score
    // ... (code to calculate the score)

    // Print the score
    printf("Your score is: %d\n", score);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Welcome the player
    printf("Welcome to Yahtzee!\n");

    // Play the game
    play_yahtzee();

    // Thank the player
    printf("Thanks for playing!\n");

    return 0;
}