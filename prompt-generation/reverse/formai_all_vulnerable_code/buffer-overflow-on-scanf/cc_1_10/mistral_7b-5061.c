//MISTRAL-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 5
#define MAX_DESC 100

typedef struct Room {
    char description[MAX_DESC];
    char *north;
    char *east;
    char *south;
    char *west;
} Room;

Room rooms[MAX_ROOMS] = {
    {
        "You are in a dimly lit room. The air is damp and heavy with the smell of mildew. There is a rusted door to the north.",
        "room2"
    },
    {
        "This room is filled with cobwebs. Sunlight streams in through the dusty windows. There is a rickety ladder leading up to the east.",
        "room1",
        "room3"
    },
    {
        "A large fire crackles in the hearth. The room is warm and inviting. There is a wooden door to the south.",
        "room4"
    },
    {
        "A musty library filled with ancient tomes. There is a long table with a quill and inkwell. The only exit is to the west.",
        "room5",
        NULL
    },
    {
        "You are outside in a dense forest. The sun is setting. The only way to go is south.",
        NULL,
        NULL,
        NULL
    }
};

void explore(char *direction) {
    Room *currentRoom = &rooms[0];

    if (strcmp(direction, "north") == 0 && currentRoom->north != NULL) {
        currentRoom = &rooms[strlen(currentRoom->north)];
    } else if (strcmp(direction, "east") == 0 && currentRoom->east != NULL) {
        currentRoom = &rooms[strlen(currentRoom->east)];
    } else if (strcmp(direction, "south") == 0 && currentRoom->south != NULL) {
        currentRoom = &rooms[strlen(currentRoom->south)];
    } else if (strcmp(direction, "west") == 0 && currentRoom->west != NULL) {
        currentRoom = &rooms[strlen(currentRoom->west)];
    } else {
        printf("Invalid direction.\n");
        return;
    }

    printf("%s\n", currentRoom->description);
}

int main() {
    char input[20];

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("%s\n", rooms[0].description);

    while (1) {
        printf("> ");
        scanf("%s", input);
        explore(input);
    }

    return 0;
}