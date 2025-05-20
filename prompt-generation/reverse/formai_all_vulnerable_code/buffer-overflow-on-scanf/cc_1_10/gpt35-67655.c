//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printWelcomeMessage();
void printInstructions();
int engageInEncounter();

int main() {
    srand(time(NULL));
    printWelcomeMessage();
    printInstructions();

    int roomNumber = 1;
    while (roomNumber <= 5) {
        printf("\nEntering Room Number %d...\n", roomNumber);
        int encounterResult = engageInEncounter();
        if (encounterResult == 1) {
            printf("\nYou survived the encounter in Room Number %d!\n", roomNumber);
            roomNumber++;
        } else {
            printf("\nYou were not able to survive the encounter in Room Number %d. Game over.\n", roomNumber);
            exit(0);
        }
    }

    printf("\nCongratulations! You have survived all encounters and made it out of the Haunted House alive!\n");

    return 0;
}

void printWelcomeMessage() {
    printf("\n*** Welcome to the Haunted House Simulator! ***\n");
}

void printInstructions() {
    printf("\nYou will have to pass through 5 rooms where you will encounter a ghost.\n");
    printf("You can either try to escape the room or fight the ghost.\n");
    printf("If you choose to fight the ghost, you will have a 50% chance of surviving.\n");
    printf("If you survive the encounter, you will move on to the next room.\n");
    printf("If you do not survive the encounter, the game will end.\n");
}

int engageInEncounter() {
    printf("\nYou have entered a room with a ghost. What do you want to do?\n");
    printf("1. Escape the room\n");
    printf("2. Fight the ghost\n");

    int choice;
    do {
        printf("Enter your choice (1 or 2): ");
        scanf("%d", &choice);
    } while (choice != 1 && choice != 2);

    if (choice == 1) {
        int escapeSuccess = rand() % 2;
        if (escapeSuccess == 1) {
            printf("\nYou were able to escape the room.\n");
            return 1;
        } else {
            printf("\nYou were not able to escape the room.\n");
            return 0;
        }
    } else {
        int fightSuccess = rand() % 2;
        if (fightSuccess == 1) {
            printf("\nYou were able to fight and defeat the ghost.\n");
            return 1;
        } else {
            printf("\nYou were not able to defeat the ghost.\n");
            return 0;
        }
    }
}