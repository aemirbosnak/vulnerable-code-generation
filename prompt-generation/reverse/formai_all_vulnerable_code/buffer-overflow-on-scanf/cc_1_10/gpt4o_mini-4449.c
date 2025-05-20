//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 100
#define MAX_NAME_LENGTH 50
#define DATABASE_FILE "game_data.txt"

typedef struct {
    char name[MAX_NAME_LENGTH];
    int level;
} Player;

Player players[MAX_PLAYERS];
int player_count = 0;

void load_database() {
    FILE *file = fopen(DATABASE_FILE, "r");
    if (file == NULL) {
        return; // If no file exists, we can start fresh
    }
    
    while (fscanf(file, "%s %d", players[player_count].name, &players[player_count].level) != EOF) {
        player_count++;
    }
    
    fclose(file);
}

void save_database() {
    FILE *file = fopen(DATABASE_FILE, "w");
    if (file == NULL) {
        printf("Error saving database.\n");
        return;
    }

    for (int i = 0; i < player_count; i++) {
        fprintf(file, "%s %d\n", players[i].name, players[i].level);
    }

    fclose(file);
}

void create_player() {
    if (player_count >= MAX_PLAYERS) {
        printf("Maximum player limit reached!\n");
        return;
    }
    
    Player new_player;
    printf("Enter player name: ");
    scanf("%s", new_player.name);
    new_player.level = 1; // Players start at level 1
    
    players[player_count++] = new_player;
    printf("Player %s created with level %d.\n", new_player.name, new_player.level);
}

void level_up_player() {
    char name[MAX_NAME_LENGTH];
    printf("Enter player name to level up: ");
    scanf("%s", name);
    
    for (int i = 0; i < player_count; i++) {
        if (strcmp(players[i].name, name) == 0) {
            players[i].level++;
            printf("Player %s leveled up to level %d.\n", players[i].name, players[i].level);
            return;
        }
    }
    
    printf("Player %s not found.\n", name);
}

void display_players() {
    printf("Current players:\n");
    for (int i = 0; i < player_count; i++) {
        printf("Name: %s, Level: %d\n", players[i].name, players[i].level);
    }
}

void menu() {
    int option;
    do {
        printf("\n----- Game Menu -----\n");
        printf("1. Create Player\n");
        printf("2. Level Up Player\n");
        printf("3. Display Players\n");
        printf("4. Save and Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                create_player();
                break;
            case 2:
                level_up_player();
                break;
            case 3:
                display_players();
                break;
            case 4:
                save_database();
                printf("Game data saved. Exiting...\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    } while (option != 4);
}

int main() {
    load_database();
    menu();
    return 0;
}