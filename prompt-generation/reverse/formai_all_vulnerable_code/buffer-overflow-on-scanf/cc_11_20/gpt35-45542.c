//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLAYERS 4
#define MAX_STRENGTH 100
#define MIN_STRENGTH 0

int main(void) {
    srand(time(NULL));
    int playerStrengths[NUM_PLAYERS];
    for (int i = 0; i < NUM_PLAYERS; i++) {
        playerStrengths[i] = rand() % (MAX_STRENGTH - MIN_STRENGTH + 1) + MIN_STRENGTH;
    }

    printf("Wi-Fi Signal Strength Analyzer Multiplayer\n");
    printf("==========================================\n");

    while (1) {
        int option;
        printf("\nPlease select an option:\n");
        printf("1. Show Players' Wi-Fi signal strengths\n");
        printf("2. Analyze Player Connection Strength\n");
        printf("3. Quit\n");
        printf("Enter option number: ");
        scanf("%d", &option);

        if (option == 1) {
            printf("\nPlayers' Wi-Fi signal strengths:\n");
            for (int i = 0; i < NUM_PLAYERS; i++) {
                printf("Player %d: %d\n", i+1, playerStrengths[i]);
            }
        } else if (option == 2) {
            printf("\nPlease enter the player numbers to analyze (separated by space): ");
            int player1, player2;
            scanf("%d %d", &player1, &player2);
            if (player1 < 1 || player1 > NUM_PLAYERS || player2 < 1 || player2 > NUM_PLAYERS) {
                printf("Invalid player numbers. Please try again.\n");
                continue;
            }
            int strength1 = playerStrengths[player1-1];
            int strength2 = playerStrengths[player2-1];
            printf("Player %d Wi-Fi signal strength is %d\n", player1, strength1);
            printf("Player %d Wi-Fi signal strength is %d\n", player2, strength2);
            if (strength1 > strength2) {
                printf("Player %d has a stronger Wi-Fi signal strength\n", player1);
            } else if (strength2 > strength1) {
                printf("Player %d has a stronger Wi-Fi signal strength\n", player2);
            } else {
                printf("Both players have the same Wi-Fi signal strength\n");
            }
        } else if (option == 3) {
            printf("\nThank you for using the Wi-Fi Signal Strength Analyzer Multiplayer!\n");
            break;
        } else {
            printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}