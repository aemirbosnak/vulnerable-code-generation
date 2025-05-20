//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define Constants */
#define ROOMS 6
#define GHOST 9
#define TREASURE 0
#define EMPTY 1

/* Declare Functions */
void reset(int house[ROOMS]);
int playGame(int house[ROOMS], int position);
void printHouse(int house[ROOMS], int position);
int move(int house[ROOMS], int position);
void reveal(int house[ROOMS], int position);

int main() {
    int house[ROOMS];
    int position = 0;
    int treasureFound = 0;
    int ghostSpotted = 0;

    srand(time(0)); // Seed random number generator

    reset(house); // Initialize house array

    // Game loop
    do {
        printHouse(house, position);
        position = move(house, position);

        if (house[position] == GHOST) {
            ghostSpotted = 1;
        } else if (house[position] == TREASURE) {
            treasureFound = 1;
        }

    } while(!ghostSpotted && !treasureFound);

    // End of game message
    if(treasureFound) {
        printf("Congratulations! You have found the treasure! You win!\n");
    } else {
        printf("Oh no! You have been scared by a ghost! Game over.\n");
    }

    return 0;
}

/* Set all rooms to empty */
void reset(int house[ROOMS]) {
    for(int i = 0; i < ROOMS; i++) {
        house[i] = EMPTY;
    }
}

/* Print out the game board */
void printHouse(int house[ROOMS], int position) {
    printf("  ");
    for(int i = 0; i < ROOMS; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");

    for(int i = 0; i < ROOMS; i++) {
        printf("---");
    }
    printf("\n");

    for(int i = 0; i < ROOMS; i++) {
        printf("|");
        if(i == position) {
            printf("*");
        } else if(house[i] == TREASURE) {
            printf("$");
        } else {
            printf(" ");
        }
        printf("|");
    }
    printf("\n");

    for(int i = 0; i < ROOMS; i++) {
        printf("---");
    }
    printf("\n");
}

/* Move the player to a new position */
int move(int house[ROOMS], int position) {
    int direction;
    printf("Enter a direction to move (1 for left, 2 for right): ");
    scanf("%d", &direction);

    switch(direction) {
        case 1:
            position--;
            break;
        case 2:
            position++;
            break;
        default:
            printf("Invalid direction! Try again.\n");
    }

    return playGame(house, position);
}

/* Check the room and reveal its content */
void reveal(int house[ROOMS], int position) {
    if(house[position] == GHOST) {
        printf("Boo! A ghost scared you.\n");
    } else if(house[position] == TREASURE) {
        printf("Congratulations! You found the treasure.\n");
    } else {
        printf("This room is empty.\n");
    }
}

/* Perform action based on the room */
int playGame(int house[ROOMS], int position) {
    if(position < 0) {
        printf("You hit a wall. Can't go left!\n");
        position = 0;
    } else if(position > ROOMS - 1) {
        printf("You hit a wall. Can't go right!\n");
        position = ROOMS - 1;
    } else {
        if(house[position] == EMPTY) {
            house[position] = rand() % 2 == 0 ? TREASURE : GHOST;
        }
        reveal(house, position);
    }
    return position;
}