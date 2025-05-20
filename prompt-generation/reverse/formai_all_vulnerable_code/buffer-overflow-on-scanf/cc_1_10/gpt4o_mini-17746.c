//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 100
#define NAME_LEN 50
#define FILE_NAME "players.db"

typedef struct {
    char name[NAME_LEN];
    int score;
} Player;

Player players[MAX_PLAYERS];
int player_count = 0;

// Function to load player data from the file
void load_players() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("No previous player data found.\n");
        return;
    }
    
    while (fscanf(file, "%49s %d", players[player_count].name, &players[player_count].score) != EOF) {
        player_count++;
    }
    fclose(file);
}

// Function to save player data to the file
void save_players() {
    FILE *file = fopen(FILE_NAME, "w");
    for (int i = 0; i < player_count; i++) {
        fprintf(file, "%s %d\n", players[i].name, players[i].score);
    }
    fclose(file);
}

// Function to register a new player
void register_player() {
    if (player_count >= MAX_PLAYERS) {
        printf("Player limit reached.\n");
        return;
    }
    
    printf("Enter player name: ");
    scanf("%49s", players[player_count].name);
    players[player_count].score = 0;
    player_count++;
    save_players();
    printf("Player registered successfully!\n");
}

// Function to update a player's score
void update_score() {
    char name[NAME_LEN];
    int score;

    printf("Enter player name to update score: ");
    scanf("%49s", name);
    
    for (int i = 0; i < player_count; i++) {
        if (strcmp(players[i].name, name) == 0) {
            printf("Enter new score for %s: ", players[i].name);
            scanf("%d", &score);
            players[i].score = score;
            save_players();
            printf("Score updated successfully!\n");
            return;
        }
    }

    printf("Player not found.\n");
}

// Function to display all players and their scores
void display_scores() {
    printf("\nPlayer Rankings:\n");
    for (int i = 0; i < player_count; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

int main() {
    int option;

    load_players();

    while (1) {
        printf("\n1. Register Player\n");
        printf("2. Update Score\n");
        printf("3. Display Rankings\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                register_player();
                break;
            case 2:
                update_score();
                break;
            case 3:
                display_scores();
                break;
            case 4:
                printf("Exiting game. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}