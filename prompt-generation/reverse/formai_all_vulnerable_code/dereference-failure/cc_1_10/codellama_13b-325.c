//Code Llama-13B DATASET v1.0 Category: Text-Based Adventure Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define MAX_COMMANDS 100
#define MAX_INPUT_SIZE 100

// Structures
typedef struct {
    char *name;
    char *description;
    char *command;
} room_t;

typedef struct {
    char *name;
    char *description;
    char *command;
    int (*func)(room_t *);
} action_t;

// Functions
int describe_room(room_t *room) {
    printf("You are in %s.\n", room->name);
    printf("%s\n", room->description);
    return 0;
}

int go_north(room_t *room) {
    printf("You go north.\n");
    return 0;
}

int go_south(room_t *room) {
    printf("You go south.\n");
    return 0;
}

int go_east(room_t *room) {
    printf("You go east.\n");
    return 0;
}

int go_west(room_t *room) {
    printf("You go west.\n");
    return 0;
}

int main() {
    room_t rooms[MAX_COMMANDS] = {
        {"the entrance", "You are at the entrance of a dungeon. There are doors to the north, south, east, and west.", "north", go_north},
        {"the hallway", "You are in a long hallway with doors to the north and south.", "north", go_north},
        {"the first room", "You are in a room with a table and a door to the east.", "east", go_east},
        {"the second room", "You are in a room with a bed and a door to the west.", "west", go_west},
        {"the dungeon", "You are in the dungeon. There are doors to the north, south, east, and west.", "north", go_north},
    };

    action_t actions[MAX_COMMANDS] = {
        {"look", "Look around you.", NULL, describe_room},
        {"north", "Go north.", "north", go_north},
        {"south", "Go south.", "south", go_south},
        {"east", "Go east.", "east", go_east},
        {"west", "Go west.", "west", go_west},
    };

    int current_room = 0;
    char input[MAX_INPUT_SIZE];

    while (1) {
        printf("> ");
        fgets(input, MAX_INPUT_SIZE, stdin);

        if (input[0] == '\n') {
            printf("Invalid input.\n");
            continue;
        }

        for (int i = 0; i < MAX_COMMANDS; i++) {
            if (strcmp(input, actions[i].command) == 0) {
                actions[i].func(&rooms[current_room]);
                current_room = i;
                break;
            }
        }
    }

    return 0;
}