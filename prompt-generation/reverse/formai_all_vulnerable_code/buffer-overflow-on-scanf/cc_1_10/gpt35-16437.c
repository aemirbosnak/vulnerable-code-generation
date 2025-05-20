//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void printIntro();
void startGame();
void gameOver();

int main() {
    printIntro();
    startGame();
    gameOver();
    return 0;
}

void printIntro() {
    printf("Welcome to the Text-Based Adventure Game!\n\n");
    printf("You are a hero on a quest to save the land from an evil sorcerer.\n");
    printf("You must travel through forests and mountains, fight off monsters, and solve puzzles to reach the sorcerer's castle.\n");
    printf("Good luck!\n\n");
}

void startGame() {
    // Define variables
    int choice;
    char name[20];
    int health = 100;
    int gold = 0;

    // Ask for name
    printf("What is your name, hero?\n");
    scanf("%s", name);
    printf("Welcome, %s!\n", name);

    // Begin game loop
    while (health > 0) {
        printf("\nYou are currently at full health.\n");
        printf("1. Travel to the forest\n");
        printf("2. Travel to the mountain\n");
        printf("3. View inventory\n");
        printf("4. Quit game\n");
        printf("What would you like to do?\n");

        // Get user input
        scanf("%d", &choice);

        // Handle user choice
        switch (choice) {
            case 1:
                printf("You travel to the forest.\n");
                printf("You encounter a giant spider!\n");
                printf("1. Fight\n");
                printf("2. Flee\n");
                printf("What would you like to do?\n");
                scanf("%d", &choice);
                if (choice == 1) {
                    printf("You fight the giant spider.\n");
                    printf("You win!\n");
                    gold += 10;
                    health -= 20;
                    printf("You gained 10 gold! You now have %d gold.\n", gold);
                    printf("You lost 20 health. You now have %d health.\n", health);
                } else {
                    printf("You flee from the giant spider.\n");
                }
                break;
            case 2:
                printf("You travel to the mountain.\n");
                printf("You encounter a pack of wolves!\n");
                printf("1. Fight\n");
                printf("2. Flee\n");
                printf("What would you like to do?\n");
                scanf("%d", &choice);
                if (choice == 1) {
                    printf("You fight the wolves.\n");
                    printf("You win!\n");
                    gold += 15;
                    health -= 25;
                    printf("You gained 15 gold! You now have %d gold.\n", gold);
                    printf("You lost 25 health. You now have %d health.\n", health);
                } else {
                    printf("You flee from the wolves.\n");
                }
                break;
            case 3:
                printf("You have %d gold and %d health.\n", gold, health);
                break;
            case 4:
                printf("Quitting game...\n");
                health = 0;
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}

void gameOver() {
    printf("\nGAME OVER\n");
    printf("Thanks for playing the Text-Based Adventure Game!\n");
}