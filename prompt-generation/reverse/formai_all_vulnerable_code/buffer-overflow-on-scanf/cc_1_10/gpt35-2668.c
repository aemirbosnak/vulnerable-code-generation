//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Function Declarations
void showInstructions();
void takeInput();
void checkInput();
void endGame();

//Global Variables
char playerName[20];
int playerAge, score;

//Room Variables
int hasKey = 0, hasHammer = 0, isSpiderDead = 0, isGhostGone = 0;

int main() {
    char choice;
    srand(time(NULL)); //initialize random seed

    //Welcome Screen
    printf("\n************************************");
    printf("\n*  Welcome to the Haunted House!   *");
    printf("\n************************************");

    //Display Instructions
    showInstructions();

    //Start Game Loop
    while (1) {
        //Take Player Input
        takeInput();

        //Check Player Input
        checkInput();

        //Check if Game Over
        endGame();

        //Ask for Next Move
        printf("\n\nWhat do you want to do next? (Press H for Help)\n>");
        scanf(" %c", &choice);
        if (choice == 'h' || choice == 'H')
            showInstructions();
    }

    return 0;
}

void showInstructions() {
    printf("\n\nYou have entered a haunted house. Your objective is to find your way out without dying.\n");
    printf("The house has 4 rooms: Living Room, Kitchen, Bedroom, and Basement. Each room has its own secrets and challenges.\n");
    printf("There are helpful items scattered throughout the house, such as keys and hammers, which can be used to solve puzzles and defeat enemies.\n");
    printf("Good luck, and be careful!\n\n");
}

void takeInput() {
    printf("\n\nPlayer Name: ");
    scanf(" %[^\n]%*c", playerName);
    printf("Player Age: ");
    scanf("%d", &playerAge);
    getchar(); //clear input buffer
}

void checkInput() {
    int roomNum = rand() % 4; //generate random room number (0-3)

    switch (roomNum) {
        case 0:
            printf("\n\nYou have entered the Living Room.");
            if (!hasKey) { //key not found yet
                printf("\nThere is a key on the table. Do you want to pick it up? (Y/N)\n>");
                char choice;
                scanf(" %c", &choice);
                if (choice == 'y' || choice == 'Y') {
                    hasKey = 1;
                    printf("\nYou have picked up the key!");
                    score += 10; //increment score
                }
            } else {
                printf("\nYou have already picked up the key.");
            }
            break;
        case 1:
            printf("\n\nYou have entered the Kitchen.");
            if (!hasHammer) { //hammer not found yet
                printf("\nThere is a hammer on the counter. Do you want to pick it up? (Y/N)\n>");
                char choice;
                scanf(" %c", &choice);
                if (choice == 'y' || choice == 'Y') {
                    hasHammer = 1;
                    printf("\nYou have picked up the hammer!");
                    score += 10; //increment score
                }
            } else {
                printf("\nYou have already picked up the hammer.");
            }
            break;
        case 2:
            printf("\n\nYou have entered the Bedroom.");
            if (!isSpiderDead && hasHammer) { //spider present and has hammer
                printf("\nThere is a spider on the wall. Do you want to kill it using your hammer? (Y/N)\n>");
                char choice;
                scanf(" %c", &choice);
                if (choice == 'y' || choice == 'Y') {
                    isSpiderDead = 1;
                    printf("\nYou have killed the spider!");
                    score += 20; //increment score
                }
            } else if (isSpiderDead) {
                printf("\nThe spider is already dead.");
            } else {
                printf("\nThere is a spider on the wall, but you do not have anything to kill it with.");
            }
            break;
        case 3:
            printf("\n\nYou have entered the Basement.");
            if (!isGhostGone && hasKey) { //ghost present and has key
                printf("\nThere is a ghost in the room. Do you want to use the key to unlock the door and escape? (Y/N)\n>");
                char choice;
                scanf(" %c", &choice);
                if (choice == 'y' || choice == 'Y') {
                    isGhostGone = 1;
                    printf("\nYou have used the key to unlock the door and escape!");
                    score += 50; //increment score
                }
            } else if (isGhostGone) {
                printf("\nYou have already escaped the basement.");
            } else {
                printf("\nThere is a ghost in the room, but you do not have the key to escape.");
            }
            break;
    }
}

void endGame() {
    if (score >= 100) {
        printf("\n\nCongratulations, %s! You have successfully escaped the haunted house with a score of %d!", playerName, score);
        exit(0); //end game
    } else if (playerAge < 18) {
        printf("\n\nSorry, %s! You are too young to play this game.", playerName);
        exit(0); //end game
    }
}