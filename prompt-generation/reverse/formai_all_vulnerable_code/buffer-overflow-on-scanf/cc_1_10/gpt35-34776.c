//FormAI DATASET v1.0 Category: Memory Game ; Style: peaceful
/*
A peaceful style memory game that tests the player's ability to remember the sequence of colors.
The player will be shown a sequence of colors for a few seconds, then they will have to input the same sequence from memory.
If the player inputs the correct sequence, they win the game.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_COLORS 5 // Max. number of colors used in the game
#define MAX_SEQUENCE 10 // Max. number of colors in a sequence
#define MAX_TIME 5 // Max. time (in seconds) for player to memorize sequence

// Colors that can be used in the game
const char* colors[MAX_COLORS] = {
    "Red", "Blue", "Green", "Yellow", "Purple"
};

int main() {
    int sequence[MAX_SEQUENCE]; // Array to hold the randomly generated sequence
    int guess[MAX_SEQUENCE]; // Array to hold the player's guess
    int num_rounds = 1; // Number of rounds played
    int num_correct = 0; // Number of correctly guessed sequences
    srand(time(NULL)); // Initialize random seed

    printf("Welcome to the Memory Game!\n\n");
    printf("In each round, you will be shown a sequence of colors for a few seconds.\n");
    printf("Then, you must input the same sequence from memory.\n\n");

    while (1) { // Game loop
        printf("Round %d: ", num_rounds);

        // Generate random sequence
        for (int i=0; i<num_rounds; i++) {
            sequence[i] = rand() % MAX_COLORS;
        }

        // Show sequence and wait for player to memorize it (for a few seconds)
        for (int i=0; i<num_rounds; i++) {
            printf("%s ", colors[sequence[i]]);
        }
        printf("\n");
        printf("Memorize the sequence (you have %d seconds)\n", MAX_TIME);

        for (int i=0; i<num_rounds; i++) {
            for (int j=0; j<MAX_TIME; j++) {
                printf(".");
                fflush(stdout);
                sleep(1);
            }
            printf("\r            \r"); // Delete the dots
        }

        // Get player's guess
        printf("Enter the sequence: ");
        for (int i=0; i<num_rounds; i++) {
            scanf("%d", &guess[i]);
        }

        // Check if player's guess is correct
        int correct = 1;
        for (int i=0; i<num_rounds; i++) {
            if (guess[i] != sequence[i]) {
                correct = 0;
                break;
            }
        }

        if (correct) {
            num_correct++;
            printf("Correct! You have guessed %d sequences correctly.\n", num_correct);
            num_rounds++;
        }
        else {
            printf("Wrong! Game over.\n");
            printf("You have guessed %d sequences correctly.\n\n", num_correct);
            printf("Thanks for playing!\n");
            break;
        }
    }

    return 0;
}