//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of rooms in the haunted house
#define NUM_ROOMS 10

// Define the maximum number of ghosts that can appear in a room
#define MAX_GHOSTS 3

// Define the structure of a room
typedef struct {
    char name[50];
    int num_ghosts;
    int is_visited;
} Room;

// Initialize the haunted house with random ghosts
void init_house(Room rooms[]) {
    srand(time(NULL));

    for (int i = 0; i < NUM_ROOMS; i++) {
        rooms[i].num_ghosts = rand() % MAX_GHOSTS + 1;
        rooms[i].is_visited = 0;
    }
}

// Print the current state of the haunted house
void print_house(Room rooms[]) {
    for (int i = 0; i < NUM_ROOMS; i++) {
        printf("%s: %d ghosts\n", rooms[i].name, rooms[i].num_ghosts);
    }
}

// Move the player to a new room
void move_player(Room rooms[], int current_room, int new_room) {
    if (new_room >= 0 && new_room < NUM_ROOMS) {
        current_room = new_room;
        rooms[current_room].is_visited = 1;
    } else {
        printf("Invalid room number.\n");
    }
}

// Main function of the haunted house simulator
int main() {
    Room rooms[NUM_ROOMS];
    int current_room = 0;

    // Initialize the haunted house with random ghosts
    init_house(rooms);

    // Print the current state of the haunted house
    printf("Welcome to the haunted house!\n\n");
    print_house(rooms);

    // Main game loop
    while (1) {
        printf("\nYou are in room %s.\n", rooms[current_room].name);

        // Ask the player for input
        char input[50];
        printf("What do you want to do? ");
        fgets(input, 50, stdin);

        // Parse the player's input
        if (strcmp(input, "move") == 0) {
            int new_room;
            printf("Enter the room number: ");
            scanf("%d", &new_room);
            move_player(rooms, current_room, new_room);
        } else if (strcmp(input, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }

        // Print the current state of the haunted house
        print_house(rooms);
    }

    return 0;
}