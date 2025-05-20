//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_ROOMS 10
#define MAX_ROOM_NAME_LENGTH 20

// Room struct
typedef struct {
    char name[MAX_ROOM_NAME_LENGTH + 1];
    int has_ghost;
} Room;

// Array of rooms
Room rooms[NUM_ROOMS];

int current_room = 0; // Starting room

// Function declarations
void init_rooms();
void print_current_room();
void simulate_ghost_encounter();

int main() {
    init_rooms();

    printf("Welcome to the Haunted House Simulator!\n");

    while(1) {
        // Print current room and ask for user input
        print_current_room();

        char input;
        printf("What would you like to do? (m) Move to another room, (q) Quit: ");
        scanf(" %c", &input);

        switch(input) {
            case 'm':
                // Move to a random room
                srand(time(NULL));
                current_room = rand() % NUM_ROOMS;
                if(rooms[current_room].has_ghost) {
                    // Simulate ghost encounter
                    simulate_ghost_encounter();
                }
                break;
            case 'q':
                // Quit
                printf("Thank you for playing the Haunted House Simulator!\n");
                exit(0);
            default:
                // Invalid input
                printf("Invalid input. Try again.\n");
        }
    }

    return 0;
}

// Initialize the rooms with names and randomly assign ghosts
void init_rooms() {
    char names[NUM_ROOMS][MAX_ROOM_NAME_LENGTH] = {
        "Living Room",
        "Kitchen",
        "Bedroom 1",
        "Bathroom 1",
        "Playroom",
        "Office",
        "Bedroom 2",
        "Bathroom 2",
        "Basement",
        "Attic"
    };

    for(int i = 0; i < NUM_ROOMS; i++) {
        // Copy room name
        for(int j = 0; j < MAX_ROOM_NAME_LENGTH; j++) {
            rooms[i].name[j] = names[i][j];
        }
        // Randomly assign ghost
        srand(i);
        rooms[i].has_ghost = rand() % 2;
    }
}

// Print the current room
void print_current_room() {
    printf("You are currently in the %s.\n", rooms[current_room].name);
    if(rooms[current_room].has_ghost) {
        printf("WARNING: This room has a ghost!\n");
    }
}

// Simulate a ghost encounter
void simulate_ghost_encounter() {
    printf("Oh no! You have encountered a ghost in the %s.\n", rooms[current_room].name);
    printf("Press any key to run away...\n");
    getchar(); // Wait for user input
    printf("You have escaped! Whew!\n");
}