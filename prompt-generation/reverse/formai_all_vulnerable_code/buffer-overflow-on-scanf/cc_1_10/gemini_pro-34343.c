//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_DESC_LEN 256

typedef struct {
    char *description;
    int north;
    int south;
    int east;
    int west;
} Room;

Room rooms[MAX_ROOMS];
int current_room;

void init_rooms() {
    rooms[0].description = "You are in a dark and musty dungeon. The walls are cold and damp, and the air is heavy with the smell of decay.";
    rooms[0].north = 1;
    rooms[0].south = -1;
    rooms[0].east = -1;
    rooms[0].west = -1;

    rooms[1].description = "You are in a small, dimly lit room. There is a single window on the north wall, and a door on the south wall.";
    rooms[1].north = -1;
    rooms[1].south = 0;
    rooms[1].east = 2;
    rooms[1].west = -1;

    rooms[2].description = "You are in a large, open room. There are several doors in the room, and a staircase in the center.";
    rooms[2].north = -1;
    rooms[2].south = -1;
    rooms[2].east = 3;
    rooms[2].west = 1;

    rooms[3].description = "You are in a small, windowless room. There is a single door on the west wall.";
    rooms[3].north = -1;
    rooms[3].south = -1;
    rooms[3].east = -1;
    rooms[3].west = 2;
}

void print_room_description() {
    printf("%s\n", rooms[current_room].description);
}

void get_command(char *command) {
    printf("> ");
    scanf("%s", command);
}

int main() {
    init_rooms();
    current_room = 0;

    char command[MAX_DESC_LEN];

    while (strcmp(command, "quit") != 0) {
        print_room_description();
        get_command(command);

        if (strcmp(command, "north") == 0) {
            if (rooms[current_room].north != -1) {
                current_room = rooms[current_room].north;
            } else {
                printf("You can't go that way!\n");
            }
        } else if (strcmp(command, "south") == 0) {
            if (rooms[current_room].south != -1) {
                current_room = rooms[current_room].south;
            } else {
                printf("You can't go that way!\n");
            }
        } else if (strcmp(command, "east") == 0) {
            if (rooms[current_room].east != -1) {
                current_room = rooms[current_room].east;
            } else {
                printf("You can't go that way!\n");
            }
        } else if (strcmp(command, "west") == 0) {
            if (rooms[current_room].west != -1) {
                current_room = rooms[current_room].west;
            } else {
                printf("You can't go that way!\n");
            }
        } else if (strcmp(command, "quit") == 0) {
            printf("Goodbye!\n");
            // Exits the game!
        } else {
            printf("I don't understand that command.\n");
        }
    }

    return 0;
}