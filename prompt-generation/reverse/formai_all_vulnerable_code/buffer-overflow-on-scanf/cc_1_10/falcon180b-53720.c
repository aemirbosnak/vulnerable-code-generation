//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intro() {
    printf("Welcome to your Ephemeral Space Adventure!\n");
    printf("You are a seasoned space explorer, on a mission to discover new worlds.\n");
    printf("Your ship is equipped with the latest technology and weapons.\n");
    printf("But be warned, space is full of surprises and dangers.\n");
    printf("Are you ready to embark on this journey?\n");
}

void game() {
    int choice;
    int enemy_health = 100;
    int player_health = 100;
    int enemy_attack = rand() % 10 + 1;
    int player_attack = rand() % 10 + 1;

    printf("\nYou encounter an enemy ship!\n");
    printf("Enemy health: %d\n", enemy_health);
    printf("Enemy attack: %d\n", enemy_attack);

    while (player_health > 0 && enemy_health > 0) {
        printf("What do you want to do?\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        scanf("%d", &choice);

        if (choice == 1) {
            enemy_health -= player_attack;
            printf("You attacked the enemy ship and dealt %d damage!\n", player_attack);
            printf("Enemy health: %d\n", enemy_health);
        } else if (choice == 2) {
            player_health -= enemy_attack;
            printf("You defended against the enemy attack and took %d damage!\n", enemy_attack);
            printf("Your health: %d\n", player_health);
        } else {
            printf("Invalid choice.\n");
        }

        if (player_health <= 0) {
            printf("\nYou have been defeated by the enemy ship.\n");
            exit(0);
        } else if (enemy_health <= 0) {
            printf("\nYou have successfully defeated the enemy ship!\n");
            break;
        }
    }
}

int main() {
    srand(time(0));
    intro();
    game();
    return 0;
}