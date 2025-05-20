//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_OPTIONS 3
#define MAX_ROOMS 5

const char* roomDescriptions[MAX_ROOMS] = {
    "You stand in a dimly lit foyer. Dust swirls in the air, and the shadows seem to flicker.",
    "You've entered a ghostly library filled with ancient books. A chill runs down your spine.",
    "This room is a kitchen, but it’s long abandoned. Strange sounds echo from the pantry.",
    "You find yourself in a long hallway lined with portraits that seem to watch you move.",
    "You've stepped into a decrepit bedroom. The air is thick with dust and whispers seem to surround you."
};

const char* roomNames[MAX_ROOMS] = {
    "Foyer",
    "Library",
    "Kitchen",
    "Hallway",
    "Bedroom"
};

int getRandomOption() {
    return rand() % MAX_OPTIONS + 1; // return options 1 to 3
}

void displayMenu(int roomIndex) {
    printf("\nYou are in the %s.\n", roomNames[roomIndex]);
    printf("%s\n", roomDescriptions[roomIndex]);
    printf("What would you like to do?\n");
    printf("1. Explore further.\n");
    printf("2. Knock on a wall.\n");
    printf("3. Leave the house.\n");
}

int exploreRoom() {
    return getRandomOption();
}

int knockOnWall() {
    return getRandomOption();
}

int leaveHouse() {
    printf("\nYou have decided to leave the haunted house. Better safe than sorry!\n");
    return 0; // Exit game
}

int main() {
    int currentRoom = 0;
    int userChoice;
    srand(time(NULL)); // Seed random number generator

    printf("Welcome to the Haunted House Simulator!\n");
    printf("Can you uncover its secrets?\n");

    while (1) {
        displayMenu(currentRoom);
        printf("Enter your choice (1-3): ");
        scanf("%d", &userChoice);

        switch (userChoice) {
            case 1: // Explore further
                if (currentRoom < MAX_ROOMS - 1) {
                    currentRoom++;
                    printf("You bravely explore further into the haunted house.\n");
                    if (exploreRoom() == 1) {
                        printf("A ghost appears! You must face it.\n");
                    }
                } else {
                    printf("You've reached the end of the house. Time to go back.\n");
                    currentRoom--;
                }
                break;
            case 2: // Knock on a wall
                printf("You knock on the wall. A hollow sound echoes back. Is something behind there?\n");
                if (knockOnWall() == 1) {
                    printf("Something frightening is awakened! It doesn't like being disturbed!\n");
                }
                break;
            case 3: // Leave the house
                if (leaveHouse() == 0) {
                    return 0; // Exit game
                }
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 3.\n");
        }
    }

    return 0;
}