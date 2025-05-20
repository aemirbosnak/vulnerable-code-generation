//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Haunted house data
const int numRooms = 5;
const char *roomNames[] = {"Foyer", "Living Room", "Kitchen", "Dining Room", "Master Bedroom"};
const char *roomDescriptions[] = {
    "A cold, dark, and musty room with a single window. A staircase leads up to the second floor.",
    "A spacious and well-lit room with a fireplace and comfortable furniture. A door leads to the kitchen.",
    "A large and well-equipped kitchen with a stove, oven, refrigerator, and all the other amenities you would expect. A door leads to the dining room.",
    "A formal dining room with a large table and chairs. A door leads to the living room.",
    "A large and comfortable bedroom with a king-sized bed, a dresser, and a nightstand. A door leads to the hallway."
};
const int numEvents = 5;
const char *eventNames[] = {"Footsteps", "Door Opens", "Window Breaks", "Ghost Appears", "Scream"};
const char *eventDescriptions[] = {
    "You hear footsteps coming from the next room.",
    "A door creaks open and then slams shut.",
    "A window shatters, sending glass flying everywhere.",
    "A ghostly figure appears before you.",
    "You hear a scream coming from the next room."
};

// Player data
int playerRoom = 0;
int playerHealth = 100;

// Function to generate a random event
int generateEvent() {
    return rand() % numEvents;
}

// Function to handle an event
void handleEvent(int event) {
    switch (event) {
        case 0:
            printf("You hear footsteps coming from the next room.\n");
            break;
        case 1:
            printf("A door creaks open and then slams shut.\n");
            break;
        case 2:
            printf("A window shatters, sending glass flying everywhere.\n");
            playerHealth -= 10;
            break;
        case 3:
            printf("A ghostly figure appears before you.\n");
            playerHealth -= 20;
            break;
        case 4:
            printf("You hear a scream coming from the next room.\n");
            playerHealth -= 10;
            break;
    }
}

// Function to play the game
void playGame() {
    // Seed the random number generator
    srand(time(NULL));

    // Loop until the player dies or wins
    while (playerHealth > 0) {
        // Get a random event
        int event = generateEvent();

        // Handle the event
        handleEvent(event);

        // Check if the player is still alive
        if (playerHealth <= 0) {
            printf("You have died.\n");
            break;
        }

        // Move the player to the next room
        playerRoom++;

        // Check if the player has won
        if (playerRoom == numRooms) {
            printf("You have escaped the haunted house!\n");
            break;
        }
    }
}

// Function to print the game menu
void printMenu() {
    printf("Haunted House Simulator\n");
    printf("=====================\n");
    printf("Commands:\n");
    printf("    explore: Explore the next room\n");
    printf("    quit: Quit the game\n");
}

// Main function
int main() {
    // Print the welcome message
    printf("Welcome to the Haunted House Simulator!\n");

    // Print the game menu
    printMenu();

    // Get the player's input
    char input[10];
    while (1) {
        printf("> ");
        scanf("%s", input);

        // Handle the player's input
        if (strcmp(input, "explore") == 0) {
            playGame();
        } else if (strcmp(input, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    // Print the goodbye message
    printf("Thank you for playing the Haunted House Simulator!\n");

    return 0;
}