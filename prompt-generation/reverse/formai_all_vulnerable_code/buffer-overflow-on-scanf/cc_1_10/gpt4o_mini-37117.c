//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 100
#define NAME_LENGTH 30
#define DATABASE_FILE "players.dat"

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int level;
    int experience;
} Player;

void registerPlayer(Player players[], int *playerCount);
void displayPlayers(Player players[], int playerCount);
void updatePlayerLevel(Player players[], int playerCount);
void saveDatabase(Player players[], int playerCount);
void loadDatabase(Player players[], int *playerCount);

int main() {
    Player players[MAX_PLAYERS];
    int playerCount = 0;
    int choice;

    loadDatabase(players, &playerCount);

    do {
        printf("\nMultiplayer Database System:\n");
        printf("1. Register Player\n");
        printf("2. Display Players\n");
        printf("3. Update Player Level\n");
        printf("4. Save and Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                registerPlayer(players, &playerCount);
                break;
            case 2:
                displayPlayers(players, playerCount);
                break;
            case 3:
                updatePlayerLevel(players, playerCount);
                break;
            case 4:
                saveDatabase(players, playerCount);
                printf("Data saved. Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (choice != 4);

    return 0;
}

void registerPlayer(Player players[], int *playerCount) {
    if (*playerCount >= MAX_PLAYERS) {
        printf("Maximum player limit reached.\n");
        return;
    }

    Player newPlayer;
    newPlayer.id = *playerCount;
    
    printf("Enter player name: ");
    scanf("%s", newPlayer.name);
    newPlayer.level = 1;
    newPlayer.experience = 0;

    players[*playerCount] = newPlayer;
    (*playerCount)++;
    printf("Player registered successfully!\n");
}

void displayPlayers(Player players[], int playerCount) {
    if (playerCount == 0) {
        printf("No players registered.\n");
        return;
    }

    printf("\nPlayers in Database:\n");
    for (int i = 0; i < playerCount; i++) {
        printf("ID: %d, Name: %s, Level: %d, Experience: %d\n", 
               players[i].id, players[i].name, 
               players[i].level, players[i].experience);
    }
}

void updatePlayerLevel(Player players[], int playerCount) {
    int id;
    printf("Enter player ID to update level: ");
    scanf("%d", &id);

    if (id >= 0 && id < playerCount) {
        players[id].level++;
        players[id].experience += 50; // award experience
        printf("Player %s has been updated to level %d with %d experience points.\n",
               players[id].name, players[id].level, players[id].experience);
    } else {
        printf("Invalid player ID.\n");
    }
}

void saveDatabase(Player players[], int playerCount) {
    FILE *file = fopen(DATABASE_FILE, "wb");
    if (!file) {
        printf("Error saving data to file.\n");
        return;
    }
    fwrite(players, sizeof(Player), playerCount, file);
    fclose(file);
    printf("Database saved successfully.\n");
}

void loadDatabase(Player players[], int *playerCount) {
    FILE *file = fopen(DATABASE_FILE, "rb");
    if (file) {
        *playerCount = fread(players, sizeof(Player), MAX_PLAYERS, file);
        fclose(file);
        printf("Database loaded successfully. %d players found.\n", *playerCount);
    } else {
        printf("No previous database found, starting fresh.\n");
    }
}