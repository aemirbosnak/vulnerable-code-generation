//Falcon2-11B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20
#define MAX_ROOMS 100

// Define a room structure to store room information
typedef struct {
    int x, y;
    int width, height;
} Room;

// Define a dungeon structure to store dungeon information
typedef struct {
    Room rooms[MAX_ROOMS];
    int num_rooms;
} Dungeon;

// Function to generate a random room
Room generate_room(int x, int y, int width, int height) {
    Room room;
    room.x = x;
    room.y = y;
    room.width = width;
    room.height = height;
    return room;
}

// Function to generate a dungeon
Dungeon generate_dungeon(int width, int height) {
    Dungeon dungeon;
    dungeon.num_rooms = 0;

    // Generate a random number of rooms
    int num_rooms = rand() % (MAX_ROOMS + 1);
    while (num_rooms--) {
        int x = rand() % width;
        int y = rand() % height;
        int width = rand() % (width / 2) + 1;
        int height = rand() % (height / 2) + 1;

        // Check for overlap with existing rooms
        for (int i = 0; i < dungeon.num_rooms; i++) {
            if (x >= dungeon.rooms[i].x && x <= dungeon.rooms[i].x + dungeon.rooms[i].width &&
                y >= dungeon.rooms[i].y && y <= dungeon.rooms[i].y + dungeon.rooms[i].height) {
                continue;
            }
        }

        // Add the new room to the dungeon
        dungeon.rooms[dungeon.num_rooms] = generate_room(x, y, width, height);
        dungeon.num_rooms++;
    }

    return dungeon;
}

// Function to print the dungeon
void print_dungeon(Dungeon dungeon) {
    for (int y = 0; y < dungeon.num_rooms; y++) {
        for (int x = 0; x < dungeon.num_rooms; x++) {
            Room room = dungeon.rooms[y];
            printf("%c", room.x == x? '#' : '.');
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    // Generate a dungeon
    Dungeon dungeon = generate_dungeon(ROWS, COLS);

    // Print the dungeon
    printf("Dungeon:\n");
    print_dungeon(dungeon);

    return 0;
}