//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Define the maximum number of rooms
#define MAX_ROOMS 10

// Define the structure for a room
typedef struct {
    char name[50];
    bool hasGhost;
    int treasureValue;
} Room;

// Define the structure for the player
typedef struct {
    char name[50];
    int currentRoom;
    int treasureCollected;
} Player;

// Function to initialize the game
void initializeGame(Room rooms[MAX_ROOMS], Player player) {
    // Set the initial room for the player
    player.currentRoom = 0;

    // Set the name of the player
    strcpy(player.name, "Player");

    // Populate the rooms with random ghosts and treasures
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].hasGhost = rand() % 2;
        rooms[i].treasureValue = rand() % 100;
    }
}

// Function to print the current room details
void printRoomDetails(Room room, Player player) {
    printf("You are in the %s.\n", room.name);

    if (room.hasGhost) {
        printf("There is a ghost here!\n");
    } else {
        printf("There is no ghost here.\n");
    }

    if (room.treasureValue > 0) {
        printf("You found a treasure worth %d points!\n", room.treasureValue);
        player.treasureCollected += room.treasureValue;
    }
}

// Function to move the player to the next room
void movePlayer(Room rooms[MAX_ROOMS], Player player) {
    if (player.currentRoom >= MAX_ROOMS - 1) {
        printf("Congratulations! You have reached the end of the haunted house.\n");
        exit(0);
    } else {
        player.currentRoom++;
    }
}

// Function to check if the player has collected all the treasures
bool checkIfWon(Player player) {
    return player.treasureCollected == 1000;
}

// Main function
int main() {
    // Initialize the random seed
    srand(time(0));

    // Initialize the rooms and the player
    Room rooms[MAX_ROOMS];
    Player player;

    // Initialize the game
    initializeGame(rooms, player);

    // Main game loop
    while (true) {
        // Print the current room details
        printRoomDetails(rooms[player.currentRoom], player);

        // Check if the player has won
        if (checkIfWon(player)) {
            printf("You have collected all the treasures and won the game!\n");
            break;
        }

        // Move the player to the next room
        movePlayer(rooms, player);
    }

    return 0;
}