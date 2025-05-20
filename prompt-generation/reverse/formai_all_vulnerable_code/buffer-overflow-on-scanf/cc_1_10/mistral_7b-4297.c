//MISTRAL-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define NUM_CHOICES 3
#define NUM_ROOMS 4

typedef struct {
    char description[MAX_LENGTH];
    char* exits[NUM_CHOICES];
} Room;

Room rooms[NUM_ROOMS] = {
    {
        "You are in a dimly lit cave. The air is damp and the sound of dripping water echoes around you.\n"
        "There is a narrow passage to the north and a wide entrance to the south.\n",
        {"south", "north"}
    },
    {
        "You have entered a dark, foreboding castle. The smell of death and decay fills the air.\n"
        "There is a passage leading west to the throne room and a secret passage to the east.\n",
        {"east", "west"}
    },
    {
        "You have found yourself in a lush garden filled with the sweet scent of roses.\n"
        "There is a stream to the north and a path leading to a small cottage to the east.\n",
        {"north", "east"}
    },
    {
        "You stand before the throne of the great king.\n"
        "There is a pedestal to the north, displaying the Holy Grail.\n",
        {NULL}}
};

void print_room_description(Room room) {
    printf("%s", room.description);
}

void print_exits(Room room) {
    printf("Exits:\n");
    for (int i = 0; room.exits[i] != NULL; i++) {
        printf("%s\n", room.exits[i]);
    }
}

void move_room(Room* current_room, char* direction) {
    for (int i = 0; i < NUM_ROOMS; i++) {
        if (strcmp(rooms[i].exits[0], direction) == 0) {
            *current_room = rooms[i];
            break;
        }
    }
}

int main() {
    Room current_room = rooms[0];
    char input[MAX_LENGTH];

    while (1) {
        print_room_description(current_room);
        print_exits(current_room);
        printf("> ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        for (int i = 0; i < NUM_CHOICES; i++) {
            if (strcmp(input, current_room.exits[i]) == 0) {
                move_room(&current_room, input);
                break;
            }
        }
    }

    return 0;
}