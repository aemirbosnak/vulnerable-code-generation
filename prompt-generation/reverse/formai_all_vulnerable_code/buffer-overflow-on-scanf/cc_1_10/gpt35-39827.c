//FormAI DATASET v1.0 Category: Table Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Returns the index of the maximum value in an array
int max_index(int arr[], int size) {
    int idx = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[idx]) {
            idx = i;
        }
    }
    return idx;
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int size = 6;
    int players[size];
    for (int i = 0; i < size; i++) {
        players[i] = rand() % 100; // Initialize each player with a random score
    }
    printf("Initial Scores:\n");
    for (int i = 0; i < size; i++) {
        printf("Player %d: %d\n", i+1, players[i]);
    }
    int round = 1;
    while (1) {
        // Determine the player with the highest score
        int max_idx = max_index(players, size);
        printf("\nRound %d: Player %d has the highest score with %d points.\n", round, max_idx+1, players[max_idx]);
        // Ask the player with the highest score to choose the next game
        printf("Player %d, please choose the next game (1-3): ", max_idx+1);
        int game = 0;
        scanf("%d", &game);
        while (game < 1 || game > 3) {
            printf("Invalid input. Please choose a game between 1 and 3: ");
            scanf("%d", &game);
        }
        printf("Player %d has chosen Game %d!\n", max_idx+1, game);
        // Update scores based on game outcome
        int outcomes[size];
        for (int i = 0; i < size; i++) {
            outcomes[i] = rand() % 20;
            players[i] += outcomes[i];
        }
        printf("Game %d outcomes:\n", game);
        for (int i = 0; i < size; i++) {
            printf("Player %d: %d", i+1, outcomes[i]);
            if (i == max_idx) {
                printf(" (+%d)", outcomes[i]);
            }
            printf("\n");
        }
        round++;
    }
    return 0;
}