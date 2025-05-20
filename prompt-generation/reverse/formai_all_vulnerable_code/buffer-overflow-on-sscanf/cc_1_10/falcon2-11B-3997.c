//Falcon2-11B DATASET v1.0 Category: Data recovery tool ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLAYERS 4
#define MAX_SCORE 100

int main() {
    int scores[NUM_PLAYERS];
    int player, choice, score;
    char name[10];
    char input[50];

    // Initialize scores
    for (player = 0; player < NUM_PLAYERS; player++) {
        scores[player] = 0;
    }

    // Loop until all players have finished
    while (1) {
        // Display menu
        printf("\nMenu:\n");
        printf("1. New game\n");
        printf("2. Show scores\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        // Get input
        fgets(input, 50, stdin);
        sscanf(input, "%d", &choice);

        // Process input
        switch (choice) {
            case 1:
                // New game
                for (player = 0; player < NUM_PLAYERS; player++) {
                    printf("Enter your name: ");
                    fgets(name, 10, stdin);
                    scores[player] = 0;
                }
                break;

            case 2:
                // Show scores
                printf("\nScores:\n");
                for (player = 0; player < NUM_PLAYERS; player++) {
                    printf("%s: %d\n", name, scores[player]);
                }
                break;

            case 3:
                // Exit
                exit(0);
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}