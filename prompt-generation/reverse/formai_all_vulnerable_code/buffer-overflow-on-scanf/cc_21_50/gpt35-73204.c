//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    srand(time(0)); // for random number generation
    int health = 100, stamina = 50, gold = 0; // player stats
    int room = 1, monster = 0, monster_health = 0; // game variables
    char action[10], choice[10]; // user input variables
    
    printf("Welcome to the Dungeon!\n");
    printf("You find yourself in a dark room. You have %d health, %d stamina, and %d gold.\n", health, stamina, gold);
    
    while (health > 0) { // game loop
        
        // room logic
        switch(room) {
            case 1:
                printf("\nYou are in a dark room. You can go 'north'.\n");
                break;
            case 2:
                printf("\nYou are in a corridor. You can go 'north' or 'south'.\n");
                break;
            case 3:
                printf("\nYou are in the treasure room. You can go 'south'. There is a chest in the room, do you want to 'open' it?\n");
                break;
            case 4:
                printf("\nYou are in the monster room. There is a monster in the room, do you want to 'fight' it or 'flee'?\n");
                break;
        }
        
        // user input
        printf("What do you want to do?\n");
        scanf("%s", action);
        
        // room actions
        if (room == 1 && strcmp(action, "north") == 0) {
            room = 2;
            printf("\nYou move north and enter a corridor.\n");
        } else if (room == 2 && strcmp(action, "north") == 0) {
            room = 3;
            printf("\nYou move north and enter the treasure room.\n");
        } else if (room == 2 && strcmp(action, "south") == 0) {
            room = 1;
            printf("\nYou move south and enter a dark room.\n");
        } else if (room == 3 && strcmp(action, "south") == 0) {
            room = 2;
            printf("\nYou move south and enter the corridor.\n");
            
            // treasure room logic
            if (strcmp(choice, "open") == 0) {
                int gold_found = rand() % 100 + 1;
                gold += gold_found;
                printf("\nYou open the chest and find %d gold!\n", gold_found);
                printf("Your new gold total is %d.\n", gold);
            }
        } else if (room == 4 && strcmp(action, "fight") == 0) {
            // monster room logic
            if (monster == 0) {
                monster_health = rand() % 50 + 50;
                printf("\nYou engage in battle with the monster!\n");
                monster = 1;
            }
            // player attack
            int damage = rand() % 10 + 10;
            monster_health -= damage;
            printf("\nYou deal %d damage to the monster!\n", damage);
            // monster attack
            if (monster_health > 0) {
                damage = rand() % 20 + 10;
                health -= damage;
                printf("\nThe monster deals %d damage to you!\n", damage);
            } else {
                int gold_found = rand() % 50 + 1;
                gold += gold_found;
                printf("\nYou have defeated the monster! You found %d gold on its body.\n", gold_found);
                monster = 0;
            }
        } else if (room == 4 && strcmp(action, "flee") == 0) {
            room = 2;
            printf("\nYou run away from the monster and enter the corridor.\n");
        } else {
            printf("\nInvalid action, try again.\n");
        }
        
        // check player stats
        if (health <= 0) {
            printf("\nYou have died! Game over.\n");
            break;
        } else if (stamina <= 0) {
            printf("\nYou are too exhausted to continue! Game over.\n");
            break;
        }
        printf("\nYour health is now %d.\n", health);
        printf("Your stamina is now %d.\n", stamina);
        printf("Your gold total is %d.\n", gold);
    }
    
    printf("\nThanks for playing!\n");
    return 0;
}