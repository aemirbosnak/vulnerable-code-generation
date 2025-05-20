//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_ROOM_DESC_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_ROOM_DESC_LEN];
    struct Room *north;
    struct Room *south;
    struct Room *east;
    struct Room *west;
} Room;

Room rooms[] = {
    { "The foyer", "A grand foyer with a marble floor and a sweeping staircase.", NULL, NULL, NULL, NULL },
    { "The ballroom", "A spacious ballroom with a high ceiling and crystal chandeliers.", NULL, NULL, NULL, NULL },
    { "The dining room", "A large dining room with a long mahogany table and velvet chairs.", NULL, NULL, NULL, NULL },
    { "The library", "A cozy library with shelves full of books and a crackling fire in the fireplace.", NULL, NULL, NULL, NULL },
    { "The garden", "A beautiful garden with fragrant flowers and a bubbling fountain.", NULL, NULL, NULL, NULL },
};

int num_rooms = sizeof(rooms) / sizeof(rooms[0]);

Room *current_room;

void print_room_description() {
    printf("%s\n", current_room->description);
}

void move(char *direction) {
    if (strcmp(direction, "north") == 0) {
        if (current_room->north != NULL) {
            current_room = current_room->north;
            print_room_description();
        } else {
            printf("There is no door to the north.\n");
        }
    } else if (strcmp(direction, "south") == 0) {
        if (current_room->south != NULL) {
            current_room = current_room->south;
            print_room_description();
        } else {
            printf("There is no door to the south.\n");
        }
    } else if (strcmp(direction, "east") == 0) {
        if (current_room->east != NULL) {
            current_room = current_room->east;
            print_room_description();
        } else {
            printf("There is no door to the east.\n");
        }
    } else if (strcmp(direction, "west") == 0) {
        if (current_room->west != NULL) {
            current_room = current_room->west;
            print_room_description();
        } else {
            printf("There is no door to the west.\n");
        }
    } else {
        printf("Invalid direction.\n");
    }
}

int main() {
    char name[MAX_NAME_LEN];
    char input[100];

    printf("What is your name, fair maiden?\n");
    scanf("%s", name);

    printf("Welcome to the castle, %s. I am your humble servant, Jeeves.\n", name);

    current_room = &rooms[0];
    print_room_description();

    while (1) {
        printf("> ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        } else if (strcmp(input, "north") == 0 || strcmp(input, "south") == 0 || strcmp(input, "east") == 0 || strcmp(input, "west") == 0) {
            move(input);
        } else {
            printf("Invalid command.\n");
        }
    }

    printf("Thank you for playing, %s. Come again soon!\n", name);

    return 0;
}