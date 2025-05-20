//FormAI DATASET v1.0 Category: Data structures visualization ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_HP 100

typedef struct player {
    char name[50];
    int hp;
    int mana;
} Player;

void print_players(Player players[MAX_PLAYERS], int num_players) {
    printf("=======================\n");
    for(int i=0; i<num_players; i++) {
        printf("Name: %s\n", players[i].name);
        printf("HP: %d\n", players[i].hp);
        printf("Mana: %d\n", players[i].mana);
        printf("-----------------------\n");
    }
    printf("=======================\n");
}

int main() {
    int num_players;
    printf("Enter the number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    Player players[MAX_PLAYERS];
    memset(players, 0, sizeof(players));

    // Initialize players
    for(int i=0; i<num_players; i++) {
        printf("Enter the name of player %d: ", i+1);
        scanf("%s", players[i].name);
        players[i].hp = MAX_HP;
        players[i].mana = 0;
    }

    // Start game loop
    int game_over = 0;
    while(!game_over) {
        print_players(players, num_players);

        // Get player input
        int current_player;
        printf("\nEnter the number of the player who wants to attack: ");
        scanf("%d", &current_player);

        int target_player;
        printf("Enter the number of the player who will be attacked: ");
        scanf("%d", &target_player);

        // Check inputs
        if(current_player < 1 || current_player > num_players ||
           target_player < 1 || target_player > num_players ||
           current_player == target_player) {
            printf("Invalid input!\n");
            continue;
        }

        // Decrease target player's HP
        players[target_player-1].hp -= 10;

        // Check if game over
        int alive_players = 0;
        int last_alive_player;
        for(int i=0; i<num_players; i++) {
            if(players[i].hp > 0) {
                alive_players++;
                last_alive_player = i;
            }
        }
        if(alive_players == 1) {
            printf("Game over! %s has won!\n", players[last_alive_player].name);
            game_over = 1;
        }
    }

    return 0;
}