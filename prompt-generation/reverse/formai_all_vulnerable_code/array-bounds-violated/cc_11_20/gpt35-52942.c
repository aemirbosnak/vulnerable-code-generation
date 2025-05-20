//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main() {
    // Introduction
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are stranded on a deserted island and need to find a way off.\n");
    printf("You will encounter challenges along the way, but keep your wits about you.\n");
 
    // Game variables
    char name[20];
    int hunger = 50;
    int thirst = 50;
    int health = 100;
 
    // Ask for player's name
    printf("Enter your name: ");
    fgets(name, 20, stdin);
    name[strlen(name) - 1] = 0;
 
    // Start game
    printf("\nHello %s, let's begin.\n", name);
 
    // Game loop
    while (health > 0) {
        // Display player's stats
        printf("\n\nStatus: \n");
        printf("Hunger: %d\n", hunger);
        printf("Thirst: %d\n", thirst);
        printf("Health: %d\n", health);
 
        // Ask player what they want to do
        printf("\nWhat do you want to do?\n");
        printf("1. Look for food.\n");
        printf("2. Look for water.\n");
        printf("3. Rest.\n");
        printf("4. Look for help.\n");
 
        int choice;
        scanf("%d", &choice);
 
        switch (choice) {
            case 1:
                // Look for food
                printf("\nYou search the island for food.\n");
                printf("You find some coconuts and berries.\n");
                hunger += 10;
                break;
            case 2:
                // Look for water
                printf("\nYou search the island for water.\n");
                printf("You find a stream and drink some water.\n");
                thirst += 10;
                break;
            case 3:
                // Rest
                printf("\nYou rest for a while.\n");
                printf("You feel better.\n");
                health += 10;
                break;
            case 4:
                // Look for help
                printf("\nYou search the island for help.\n");
                printf("You find an old radio that still works.\n");
                printf("You call for help and a helicopter comes to your rescue!\n");
                health = 0;
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
 
        // Decrease hunger and thirst every turn
        hunger -= 5;
        thirst -= 5;
 
        // Check for death
        if (hunger <= 0) {
            printf("\nYou died of hunger.\n");
            health = 0;
        }
 
        if (thirst <= 0) {
            printf("\nYou died of thirst.\n");
            health = 0;
        }
 
        // Check for victory
        if (health == 0) {
            if (hunger > 0 && thirst > 0) {
                printf("\nYou have survived and have been rescued!\n");
            } else {
                printf("\nYou almost made it, but died before being rescued.\n");
            }
        }
    }
 
    return 0;
}