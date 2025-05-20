//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print the haunted house
void printHauntedHouse(int rooms, int currentRoom) {
    int i;
    for (i = 1; i <= rooms; i++) {
        if (i == currentRoom) {
            printf("You are in room %d.\n", i);
        } else {
            printf("Room %d is ", i);
            if (randInt(0, 1) == 0) {
                printf("haunted.\n");
            } else {
                printf("not haunted.\n");
            }
        }
    }
}

// Function to move to a new room
void move(int *currentRoom) {
    int newRoom = randInt(1, *currentRoom);
    while (newRoom == *currentRoom) {
        newRoom = randInt(1, *currentRoom);
    }
    *currentRoom = newRoom;
}

// Main function
int main() {
    srand(time(NULL));
    int rooms, currentRoom = 1;

    // Get number of rooms from user
    printf("How many rooms does the haunted house have? ");
    scanf("%d", &rooms);

    // Print initial haunted house
    printf("You are in room %d.\n", currentRoom);
    printHauntedHouse(rooms, currentRoom);

    // Move to a new room
    move(&currentRoom);
    printf("\nYou move to room %d.\n", currentRoom);
    printHauntedHouse(rooms, currentRoom);

    // Move to another new room
    move(&currentRoom);
    printf("\nYou move to room %d.\n", currentRoom);
    printHauntedHouse(rooms, currentRoom);

    return 0;
}