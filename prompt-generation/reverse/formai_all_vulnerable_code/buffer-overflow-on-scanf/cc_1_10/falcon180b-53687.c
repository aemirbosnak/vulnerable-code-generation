//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int player_health = 100;
    int enemy_health = 50;
    int player_attack = rand() % 10 + 1;
    int enemy_attack = rand() % 10 + 1;

    printf("Welcome to the Space Adventure!\n");
    printf("You are a brave space warrior with %d health points.\n", player_health);
    printf("Your enemy is a fierce alien with %d health points.\n", enemy_health);
    printf("You attack with a strength of %d.\n", player_attack);
    printf("The alien attacks with a strength of %d.\n", enemy_attack);

    while (player_health > 0 && enemy_health > 0) {
        int player_choice;
        printf("What will you do?\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        printf("3. Heal\n");
        scanf("%d", &player_choice);

        switch (player_choice) {
            case 1:
                enemy_health -= player_attack;
                if (enemy_health <= 0) {
                    printf("You have defeated the alien!\n");
                    break;
                } else {
                    printf("The alien has %d health points left.\n", enemy_health);
                }
                break;
            case 2:
                player_health -= enemy_attack;
                if (player_health <= 0) {
                    printf("You have been defeated by the alien.\n");
                    break;
                } else {
                    printf("You have %d health points left.\n", player_health);
                }
                break;
            case 3:
                printf("You heal yourself and now have %d health points.\n", player_health);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}