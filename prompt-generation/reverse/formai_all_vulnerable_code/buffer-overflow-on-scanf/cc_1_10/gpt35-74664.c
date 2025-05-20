//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10 // Maximum number of rooms in the haunted house
#define MAX_GHOSTS 5 // Maximum number of ghosts in the haunted house

typedef struct Room {
    int id;
    int isExit;
    int numGhosts;
    int ghostIDs[MAX_GHOSTS];
} Room;

// Function to generate a random number between min and max
int randomInRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to check if a ghost is present in the room
int isGhostPresent(int ghostID, Room room) {
    for (int i = 0; i < room.numGhosts; i++) {
        if (room.ghostIDs[i] == ghostID) {
            return 1;
        }
    }
    return 0;
}

// Function to configure the haunted house
void configureHauntedHouse(Room rooms[], int numRooms, int numGhosts) {
    // Assign random IDs to each room
    for (int i = 0; i < numRooms; i++) {
        rooms[i].id = i + 1;
    }
    // Assign random exits to some of the rooms
    int numExits = randomInRange(1, numRooms);
    for (int i = 0; i < numExits; i++) {
        int exitRoom = randomInRange(0, numRooms - 1);
        rooms[exitRoom].isExit = 1;
    }
    // Assign ghosts to random rooms
    for (int i = 0; i < numGhosts; i++) {
        int ghostRoom = randomInRange(0, numRooms - 1);
        rooms[ghostRoom].ghostIDs[rooms[ghostRoom].numGhosts] = i + 1;
        rooms[ghostRoom].numGhosts++;
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    Room rooms[MAX_ROOMS];
    
    // Ask user for number of rooms and ghosts
    int numRooms, numGhosts;
    printf("Enter the number of rooms in the haunted house (1-%d): ", MAX_ROOMS);
    scanf("%d", &numRooms);
    printf("Enter the number of ghosts in the haunted house (1-%d): ", MAX_GHOSTS);
    scanf("%d", &numGhosts);
    
    // Validate user input
    if (numRooms < 1 || numRooms > MAX_ROOMS) {
        printf("Invalid number of rooms!\n");
        return 1;
    }
    if (numGhosts < 1 || numGhosts > MAX_GHOSTS) {
        printf("Invalid number of ghosts!\n");
        return 1;
    }
    
    // Configure the haunted house
    configureHauntedHouse(rooms, numRooms, numGhosts);
    
    // Simulation loop
    int currentRoom = 0; // Start in room 1
    while (!rooms[currentRoom].isExit) {
        // Print room description
        printf("You are in room %d. ", rooms[currentRoom].id);
        if (rooms[currentRoom].numGhosts == 0) {
            printf("There are no ghosts in this room.\n");
        } else {
            printf("There %s %d ghost%s in this room.\n", 
                   (rooms[currentRoom].numGhosts == 1 ? "is" : "are"),
                   rooms[currentRoom].numGhosts,
                   (rooms[currentRoom].numGhosts == 1 ? "" : "s"));
        }
        // Ask user for direction
        int direction;
        printf("Which direction do you want to go (1-%d)? ", numRooms);
        scanf("%d", &direction);
        // Validate user input
        if (direction < 1 || direction > numRooms) {
            printf("Invalid direction!\n");
            continue;
        }
        // Check if there is a ghost in the current room
        int currentGhost = 0;
        if (rooms[currentRoom].numGhosts > 0) {
            currentGhost = rooms[currentRoom].ghostIDs[randomInRange(0, rooms[currentRoom].numGhosts - 1)];
            printf("You encountered ghost %d in this room!\n", currentGhost);
        }
        // Move to the new room
        currentRoom = direction - 1;
        // Check if there is a ghost in the new room
        if (isGhostPresent(currentGhost, rooms[currentRoom])) {
            printf("The ghost follows you to the new room!\n");
        }
    }
    printf("Congratulations, you escaped the haunted house!\n");
    
    return 0;
}