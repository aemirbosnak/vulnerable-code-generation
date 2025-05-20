//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of players
#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 50
#define FILENAME "players.dat"

// Structure to hold player information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

// Function prototypes
void addPlayer();
void displayPlayers();
void savePlayers();
void loadPlayers();
void clearScreen();

Player players[MAX_PLAYERS];
int playerCount = 0;

int main() {
    int choice;

    loadPlayers();

    do {
        clearScreen();
        printf("Multiplayer Score Tracker\n");
        printf("==========================\n");
        printf("1. Add Player\n");
        printf("2. Display Players\n");
        printf("3. Save and Exit\n");
        printf("4. Load Players\n");
        printf("5. Clear Screen\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch(choice) {
            case 1:
                addPlayer();
                break;
            case 2:
                displayPlayers();
                break;
            case 3:
                savePlayers();
                printf("Players saved. Exiting...\n");
                break;
            case 4:
                loadPlayers();
                printf("Players loaded.\n");
                break;
            case 5:
                clearScreen();
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }

        printf("Press Enter to continue...");
        getchar(); // Wait for user to press Enter
    } while(choice != 3);

    return 0;
}

void clearScreen() {
    // Clear screen with ANSI escape code
    printf("\033[H\033[J");
}

void addPlayer() {
    if (playerCount >= MAX_PLAYERS) {
        printf("Maximum players reached! Cannot add more.\n");
        return;
    }

    Player newPlayer;
    printf("Enter player name: ");
    fgets(newPlayer.name, MAX_NAME_LENGTH, stdin);
    newPlayer.name[strcspn(newPlayer.name, "\n")] = 0; // Remove newline character
    newPlayer.score = 0; // Initialize score

    players[playerCount++] = newPlayer;
    printf("Player '%s' added with initial score of %d!\n", newPlayer.name, newPlayer.score);
}

void displayPlayers() {
    if (playerCount == 0) {
        printf("No players to display.\n");
        return;
    }

    printf("Current Players and Scores:\n");
    printf("============================\n");
    for (int i = 0; i < playerCount; i++) {
        printf("%d. %s - Score: %d\n", i + 1, players[i].name, players[i].score);
    }
}

void savePlayers() {
    FILE *file = fopen(FILENAME, "wb");
    if (file == NULL) {
        printf("Error saving players to file.\n");
        return;
    }

    fwrite(players, sizeof(Player), playerCount, file);
    fclose(file);
}

void loadPlayers() {
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) {
        printf("No previous data found. Starting fresh.\n");
        return;
    }

    playerCount = fread(players, sizeof(Player), MAX_PLAYERS, file);
    fclose(file);
}