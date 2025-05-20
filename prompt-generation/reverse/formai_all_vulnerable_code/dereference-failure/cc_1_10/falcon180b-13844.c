//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct room {
    char *description;
    int num_exits;
    struct room **exits;
};

struct room *create_room(char *description, int num_exits, struct room *exits[]) {
    struct room *room = malloc(sizeof(struct room));
    room->description = description;
    room->num_exits = num_exits;
    room->exits = exits;
    return room;
}

void print_room(struct room *room) {
    printf("%s\n", room->description);
}

void move(struct room *current_room, int direction) {
    if (direction == 1) {
        if (current_room->exits[0]!= NULL) {
            current_room = current_room->exits[0];
        } else {
            printf("There is no exit to the north.\n");
        }
    } else if (direction == 2) {
        if (current_room->exits[1]!= NULL) {
            current_room = current_room->exits[1];
        } else {
            printf("There is no exit to the south.\n");
        }
    } else if (direction == 3) {
        if (current_room->exits[2]!= NULL) {
            current_room = current_room->exits[2];
        } else {
            printf("There is no exit to the east.\n");
        }
    } else if (direction == 4) {
        if (current_room->exits[3]!= NULL) {
            current_room = current_room->exits[3];
        } else {
            printf("There is no exit to the west.\n");
        }
    } else {
        printf("Invalid direction.\n");
    }
}

int main() {
    srand(time(NULL));
    int num_rooms = rand() % 10 + 5;
    struct room *rooms[num_rooms];
    int num_exits = rand() % 4 + 1;
    int i, j;

    rooms[0] = create_room("You are in a dark, damp cave. The air is musty and cold. There are passages leading north, south, east, and west.", num_exits, rooms + 1);

    for (i = 1; i < num_rooms; i++) {
        rooms[i] = create_room("This room is empty.", 1, rooms + i);
    }

    int current_room = 0;
    while (1) {
        print_room(rooms[current_room]);
        printf("Which direction would you like to go? ");
        scanf("%d", &i);
        move(rooms[current_room], i);
    }

    return 0;
}