//MISTRAL-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_DESCRIPTION_LENGTH 256

typedef struct {
    char name[50];
    char description[MAX_DESCRIPTION_LENGTH];
    char exits[MAX_ROOMS][20];
} Room;

Room rooms[MAX_ROOMS] = {
    {
        "Great Hall",
        "You are in the Great Hall, a grand room with high ceilings and large fireplace.\n"
        "To the north is the Enchanted Garden, to the east is the Dragon's Lair.\n",
        {"North", "East"}
    },
    {
        "Enchanted Garden",
        "You are in the Enchanted Garden, a beautiful and peaceful place filled with colorful flowers and singing birds.\n"
        "To the south is the Great Hall.\n",
        {"South"}
    },
    {
        "Dragon's Lair",
        "You are in the Dragon's Lair, a dark and damp cave filled with the smell of fire and sulfur.\n"
        "To the west is the Great Hall.\n",
        {"West"}
    },
    // Add more rooms here
};

void describe_room(int room_number) {
    printf("%s\n%s\n", rooms[room_number].name, rooms[room_number].description);
}

void explore_exit(int room_number, char *direction) {
    int exit_number;

    for (int i = 0; i < strlen(rooms[room_number].exits); i += 2) {
        if (strcmp(rooms[room_number].exits + i, direction) == 0) {
            exit_number = i / 2;
            describe_room(exit_number);
            break;
        }
    }
}

int main() {
    int current_room = 0;
    char direction[20];

    while (1) {
        describe_room(current_room);
        printf("Where would you like to go? ");
        scanf("%s", direction);
        explore_exit(current_room, direction);
    }

    return 0;
}