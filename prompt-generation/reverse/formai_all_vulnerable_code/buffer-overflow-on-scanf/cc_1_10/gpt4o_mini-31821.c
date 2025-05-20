//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROOMS 5
#define MAX_ITEMS 3

typedef struct {
    char *name;
    int hasGhost;
    char *items[MAX_ITEMS];
    int itemCount;
} Room;

void initializeRooms(Room rooms[]) {
    rooms[0] = (Room){"Entry Hall", 0, {"Flashlight", "Key", NULL}, 2};
    rooms[1] = (Room){"Living Room", 1, {"Haunted Mirror", NULL, NULL}, 1};
    rooms[2] = (Room){"Kitchen", 0, {"Potion", "Skull", NULL}, 2};
    rooms[3] = (Room){"Attic", 1, {"Old Photo", NULL, NULL}, 1};
    rooms[4] = (Room){"Cellar", 0, {NULL, NULL, NULL}, 0};
}

void printRoom(Room room) {
    printf("You are in the %s.\n", room.name);
    if (room.hasGhost) {
        printf("A ghost appears! You need to escape!\n");
    }
    if (room.itemCount > 0) {
        printf("You see the following items: ");
        for (int i = 0; i < room.itemCount; i++) {
            if (room.items[i] != NULL) {
                printf("%s, ", room.items[i]);
            }
        }
        printf("\b\b \n");
    } else {
        printf("There are no items here.\n");
    }
}

int main() {
    srand(time(NULL));
    Room rooms[NUM_ROOMS];
    initializeRooms(rooms);
    
    int currentRoomIndex = 0;
    int keepPlaying = 1;
    char choice[10];

    printf("Welcome to the Haunted House Simulator!\n");
    
    while (keepPlaying) {
        printRoom(rooms[currentRoomIndex]);
        printf("What would you like to do? (explore/exit)\n");
        scanf("%s", choice);
        
        if (strcmp(choice, "explore") == 0) {
            int nextRoomIndex = (currentRoomIndex + 1) % NUM_ROOMS;
            currentRoomIndex = nextRoomIndex;
        } else if (strcmp(choice, "exit") == 0) {
            printf("Exiting the haunted house. Thanks for playing!\n");
            keepPlaying = 0;
        } else {
            printf("Invalid choice. Please choose 'explore' or 'exit'.\n");
        }

        if (rooms[currentRoomIndex].hasGhost) {
            if (rand() % 2 == 1) {
                printf("You encountered a ghost! You lose!\n");
                keepPlaying = 0;
            }
        }
    }

    printf("Game Over!\n");
    return 0;
}