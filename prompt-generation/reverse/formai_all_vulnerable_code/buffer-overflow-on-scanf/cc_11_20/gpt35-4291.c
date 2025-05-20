//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    srand(time(NULL)); // seed the rand function
    
    char name[20]; // to store player name
    int health = 100; // to store player health
    int score = 0; // to store player score
    int level = 1; // to store game level
    
    printf("Welcome to the Text-Based Adventure Game!\n\n");
    
    // get player name
    printf("Enter your name: ");
    scanf("%s", name);
    printf("\nHello, %s! Let's start the game.\n\n", name);
    
    // main game loop
    while (1) {
        
        // print game status
        printf("Level: %d\n", level);
        printf("Health: %d\n", health);
        printf("Score: %d\n\n", score);
        
        // generate random number between 1 to 10
        int randNum = rand() % 10 + 1;
        
        // check level and print appropriate scenario
        if (level == 1) {
            printf("You are in a dungeon. There are two paths ahead, left and right.\n");
            printf("Which path do you choose? (1 for left, 2 for right)\n");
            int choice;
            scanf("%d", &choice);
            if (choice == 1) {
                printf("\nYou encountered an ogre!\n");
                if (randNum <= 5) {
                    printf("You defeated the ogre and gained 10 points.\n");
                    score += 10;
                    health -= 10;
                } else {
                    printf("The ogre defeated you. Game over.\n");
                    break;
                }
            } else if (choice == 2) {
                printf("\nYou encountered a treasure chest!\n");
                if (randNum <= 7) {
                    printf("The chest was full of gold coins. You gained 20 points.\n");
                    score += 20;   
                } else {
                    printf("The chest was a trap! You lost 10 health points.\n");
                    health -= 10;
                }
            }
            level++;
        } else if (level == 2) {
            printf("You are outside now. You see a bridge over a river.\n");
            printf("Do you cross the bridge? (1 for yes, 2 for no)\n");
            int choice;
            scanf("%d", &choice);
            if (choice == 1) {
                printf("\nYou are halfway across the bridge when it starts to collapse!\n");
                if (randNum <= 5) {
                    printf("You managed to jump to the other side and gained 10 points.\n");
                    score += 10;
                    health -= 5;
                } else {
                    printf("You fell into the river and lost 20 health points. Game over.\n");
                    health -= 20;
                    break;
                }
            } else if (choice == 2) {
                printf("\nYou decided to follow the river. You found a hidden cave.\n");
                if (randNum <= 7) {
                    printf("Inside the cave, you found a magic sword. You gained 30 points.\n");
                    score += 30;   
                } else {
                    printf("The cave was full of monsters! You lost 20 health points.\n");
                    health -= 20;
                }
            }
            level++;
        } else {
            printf("You are in a forest. You hear strange noises all around you.\n");
            printf("What do you do? (1 for run, 2 for hide)\n");
            int choice;
            scanf("%d", &choice);
            if (choice == 1) {
                printf("\nYou kept running, but stumbled into a trap!\n");
                if (randNum <= 5) {
                    printf("Luckily, you managed to free yourself and gained 10 points.\n");
                    score += 10;
                    health -= 5;
                } else {
                    printf("The trap was too strong. You lost 30 health points. Game over.\n");
                    health -= 30;
                    break;
                }
            } else if (choice == 2) {
                printf("\nYou found a hiding spot and waited. Suddenly, a group of bandits appeared!\n");
                if (randNum <= 7) {
                    printf("You successfully ambushed them and took their loot. You gained 40 points.\n");
                    score += 40;   
                } else {
                    printf("They found you! You lost 50 health points. Game over.\n");
                    health -= 50;
                    break;
                }
            }
            level++;
        }
        
        // check health
        if (health <= 0) {
            printf("\nYou have no health left. Game over.\n");
            break;
        }
        
        // check score
        if (score >= 100) {
            printf("\nCongratulations, %s! You have completed the game.\n", name);
            break;
        }
        
        printf("===========================================\n\n");
    }
    
    return 0;
}