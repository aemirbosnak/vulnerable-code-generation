//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RSSI 100
#define MIN_RSSI 0
#define NUM_PLAYERS 4

int main() {
    srand(time(NULL));

    int playerRSSI[NUM_PLAYERS];
    int i, j, inputPlayer;

    // Generate random RSSI values for each player
    for (i = 0; i < NUM_PLAYERS; i++) {
        playerRSSI[i] = (rand() % (MAX_RSSI - MIN_RSSI + 1)) + MIN_RSSI;
    }

    // Print out the RSSI values for each player
    printf("Wi-Fi Signal Strength Analyzer\n\n");
    for (i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d RSSI: %d\n", i+1, playerRSSI[i]);
    }

    // Let each player guess the strongest signal
    printf("\nGuess the player with the strongest Wi-Fi signal (1-%d): ", NUM_PLAYERS);
    scanf("%d", &inputPlayer);
    
    while (inputPlayer < 1 || inputPlayer > NUM_PLAYERS) {
        printf("Invalid input. Guess the player with the strongest Wi-Fi signal (1-%d): ", NUM_PLAYERS);
        scanf("%d", &inputPlayer);
    }

    int strongestPlayer = 0;
    for (i = 1; i < NUM_PLAYERS; i++) {
        if (playerRSSI[i] > playerRSSI[strongestPlayer]) {
            strongestPlayer = i;
        }
    }

    // Determine if the player guessed correctly
    if (inputPlayer == strongestPlayer + 1) {
        printf("\nYou guessed correctly! Player %d has the strongest Wi-Fi signal!\n", inputPlayer);
    } else {
        printf("\nYou guessed wrong. Player %d has the strongest Wi-Fi signal.\n", strongestPlayer+1);
    }

    return 0;
}