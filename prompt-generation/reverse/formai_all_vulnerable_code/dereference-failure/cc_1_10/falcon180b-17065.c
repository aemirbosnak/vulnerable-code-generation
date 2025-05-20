//Falcon-180B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum size of the dungeon
#define MAX_ROOMS 100
#define MAX_ROOM_SIZE 20

// Define the structure for a room
typedef struct {
    int x;
    int y;
    int w;
    int h;
} Room;

// Define the structure for the dungeon
typedef struct {
    Room *rooms;
    int num_rooms;
} Dungeon;

// Function to generate a random number between min and max
int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to create a new room at the given position
void create_room(Dungeon *dungeon, int x, int y, int w, int h) {
    Room *room = &dungeon->rooms[dungeon->num_rooms];
    room->x = x;
    room->y = y;
    room->w = w;
    room->h = h;
    dungeon->num_rooms++;
}

// Function to generate a new dungeon with the given size
Dungeon generate_dungeon(int w, int h) {
    Dungeon dungeon;
    dungeon.num_rooms = 0;
    dungeon.rooms = malloc(MAX_ROOMS * sizeof(Room));

    // Create the first room
    create_room(&dungeon, 0, 0, w, h);

    // Fill the dungeon with rooms
    while (dungeon.num_rooms < MAX_ROOMS) {
        int num_attempts = 0;
        while (num_attempts < 100) {
            int x = rand_range(0, w - 1);
            int y = rand_range(0, h - 1);
            int w = rand_range(1, MAX_ROOM_SIZE);
            int h = rand_range(1, MAX_ROOM_SIZE);

            if (check_collision(&dungeon, x, y, w, h)) {
                num_attempts++;
            } else {
                create_room(&dungeon, x, y, w, h);
                num_attempts = 0;
            }
        }
    }

    return dungeon;
}

// Function to check if a room at the given position would collide with an existing room
int check_collision(Dungeon *dungeon, int x, int y, int w, int h) {
    for (int i = 0; i < dungeon->num_rooms; i++) {
        Room *room = &dungeon->rooms[i];
        if ((x >= room->x && x < room->x + room->w) &&
            (y >= room->y && y < room->y + room->h)) {
            return 1;
        }
    }
    return 0;
}

// Function to print the dungeon
void print_dungeon(Dungeon dungeon) {
    for (int i = 0; i < dungeon.num_rooms; i++) {
        Room *room = &dungeon.rooms[i];
        for (int j = room->x; j < room->x + room->w; j++) {
            for (int k = room->y; k < room->y + room->h; k++) {
                printf("#");
            }
            printf("\n");
        }
        printf("\n");
    }
}

// Function to free the memory used by the dungeon
void free_dungeon(Dungeon dungeon) {
    free(dungeon.rooms);
}

int main() {
    srand(time(NULL));

    Dungeon dungeon = generate_dungeon(80, 25);
    print_dungeon(dungeon);

    free_dungeon(dungeon);

    return 0;
}