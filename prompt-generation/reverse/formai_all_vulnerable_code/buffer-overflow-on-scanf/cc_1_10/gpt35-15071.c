//FormAI DATASET v1.0 Category: Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int enemy_health = 100;
int player_health = 100;
int player_attack = 10;
int enemy_attack = 15;

int getRandomNumber(int min, int max) {
    return (rand() % (max - min + 1) + min);
}

void attackEnemy() {
    int damage_dealt = getRandomNumber(player_attack - 5, player_attack + 5);
    printf("You attack the enemy and deal %d damage.\n", damage_dealt);
    enemy_health -= damage_dealt;
    if (enemy_health <= 0) {
        printf("You have defeated the enemy!\n");
        exit(0);
    }
}

void attackPlayer() {
    int damage_dealt = getRandomNumber(enemy_attack - 5, enemy_attack + 5);
    printf("The enemy attacks you and deals %d damage.\n", damage_dealt);
    player_health -= damage_dealt;
    if (player_health <= 0) {
        printf("You have been defeated by the enemy...\n");
        exit(0);
    }
}

void printStats() {
    printf("\n---STATS---\n");
    printf("Player health: %d\n", player_health);
    printf("Enemy health: %d\n", enemy_health);
    printf("------------\n");
}

void startGame() {
    printf("Welcome to the battle arena!\n");
    while (1) {
        printStats();
        printf("What would you like to do?\n");
        printf("1. Attack\n");
        printf("2. Run away\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                attackEnemy();
                attackPlayer();
                break;
            case 2:
                printf("You run away from the battle...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
}

int main() {
    printf("Press any key to start the game...\n");
    getchar();
    startGame();
    return 0;
}