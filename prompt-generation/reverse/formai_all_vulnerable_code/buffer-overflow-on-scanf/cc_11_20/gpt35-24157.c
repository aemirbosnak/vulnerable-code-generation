//FormAI DATASET v1.0 Category: Table Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Welcome message
    printf("Welcome to the hilarious C Table Game, where your fortunes will be made or lost!\n");
    printf("How many players are there?\n");

    // Get number of players
    int numPlayers;
    scanf("%d", &numPlayers);

    // Initialize array of player scores
    int scores[numPlayers];
    for (int i = 0; i < numPlayers; i++) {
        scores[i] = 0;
    }

    // Randomly determine whether the table is tilted or not
    srand(time(NULL)); // Seed random number generator
    int isTilted = rand() % 2;

    // Start game loop
    int round = 1;
    while (round <= 5) {
        // Display round number
        printf("Round %d\n", round);

        // Loop through each player's turn
        for (int i = 0; i < numPlayers; i++) {
            printf("Player %d: Press any key to spin the wheel...\n", i+1);
            getchar(); // Wait for user to press key

            // Randomly determine spin result
            int spinResult = rand() % 10 + 1;

            if (!isTilted) { // Table is level
                if (spinResult == 1) {
                    printf("Disaster strikes! The table tilts and all your pieces fall off!\n");
                    scores[i] = 0;
                } else if (spinResult >= 2 && spinResult <= 6) {
                    printf("Not bad... You move %d spaces forward.\n", spinResult);
                    scores[i] += spinResult;
                } else if (spinResult >= 7 && spinResult <= 9) {
                    printf("You hit a jackpot! You move %d spaces forward and earn 10 extra points.\n", spinResult);
                    scores[i] += spinResult + 10;
                } else { // spinResult == 10
                    printf("You hit the jackpot of jackpots! You move all the way to the end and earn 50 extra points.\n");
                    scores[i] = 100;
                }
            } else { // Table is tilted
                if (spinResult == 1 || spinResult == 2) {
                    printf("Disaster strikes again! The table tilts even more and all your pieces fall off!\n");
                    scores[i] = 0;
                } else if (spinResult >= 3 && spinResult <= 6) {
                    printf("Not bad... You move %d spaces forward before the table tilts and you fall off.\n", spinResult);
                    scores[i] += spinResult;
                } else if (spinResult >= 7 && spinResult <= 9) {
                    printf("You hit a jackpot! You move %d spaces forward and earn 10 extra points before the table tilts and you fall off.\n", spinResult);
                    scores[i] += spinResult + 10;
                } else { // spinResult == 10
                    printf("You hit the jackpot of jackpots! You move all the way to the end and earn 50 extra points before the table tilts and you fall off.\n");
                    scores[i] = 100;
                }
            }

            // Display current score
            printf("Your current score is %d.\n", scores[i]);
        }

        // End of round
        printf("End of round %d.\n\n", round);
        round++;
    }

    // Display final scores
    printf("Final Scores:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d: %d points\n", i+1, scores[i]);
    }
    printf("Thanks for playing! Come back again soon!\n");

    return 0;
}