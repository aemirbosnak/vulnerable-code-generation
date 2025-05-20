//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_ROOMS 10

typedef struct room {
    int num;
    bool visited;
    bool has_monster;
} room_t;

room_t rooms[NUM_ROOMS];

void init_rooms() {
    for (int i = 0; i < NUM_ROOMS; i++) {
        rooms[i].num = i;
        rooms[i].visited = false;
        rooms[i].has_monster = false;
    }

    srand(time(NULL));
    for (int i = 0; i < NUM_ROOMS / 2; i++) {
        int room = rand() % NUM_ROOMS;
        rooms[room].has_monster = true;
    }
}

void print_rooms() {
    for (int i = 0; i < NUM_ROOMS; i++) {
        printf("Room %d: %s\n", rooms[i].num, rooms[i].visited ? "Visited" : "Unvisited");
        if (rooms[i].has_monster) {
            printf("  - Monster: Yes\n");
        }
    }
}

int main() {
    init_rooms();
    print_rooms();

    int current_room = 0;
    bool game_over = false;

    while (!game_over) {
        // Get user input
        printf("Enter a room number (0-%d): ", NUM_ROOMS - 1);
        int room;
        scanf("%d", &room);

        // Check if the room is valid
        if (room < 0 || room >= NUM_ROOMS) {
            printf("Invalid room number.\n");
            continue;
        }

        // Check if the room has been visited
        if (rooms[room].visited) {
            printf("You have already visited this room.\n");
            continue;
        }

        // Mark the room as visited
        rooms[room].visited = true;

        // Check if the room has a monster
        if (rooms[room].has_monster) {
            printf("You have encountered a monster!\n");
            game_over = true;
            break;
        }

        // Update the current room
        current_room = room;

        // Print the rooms
        print_rooms();
    }

    if (game_over) {
        printf("Game over!\n");
    } else {
        printf("You have escaped the haunted house!\n");
    }

    return 0;
}