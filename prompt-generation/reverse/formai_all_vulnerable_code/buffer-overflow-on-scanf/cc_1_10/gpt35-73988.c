//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Function to print the opening message
void printOpeningMessage() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You have entered a haunted house and have to find your way out.\n");
    printf("Be careful, as you never know what might be lurking in the shadows...\n\n");
}

// Function to initialize the rooms and doors
void initializeRoomsAndDoors(int rooms[], bool doors[][4], int numRooms) {
    // Set each room to a random number between 1 and 4
    for (int i = 0; i < numRooms; i++) {
        rooms[i] = rand() % 4 + 1;
    }
    
    // Initialize the doors to be closed for all rooms
    for (int i = 0; i < numRooms; i++) {
        for (int j = 0; j < 4; j++) {
            doors[i][j] = false;
        }
    }
}

// Function to print the current room and the available doors
void printCurrentRoomAndDoors(int currentRoom, bool doors[][4]) {
    printf("You are currently in Room %d\n", currentRoom + 1);
    printf("Available Doors: ");
    for (int i = 0; i < 4; i++) {
        if (doors[currentRoom][i]) {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
}

// Function to get the user's choice of door to open
int getUserChoiceOfDoorToOpen(bool doors[]) {
    int choice;
    // Loop until the user enters a valid choice
    do {
        printf("Which door would you like to open? (Enter 1, 2, 3, or 4): ");
        scanf("%d", &choice);
        if (choice < 1 || choice > 4 || !doors[choice - 1]) {
            printf("Invalid choice, please try again.\n");
        }
    } while (choice < 1 || choice > 4 || !doors[choice - 1]);
    return choice;
}

// Function to check if the user has won
bool checkIfUserHasWon(int currentRoom, int endRoom) {
    return currentRoom == endRoom;
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    const int NUM_ROOMS = 5; // Number of rooms in the haunted house
    const int START_ROOM = 0; // Starting room
    const int END_ROOM = 4; // Ending room
    int rooms[NUM_ROOMS]; // Array to store the contents of each room
    bool doors[NUM_ROOMS][4]; // 2D array to store the state of each door in each room
    int currentRoom = START_ROOM; // Set the starting room as the current room
    bool hasWon = false; // Flag to indicate if the user has won
    
    printOpeningMessage();
    initializeRoomsAndDoors(rooms, doors, NUM_ROOMS);
    
    // Loop until the user has won or quit
    while (!hasWon) {
        printCurrentRoomAndDoors(currentRoom, doors);
        int choice = getUserChoiceOfDoorToOpen(doors[currentRoom]);
        doors[currentRoom][choice - 1] = true; // Open the chosen door
        
        // Move to the next room if the door leads to a different room
        if (rooms[currentRoom] != rooms[currentRoom + choice - 1]) {
            currentRoom += choice - 1;
        }
        
        // Check if the user has won
        if (checkIfUserHasWon(currentRoom, END_ROOM)) {
            printf("Congratulations! You have found your way out of the haunted house!\n");
            hasWon = true;
        }
    }
    
    return 0;
}