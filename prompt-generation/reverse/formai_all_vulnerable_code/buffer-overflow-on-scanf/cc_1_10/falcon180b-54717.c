//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int player_health = 100;
    int enemy_health = 100;
    int player_attack = 10;
    int enemy_attack = 10;
    int player_defense = 5;
    int enemy_defense = 5;
    int round = 1;

    srand(time(NULL));

    printf("Welcome to the Space Adventure!\n\n");
    printf("You are a space explorer on a mission to defeat the evil alien.\n");
    printf("You have %d health points, %d attack points, and %d defense points.\n", player_health, player_attack, player_defense);
    printf("The alien has %d health points, %d attack points, and %d defense points.\n", enemy_health, enemy_attack, enemy_defense);

    while (player_health > 0 && enemy_health > 0) {
        printf("\nRound %d\n", round);

        printf("Choose your action:\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        printf("3. Heal\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                player_attack -= enemy_defense;
                enemy_health -= player_attack;
                printf("You attacked the alien and dealt %d damage!\n", player_attack - enemy_defense);
                break;
            case 2:
                player_defense -= enemy_attack;
                enemy_health -= player_defense;
                printf("You defended against the alien and dealt %d damage!\n", player_defense - enemy_attack);
                break;
            case 3:
                player_health += 20;
                printf("You healed yourself and gained 20 health points!\n");
                break;
            case 4:
                printf("You decided to quit the battle.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

        if (player_health <= 0) {
            printf("You have lost the battle. The alien has defeated you.\n");
            break;
        } else if (enemy_health <= 0) {
            printf("You have won the battle. Congratulations!\n");
            break;
        }

        round++;
    }

    return 0;
}