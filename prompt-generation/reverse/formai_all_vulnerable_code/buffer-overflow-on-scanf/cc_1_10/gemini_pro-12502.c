//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables for the haunted house
int rooms = 10;
char *roomNames[] = {
    "Foyer", "Living Room", "Dining Room", "Kitchen", "Master Bedroom", "Guest Bedroom", "Library", "Attic", "Basement", "Wine Cellar"
};
int roomDescriptions[][10] = {
    {1, 2, 3, 4, 0, 0, 0, 0, 0, 0},
    {0, 2, 3, 5, 0, 0, 0, 0, 0, 0},
    {0, 1, 4, 6, 0, 0, 0, 0, 0, 0},
    {0, 1, 3, 5, 0, 0, 0, 0, 0, 0},
    {0, 1, 3, 6, 0, 0, 0, 0, 0, 0},
    {0, 1, 4, 6, 0, 0, 0, 0, 0, 0},
    {0, 1, 3, 5, 0, 0, 0, 0, 0, 0},
    {0, 1, 3, 6, 0, 0, 0, 0, 0, 0},
    {0, 1, 3, 6, 0, 0, 0, 0, 0, 0},
    {0, 1, 3, 6, 0, 0, 0, 0, 0, 0}
};

// Function to generate a random number between min and max
int randomInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print the description of a room
void printRoomDescription(int room) {
    printf("You are in the %s.\n", roomNames[room]);
    printf("You can go to the following rooms: ");
    for (int i = 0; i < 10; i++) {
        if (roomDescriptions[room][i] != 0) {
            printf("%s, ", roomNames[roomDescriptions[room][i]]);
        }
    }
    printf("\n");
}

// Function to simulate the haunted house
void hauntedHouse() {
    // Seed the random number generator
    srand(time(NULL));

    // Start the player in the foyer
    int room = 0;

    // Loop until the player exits the house
    while (room != -1) {
        // Print the description of the current room
        printRoomDescription(room);

        // Get the player's input
        printf("Where do you want to go? (-1 to exit) ");
        scanf("%d", &room);

        // Check if the player entered a valid room number
        if (room < -1 || room >= rooms) {
            printf("Invalid room number. Please try again.\n");
        }
    }

    // Print a goodbye message
    printf("Thank you for visiting the haunted house. Please come again soon!\n");
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Generate a random haunted house
    hauntedHouse();

    return 0;
}