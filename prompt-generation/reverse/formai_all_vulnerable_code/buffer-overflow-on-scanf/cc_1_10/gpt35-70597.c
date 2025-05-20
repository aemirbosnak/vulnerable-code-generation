//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // Welcome the player to the game
    printf("Welcome to the Text Adventure Game!\n");
    printf("Please enter your name: ");
    char name[50];
    scanf("%s", name);

    // Start the game with an introduction
    printf("\nHello, %s! You find yourself in a dark forest.\n", name);
    printf("You have no memory of how you got here, but you know you need to find a way out.\n");

    // Initialize variables for the game
    int health = 100;
    int stamina = 100;
    int gold = 0;

    // Create an array to store player's inventory
    char inventory[5][20] = {"", "", "", "", ""};

    // Start the main game loop
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Look for a path\n");
        printf("2. Check your inventory\n");
        printf("3. Quit the game\n");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            // Player looks for a path
            printf("\nYou search the forest for a path but find nothing.");
            // Player loses some stamina
            stamina -= 10;
            // Check if player still has enough stamina to continue
            if (stamina <= 0) {
                printf("\n\nYou are too tired to continue. You collapse and die of exhaustion.");
                printf("\n\nGAME OVER\n");
                return 0;
            }
        }
        else if (choice == 2) {
            // Player checks inventory
            printf("\nYou check your inventory:");
            for (int i = 0; i < 5; i++) {
                if (strcmp(inventory[i], "") != 0) {
                    printf("\n%s", inventory[i]);
                }
            }
            // Check if player has any items
            if (strcmp(inventory[0], "") == 0) {
                printf("\n\nYou have no items in your inventory.");
            }
        }
        else if (choice == 3) {
            // Player quits the game
            printf("\n\nThanks for playing, %s! Goodbye.\n", name);
            return 0;
        }
        else {
            // Player entered an invalid choice
            printf("\n\nPlease enter a valid choice.\n");
        }
    }
}