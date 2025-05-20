//MISTRAL-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 100
#define NUM_ROOMS 5

typedef struct {
    char description[MAX_LINE];
    char exits[NUM_ROOMS][20];
    int has_treasure;
} Room;

Room rooms[NUM_ROOMS] = {
    {
        "You are in the entrance hall of the mansion. There are doors to the north, east, and west.",
        {"north", "east", "west"},
        0
    },
    {
        "This is a dark library. The shelves are filled with dusty books. There is a door to the south.",
        {"south"},
        1
    },
    {
        "This is a dusty drawing room. There is a door to the east.",
        {"east"},
        0
    },
    {
        "This is a long, dark corridor. There are doors to the north and south.",
        {"north", "south"},
        0
    },
    {
        "You have found the treasure room! Congratulations!",
        {""},
        1
    }
};

void look(int room) {
    printf("%s\n", rooms[room].description);
}

void go(int current_room, char *direction) {
    int next_room = -1;
    int i;

    for (i = 0; i < NUM_ROOMS; i++) {
        if (strcmp(rooms[current_room].exits[i], direction) == 0) {
            next_room = i;
            break;
        }
    }

    if (next_room == -1) {
        printf("There is no exit in that direction.\n");
    } else {
        look(next_room);
    }
}

int main() {
    int current_room = 0;
    char direction[20];

    while (1) {
        look(current_room);
        printf("Where would you like to go? (north, south, east, west): ");
        scanf("%s", direction);

        go(current_room, direction);

        if (rooms[current_room].has_treasure) {
            printf("Congratulations! You have found the treasure.\n");
            break;
        }
    }

    return 0;
}