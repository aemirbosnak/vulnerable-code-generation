//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Define constants
#define MAX_ROOMS 10
#define MIN_ROOMS 5
#define MAX_GHOSTS 5
#define MIN_GHOSTS 1

// Define room struct
struct Room {
    bool isHaunted;
    int numGhosts;
};

// Define random number generator function
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main(void) {
    // Initialize random number generator with current time
    srand((unsigned) time(NULL));

    // Generate a random number of rooms between MIN_ROOMS and MAX_ROOMS
    int numRooms = generateRandomNumber(MIN_ROOMS, MAX_ROOMS);

    // Create an array of rooms
    struct Room rooms[numRooms];

    // Populate the array of rooms with random number of ghosts and hauntings
    for (int i = 0; i < numRooms; i++) {
        rooms[i].numGhosts = generateRandomNumber(MIN_GHOSTS, MAX_GHOSTS);
        rooms[i].isHaunted = (generateRandomNumber(0, 1) == 1);
    }

    // Print out the details of the haunted house
    printf("Welcome to the haunted house simulator!\n");
    printf("This house has %d rooms:\n", numRooms);
    for (int i = 0; i < numRooms; i++) {
        printf("Room %d: %d ghosts, %s\n", i+1, rooms[i].numGhosts, (rooms[i].isHaunted) ? "haunted" : "not haunted");
    }

    // Let the user explore the house
    int currentRoom = 1;
    while (true) {
        // Print out the details of the current room
        printf("\nYou are in room %d.\n", currentRoom);
        printf("This room has %d ghosts and is %s.\n", rooms[currentRoom-1].numGhosts, (rooms[currentRoom-1].isHaunted) ? "haunted" : "not haunted");

        // Check if the room is haunted
        if (rooms[currentRoom-1].isHaunted) {
            // If the room is haunted, roll a die to see if the user encounters a ghost
            int roll = generateRandomNumber(1, 6);
            if (roll <= rooms[currentRoom-1].numGhosts) {
                // If the user encounters a ghost, print a spooky message and end the game
                printf("A ghost appears and scares you! Game over!\n");
                break;
            }
            else {
                // If the user doesn't encounter a ghost, print an encouraging message
                printf("You heroically navigate through the haunted room.\n");
            }
        }

        // Ask the user if they want to move to another room
        char response;
        printf("Do you want to move to another room? (Y/N) ");
        scanf(" %c", &response);
        if (response == 'Y' || response == 'y') {
            // If the user wants to move to another room, choose a random room to move to
            currentRoom = generateRandomNumber(1, numRooms);
        }
        else {
            // If the user doesn't want to move to another room, end the game
            printf("Thanks for playing!\n");
            break;
        }
    }

    return 0;
}