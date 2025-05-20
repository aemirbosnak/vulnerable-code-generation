//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROOMS 10

typedef struct {
    char *name;
    int num_exits;
    int *exits;
} Room;

void init_rooms(Room rooms[NUM_ROOMS]) {
    int i;
    for (i = 0; i < NUM_ROOMS; i++) {
        rooms[i].name = malloc(20 * sizeof(char));
        sprintf(rooms[i].name, "Room %d", i + 1);
        rooms[i].num_exits = rand() % 3 + 1;
        rooms[i].exits = malloc(rooms[i].num_exits * sizeof(int));
        int j;
        for (j = 0; j < rooms[i].num_exits; j++) {
            rooms[i].exits[j] = rand() % NUM_ROOMS;
        }
    }
}

void print_room(Room room) {
    printf("You are in %s.\n", room.name);
    printf("There are %d doors:\n", room.num_exits);
    int i;
    for (i = 0; i < room.num_exits; i++) {
        printf("  Door %d leads to Room %d\n", i + 1, room.exits[i]);
    }
}

int main() {
    srand(time(NULL));
    Room rooms[NUM_ROOMS];
    init_rooms(rooms);

    int player_room = 0;
    while (1) {
        print_room(rooms[player_room]);
        int choice;
        printf("What door do you choose? ");
        scanf("%d", &choice);
        if (choice < 1 || choice > rooms[player_room].num_exits) {
            printf("Invalid choice.\n");
        } else {
            player_room = rooms[player_room].exits[choice - 1];
        }
    }

    return 0;
}