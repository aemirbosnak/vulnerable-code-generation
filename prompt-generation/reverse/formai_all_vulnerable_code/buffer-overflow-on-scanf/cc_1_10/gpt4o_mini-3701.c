//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_HEALTH 100
#define ENEMY_HEALTH 100
 
typedef struct {
    char name[20];
    int health;
    int damage;
} Player;

typedef struct {
    int health;
    int damage;
} Enemy;

void initializePlayers(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].health = MAX_HEALTH;
        players[i].damage = rand() % 20 + 10; // Random damage between 10 and 30
    }
}

void displayStatus(Player players[], int numPlayers, Enemy enemy) {
    printf("\n--- Status ---\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s - Health: %d\n", players[i].name, players[i].health);
    }
    printf("Enemy - Health: %d\n", enemy.health);
    printf("----------------\n");
}

int takeAction(Player *player, Enemy *enemy) {
    int action;
    printf("\n%s's turn. Choose action:\n", player->name);
    printf("1. Attack\n2. Defend\n3. Retreat\nChoose: ");
    scanf("%d", &action);
    
    switch (action) {
        case 1: // Attack
            printf("%s attacks!\n", player->name);
            enemy->health -= player->damage;
            return 1;  // signifies a successful attack
        case 2: // Defend
            printf("%s defends!\n", player->name);
            // Defense logic can be added here
            return 0;  // signifies no attack
        case 3: // Retreat
            printf("%s retreats!\n", player->name);
            player->health = 0;  // Player is out of the game
            return -1;  // signifies retreat
        default:
            printf("Invalid action!\n");
            return 0;
    }
}

void enemyAttack(Player *player, Enemy enemy) {
    if (player->health > 0) {
        int damage = enemy.damage;
        player->health -= damage;
        printf("Enemy attacks %s for %d damage!\n", player->name, damage);
    }
}

int main() {
    srand(time(NULL));

    int numPlayers;
    Player players[MAX_PLAYERS];
    Enemy enemy = {ENEMY_HEALTH, rand() % 10 + 5}; // Random enemy damage between 5 and 15

    printf("Welcome to Space Adventure!\n");
    printf("Enter the number of players (1-%d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);
    initializePlayers(players, numPlayers);

    while (enemy.health > 0) {
        displayStatus(players, numPlayers, enemy);
        
        for (int i = 0; i < numPlayers; i++) {
            if (players[i].health <= 0) {
                printf("%s is out of the game!\n", players[i].name);
                continue;
            }

            int actionResult = takeAction(&players[i], &enemy);
            if (actionResult == 1 && enemy.health <= 0) {
                printf("The enemy is defeated!\n");
                return 0;
            } else if (actionResult == -1) {
                printf("%s has retreated.\n", players[i].name);
                continue;
            }

            enemyAttack(&players[i], enemy);
            if (players[i].health <= 0) {
                printf("%s has been defeated!\n", players[i].name);
            }
        }
    }

    printf("All players are defeated. Game Over!\n");
    return 0;
}