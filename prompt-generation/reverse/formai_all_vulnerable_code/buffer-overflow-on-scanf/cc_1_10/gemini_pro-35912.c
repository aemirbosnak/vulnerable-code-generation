//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: energetic
// Embark on a thrilling adventure through the Haunted House Simulator!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define spooky sounds for the haunted house experience
char *spookySounds[] = {
    "Creaking floorboards",
    "Whispering voices",
    "Howling wind",
    "Groaning doors",
    "Eerie laughter"
};

// Create a spine-tingling menu of options
void printMenu() {
    printf("\nWelcome to the Haunted House Simulator! Choose your destiny:\n");
    printf("1. Explore the Creaky Corridor\n");
    printf("2. Venture into the Shadowy Attic\n");
    printf("3. Descend into the Chilling Basement\n");
    printf("4. Confront the Ghostly Intruder\n");
    printf("5. Escape the Haunted House\n");
}

// Function to generate a random spooky sound
char *getRandomSound() {
    return spookySounds[rand() % 5];
}

// Function to simulate the eerie atmosphere of the haunted house
void createAmbiance() {
    char *sound = getRandomSound();
    printf("\nYou hear the chilling sounds of %s echoing through the corridors...\n", sound);
}

// Function to simulate the exploration of the haunted house
void exploreHauntedHouse(int choice) {
    switch (choice) {
        case 1:
            printf("\nYou cautiously tread down the Creaky Corridor, wooden floorboards groaning beneath your feet.\n");
            createAmbiance();
            break;
        case 2:
            printf("\nYou ascend the creaky staircase into the dust-filled Shadowy Attic, where shadows dance on the walls.\n");
            createAmbiance();
            break;
        case 3:
            printf("\nYou descend the rickety wooden steps into the Chilling Basement, where cobwebs hang from every corner.\n");
            createAmbiance();
            break;
        case 4:
            printf("\nYou gather your courage and confront the Ghostly Intruder, a translucent figure floating in the darkness.\n");
            createAmbiance();
            break;
        case 5:
            printf("\nYou sprint towards the creaking front door, desperate to escape the clutches of the haunted house.\n");
            createAmbiance();
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
    }
}

// Main function to start the haunted house simulation
int main() {
    // Initialize random number generator
    srand(time(NULL));

    int choice;
    do {
        printMenu();
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);
        exploreHauntedHouse(choice);
    } while (choice != 5); // Continue exploring until the user chooses to escape

    printf("\nYou have escaped the haunted house! Congratulations!\n");

    return 0;
}