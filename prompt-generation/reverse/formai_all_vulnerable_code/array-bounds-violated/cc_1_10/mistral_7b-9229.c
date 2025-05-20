//MISTRAL-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10
#define MAX_ROOM 5
#define ROOM_MIN_SIZE 3
#define ROOM_MAX_SIZE 10

typedef struct {
    int x, y, w, h;
} Room;

Room rooms[MAX_ROOM];
int room_count = 0;

int rnd(int max) {
    return rand() % max;
}

void generate_room(Room *room, int x, int y) {
    room->x = x;
    room->y = y;
    room->w = rnd(ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
    room->h = rnd(ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;

    while (room_count > 0 && (room->x < rooms[room_count - 1].x + rooms[room_count - 1].w ||
                              room->x + room->w > rooms[room_count - 1].x + rooms[room_count - 1].w ||
                              room->y < rooms[room_count - 1].y + rooms[room_count - 1].h ||
                              room->y + room->h > rooms[room_count - 1].y + rooms[room_count - 1].h)) {
        room->x = x;
        room->y = y;
        room->w = rnd(ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
        room->h = rnd(ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
    }

    room_count++;
}

void print_map(int map[WIDTH][HEIGHT]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            putchar(map[x][y] == 0 ? '.' : '#');
        }
        putchar('\n');
    }
}

int main() {
    srand(time(NULL));

    int map[WIDTH][HEIGHT] = { 0 };

    for (int i = 0; i < MAX_ROOM; i++) {
        generate_room(&rooms[i], rnd(WIDTH), rnd(HEIGHT));
        for (int j = rooms[i].y; j < rooms[i].y + rooms[i].h; j++) {
            for (int k = rooms[i].x; k < rooms[i].x + rooms[i].w; k++) {
                map[k][j] = 1;
            }
        }
    }

    print_map(map);

    return 0;
}