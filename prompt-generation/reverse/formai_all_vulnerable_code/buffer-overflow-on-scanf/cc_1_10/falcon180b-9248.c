//Falcon-180B DATASET v1.0 Category: Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int player_health = 100;
    int enemy_health = 100;
    int player_attack = rand() % 10 + 1;
    int enemy_attack = rand() % 10 + 1;

    printf("Welcome to the game!\n");
    printf("You have %d health points.\n", player_health);
    printf("The enemy has %d health points.\n", enemy_health);
    printf("Your attack power is %d.\n", player_attack);
    printf("The enemy's attack power is %d.\n", enemy_attack);

    while (player_health > 0 && enemy_health > 0) {
        int player_choice;
        printf("\nWhat would you like to do?\n");
        printf("1. Attack\n2. Defend\n3. Heal\n");
        scanf("%d", &player_choice);

        switch (player_choice) {
            case 1:
                enemy_health -= player_attack;
                if (enemy_health <= 0) {
                    printf("You win! The enemy has been defeated.\n");
                    break;
                }
                printf("You attacked the enemy and dealt %d damage.\n", player_attack);
                break;
            case 2:
                player_health += 10;
                printf("You defended and regained 10 health points.\n");
                break;
            case 3:
                player_health += 20;
                printf("You healed and regained 20 health points.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

        if (player_health <= 0) {
            printf("You lost! The enemy has defeated you.\n");
            break;
        }

        enemy_attack = rand() % 10 + 1;
        printf("The enemy attacked and dealt %d damage.\n", enemy_attack);
        player_health -= enemy_attack;
    }

    return 0;
}