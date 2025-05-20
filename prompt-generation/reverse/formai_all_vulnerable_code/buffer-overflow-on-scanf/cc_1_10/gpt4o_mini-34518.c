//GPT-4o-mini DATASET v1.0 Category: Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void printInstructions() {
    printf("\nWelcome to the Mysterious Cave Game!\n");
    printf("You are about to explore a dark cave filled with unexpected surprises.\n");
    printf("Choose your path wisely as you navigate through the cave.\n");
    printf("Commands: north, south, east, west or type 'exit' to leave the cave.\n");
}

void encounterSurprise() {
    int surprise = rand() % 5; // Random surprise
    switch (surprise) {
        case 0:
            printf("Whoa! You found a treasure chest full of gold!\n");
            break;
        case 1:
            printf("A friendly goblin appears and offers you helpful advice!\n");
            break;
        case 2:
            printf("Oh no! A wild snake slithers past you, scaring you a bit!\n");
            break;
        case 3:
            printf("You stumble upon a magical fountain that grants you a boost of energy!\n");
            break;
        case 4:
            printf("You hear a mysterious sound echoing through the cave... what could it be?\n");
            break;
    }
}

void exploreCave() {
    char command[10];
    printf("\nYou enter the cave. It's dark, and you can barely see.\n");

    while (1) {
        printf("\nWhat will you do? ");
        scanf("%s", command);

        if (strcmp(command, "exit") == 0) {
            printf("You decide to leave the cave. Until next time!\n");
            break;
        } else if (strcmp(command, "north") == 0) {
            printf("You move north into the dark tunnel...\n");
            encounterSurprise();
        } else if (strcmp(command, "south") == 0) {
            printf("You venture south, the air growing cooler...\n");
            encounterSurprise();
        } else if (strcmp(command, "east") == 0) {
            printf("You head east, brushing against moist cave walls...\n");
            encounterSurprise();
        } else if (strcmp(command, "west") == 0) {
            printf("You walk west towards a faint glimmer in the distance...\n");
            encounterSurprise();
        } else {
            printf("That's not a valid command! Please choose: north, south, east, west, or exit.\n");
        }
    }
}

int main() {
    srand(time(NULL)); // Seed for random surprises
    printInstructions();
    exploreCave();
    return 0;
}