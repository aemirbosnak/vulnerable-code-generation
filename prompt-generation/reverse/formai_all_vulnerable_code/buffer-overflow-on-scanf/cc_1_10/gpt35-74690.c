//FormAI DATASET v1.0 Category: Database querying ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct player {
    int id;
    char* name;
    int score;
} Player;

typedef struct database {
    int num_players;
    Player* players;
} Database;

void query_database(Database* db) {
    int input;
    printf("What do you want to query?\n");
    printf("1. Get all player data\n");
    printf("2. Get player data by ID\n");
    printf("3. Get player data by name\n");
    scanf("%d", &input);

    switch(input) {
        case 1:
            // Print all player data
            printf("Player ID\tName\tScore\n");
            for(int i = 0; i < db->num_players; i++) {
                printf("%d\t%s\t%d\n", db->players[i].id, db->players[i].name, db->players[i].score);
            }
            break;
        case 2:
            // Get player data by ID
            printf("Enter player ID: ");
            int id;
            scanf("%d", &id);
            for(int i = 0; i < db->num_players; i++) {
                if(db->players[i].id == id) {
                    printf("Player ID\tName\tScore\n");
                    printf("%d\t%s\t%d\n", db->players[i].id, db->players[i].name, db->players[i].score);
                    return;
                }
            }
            printf("Error: Player with ID %d not found\n", id);
            break;
        case 3:
            // Get player data by name
            printf("Enter player name: ");
            char name[50];
            scanf("%s", name);
            for(int i = 0; i < db->num_players; i++) {
                if(strcmp(db->players[i].name, name) == 0) {
                    printf("Player ID\tName\tScore\n");
                    printf("%d\t%s\t%d\n", db->players[i].id, db->players[i].name, db->players[i].score);
                    return;
                }
            }
            printf("Error: Player with name %s not found\n", name);
            break;
        default:
            printf("Invalid input\n");
            break;
    }
}

int main() {
    Database db;
    db.num_players = 3;

    // Allocate memory for players
    db.players = (Player*)malloc(sizeof(Player) * db.num_players);

    // Initialize player data
    db.players[0].id = 1;
    db.players[0].name = "Alice";
    db.players[0].score = 100;

    db.players[1].id = 2;
    db.players[1].name = "Bob";
    db.players[1].score = 75;

    db.players[2].id = 3;
    db.players[2].name = "Charlie";
    db.players[2].score = 50;

    while(1) {
        query_database(&db);
    }

    // Free allocated memory
    free(db.players);

    return 0;
}