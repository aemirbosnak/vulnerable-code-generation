//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the function to clear the console
void clearScreen() {
    system("clear||cls");
}

// Define the function to wait for user input
void waitForInput() {
    printf("\n Press ENTER to continue...");
    while (getchar() != '\n');
}

// Define the function to print the opening message
void printOpening() {
    printf("\n\n\t\t\tWelcome to the Haunted House Simulator!\n");
    printf("\n You find yourself in front of a spooky house...\n");
    printf("\n Will you dare to enter and uncover its secrets?\n");
    printf("\n Press ENTER to continue...");
    waitForInput();
}

// Define the function to randomly generate a spooky sound
void generateSound() {
    int random = rand() % 5;

    if (random == 0) {
        printf("\n You hear footsteps behind you...");
    } else if (random == 1) {
        printf("\n You hear a door creaking...");
    } else if (random == 2) {
        printf("\n You hear a blood-curdling scream...");
    } else if (random == 3) {
        printf("\n You hear whispers in your ear...");
    } else {
        printf("\n You hear chains rattling...");
    }

    waitForInput();
}

// Define the function to print the game over message
void printGameOver() {
    printf("\n\n\t\t\tGAME OVER!\n");
    printf("\n You were unable to uncover the secrets of the haunted house...\n");
    generateSound();
}

// Define the function to print the winning message
void printWin() {
    printf("\n\n\t\t\tCONGRATULATIONS!\n");
    printf("\n You have uncovered the secrets of the haunted house!\n");
    generateSound();
}

int main() {
    // Seed the random function with current time
    srand(time(NULL));

    // Print the opening message
    clearScreen();
    printOpening();

    // Define variables for game state
    int roomNum = 1;
    int hasKey = 0;
    int isAlive = 1;

    // Loop while player is alive and has not won yet
    while (isAlive && roomNum != 4) {
        // Print room description and instructions
        clearScreen();
        printf("\n\n\t\t\tRoom %d\n", roomNum);
        if (roomNum == 1) {
            printf("\n You are in the foyer of the haunted house.\n");
            printf(" There is a door to your left and stairs leading up.\n");
        } else if (roomNum == 2) {
            printf("\n You are in a musty hallway.\n");
            printf(" There is a door to your right and a door at the end of the hallway.\n");
        } else if (roomNum == 3) {
            printf("\n You are in a dimly lit room.\n");
            printf(" There is a table in the center of the room with a key on it.\n");
            printf(" There is a door to your left and a door to your right.\n");
        }

        // Get user input
        printf("\n What would you like to do? ");
        char input[50];
        fgets(input, 50, stdin);
        input[strlen(input) - 1] = '\0';

        // Process user input
        if (roomNum == 1) {
            if (strcmp(input, "left") == 0) {
                roomNum = 2;
            } else if (strcmp(input, "up") == 0) {
                roomNum = 3;
            } else {
                generateSound();
            }
        } else if (roomNum == 2) {
            if (strcmp(input, "right") == 0) {
                roomNum = 3;
            } else if (strcmp(input, "end") == 0) {
                roomNum = 4;
            } else {
                generateSound();
            }
        } else if (roomNum == 3) {
            if (strcmp(input, "left") == 0) {
                printGameOver();
                isAlive = 0;
            } else if (strcmp(input, "right") == 0) {
                if (hasKey) {
                    printWin();
                    isAlive = 0;
                } else {
                    printf("\n You need a key to open this door...");
                    generateSound();
                }
            } else if (strcmp(input, "take key") == 0) {
                if (!hasKey) {
                    printf("\n You take the key from the table...");
                    hasKey = 1;
                } else {
                    printf("\n You already have the key...");
                }
                waitForInput();
            } else {
                generateSound();
            }
        }
    }

    // Print game over message if player did not win
    if (isAlive && roomNum == 4) {
        clearScreen();
        printf("\n\n\t\t\tYou made it out of the house!\n");
        printf("\n But remember, the secrets you uncovered might haunt you forever...\n");
        generateSound();
    }

    // Wait for user input before exiting
    printf("\n\n Press ENTER to exit.");
    while (getchar() != '\n');
    return 0;
}