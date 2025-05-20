//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function to clear the screen
void clearScreen(void) {
    system("clear");
}

// Function to wait for n seconds
void delay(int seconds) {
    long pause;
    clock_t now, then;
  
    pause = seconds * CLOCKS_PER_SEC;
    now = then = clock();
    while ((now - then) < pause) {
        now = clock();
    }
}

// Function to simulate the sound of footsteps
void footsteps(int numSteps) {
    for (int i = 1; i <= numSteps; i++) {
        clearScreen();
        printf("Footstep %d\n", i);
        delay(1);
    }
}

// Function to simulate the sound of a door creaking
void doorCreak(void) {
    clearScreen();
    printf("Creeaaaakkkkkk!\n");
    delay(2);
}

// Function to simulate the sound of a ghostly voice
void ghostlyVoice(void) {
    clearScreen();
    printf("Boooooo!\n");
    delay(2);
}

// Function to simulate the sound of a scream
void scream(void) {
    clearScreen();
    printf("AHHHHHHH!!!!\n");
    delay(2);
}

int main(void) {
    bool inRoom = true;
    bool canSeeGhost = false;
    bool itemFound = false;

    printf("Welcome to the haunted house simulator!\n");

    while (inRoom) {
        // Room description
        clearScreen();
        printf("You are in a dark, creepy room. You can see a door to the north.\n");

        // User input
        char input;
        printf("What do you want to do? (N to go north, L to look for items, I to check inventory): ");
        scanf(" %c", &input);
        input = toupper(input);

        // User options
        switch (input) {
            case 'N':
                // Move north
                inRoom = false;
                footsteps(10);
                doorCreak();
                break;
            case 'L':
                // Look for items
                clearScreen();
                printf("You search the room for items...\n");
                delay(2);

                // 50% chance of finding an item
                int result = rand() % 2;
                if (result == 0) {
                    printf("You found a flashlight!\n");
                    itemFound = true;
                } else {
                    printf("You didn't find anything.\n");
                }
                delay(2);
                break;
            case 'I':
                // Check inventory
                clearScreen();
                if (itemFound) {
                    printf("You have a flashlight in your inventory.\n");
                } else {
                    printf("You don't have anything in your inventory.\n");
                }
                delay(2);
                break;
            default:
                // Invalid input
                clearScreen();
                printf("Invalid input. Please try again.\n");
                delay(2);
                break;
        }

        // Ghost encounter
        if (canSeeGhost && inRoom) {
            clearScreen();
            printf("You see a ghostly figure in front of you!\n");
            delay(2);

            // User response
            printf("What do you want to do? (R to run, F to fight): ");
            scanf(" %c", &input);
            input = toupper(input);

            // User options
            switch (input) {
                case 'R':
                    // Run away
                    clearScreen();
                    printf("You run away from the ghost!\n");
                    footsteps(10);
                    break;
                case 'F':
                    // Fight the ghost (spoiler: it doesn't work)
                    clearScreen();
                    printf("You try to fight the ghost, but your attacks go right through it!\n");
                    scream();
                    break;
                default:
                    // Invalid input
                    clearScreen();
                    printf("Invalid input. The ghost is getting closer!\n");
                    ghostlyVoice();
                    scream();
                    inRoom = false;
                    break;
            }
        }

        // Ghost sighting
        if (rand() % 10 == 0 && inRoom) {
            canSeeGhost = true;
        }
    }

    clearScreen();
    printf("You made it out of the haunted house!\n");

    return 0;
}