//Code Llama-13B DATASET v1.0 Category: Text-Based Adventure Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_INPUT 256
#define MAX_ITEMS 10
#define MAX_ROOMS 10

typedef struct {
    char name[MAX_INPUT];
    char description[MAX_INPUT];
    char *items[MAX_ITEMS];
} Room;

Room rooms[MAX_ROOMS] = {
    {"Starting Room", "You find yourself in a dark and dingy room. There is a door to the north and a door to the south.", {"key", "torch"}},
    {"North Room", "You enter a room with a large table in the center. There is a door to the east.", {"chair", "lamp", "book"}},
    {"South Room", "You enter a room with a small window. There is a door to the west.", {"bed", "table", "chair"}},
    {"East Room", "You enter a room with a large bookshelf. There is a door to the south.", {"chair", "lamp", "book"}},
    {"West Room", "You enter a room with a small desk. There is a door to the east.", {"chair", "lamp", "book"}},
};

int main() {
    int current_room = 0;
    char input[MAX_INPUT];

    while (1) {
        printf("You are in room %s.\n", rooms[current_room].name);
        printf("%s\n", rooms[current_room].description);

        printf("What would you like to do?\n");
        printf("1. Look around\n");
        printf("2. Take item\n");
        printf("3. Go to room\n");

        scanf("%s", input);

        if (strcmp(input, "look around") == 0) {
            printf("You look around the room and see the following items:\n");
            for (int i = 0; i < MAX_ITEMS; i++) {
                if (rooms[current_room].items[i] != NULL) {
                    printf("%s\n", rooms[current_room].items[i]);
                }
            }
        } else if (strcmp(input, "take item") == 0) {
            printf("Which item would you like to take?\n");
            scanf("%s", input);

            for (int i = 0; i < MAX_ITEMS; i++) {
                if (strcmp(input, rooms[current_room].items[i]) == 0) {
                    printf("You take the %s.\n", input);
                    rooms[current_room].items[i] = NULL;
                    break;
                }
            }
        } else if (strcmp(input, "go to room") == 0) {
            printf("Which room would you like to go to?\n");
            scanf("%s", input);

            for (int i = 0; i < MAX_ROOMS; i++) {
                if (strcmp(input, rooms[i].name) == 0) {
                    current_room = i;
                    break;
                }
            }
        } else {
            printf("Invalid input.\n");
        }
    }

    return 0;
}