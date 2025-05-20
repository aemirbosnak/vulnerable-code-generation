//Falcon-180B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25
#define MAX_ROOMS 100

// Define structure for a room
typedef struct {
    int x;
    int y;
    int width;
    int height;
} Room;

// Define structure for a door
typedef struct {
    int x;
    int y;
} Door;

// Define structure for a dungeon
typedef struct {
    Room rooms[MAX_ROOMS];
    int num_rooms;
} Dungeon;

// Function to create a new room
void create_room(Dungeon *dungeon, int x, int y, int width, int height) {
    Room room = {x, y, width, height};
    dungeon->rooms[dungeon->num_rooms++] = room;
}

// Function to generate a dungeon
void generate_dungeon(Dungeon *dungeon) {
    srand(time(NULL));
    int num_rooms = rand() % MAX_ROOMS + 1;
    for(int i = 0; i < num_rooms; i++) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        int width = rand() % (WIDTH / 2) + 3;
        int height = rand() % (HEIGHT / 2) + 3;
        create_room(dungeon, x, y, width, height);
    }
}

// Function to print a room
void print_room(Room room) {
    for(int i = room.x; i < room.x + room.width; i++) {
        for(int j = room.y; j < room.y + room.height; j++) {
            printf("#");
        }
        printf("\n");
    }
}

// Function to print a dungeon
void print_dungeon(Dungeon dungeon) {
    for(int i = 0; i < dungeon.num_rooms; i++) {
        print_room(dungeon.rooms[i]);
    }
}

int main() {
    Dungeon dungeon;
    generate_dungeon(&dungeon);
    print_dungeon(dungeon);
    return 0;
}