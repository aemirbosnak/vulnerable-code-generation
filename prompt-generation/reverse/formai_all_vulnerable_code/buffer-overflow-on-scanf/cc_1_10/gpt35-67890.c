//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void printHeader();
void printFooter();
void printRoom(int currentRoom);

int main() {
    srand(time(NULL)); // seed RNG for random events
    int currentRoom = 1; // starting room
    char name[20]; // player's name
    int score = 0; // player's score
    int flashlight = 0; // flashlight status (0 = off, 1 = on)

    printHeader(); // print game title and instructions
    printf("\nWhat is your name?\n");
    scanf("%s", name);

    // game loop
    while (currentRoom != 0) { // continue until player reaches the exit
        printRoom(currentRoom); // print description of current room

        // generate random event
        int event = rand() % 3; // 0 = nothing, 1 = ghost, 2 = item
        if (event == 1) { // ghost event
            printf("\nOh no! You have encountered a ghost!\n");
            if (flashlight == 0) { // player doesn't have flashlight
                printf("You cannot see anything! You run out of the haunted house in fear...\n");
                printf("GAME OVER\n");
                printFooter(score); // print final score
                return 0;
            }
            else { // player has flashlight
                printf("You shine your flashlight at the ghost and it disappears.\n");
            }
        }
        else if (event == 2) { // item event
            printf("\nYou found a flashlight!\n");
            flashlight = 1;
            score += 10; // add points to player's score
        }

        // prompt user for next room
        printf("\nWhere do you want to go? (1, 2, 3, or 4)\n");
        int nextRoom;
        scanf("%d", &nextRoom);
        while (nextRoom < 1 || nextRoom > 4) { // input validation
            printf("Invalid room number. Please choose 1, 2, 3, or 4.\n");
            scanf("%d", &nextRoom);
        }
        currentRoom = nextRoom;
        score++; // increment player's score for each move
        system("clear"); // clear console for next loop
    }

    printf("\nCongratulations, %s! You have made it out of the haunted house!\n", name);
    printFooter(score); // print final score
    return 0;
}

/**
 * Function to print the header of the game.
 */
void printHeader() {
    printf("*******************************************************************\n");
    printf("*                                                                 *\n");
    printf("*         Welcome to the Haunted House Simulator!                  *\n");
    printf("*                                                                 *\n");
    printf("*       You will be given a series of rooms to navigate            *\n");
    printf("*    through and must find the exit without encountering           *\n");
    printf("*         any ghosts. Use your wits and luck to succeed!            *\n");
    printf("*                                                                 *\n");
    printf("*******************************************************************\n");
}

/**
 * Function to print the footer with the player's final score.
 */
void printFooter(int score) {
    printf("\nYour final score is: %d\n", score);
    printf("Thank you for playing! Goodbye.\n");
}

/**
 * Function to print the description of a given room.
 */
void printRoom(int currentRoom) {
    switch (currentRoom) {
        case 1:
            printf("\nYou are in the foyer of the haunted house. You can see four doors:\n");
            printf("1. North door\n");
            printf("2. East door\n");
            printf("3. South door\n");
            printf("4. West door\n");
            break;
        case 2:
            printf("\nYou are in the living room of the haunted house. You can see:\n");
            printf("1. A staircase leading up\n");
            printf("2. A fireplace\n");
            printf("3. A door to the north\n");
            break;
        case 3:
            printf("\nYou are in the dining room of the haunted house. You can see:\n");
            printf("1. A table set for a meal\n");
            printf("2. A door to the west\n");
            printf("3. A door to the south\n");
            printf("4. A door to the east\n");
            break;
        case 4:
            printf("\nYou are in the kitchen of the haunted house. You can see:\n");
            printf("1. A stove\n");
            printf("2. A refrigerator\n");
            printf("3. A door to the east\n");
            break;
        default:
            printf("Error: invalid room number.\n");
            break;
    }
}