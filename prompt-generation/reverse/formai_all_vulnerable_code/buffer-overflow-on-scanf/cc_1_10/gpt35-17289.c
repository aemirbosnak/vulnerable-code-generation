//FormAI DATASET v1.0 Category: Modern Encryption ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10

typedef struct {
    char* name;
    int health;
    int damage;
} player;

int encrypt(int num) {
    return num * 2;
}

int decrypt(int num) {
    return num / 2;
}

void attack(player* attacker, player* defender) {
    int damage = encrypt(attacker->damage);
    printf("%s attacks %s and deals %d damage!\n", attacker->name, defender->name, decrypt(damage));
    defender->health -= decrypt(damage);
    if (defender->health <= 0) {
        printf("%s has been defeated!\n", defender->name);
    }
}

int main() {
    // Initialize players
    int num_players;
    printf("Enter the number of players (Max %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);
    if (num_players <= 0 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players!\n");
        return 0;
    }
    player* players = malloc(num_players * sizeof(player));
    for (int i = 0; i < num_players; i++) {
        players[i].health = 100;
        players[i].damage = rand() % 10 + 1; // Random damage between 1 and 10
        printf("Enter the name of player %d: ", i+1);
        players[i].name = malloc(20 * sizeof(char));
        scanf("%s", players[i].name);
    }

    // Start game
    int alive_players = num_players;
    int turn = 1;
    while (alive_players > 1) {
        printf("\n--- Turn %d ---\n", turn);
        for (int i = 0; i < num_players; i++) {
            if (players[i].health <= 0) {
                continue; // Skip dead players
            }
            printf("%s's turn\n", players[i].name);
            printf("Choose a player to attack:\n");
            for (int j = 0; j < num_players; j++) {
                if (i == j || players[j].health <= 0) {
                    continue; // Skip self and dead players
                }
                printf("%d. %s (%d health)\n", j+1, players[j].name, players[j].health);
            }
            int target;
            scanf("%d", &target);
            while (target <= 0 || target > num_players || target == i+1 || players[target-1].health <= 0) {
                printf("Invalid target! Choose again:\n");
                scanf("%d", &target);
            }
            attack(&players[i], &players[target-1]);
            if (alive_players == 1) {
                break; // Game over
            }
        }
        turn++;
    }

    // Print winner
    printf("\n--- Game Over ---\n");
    for (int i = 0; i < num_players; i++) {
        if (players[i].health > 0) {
            printf("%s wins!\n", players[i].name);
            break;
        }
    }

    // Clean up memory
    for (int i = 0; i < num_players; i++) {
        free(players[i].name);
    }
    free(players);

    return 0;
}