//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROOMS 5
#define MAX_TRAPS 3

typedef struct {
    char *description;
    int hasTrap;
} Room;

Room rooms[NUM_ROOMS];
int gameOver = 0;

void initializeRooms() {
    rooms[0].description = "You are in a dark alley. The shadows seem to be watching you.";
    rooms[0].hasTrap = rand() % 2;

    rooms[1].description = "You find yourself in a run-down apartment. The floor creaks unnervingly.";
    rooms[1].hasTrap = rand() % 2;

    rooms[2].description = "You stand in a dusty library. Whispers echo through the shelves.";
    rooms[2].hasTrap = rand() % 2;

    rooms[3].description = "A dimly lit tunnel stretches before you. A chill runs down your spine.";
    rooms[3].hasTrap = rand() % 2;

    rooms[4].description = "You arrive at an ominous mansion. Something feels very wrong here.";
    rooms[4].hasTrap = rand() % 2;
}

void printIntroduction() {
    printf("Welcome to 'Paranoid Escape'!\n");
    printf("As you traverse through eerie environments, every decision could lead to danger!\n\n");
}

void encounterTrap() {
    printf("A trap has been triggered! You feel a shiver down your spine...\n");
    int action;
    printf("1. Run away!\n");
    printf("2. Investigate the noise.\n");
    printf("Choose your action (1-2): ");
    scanf("%d", &action);

    if (action == 1) {
        printf("You escaped, but your paranoia grows.\n");
    } else {
        printf("You cautiously approach and realize it was just your imagination...\n");
    }
}

void enterRoom(int roomIndex) {
    printf("%s\n", rooms[roomIndex].description);
    if (rooms[roomIndex].hasTrap) {
        encounterTrap();
    } else {
        printf("You found nothing suspicious here...\n");
    }
}

int main() {
    srand(time(NULL));
    initializeRooms();
    printIntroduction();

    int currentRoom = 0;
    while (!gameOver) {
        printf("\nYou can enter the following rooms:\n");
        printf("0) %s\n", rooms[0].description);
        printf("1) %s\n", rooms[1].description);
        printf("2) %s\n", rooms[2].description);
        printf("3) %s\n", rooms[3].description);
        printf("4) %s\n", rooms[4].description);
        
        int choice;
        printf("Which room do you want to enter (0-4)? ");
        scanf("%d", &choice);
        if (choice < 0 || choice >= NUM_ROOMS) {
            printf("Invalid choice! You hesitate and feel more paranoid...\n");
            continue;
        }

        enterRoom(choice);

        if (rand() % 10 < 2) { // 20% chance to end the game due to paranoia
            printf("Your paranoia has overwhelmed you. You must leave this place now!\n");
            gameOver = 1;
        }
    }

    printf("\nThank you for playing 'Paranoid Escape'. Until next time...\n");
    return 0;
}