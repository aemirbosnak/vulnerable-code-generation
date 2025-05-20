//FormAI DATASET v1.0 Category: Database simulation ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// Player struct to hold player data
struct Player {
    char name[20];
    int score;
};

// Create an array of players
struct Player players[4];

// Function to add a player to the database
void addPlayer(int playerIndex) {
    printf("Enter name of player %d: ", playerIndex+1);
    scanf("%s", players[playerIndex].name);
    players[playerIndex].score = 0;
    printf("Player added successfully!\n");
}

// Function to display the leaderboard
void displayLeaderboard() {
    printf("\nLeaderboard:\n");
    for(int i=0; i<4; i++) {
        printf("%d. %s - %d points\n", i+1, players[i].name, players[i].score);
    }
    printf("\n");
}

int main() {
    int choice, playerCount = 0;

    printf("Welcome to the multiplayer database simulation game!\n\n");

    do {
        printf("1. Add player\n");
        printf("2. Display leaderboard\n");
        printf("3. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(playerCount < 4) {
                    addPlayer(playerCount);
                    playerCount++;
                } else {
                    printf("Maximum number of players reached.\n");
                }
                break;
            case 2:
                displayLeaderboard();
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 3);

    return 0;
}