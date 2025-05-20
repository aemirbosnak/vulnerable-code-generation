//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random number
int getRandomNumber(int min, int max) {
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

// function to simulate a haunted house experience
void creepyHouse() {
    // define variables
    int roomNum, scareNum;

    printf("Welcome to the Creepy Haunted House Simulator!\n");
    
    // ask the user how many rooms there are in the house
    printf("How many rooms are there in the house? ");
    scanf("%d", &roomNum);
    
    // ask the user how many scares they want to experience
    printf("How many scares do you want to experience? ");
    scanf("%d", &scareNum);

    // initialize counter variables
    int roomCounter = 0, scareCounter = 0;

    // loop through each room in the house
    while (roomCounter < roomNum && scareCounter < scareNum) {
        // generate a random number to determine if a scare happens
        int scare = getRandomNumber(0, 1);

        if (scare == 1) {
            // output a scare
            printf("\nYou have been scared in room %d!\n", roomCounter + 1);
            scareCounter++;
        } else {
            // output a safe room
            printf("\nWalked through room %d safely.\n", roomCounter + 1);
        }

        roomCounter++;
    }

    // output the final result of the experience
    if (scareCounter == scareNum) {
        printf("\nCongratulations! You experienced %d scares as requested.\n", scareNum);
    } else {
        printf("\nYou couldn't experience %d scares in the %d rooms.\n", scareNum, roomNum);
    }
}

// main function
int main() {
    // call the creepyHouse function
    creepyHouse();
    return 0;
}