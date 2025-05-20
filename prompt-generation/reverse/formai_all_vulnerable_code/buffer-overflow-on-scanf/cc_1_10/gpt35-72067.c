//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed

    int player_hp = 10;
    int player_dmg = 2;
    int enemy_hp = 5 + rand() % 5;
    int enemy_dmg = 1 + rand() % 3;
    int num_potions = 3;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are facing an enemy with %d HP and %d damage.\n", enemy_hp, enemy_dmg);

    while (player_hp > 0 && enemy_hp > 0) {
        printf("Your HP: %d\n", player_hp);
        printf("Enemy HP: %d\n", enemy_hp);
        printf("What do you want to do? (1. Attack, 2. Drink potion): ");
        int choice;
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("You attack the enemy with %d damage.\n", player_dmg);
            enemy_hp -= player_dmg;
            
            if (enemy_hp <= 0) {
                printf("You defeated the enemy! Congratulations!\n");
                break;
            }
            
            printf("The enemy attacks you with %d damage.\n", enemy_dmg);
            player_hp -= enemy_dmg;
            
            if (player_hp <= 0) {
                printf("You have been defeated! Game over.\n");
                break;
            }
            
        } else if (choice == 2) {
            if (num_potions <= 0) {
                printf("You are out of potions!\n");
            } else {
                printf("You drink a potion and heal 5 HP.\n");
                player_hp += 5;
                num_potions--;
                printf("You have %d more potions left.\n", num_potions);
            }
        } else {
            printf("Invalid choice! Please choose 1 or 2.\n");
        }
    }

    return 0;
}