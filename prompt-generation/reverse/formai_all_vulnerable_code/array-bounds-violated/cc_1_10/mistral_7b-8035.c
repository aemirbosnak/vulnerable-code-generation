//MISTRAL-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 25
#define HEIGHT 10
#define DEPTH 5
#define NUM_ROOMS 3
#define ROOM_SIZE 10

typedef struct {
    int x, y, width, height;
} Room;

typedef struct {
    int x, y, width, height;
    int isDoor;
} Door;

typedef struct {
    int x, y;
    int isPlayer;
} Player;

Room rooms[NUM_ROOMS];
Door doors[NUM_ROOMS * 2];
Player player;

void generate_rooms() {
    int x, y, room_index = 0;
    for (int i = 0; i < NUM_ROOMS; i++) {
        do {
            x = rand() % (WIDTH - ROOM_SIZE) + 1;
            y = rand() % (HEIGHT - DEPTH) + 1;
        } while (is_room_overlapping(x, y, &rooms[room_index]));

        rooms[room_index].x = x;
        rooms[room_index].y = y;
        rooms[room_index].width = ROOM_SIZE;
        rooms[room_index].height = ROOM_SIZE;

        room_index++;
    }
}

void generate_doors() {
    int room_index = 0, door_index = 0;
    for (int i = 0; i < NUM_ROOMS * 2; i++) {
        if (i % 2 == 0) {
            doors[door_index].x = rooms[room_index].x + rooms[room_index].width / 2;
            doors[door_index].y = rooms[room_index].y;
            doors[door_index].width = 2;
            doors[door_index].height = rooms[room_index].height;
            doors[door_index].isDoor = 1;
            room_index++;
        } else {
            doors[door_index].x = rooms[room_index - 1].x + rooms[room_index - 1].width + 1;
            doors[door_index].y = rooms[room_index - 1].y + rooms[room_index - 1].height / 2;
            doors[door_index].width = 2;
            doors[door_index].height = 2;
            doors[door_index].isDoor = 1;
            room_index++;
        }
        door_index++;
    }
}

int is_room_overlapping(int x, int y, Room *room) {
    for (int i = 0; i < NUM_ROOMS; i++) {
        if (rooms[i].x <= x && x < rooms[i].x + rooms[i].width &&
            rooms[i].y <= y && y < rooms[i].y + rooms[i].height) {
            return 1;
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));
    generate_rooms();
    generate_doors();

    // Initialize the game here

    while (1) {
        // Game loop here
    }

    return 0;
}