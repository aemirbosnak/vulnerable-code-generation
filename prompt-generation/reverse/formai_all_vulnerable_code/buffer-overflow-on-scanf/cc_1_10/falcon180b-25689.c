//Falcon-180B DATASET v1.0 Category: Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int player_score = 0;
    int enemy_score = 0;
    int player_health = 100;
    int enemy_health = 100;
    char player_move;
    char enemy_move;
    int attack_result;
    int defense_result;
    int player_attack;
    int enemy_attack;
    int player_defense;
    int enemy_defense;

    while (player_health > 0 && enemy_health > 0) {
        printf("Player health: %d\n", player_health);
        printf("Enemy health: %d\n", enemy_health);
        printf("Enter your move (a/d): ");
        scanf("%c", &player_move);

        if (player_move == 'a') {
            player_attack = rand() % 6 + 1;
            enemy_defense = rand() % 6 + 1;
            attack_result = player_attack - enemy_defense;
            if (attack_result > 0) {
                enemy_health -= attack_result;
                printf("You dealt %d damage!\n", attack_result);
            } else {
                printf("Your attack was blocked.\n");
            }
        } else if (player_move == 'd') {
            player_defense = rand() % 6 + 1;
            enemy_attack = rand() % 6 + 1;
            defense_result = player_defense - enemy_attack;
            if (defense_result > 0) {
                printf("You blocked the enemy's attack!\n");
            } else {
                enemy_health -= enemy_attack;
                printf("You took %d damage!\n", enemy_attack);
            }
        } else {
            printf("Invalid move.\n");
        }

        if (player_health <= 0) {
            printf("You have been defeated!\n");
            break;
        } else if (enemy_health <= 0) {
            printf("You have emerged victorious!\n");
            break;
        }
    }

    return 0;
}