//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100

void displayIntroduction() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You will navigate through rooms, make decisions, and encounter spooky surprises.\n");
    printf("Can you survive the haunted house? Let's begin!\n\n");
}

void displayRoom(const char *room) {
    printf("You enter the %s.\n", room);
}

void encounterGhost() {
    printf("\nA ghost appears! It's looking at you with hollow eyes!\n");
    printf("1. Run away\n");
    printf("2. Try to communicate\n");
    printf("Choose your action: ");
}

void encounterZombie() {
    printf("\nA zombie shuffles towards you with a menacing groan!\n");
    printf("1. Fight back\n");
    printf("2. Hide behind a door\n");
    printf("Choose your action: ");
}

void encounterSpider() {
    printf("\nA giant spider drops down from the ceiling!\n");
    printf("1. Scream and run\n");
    printf("2. Try to catch it\n");
    printf("Choose your action: ");
}

void processChoice(int choice) {
    switch (choice) {
        case 1:
            printf("You chose to run away! You escape safely!\n");
            break;
        case 2:
            printf("You chose to communicate. It didn't understand you and vanishes.\n");
            break;
        case 3:
            printf("You chose to fight back! It's a tough battle, but you managed to win!\n");
            break;
        case 4:
            printf("You chose to hide. The zombie never found you!\n");
            break;
        case 5:
            printf("You screamed and ran away! You live to see another day!\n");
            break;
        case 6:
            printf("You try to catch the spider! It escapes, but you're safe!\n");
            break;
        default:
            printf("You stood there in fear...\n");
            break;
    }
}

void enterRoom(const char *room, int type) {
    displayRoom(room);
    
    switch (type) {
        case 1:
            encounterGhost();
            break;
        case 2:
            encounterZombie();
            break;
        case 3:
            encounterSpider();
            break;
        default:
            printf("You see nothing unusual.\n");
            return;
    }

    int action;
    scanf("%d", &action);
    processChoice(action + (type - 1) * 2);  // Adjust choice based on the type of encounter
}

int main() {
    char **rooms;
    const int numRooms = 5;
    
    rooms = (char **)malloc(numRooms * sizeof(char *));
    rooms[0] = "Living Room";
    rooms[1] = "Creepy Hallway";
    rooms[2] = "Dark Basement";
    rooms[3] = "Attic";
    rooms[4] = "Abandoned Bedroom";

    int choices[] = {1, 2, 3, 1, 2};  // Types of encounters in each room

    displayIntroduction();

    for(int i = 0; i < numRooms; i++) {
        enterRoom(rooms[i], choices[i]);
        printf("\nPress Enter to continue to the next room...");
        while (getchar() != '\n'); // Wait for Enter
    }

    printf("\nCongratulations! You've explored all the rooms of the haunted house!\n");
    free(rooms);  // Clean up
    return 0;
}