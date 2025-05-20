//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int player_health = 100, enemy_health = 50, player_attack = 10, enemy_attack = 5;
    char player_action, enemy_action;

    printf("Welcome to the Space Adventure!\n");
    printf("You are a space warrior with %d health points.\n", player_health);
    printf("Your enemy is an alien with %d health points.\n", enemy_health);

    while(player_health > 0 && enemy_health > 0) {
        printf("\nRound %d:\n", rand() % 10 + 1);
        printf("Your health: %d\n", player_health);
        printf("Enemy health: %d\n", enemy_health);

        printf("Choose your action (a/d): ");
        scanf(" %c", &player_action);

        if(player_action == 'a') {
            printf("You attacked the enemy with %d damage!\n", player_attack);
            enemy_health -= player_attack;
        } else if(player_action == 'd') {
            printf("You defended yourself with %d shield!\n", player_attack);
            player_health += player_attack;
        }

        printf("Enemy's turn...\n");
        enemy_action = rand() % 2? 'a' : 'd';

        if(enemy_action == 'a') {
            printf("The enemy attacked you with %d damage!\n", enemy_attack);
            player_health -= enemy_attack;
        } else if(enemy_action == 'd') {
            printf("The enemy defended itself with %d shield!\n", enemy_attack);
            enemy_health += enemy_attack;
        }

        printf("\n");
    }

    if(player_health <= 0) {
        printf("You have been defeated by the enemy.\n");
    } else {
        printf("You have defeated the enemy!\n");
    }

    return 0;
}