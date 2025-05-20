//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100
#define NUM_ROOMS 5

// Define room structure
typedef struct {
    char description[MAX_LEN];
    char name[MAX_LEN];
    int east;
    int west;
    int north;
    int south;
} Room;

// Initialize rooms with given descriptions and names
Room rooms[NUM_ROOMS] = {
    {"You are in a dark and damp dungeon. The stench of mold fills the air.", "dungeon", -1, 1, -1, -1},
    {"This is a dimly lit room with a large table in the middle. There are books and scrolls scattered around.", "library", 1, -1, -1, -1},
    {"A large room with high ceilings and a throne at the far end. There are guards standing at the entrance.", "throne_room", -1, 1, 1, -1},
    {"A small room with a bed and a chest. There is a key on the bedside table.", "bedroom", -1, 1, -1, 1},
    {"A large open space with a pit in the center. There are bones scattered around the edge.", "bone_pit", 1, -1, -1, -1}
};

// Function to print room description
void print_room_description(int room_num) {
    printf("%s\n", rooms[room_num].description);
}

// Function to print room name
void print_room_name(int room_num) {
    printf("You are in the %s.\n", rooms[room_num].name);
}

// Function to move the player to a new room based on direction
void move_player(int current_room, int direction) {
    int next_room = current_room;

    switch (direction) {
        case 1: // East
            next_room = rooms[current_room].east;
            break;
        case 2: // West
            next_room = rooms[current_room].west;
            break;
        case 3: // North
            next_room = rooms[current_room].north;
            break;
        case 4: // South
            next_room = rooms[current_room].south;
            break;
        default:
            printf("Invalid direction.\n");
            return;
    }

    current_room = next_room;

    print_room_name(current_room);
    print_room_description(current_room);
}

int main() {
    int current_room = 0; // Initialize current room to dungeon
    int direction;

    // Game loop
    while (1) {
        printf("Which direction would you like to go? (1) East, (2) West, (3) North, (4) South: ");
        scanf("%d", &direction);

        if (direction < 1 || direction > 4) {
            continue;
        }

        move_player(current_room, direction);
    }

    return 0;
}