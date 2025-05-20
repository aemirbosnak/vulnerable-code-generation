//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    int doors[3] = {0, 0, 0}; // array to represent doors, 0 = safe, 1 = haunted
    int playerChoice = 0; // player's chosen door, ranged from 1-3
    int i = 0; // loop iterator
    int hauntedDoor = 0; // randomly chosen haunted door
    int openedDoor = 0; // door opened by host
    
    srand(time(NULL)); // seed Random number generator
    
    // randomly assign one door as haunted
    hauntedDoor = rand() % 3;
    doors[hauntedDoor] = 1;

    printf("Welcome to the Haunted House Simulator! Pick a door (1-3) to open: ");
    scanf("%d", &playerChoice);
    
    // validate player input
    while ((playerChoice < 1) || (playerChoice > 3)) {
        printf("Invalid input. Please enter a number between 1 and 3: ");
        scanf("%d", &playerChoice);
    }
    
    printf("You have selected door %d.\n", playerChoice);
    
    // check if player chose the haunted door
    if (doors[playerChoice - 1] == 1) {
        printf("You have opened a haunted door! You lose.\n");
    } else { // player chose safe door
        // host opens one of the other doors that is not haunted
        for (i = 0; i < 3; i++) {
            if ((i != playerChoice - 1) && (doors[i] == 0)) {
                openedDoor = i;
                break;
            }
        }
        printf("Host opens door %d. It is not haunted.\n", openedDoor + 1);
        
        // give player option to switch doors
        printf("Would you like to switch to door %d? (y/n): ", (6 - playerChoice - openedDoor));
        char switchChoice;
        scanf(" %c", &switchChoice);
        
        if (switchChoice == 'y') { // player chooses to switch doors
            playerChoice = 6 - playerChoice - openedDoor;
        }
        
        // check if final choice is haunted
        if (doors[playerChoice - 1] == 1) {
            printf("You have opened a haunted door! You lose.\n");
        } else {
            printf("Congratulations! You have chosen the safe door and won the game!");
        }
    }
    
    return 0;
}