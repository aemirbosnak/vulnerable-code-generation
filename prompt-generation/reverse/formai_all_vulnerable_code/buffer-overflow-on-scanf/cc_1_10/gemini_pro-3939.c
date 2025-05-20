//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10

typedef struct {
    char *name;
    char *description;
    int north;
    int south;
    int east;
    int west;
} Room;

Room rooms[MAX_ROOMS];
int current_room = 0;

void create_room(int room_number, char *name, char *description, int north, int south, int east, int west) {
    rooms[room_number].name = name;
    rooms[room_number].description = description;
    rooms[room_number].north = north;
    rooms[room_number].south = south;
    rooms[room_number].east = east;
    rooms[room_number].west = west;
}

void print_room(int room_number) {
    printf("%s\n", rooms[room_number].name);
    printf("%s\n", rooms[room_number].description);
}

int main() {
    create_room(0, "The Great Hall", "A large hall with a high ceiling and a long table in the center.", 1, 2, 3, 4);
    create_room(1, "The North Room", "A small room with a single window.", 0, -1, -1, -1);
    create_room(2, "The South Room", "A small room with a single door.", -1, 0, -1, -1);
    create_room(3, "The East Room", "A small room with a single window.", -1, -1, 0, -1);
    create_room(4, "The West Room", "A small room with a single door.", -1, -1, -1, 0);

    print_room(current_room);

    while (1) {
        char input[10];
        printf("> ");
        scanf("%s", input);

        if (strcmp(input, "north") == 0) {
            if (rooms[current_room].north != -1) {
                current_room = rooms[current_room].north;
                print_room(current_room);
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(input, "south") == 0) {
            if (rooms[current_room].south != -1) {
                current_room = rooms[current_room].south;
                print_room(current_room);
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(input, "east") == 0) {
            if (rooms[current_room].east != -1) {
                current_room = rooms[current_room].east;
                print_room(current_room);
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(input, "west") == 0) {
            if (rooms[current_room].west != -1) {
                current_room = rooms[current_room].west;
                print_room(current_room);
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(input, "quit") == 0) {
            break;
        } else {
            printf("I don't understand.\n");
        }
    }

    return 0;
}