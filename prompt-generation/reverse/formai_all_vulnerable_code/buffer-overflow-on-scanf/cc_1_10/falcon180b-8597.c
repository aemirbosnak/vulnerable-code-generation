//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int player_health = 100;
    int enemy_health = 50;
    int player_attack = rand() % 10 + 1;
    int enemy_attack = rand() % 10 + 1;

    printf("Welcome to the Mathematical Adventure!\n");
    printf("You have %d health points.\n", player_health);
    printf("The enemy has %d health points.\n", enemy_health);
    printf("Your attack power is %d.\n", player_attack);
    printf("The enemy's attack power is %d.\n", enemy_attack);

    int choice;
    printf("What would you like to do?\n");
    printf("1. Attack\n");
    printf("2. Defend\n");
    printf("3. Heal\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("You attack the enemy with %d damage!\n", player_attack);
            enemy_health -= player_attack;
            if(enemy_health <= 0) {
                printf("You have defeated the enemy!\n");
            }
            break;
        case 2:
            printf("You defend against the enemy's attack.\n");
            if(enemy_attack > player_health) {
                printf("You have been defeated by the enemy.\n");
                return 0;
            }
            player_health -= enemy_attack;
            break;
        case 3:
            printf("You heal yourself with %d health points!\n", player_attack);
            player_health += player_attack;
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    if(player_health <= 0) {
        printf("You have been defeated by the enemy.\n");
        return 0;
    }

    if(enemy_health <= 0) {
        printf("You have defeated the enemy!\n");
    }

    return 0;
}