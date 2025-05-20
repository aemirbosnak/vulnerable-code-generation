//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4

int main(void) {
    int signals[MAX_PLAYERS]; // Store the Wi-Fi signal strengths of each player
    int playerCount = 0;
    int quit = 0;
    srand(time(NULL)); // Initialize random number generator

    while (!quit) {
        if (playerCount == 0) { // No players yet, ask user if they want to start a game or quit
            printf("No players have joined the game yet. Press 1 to start a new game, or 0 to quit: ");
            int choice;
            scanf("%d", &choice);
            if (choice == 0) {
                quit = 1; // User wants to quit
            } else if (choice == 1) {
                printf("New game started! Waiting for players to join...\n");
            } else {
                printf("Invalid choice! Please try again.\n");
            }
        } else { // At least one player has joined, so we can start playing
            printf("%d players have joined the game. Press 0 to quit at any time.\n", playerCount);
            printf("Current Wi-Fi signals:\n");
            for (int i = 0; i < playerCount; i++) {
                printf("Player %d: %d\n", i + 1, signals[i]);
            }

            // Simulate Wi-Fi signal strength changes
            for (int i = 0; i < playerCount; i++) {
                signals[i] = signals[i] + rand() % 5 - 2; // Add a random value between -2 and 2
            }

            // Check for players with low signals
            int lowSignals[MAX_PLAYERS];
            int lowCount = 0;
            for (int i = 0; i < playerCount; i++) {
                if (signals[i] < 50) { // Player has a low signal strength
                    lowSignals[lowCount] = i + 1; // Store the player number (1-indexed)
                    lowCount++;
                }
            }
            if (lowCount > 0) { // At least one player has a low signal
                printf("Warning! The following player(s) have a low signal strength:\n");
                for (int i = 0; i < lowCount; i++) {
                    printf("Player %d\n", lowSignals[i]);
                }
            }

            // Wait for player input
            printf("Enter 1 to add a new player, 2 to remove a player, or 0 to continue: ");
            int choice;
            scanf("%d", &choice);
            if (choice == 0) {
                printf("Continuing...\n");
            } else if (choice == 1) {
                if (playerCount == MAX_PLAYERS) { // Maximum number of players reached
                    printf("Sorry, the maximum number of players has been reached.\n");
                } else {
                    playerCount++;
                    signals[playerCount - 1] = rand() % 100; // Generate a random signal strength for the new player
                    printf("New player added! Wi-Fi signal strength: %d\n", signals[playerCount - 1]);
                }
            } else if (choice == 2) {
                printf("Enter the number of the player to remove (1-%d): ", playerCount);
                int removeNum;
                scanf("%d", &removeNum);
                if (removeNum < 1 || removeNum > playerCount) { // Invalid player number
                    printf("Invalid player number! Please try again.\n");
                } else {
                    for (int i = removeNum - 1; i < playerCount - 1; i++) {
                        signals[i] = signals[i + 1]; // Move values to the left to remove the chosen player
                    }
                    playerCount--;
                    signals[playerCount] = 0; // Set the signal strength of the removed player to 0
                    printf("Player %d removed.\n", removeNum);
                }
            } else {
                printf("Invalid choice! Please try again.\n");
            }
        }
    }

    printf("Goodbye!\n");

    return 0;
}