//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    // Initializing the random number generator
    srand(time(NULL));
    
    // Initializing the player's health and gold
    int health = 100;
    int gold = 0;
    
    // Introduction to the game
    printf("Welcome to The Adventure Game!\n");
    printf("You are a brave adventurer, seeking treasure and glory.\n");
    printf("Let's see how far you can go!\n\n");
    
    // The game loop
    while (health > 0) {
        
        // Generating a random number to determine the encounter
        int encounter = rand() % 3;
        
        // Encountering a monster
        if (encounter == 0) {
            printf("You encounter a vicious monster!\n");
            printf("What do you do?\n");
            printf("1. Fight\n");
            printf("2. Flee\n");
            
            int choice;
            scanf("%d", &choice);
            
            // Fighting the monster
            if (choice == 1) {
                int damage = rand() % 21;
                int monster_damage = rand() % 11;
                health -= monster_damage;
                printf("You deal %d damage to the monster!\n", damage);
                printf("The monster deals %d damage to you!\n", monster_damage);
                
                if (health <= 0) {
                    printf("You have been defeated!\n");
                    break;
                }
                else {
                    printf("You are now at %d health.\n", health);
                }
            }
            
            // Fleeing from the monster
            else if (choice == 2) {
                int flee_chance = rand() % 2;
                
                if (flee_chance == 0) {
                    printf("You successfully flee from the monster!\n");
                    continue;
                }
                else {
                    int monster_damage = rand() % 11;
                    health -= monster_damage;
                    printf("You couldn't escape from the monster!\n");
                    printf("The monster deals %d damage to you!\n", monster_damage);
                    
                    if (health <= 0) {
                        printf("You have been defeated!\n");
                        break;
                    }
                    else {
                        printf("You are now at %d health.\n", health);
                    }
                }
            }
        }
        
        // Encountering a treasure chest
        else if (encounter == 1) {
            printf("You stumble upon a treasure chest!\n");
            printf("What do you do?\n");
            printf("1. Open the chest\n");
            printf("2. Ignore it\n");
            
            int choice;
            scanf("%d", &choice);
            
            // Opening the treasure chest
            if (choice == 1) {
                int gold_amount = rand() % 101;
                gold += gold_amount;
                printf("You found %d gold!\n", gold_amount);
                printf("You now have %d gold.\n", gold);
            }
            
            // Ignoring the treasure chest
            else if (choice == 2) {
                printf("You decide to ignore the chest and move on.\n");
            }
        }
        
        // Encountering a healing fountain
        else if (encounter == 2) {
            printf("You come across a healing fountain!\n");
            printf("What do you do?\n");
            printf("1. Drink from the fountain\n");
            printf("2. Leave it alone\n");
            
            int choice;
            scanf("%d", &choice);
            
            // Drinking from the fountain
            if (choice == 1) {
                int heal_amount = rand() % 21;
                health += heal_amount;
                
                if (health > 100) {
                    health = 100;
                }
                
                printf("You drink from the fountain and heal %d health!\n", heal_amount);
                printf("You are now at %d health.\n", health);
            }
            
            // Leaving the fountain alone
            else if (choice == 2) {
                printf("You decide to leave the fountain alone and move on.\n");
            }
        }
    }
    
    // Game over
    printf("Thanks for playing!\n");
    printf("Your final score is %d gold.\n", gold);

    return 0;
}