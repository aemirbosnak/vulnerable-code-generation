//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 100
#define MAX_USERNAME_LENGTH 30

typedef struct Player {
    int id;
    char username[MAX_USERNAME_LENGTH];
} Player;

typedef struct PlayerDatabase {
    Player players[MAX_PLAYERS];
    int count;
} PlayerDatabase;

void initDatabase(PlayerDatabase* db) {
    db->count = 0;
}

int addPlayer(PlayerDatabase* db, const char* username) {
    if (db->count >= MAX_PLAYERS) {
        printf("Maximum player limit reached.\n");
        return -1;
    }
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->players[i].username, username) == 0) {
            printf("Username already exists. Please choose a different one.\n");
            return -1;
        }
    }
    db->players[db->count].id = db->count + 1;
    strncpy(db->players[db->count].username, username, MAX_USERNAME_LENGTH);
    db->count++;
    printf("Player '%s' added with ID: %d\n", username, db->players[db->count - 1].id);
    return db->count - 1;
}

int removePlayer(PlayerDatabase* db, const char* username) {
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->players[i].username, username) == 0) {
            printf("Removing player '%s' (ID: %d)\n", username, db->players[i].id);
            for (int j = i; j < db->count - 1; j++) {
                db->players[j] = db->players[j + 1];
            }
            db->count--;
            return 0;
        }
    }
    printf("Player '%s' not found.\n", username);
    return -1;
}

Player* findPlayer(PlayerDatabase* db, const char* username) {
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->players[i].username, username) == 0) {
            return &db->players[i];
        }
    }
    return NULL;
}

void displayPlayers(PlayerDatabase* db) {
    if (db->count == 0) {
        printf("No players in the database.\n");
        return;
    }
    printf("Current players:\n");
    for (int i = 0; i < db->count; i++) {
        printf("ID: %d, Username: %s\n", db->players[i].id, db->players[i].username);
    }
}

void menu() {
    printf("\nMultiplayer Database Management\n");
    printf("1. Add Player\n");
    printf("2. Remove Player\n");
    printf("3. Find Player\n");
    printf("4. Display Players\n");
    printf("5. Exit\n");
}

int main() {
    PlayerDatabase db;
    initDatabase(&db);

    int choice;
    char username[MAX_USERNAME_LENGTH];

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter username to add: ");
                scanf("%s", username);
                addPlayer(&db, username);
                break;
            case 2:
                printf("Enter username to remove: ");
                scanf("%s", username);
                removePlayer(&db, username);
                break;
            case 3:
                printf("Enter username to find: ");
                scanf("%s", username);
                Player* player = findPlayer(&db, username);
                if (player != NULL) {
                    printf("Player found: ID: %d, Username: %s\n", player->id, player->username);
                } else {
                    printf("Player '%s' not found.\n", username);
                }
                break;
            case 4:
                displayPlayers(&db);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}