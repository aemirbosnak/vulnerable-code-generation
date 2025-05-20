//MISTRAL-7B DATASET v1.0 Category: Haunted House Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_ROOM 10
#define MAX_OBJ 5

typedef struct {
    char name[20];
    int x, y;
} Room;

typedef struct {
    char name[20];
    int weight;
    Room *location;
} Object;

typedef struct {
    Room rooms[MAX_ROOM];
    Object obj[MAX_OBJ];
    int num_room, num_obj;
} HauntedHouse;

void init_house(HauntedHouse *hh) {
    srand(time(NULL));
    hh->num_room = 0;
    hh->num_obj = 0;

    // Initialize rooms
    for (int i = 0; i < MAX_ROOM; i++) {
        strcpy(hh->rooms[i].name, "Room ");
        sprintf(hh->rooms[i].name + strlen(hh->rooms[i].name), "%d", i + 1);
        hh->rooms[i].x = rand() % 10 + 1;
        hh->rooms[i].y = rand() % 10 + 1;
        hh->num_room++;
    }

    // Initialize objects
    for (int i = 0; i < MAX_OBJ; i++) {
        strcpy(hh->obj[i].name, "Object ");
        sprintf(hh->obj[i].name + strlen(hh->obj[i].name), "%d", i + 1);
        hh->obj[i].weight = rand() % 5 + 1;
        hh->obj[i].location = NULL;
        hh->num_obj++;
    }

    // Assign objects to rooms randomly
    for (int i = 0; i < hh->num_obj; i++) {
        int room_idx = rand() % hh->num_room;
        hh->obj[i].location = &hh->rooms[room_idx];
    }
}

void print_house(HauntedHouse hh) {
    for (int i = 0; i < hh.num_room; i++) {
        printf("%s:\n", hh.rooms[i].name);
        printf("X: %d, Y: %d\n", hh.rooms[i].x, hh.rooms[i].y);
        if (hh.obj[i].location == &hh.rooms[i]) {
            printf("%s (Weight: %d)\n", hh.obj[i].name, hh.obj[i].weight);
        }
    }
}

int main() {
    HauntedHouse hh;
    init_house(&hh);
    print_house(hh);
    return 0;
}