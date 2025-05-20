//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MIN_ROOMS 3
#define MAX_GHOSTS 3
#define MIN_GHOSTS 1

void printHeader() {
    printf("\n\n\tWelcome to the Haunted House Simulator!\n\n\n");
}

void printFooter() {
    printf("\n\n\tThanks for playing the Haunted House Simulator!\n\n");
}

void printInstructions() {
    printf("You are trapped in a haunted house.\n");
    printf("There are ghosts lurking around.\n");
    printf("You need to find the exit to the house to escape.\n");
    printf("But beware, the ghosts are going to try to stop you!\n\n");
}

void printRoomInfo(int roomNum, int numGhosts) {
    printf("You are in room %d.\n", roomNum);
    printf("There are %d ghosts in this room!\n", numGhosts);
}

int prompt() {
    int choice;
    printf("\nWhat do you want to do?\n");
    printf("\t1. Move to the next room.\n");
    printf("\t2. Stay in the same room.\n");
    printf("\t3. Quit the game.\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void endGame() {
    printf("\n\nYou successfully exited the haunted house!\n");
    printf("You are now safe!\n\n");
}

void playGame(int numRooms) {
    int i, j, choice;
    
    srand(time(NULL));
    int numGhosts[numRooms];
    for (i = 0; i < numRooms; i++) {
        numGhosts[i] = (rand() % (MAX_GHOSTS - MIN_GHOSTS + 1)) + MIN_GHOSTS;
    }
    
    int currentRoom = 1;
    
    while (currentRoom <= numRooms) {
        printRoomInfo(currentRoom, numGhosts[currentRoom - 1]);
        choice = prompt();
        switch (choice) {
            case 1:
                if (currentRoom == numRooms) {
                    endGame();
                    return;
                }
                else {
                    currentRoom++;
                }
                break;
            case 2:
                printf("You stay in the same room.\n");
                break;
            case 3:
                printFooter();
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
}

int main() {
    printHeader();
    printInstructions();
    int numRooms;
    do {
        printf("How many rooms does the haunted house have? (%d-%d): ", MIN_ROOMS, MAX_ROOMS);
        scanf("%d", &numRooms);
    } while (numRooms < MIN_ROOMS || numRooms > MAX_ROOMS);
    
    playGame(numRooms);
    
    printFooter();
    return 0;
}