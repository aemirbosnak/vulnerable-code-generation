//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function to clear screen
void clearScreen() {
    system("clear || cls");
}

// Function to wait for input from user
void waitForInput() {
    getchar();
    clearScreen();
}

// Function to generate random number between min and max
int randomNum(int min, int max) {
    return (rand() % (max - min + 1) + min);
}

// Function to print introduction message
void introduction() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You have entered a haunted house and must find your way out.\n");
    printf("Along the way you may encounter ghosts and other spooky things.\n\n");
    printf("Press enter to begin.\n");
    waitForInput();
}

// Function to print game over message
void gameOver() {
    printf("GAME OVER!\n");
    printf("You were unable to exit the haunted house.\n");
    printf("Better luck next time!\n");
}

// Function to print success message
void success() {
    printf("CONGRATULATIONS!\n");
    printf("You have successfully exited the haunted house.\n");
    printf("You are safe...for now.\n");
}

int main() {
    // Set random seed for generating random numbers
    srand(time(NULL));

    // Print introduction message
    introduction();

    // Initialize variables
    bool exitFound = false;
    int ghostEncounters = 0;
    int roomNumber = 1;

    // Loop until exit is found or player has encountered 3 ghosts
    while (!exitFound && ghostEncounters < 3) {
        clearScreen();
        printf("You are in room %d.\n", roomNumber);
        printf("You see three doors in front of you:\n");
        printf("1. Red door\n");
        printf("2. Blue door\n");
        printf("3. Green door\n");

        int doorChoice;
        printf("Which door would you like to choose? ");
        scanf("%d", &doorChoice);

        switch (doorChoice) {
            case 1: // Red door
                printf("You have entered a room with a ghost!\n");
                ghostEncounters++;
                waitForInput();
                break;
            case 2: // Blue door
                printf("You have entered a room with nothing of interest.\n");
                waitForInput();
                break;
            case 3: // Green door
                roomNumber++;
                if (roomNumber == 5) {
                    printf("Congratulations! You have found the exit!\n");
                    exitFound = true;
                } else {
                    printf("You have entered a room with nothing of interest.\n");
                }
                waitForInput();
                break;
            default:
                printf("Invalid choice.\n");
                waitForInput();
                break;
        }
    }

    clearScreen();

    // Print appropriate message based on outcome of game
    if (exitFound) {
        success();
    } else {
        gameOver();
    }

    return 0;
}