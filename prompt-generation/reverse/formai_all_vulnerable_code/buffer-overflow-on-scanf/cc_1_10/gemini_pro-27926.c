//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the haunted house
#define ROOMS 10
#define MAX_SCARES 5

// Create a struct to represent a room
typedef struct {
    int scares;
    int visited;
} Room;

// Create an array of rooms
Room rooms[ROOMS];

// Initialize the haunted house
void init_house() {
    // Set all rooms to have 0 scares and not visited
    for (int i = 0; i < ROOMS; i++) {
        rooms[i].scares = 0;
        rooms[i].visited = 0;
    }

    // Randomly add scares to some rooms
    srand(time(NULL));
    for (int i = 0; i < MAX_SCARES; i++) {
        int room = rand() % ROOMS;
        rooms[room].scares++;
    }
}

// Get the number of scares in a room
int get_scares(int room) {
    return rooms[room].scares;
}

// Set the number of scares in a room
void set_scares(int room, int scares) {
    rooms[room].scares = scares;
}

// Get whether a room has been visited
int is_visited(int room) {
    return rooms[room].visited;
}

// Set whether a room has been visited
void set_visited(int room, int visited) {
    rooms[room].visited = visited;
}

// Print the haunted house
void print_house() {
    for (int i = 0; i < ROOMS; i++) {
        printf("Room %d: %d scares, %s visited\n", i + 1, rooms[i].scares, rooms[i].visited ? "yes" : "no");
    }
}

// Play the haunted house simulator
void play_house() {
    // Initialize the game
    init_house();

    // Get the player's name
    char name[256];
    printf("Enter your name: ");
    scanf("%s", name);

    // Start the game loop
    int room = 0;
    while (room != ROOMS - 1) {
        // Print the current room
        printf("You are in room %d.\n", room + 1);

        // Get the player's input
        int choice;
        printf("Enter your choice: 1 to move forward, 2 to move backward, 3 to quit: ");
        scanf("%d", &choice);

        // Move the player
        switch (choice) {
            case 1:
                if (room < ROOMS - 1) {
                    room++;
                } else {
                    printf("You cannot move forward. You are already in the last room.\n");
                }
                break;
            case 2:
                if (room > 0) {
                    room--;
                } else {
                    printf("You cannot move backward. You are already in the first room.\n");
                }
                break;
            case 3:
                printf("Goodbye, %s!\n", name);
                return;
        }

        // Check if the player has been scared
        if (get_scares(room) > 0) {
            printf("BOO!\n");
            set_scares(room, 0);
        }

        // Mark the room as visited
        set_visited(room, 1);
    }

    // Print the ending message
    printf("Congratulations, %s! You have escaped the haunted house!\n", name);
}

// Main function
int main() {
    // Play the haunted house simulator
    play_house();

    return 0;
}