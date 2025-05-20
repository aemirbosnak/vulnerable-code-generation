//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    NORTH,
    EAST,
    SOUTH,
    WEST,
    UP,
    DOWN
} direction;

typedef struct {
    char *name;
    int x, y, z;
    char *description;
} room;

room rooms[] = {
    { "The foyer", 0, 0, 0, "You are in a small, square room with a door to the north." },
    { "The living room", 1, 0, 0, "You are in a large, open room with a fireplace to the north and a door to the east." },
    { "The kitchen", 0, 1, 0, "You are in a small, square room with a stove to the north and a door to the west." },
    { "The dining room", 1, 1, 0, "You are in a large, open room with a table and chairs to the north and a door to the south." },
    { "The master bedroom", 0, 0, 1, "You are in a large, square room with a bed to the north and a door to the west." },
    { "The guest bedroom", 1, 0, 1, "You are in a small, square room with a bed to the north and a door to the east." },
    { "The bathroom", 0, 1, 1, "You are in a small, square room with a toilet to the north and a door to the west." },
    { "The attic", 0, 0, 2, "You are in a large, open room with a window to the north and a door to the south." },
    { "The basement", 0, 1, -1, "You are in a large, open room with a furnace to the north and a door to the south." }
};

int main() {
    int x = 0, y = 0, z = 0;
    int playing = 1;

    while (playing) {
        room *current_room = &rooms[x + y * 3 + z * 9];

        printf("%s\n", current_room->description);

        char input[100];
        scanf("%s", input);

        if (strcmp(input, "north") == 0) {
            if (current_room->z == 2) {
                printf("You cannot go north.\n");
            } else {
                z++;
            }
        } else if (strcmp(input, "east") == 0) {
            if (current_room->y == 1) {
                printf("You cannot go east.\n");
            } else {
                y++;
            }
        } else if (strcmp(input, "south") == 0) {
            if (current_room->z == -1) {
                printf("You cannot go south.\n");
            } else {
                z--;
            }
        } else if (strcmp(input, "west") == 0) {
            if (current_room->x == 0) {
                printf("You cannot go west.\n");
            } else {
                x--;
            }
        } else if (strcmp(input, "up") == 0) {
            if (current_room->z == 2) {
                printf("You cannot go up.\n");
            } else {
                z++;
            }
        } else if (strcmp(input, "down") == 0) {
            if (current_room->z == -1) {
                printf("You cannot go down.\n");
            } else {
                z--;
            }
        } else if (strcmp(input, "quit") == 0) {
            playing = 0;
        } else {
            printf("Invalid input.\n");
        }
    }

    return 0;
}