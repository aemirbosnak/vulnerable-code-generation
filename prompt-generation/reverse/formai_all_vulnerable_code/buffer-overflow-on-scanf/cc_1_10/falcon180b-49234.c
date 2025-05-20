//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

int main() {
    char choice;
    int health = 100;
    int gold = 50;
    int level = 1;
    int xp = 0;
    int enemy_health = 50;
    int enemy_attack = 10;
    int player_attack = 5;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a level %d adventurer with %d health points and %d gold coins.\n", level, health, gold);

    while(1) {
        printf("\nWhat would you like to do?\nA)ttack enemy\nB)uy item\nC)heck status\nQ)uit\n");
        scanf("%c", &choice);

        switch(choice) {
            case 'A':
                printf("You attack the enemy!\n");
                if(enemy_health <= 0) {
                    printf("You have defeated the enemy! You gain %d experience points.\n", enemy_attack);
                    xp += enemy_attack;
                } else {
                    printf("The enemy attacks back! You lose %d health points.\n", enemy_attack);
                    health -= enemy_attack;
                }
                break;
            case 'B':
                printf("You buy an item for %d gold coins.\n", gold);
                gold -= 10;
                break;
            case 'C':
                printf("Your current status:\n");
                printf("Health: %d\n", health);
                printf("Gold: %d\n", gold);
                printf("Level: %d\n", level);
                printf("Experience: %d\n", xp);
                break;
            case 'Q':
                printf("Thank you for playing!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}