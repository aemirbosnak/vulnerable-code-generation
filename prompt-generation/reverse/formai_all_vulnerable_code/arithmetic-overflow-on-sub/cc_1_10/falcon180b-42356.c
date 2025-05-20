//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOMS 10
#define GHOSTS 3
#define SCARE_VALUE 50
#define MAX_MOVES 100

// Define struct for rooms
typedef struct {
    char name[30];
    int hasGhost;
} Room;

// Define struct for player
typedef struct {
    char name[30];
    int currentRoom;
    int movesRemaining;
} Player;

// Function to initialize game
void initGame() {
    Room rooms[ROOMS];
    Player player;

    // Initialize all rooms
    for (int i = 0; i < ROOMS; i++) {
        rooms[i].hasGhost = 0;
        sprintf(rooms[i].name, "Room %d", i+1);
    }

    // Initialize player
    player.currentRoom = 1;
    player.movesRemaining = MAX_MOVES;
    strcpy(player.name, "Player");

    // Place ghosts in random rooms
    for (int i = 0; i < GHOSTS; i++) {
        int roomNum = rand() % ROOMS;
        rooms[roomNum].hasGhost = 1;
    }

    // Print game introduction
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are a brave explorer named %s.\n", player.name);
    printf("You have %d moves to explore the house and avoid the ghosts.\n", MAX_MOVES);
    printf("Good luck!\n\n");

    // Start game loop
    int gameOver = 0;
    while (!gameOver) {
        printf("You are currently in Room %s.\n", rooms[player.currentRoom-1].name);
        printf("You have %d moves remaining.\n", player.movesRemaining);

        // Check if player has encountered a ghost
        if (rooms[player.currentRoom-1].hasGhost) {
            printf("There is a ghost in this room!\n");
            player.movesRemaining -= SCARE_VALUE;
        }

        // Check if player has run out of moves
        if (player.movesRemaining <= 0) {
            printf("You have run out of moves and are trapped in the haunted house forever.\n");
            gameOver = 1;
        }

        // Ask player for next move
        printf("Enter your next move (room number): ");
        scanf("%d", &player.currentRoom);

        // Check if move is valid
        if (player.currentRoom < 1 || player.currentRoom > ROOMS) {
            printf("Invalid room number.\n");
            continue;
        }

        // Decrement moves remaining
        player.movesRemaining--;
    }

    // Print game over message
    printf("\nGame Over!\n");
}

int main() {
    srand(time(NULL));
    initGame();
    return 0;
}