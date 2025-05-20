//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOMS 10
#define MAX_ROOM_SIZE 20
#define MAX_ITEMS_PER_ROOM 3
#define MAX_DESCRIPTION_LENGTH 80
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

typedef struct {
    char *description;
    int hasItem;
    int itemValue;
} Room;

int main() {
    srand(time(NULL));
    int roomSize[ROOMS];
    Room rooms[ROOMS];

    for (int i = 0; i < ROOMS; i++) {
        roomSize[i] = rand() % MAX_ROOM_SIZE + 1;
        rooms[i].description = malloc(MAX_DESCRIPTION_LENGTH * sizeof(char));
        sprintf(rooms[i].description, "You are in room %d. It is %d meters long.", i + 1, roomSize[i]);
        rooms[i].hasItem = rand() % 2;
        if (rooms[i].hasItem) {
            rooms[i].itemValue = rand() % 100;
            sprintf(rooms[i].description + strlen(rooms[i].description), " You find a valuable item worth %d dollars.", rooms[i].itemValue);
        }
    }

    int currentRoom = 0;
    while (1) {
        printf("\n%s\n", rooms[currentRoom].description);
        printf("What do you want to do? ");
        char action[MAX_DESCRIPTION_LENGTH];
        scanf("%s", action);

        if (strcmp(action, "go to next room") == 0) {
            currentRoom = (currentRoom + 1) % ROOMS;
        } else if (strcmp(action, "go to previous room") == 0) {
            currentRoom = (currentRoom - 1 + ROOMS) % ROOMS;
        } else if (strcmp(action, "search room") == 0) {
            if (rooms[currentRoom].hasItem) {
                printf("\nYou found an item worth %d dollars!\n", rooms[currentRoom].itemValue);
            } else {
                printf("\nYou didn't find anything.\n");
            }
        } else {
            printf("\nInvalid action.\n");
        }
    }

    return EXIT_SUCCESS;
}