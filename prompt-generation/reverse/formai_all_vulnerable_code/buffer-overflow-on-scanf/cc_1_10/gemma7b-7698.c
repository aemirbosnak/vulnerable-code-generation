//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 10

typedef struct Ghost {
    char name[20];
    int room;
    int state;
    int target_room;
} Ghost;

Ghost ghosts[MAX_GHOULS];

void initializeGhosts() {
    for (int i = 0; i < MAX_GHOULS; i++) {
        ghosts[i].name[0] = '\0';
        ghosts[i].room = -1;
        ghosts[i].state = 0;
        ghosts[i].target_room = -1;
    }
}

void moveGhosts() {
    for (int i = 0; i < MAX_GHOULS; i++) {
        if (ghosts[i].state == 1) {
            int target_room = ghosts[i].target_room;
            if (ghosts[i].room != target_room) {
                ghosts[i].room = target_room;
            }
        }
    }
}

void simulateHauntedHouse() {
    initializeGhosts();
    moveGhosts();

    printf("Welcome to the futuristic haunted house of the future!\n");
    printf("Please enter the room number you want to visit: ");
    int room_number;
    scanf("%d", &room_number);

    for (int i = 0; i < MAX_GHOULS; i++) {
        if (ghosts[i].room == room_number) {
            printf("BOO! You have encountered a ghost named %s!\n", ghosts[i].name);
            printf("Prepare for a spooky encounter... \n");
            sleep(1);
            printf("The ghost has gone away.\n");
        }
    }

    printf("Thank you for visiting the haunted house of the future.\n");
}

int main() {
    simulateHauntedHouse();
    return 0;
}