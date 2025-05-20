//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Initialize random seed

    int player_health = 100;
    int monster_health = 100;
    int player_damage;
    int monster_damage;

    printf("You have stumbled upon a fearsome monster! Prepare to battle!\n\n");

    while (player_health > 0 && monster_health > 0) {
        printf("Your health: %d\n", player_health);
        printf("Monster health: %d\n\n", monster_health);

        printf("Choose your attack:\n");
        printf("1. Sword (10-15 damage)\n");
        printf("2. Bow (5-20 damage)\n");
        printf("3. Magic (15-25 damage)\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                player_damage = rand() % 6 + 10;
                printf("You attack the monster with your sword for %d damage!\n", player_damage);
                break;
            case 2:
                player_damage = rand() % 16 + 5;
                printf("You shoot the monster with your bow for %d damage!\n", player_damage);
                break;
            case 3:
                player_damage = rand() % 11 + 15;
                printf("You cast a spell and deal %d damage to the monster!\n", player_damage);
                break;
            default:
                printf("Invalid choice, try again.\n");
                continue;
        }

        monster_health -= player_damage;
        if (monster_health <= 0) {
            printf("You have defeated the monster!\n");
            break;
        }

        monster_damage = rand() % 10 + 5;
        printf("The monster attacks you for %d damage!\n", monster_damage);
        player_health -= monster_damage;
        if (player_health <= 0) {
            printf("You have been defeated by the monster!\n");
            break;
        }
    }

    return 0;
}