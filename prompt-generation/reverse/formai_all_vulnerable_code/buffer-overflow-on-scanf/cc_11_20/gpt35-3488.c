//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  // Seed the random number generator
    char name[20];
    char choice;
    int health = 100;
    int gold = 0;
    int damage;
    int enemy_health;
    int enemy_damage;
    
    printf("Welcome to the Text Adventure Game!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    
    printf("\n%s, you are a brave warrior on a dangerous quest.\n", name);
    printf("Your mission is to defeat the evil dragon and retrieve the treasure it guards.\n");
    printf("You find yourself at the entrance to a dark cave. Do you enter? (y/n)\n");
    
    while(1) {
        scanf(" %c", &choice);
        if(choice == 'y') {
            printf("\nYou cautiously enter the cave and hear rustling in the darkness.\n");
            break;
        } else if(choice == 'n') {
            printf("\nYou turn back and abandon your mission. GAME OVER.\n");
            return 0;
        } else {
            printf("\nInvalid choice. Please enter y or n.\n");
        }
    }
    
    printf("\nYou come face to face with a goblin! Prepare for battle!\n");
    enemy_health = 30;
    
    while(1) {
        printf("\n%s's health: %d\n", name, health);
        printf("Goblin's health: %d\n", enemy_health);
        printf("Choose an action:\n");
        printf("a - Attack\n");
        printf("r - Run away\n");
        scanf(" %c", &choice);
        
        if(choice == 'a') {
            damage = rand() % 20 + 1;
            enemy_health -= damage;
            printf("\nYou strike the goblin for %d damage!\n", damage);
            if(enemy_health <= 0) {
                printf("\nYou have defeated the goblin!\n");
                gold += 20;
                health += 20;
                break;
            }
            enemy_damage = rand() % 10 + 1;
            health -= enemy_damage;
            printf("\nThe goblin strikes you for %d damage!\n", enemy_damage);
            if(health <= 0) {
                printf("\n%s has been defeated. GAME OVER.\n", name);
                return 0;
            }
        } else if(choice == 'r') {
            printf("\nYou run away from the goblin. Coward! GAME OVER.\n");
            return 0;
        } else {
            printf("\nInvalid choice. Please choose a or r.\n");
        }
    }
    
    printf("\nYou continue deeper into the cave and come to a fork in the path.\n");
    printf("Do you go left or right? (l/r)\n");
    
    while(1) {
        scanf(" %c", &choice);
        if(choice == 'l') {
            printf("\nYou find a treasure chest containing 50 gold!\n");
            gold += 50;
            break;
        } else if(choice == 'r') {
            printf("\nYou walk into a trap and lose 30 health!\n");
            health -= 30;
            if(health <= 0) {
                printf("\n%s has been defeated. GAME OVER.\n", name);
                return 0;
            }
            printf("\nYou manage to escape the trap and continue on your quest.\n");
            break;
        } else {
            printf("\nInvalid choice. Please choose l or r.\n");
        }
    }
    
    printf("\nYou finally come face to face with the dragon!\n");
    enemy_health = 100;
    
    while(1) {
        printf("\n%s's health: %d\n", name, health);
        printf("Dragon's health: %d\n", enemy_health);
        printf("Choose an action:\n");
        printf("a - Attack\n");
        printf("r - Run away\n");
        scanf(" %c", &choice);
        
        if(choice == 'a') {
            damage = rand() % 50 + 1;
            enemy_health -= damage;
            printf("\nYou strike the dragon for %d damage!\n", damage);
            if(enemy_health <= 0) {
                printf("\nYou have defeated the dragon and retrieved the treasure!\n");
                gold += 200;
                printf("\n%s's gold: %d\n", name, gold);
                printf("\n%s's health: %d\n", name, health);
                printf("\nCongratulations, %s! You have completed your quest!\n", name);
                return 0;
            }
            enemy_damage = rand() % 20 + 1;
            health -= enemy_damage;
            printf("\nThe dragon strikes you for %d damage!\n", enemy_damage);
            if(health <= 0) {
                printf("\n%s has been defeated. GAME OVER.\n", name);
                return 0;
            }
        } else if(choice == 'r') {
            printf("\nYou run away from the dragon. Coward! GAME OVER.\n");
            return 0;
        } else {
            printf("\nInvalid choice. Please choose a or r.\n");
        }
    }
    
    return 0;
}