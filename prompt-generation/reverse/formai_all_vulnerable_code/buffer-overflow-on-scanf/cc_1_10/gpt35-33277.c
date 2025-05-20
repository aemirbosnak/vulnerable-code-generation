//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: light-weight
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int roomCount = 5; // Number of rooms in the house
int currentRoom = 0; // We start in room 0
int maxSteps = 10; // Maximum number of steps we can take
int currentSteps = 0; // Number of steps we have taken
bool endGame = false; // Have we reached the end of the game?

// Array of room descriptions
const char* roomDescriptions[] = {
    "You are in the foyer. There is a door to the north.",
    "You are in the living room. There is a door to the north and a door to the east.",
    "You are in the dining room. There is a door to the west and a door to the south.",
    "You are in the kitchen. There is a door to the east.",
    "You are in the bedroom. There is a door to the south."
};

// Array of room spooky descriptions
const char* roomSpookyDescriptions[] = {
    "You feel a chill run down your spine as you step into the foyer.",
    "You hear a faint whisper coming from the living room.",
    "You smell a faint scent of decaying flesh coming from the dining room.",
    "You hear a loud creaking noise coming from the kitchen.",
    "You see a shadowy figure in the bedroom."
};

// Function to randomly generate spooky descriptions
const char* getSpookyDescription() {
    int index = rand() % roomCount;
    return roomSpookyDescriptions[index];
}

// Function to handle the player moving to a new room
void moveToRoom(int roomIndex) {
    currentRoom = roomIndex;
    currentSteps++;
    
    printf("You walk into the room.\n\n");
    printf("%s\n\n", roomDescriptions[currentRoom]);
    
    // Occasionally print a spooky description
    int chance = rand() % 10; 
    if(chance == 0) {
        printf("%s\n\n", getSpookyDescription());
    }
    
    // If we have reached the last room, end the game
    if(currentRoom == roomCount - 1) {
        printf("You have reached the end of the haunted house!\n");
        endGame = true;
        return;
    }
    
    // If we have taken too many steps, end the game
    if(currentSteps >= maxSteps) {
        printf("You've run out of steps and have become lost in the haunted house...\n");
        endGame = true;
        return;
    }
}

int main() {
    // Seed random number generator
    srand(time(NULL));
    
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You have 10 steps to navigate through the haunted house and reach the end.\n\n");
    
    // Start in the first room
    printf("%s\n\n", roomDescriptions[currentRoom]);
    
    // Main game loop
    while(!endGame) {
        // Ask the player which direction they want to go
        printf("Which direction do you want to go? (north/south/east/west)\n");
        char input[10];
        scanf("%s", input);
        
        int nextRoom = -1;
        
        // Figure out which room the player wants to enter
        if(strcmp(input, "north") == 0) {
            nextRoom = currentRoom + 1;
        }
        else if(strcmp(input, "south") == 0) {
            nextRoom = currentRoom - 1;
        }
        else if(strcmp(input, "east") == 0) {
            nextRoom = currentRoom + 2;
        }
        else if(strcmp(input, "west") == 0) {
            nextRoom = currentRoom - 2;
        }
        else {
            printf("Invalid direction!\n\n");
        }
        
        // If the next room is valid, move to it
        if(nextRoom >= 0 && nextRoom < roomCount) {
            moveToRoom(nextRoom);
        }
    }
    
    printf("Thanks for playing!\n");
    
    return 0;
}