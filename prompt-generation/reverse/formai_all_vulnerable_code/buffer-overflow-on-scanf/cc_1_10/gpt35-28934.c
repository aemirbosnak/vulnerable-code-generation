//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printDescription(int roomNumber, int ghostCount) {
    printf("You are currently in Room %d. ", roomNumber);
    if (ghostCount > 0) {
        printf("There are %d ghosts in the room.\n", ghostCount);
    } else {
        printf("There are no ghosts in the room.\n");
    }
}

void printGameRules() {
    printf("Welcome to Haunted House Simulator! \n");
    printf("You must navigate through a haunted house and find the escape route. \n");
    printf("Be careful! The house is haunted by ghosts who will try to scare you. \n");
    printf("If you encounter a ghost, you must decide whether to fight or run. \n");
    printf("If you fight and win, you will gain points. If you lose, you will lose points. \n");
    printf("If you run away, you will lose points. \n");
}

int main() {
    int playerPoints = 0;
    int roomNumber = 1;
    int ghostCount = 2;
    int choice;
    srand(time(0)); // initialize random number generator with current time

    printGameRules(); // display game rules to player

    while (roomNumber != 0) { // continue playing until player reaches the exit
        printDescription(roomNumber, ghostCount); // display current room information
        if (ghostCount > 0) { // check if there are any ghosts in the room
            printf("You have encountered a ghost! What do you want to do? \n");
            printf("1. Fight the ghost \n");
            printf("2. Run away \n");
            scanf("%d", &choice);
            if (choice == 1) { // player chooses to fight the ghost
                int randNum = rand() % 100 + 1; // generate random number between 1-100
                if (randNum < 50) { // player loses the fight
                    printf("You have lost the fight! You lose 10 points. \n");
                    playerPoints -= 10;
                } else { // player wins the fight
                    printf("Congratulations! You have defeated the ghost. You gain 20 points. \n");
                    playerPoints += 20;
                    ghostCount--; // decrease ghost count in the room
                }
            } else { // player chooses to run away
                printf("You ran away! You lose 5 points. \n");
                playerPoints -= 5;
            }
        } else { // no ghosts in the room
            printf("This room is safe. You can continue to the next room. \n");
            roomNumber++;
            ghostCount = rand() % 3; // randomly generate ghost count for next room
            printf("You have entered Room %d. There are %d ghosts in the room. \n", roomNumber, ghostCount);
        }
    }

    printf("Congratulations! You have escaped the haunted house with %d points. \n", playerPoints);
    return 0;
}