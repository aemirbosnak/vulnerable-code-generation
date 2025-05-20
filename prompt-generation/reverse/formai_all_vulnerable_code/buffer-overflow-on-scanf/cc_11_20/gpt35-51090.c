//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed randomizer with current time
    srand(time(NULL));
    
    // Set up haunted house rooms with random spooky noises and creepy objects
    char* rooms[4] = {
        "Haunted Bedroom",
        "Creepy Library",
        "Ghostly Attic",
        "Spooky Basement"
    };
    char* noises[4] = {
        "eerie whispers",
        "ghostly moans",
        "creaking floorboards",
        "howling winds"
    };
    char* objects[4] = {
        "cobweb-covered antique dresser",
        "dusty old bookshelf",
        "creepy porcelain doll",
        "rusty chain and shackles"
    };
    
    // Set up player variables
    int health = 100;
    int sanity = 100;
    int location = 0; // Starting room is Haunted Bedroom
    
    // Introduction
    printf("Welcome to the Haunted House Simulator!\n");
    
    // Main game loop
    while (health > 0 && sanity > 0) {
        // Print player status
        printf("\nCurrent Location: %s\n", rooms[location]);
        printf("Health: %d\n", health);
        printf("Sanity: %d\n", sanity);
        
        // Randomly generate a spooky noise and creepy object for the current room
        int noiseIndex = rand() % 4;
        int objectIndex = rand() % 4;
        
        // Print room description
        printf("You hear %s coming from the %s. ", noises[noiseIndex], rooms[location]);
        printf("In the corner there is a %s.\n", objects[objectIndex]);
        
        // Prompt user for action
        printf("\nWhat would you like to do?\n");
        printf("[1] Investigate the %s\n", objects[objectIndex]);
        printf("[2] Search the room for items\n");
        printf("[3] Move to another room\n");
        
        // Get user input
        int choice;
        scanf("%d", &choice);
        
        // Process user input
        switch (choice) {
            case 1:
                // Decrease sanity and possibly damage health by investigating object
                printf("\nYou gingerly approach the %s...", objects[objectIndex]);
                int success = rand() % 2; // Random chance of success
                if (success) {
                    printf("and find a valuable clue!\n");
                    sanity -= 20;
                } else {
                    printf("and disturb a ghostly presence, which attacks you!\n");
                    health -= 30;
                    sanity -= 10;
                }
                break;
            case 2:
                // Increase sanity and possibly find health item by searching room
                printf("\nYou search the room carefully...");
                int itemFound = rand() % 2; // Random chance of finding item
                if (itemFound) {
                    printf("and discover a first aid kit!\n");
                    health += 20;
                    if (health > 100) // Cap health at 100
                        health = 100;
                } else {
                    printf("but find nothing useful.\n");
                    sanity += 10;
                    if (sanity > 100) // Cap sanity at 100
                        sanity = 100;
                }
                break;
            case 3:
                // Randomly move to another room
                printf("\nYou cautiously make your way to another room...\n");
                int newLocation = rand() % 4;
                while (newLocation == location) // Make sure new location is different from current location
                    newLocation = rand() % 4;
                location = newLocation;
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }
        
        // Check if player has lost (health or sanity below zero)
        if (health <= 0) {
            printf("\nYou have succumbed to your injuries. Game over.\n");
            break;
        }
        if (sanity <= 0) {
            printf("\nYou have lost your mind. Game over.\n");
            break;
        }
    }
    
    // Epilogue
    printf("\nThanks for playing the Haunted House Simulator!\n");
    return 0;
}