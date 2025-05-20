//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Player struct to hold the player's information
typedef struct player {
    char name[20];
    int health;
} Player;

int main() {
    // Initializing the player
    Player p;
    strcpy(p.name, "John");
    p.health = 100;

    // Introduction to the game
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are %s and you have %d health points. Good luck!\n", p.name, p.health);

    // Game loop
    while (p.health > 0) {
        char choice[10];
        printf("Choose your next move:\n1. Go left\n2. Go right\n3. Take a rest\n4. Quit game\n");
        scanf("%s", choice);

        if (strcmp(choice, "1") == 0) {
            printf("You have encountered an enemy!\n");
            printf("Your health is now %d.\n", p.health -= 20);
            if (p.health <= 0) {
                printf("Game over!\n");
                break;
            } else {
                printf("You defeated the enemy!\n");
            }
        } else if (strcmp(choice, "2") == 0) {
            printf("You found a treasure chest!\n");
            printf("You gained 50 health points.\n");
            p.health += 50;
        } else if (strcmp(choice, "3") == 0) {
            printf("You took a rest and gained 20 health points.\n");
            p.health += 20;
        } else if (strcmp(choice, "4") == 0) {
            printf("Thanks for playing!\n");
            exit(0);
        } else {
            printf("Invalid input. Please try again.\n");
        }

        // Printing player's current health after each move
        printf("Your current health is %d.\n", p.health);
    }

    return 0;
}