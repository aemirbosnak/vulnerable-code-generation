//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HEALTH 100
#define MAX_STATS 20

typedef struct {
    char name[50];
    int health;
    int attack;
    int defense;
} Player;

void initializePlayer(Player *player, const char *name) {
    strcpy(player->name, name);
    player->health = MAX_HEALTH;
    player->attack = rand() % MAX_STATS + 1; // Random attack value between 1 and MAX_STATS
    player->defense = rand() % MAX_STATS + 1; // Random defense value between 1 and MAX_STATS
}

void displayStats(Player *player) {
    printf("%s - Health: %d, Attack: %d, Defense: %d\n", player->name, player->health, player->attack, player->defense);
}

int calculateDamage(Player *attacker, Player *defender) {
    int damage = attacker->attack - defender->defense;
    return (damage > 0) ? damage : 0; // Damage cannot be negative
}

void performAttack(Player *attacker, Player *defender) {
    int damage = calculateDamage(attacker, defender);
    printf("%s attacks %s and deals %d damage!\n", attacker->name, defender->name, damage);
    defender->health -= damage;
    
    // Health should not be negative
    if (defender->health < 0) {
        defender->health = 0;
    }
}

void battle(Player *player1, Player *player2) {
    while (player1->health > 0 && player2->health > 0) {
        performAttack(player1, player2);
        if (player2->health <= 0) break;

        performAttack(player2, player1);
    }
}

void displayBattleResults(Player *player1, Player *player2) {
    printf("\nBattle Results:\n");
    displayStats(player1);
    displayStats(player2);
    
    if (player1->health > 0) {
        printf("%s wins!\n", player1->name);
    } else {
        printf("%s wins!\n", player2->name);
    }
}

void displayStatistics(Player *player1, Player *player2) {
    printf("\nStatistics:\n");
    printf("%s dealt a total of %d damage.\n", player1->name, MAX_HEALTH - player2->health);
    printf("%s dealt a total of %d damage.\n", player2->name, MAX_HEALTH - player1->health);
}

int main() {
    srand(time(NULL));
    
    Player player1, player2;
    
    printf("Enter Player 1's name: ");
    scanf("%s", player1.name);
    initializePlayer(&player1, player1.name);
    
    printf("Enter Player 2's name: ");
    scanf("%s", player2.name);
    initializePlayer(&player2, player2.name);

    printf("\nThe battle begins!\n");
    displayStats(&player1);
    displayStats(&player2);
    
    battle(&player1, &player2);
    
    displayBattleResults(&player1, &player2);
    displayStatistics(&player1, &player2);
    
    return 0;
}