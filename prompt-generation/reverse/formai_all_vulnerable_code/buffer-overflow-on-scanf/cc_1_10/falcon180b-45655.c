//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void hauntedHouse();
void enterRoom(int room);
void ghostAttack(int room);

int main() {
    srand(time(NULL)); // seed the random number generator
    int choice;

    do {
        printf("Welcome to the Haunted House!\n");
        printf("Do you want to enter? (y/n): ");
        scanf("%c", &choice);

        if (choice == 'y' || choice == 'Y') {
            hauntedHouse();
        } else {
            printf("Goodbye!\n");
        }

        printf("Do you want to try again? (y/n): ");
        scanf("%c", &choice);

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

// the haunted house simulation
void hauntedHouse() {
    int room = rand() % 10 + 1; // start in a random room between 1 and 10
    int ghostRoom = rand() % 10 + 1; // the ghost starts in a random room

    while (room!= ghostRoom) {
        enterRoom(room);
        room = (room + 1) % 10; // move to the next room
    }

    ghostAttack(room);
}

// enter a room in the haunted house
void enterRoom(int room) {
    switch (room) {
        case 1:
            printf("You enter a long hallway with flickering candles.\n");
            break;
        case 2:
            printf("You find yourself in a dusty old library.\n");
            break;
        case 3:
            printf("You cautiously step into a dark and creepy bedroom.\n");
            break;
        case 4:
            printf("You hear strange noises coming from the basement.\n");
            break;
        case 5:
            printf("You discover a hidden passage behind a bookcase.\n");
            break;
        case 6:
            printf("You enter a room filled with antique furniture.\n");
            break;
        case 7:
            printf("You stumble upon a secret garden overgrown with vines.\n");
            break;
        case 8:
            printf("You find yourself in a creepy old kitchen.\n");
            break;
        case 9:
            printf("You cautiously approach a locked door.\n");
            break;
        case 10:
            printf("You've reached the end of the haunted house!\n");
            break;
    }
}

// the ghost attacks!
void ghostAttack(int room) {
    printf("Suddenly, a ghost appears in front of you!\n");
    printf("You scream and run back to room 1.\n");
}