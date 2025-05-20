//FormAI DATASET v1.0 Category: Password management ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 5
#define PASSWORD_LENGTH 10

typedef struct player {
    char name[20];
    char password[PASSWORD_LENGTH];
} player_t;

player_t players[MAX_PLAYERS];
int num_players = 0;

void add_player() {
    if(num_players > MAX_PLAYERS) {
        printf("Max number of players reached\n");
        return;
    }
    printf("Enter player name:\n");
    scanf("%s", players[num_players].name);
    printf("Set player password (max %d characters):\n", PASSWORD_LENGTH-1);
    scanf("%s", players[num_players].password);
    printf("Player %s added successfully!\n", players[num_players].name);
    num_players++;
}

int authenticate_player(char *name, char *password) {
    int i;
    for(i = 0; i < num_players; i++) {
        if(strcmp(name, players[i].name) == 0 && strcmp(password, players[i].password) == 0)
            return i;
    }
    return -1;
}

void change_player_password(int id) {
    char new_password[PASSWORD_LENGTH];
    printf("Set new player password (max %d characters):\n", PASSWORD_LENGTH-1);
    scanf("%s", new_password);
    strncpy(players[id].password, new_password, PASSWORD_LENGTH-1);
    players[id].password[PASSWORD_LENGTH-1] = '\0';
    printf("Password changed successfully!\n");
}

int main() {
    int choice, player_id;
    char name[20], password[PASSWORD_LENGTH];

    while(1) {

        printf("Welcome to Password Management Game!\n");
        printf("1 - Add player\n");
        printf("2 - Authenticate player\n");
        printf("3 - Change player password\n");
        printf("4 - Exit\n");
        printf("Your choice:\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_player();
                break;
            case 2:
                printf("Enter player name:\n");
                scanf("%s", name);
                printf("Enter player password:\n");
                scanf("%s", password);
                player_id = authenticate_player(name, password);
                if(player_id >= 0)
                    printf("Authentication successful! Welcome %s\n", players[player_id].name);
                else
                    printf("Authentication failed. Invalid name or password.\n");
                break;
            case 3:
                printf("Enter player name:\n");
                scanf("%s", name);
                printf("Enter player password:\n");
                scanf("%s", password);
                player_id = authenticate_player(name, password);
                if(player_id >= 0)
                    change_player_password(player_id);
                else
                    printf("Authentication failed. Invalid name or password.\n");
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    return 0;
}