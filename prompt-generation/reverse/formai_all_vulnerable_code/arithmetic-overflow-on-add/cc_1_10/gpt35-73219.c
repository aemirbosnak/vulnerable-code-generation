//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int sec) {
    int ms = 1000 * sec;
    clock_t start_time = clock();
    while (clock() < start_time + ms) {}
}
// Delay function to simulate suspense

void printGhost(int count) {
    for (int i = 0; i < count; i++) {
        printf(" ");
    }
    printf("  ooo\n");
    for (int i = 0; i < count; i++) {
        printf(" ");
    }
    printf(" ( o ) \n");
    for (int i = 0; i < count; i++) {
        printf(" ");
    }
    printf("-(   )-\n");
    for (int i = 0; i < count; i++) {
        printf(" ");
    }
    printf("  '-' \n\n");
    delay(1);
}

void visitRoom(int roomNumber, int count) {

    printf("\nEntering room %d...\n", roomNumber);
    printf("You have entered a dark, eerie room.\n");
    delay(1);
    printf("You hear the sound of creaking floorboards.\n");
    delay(1);

    if (roomNumber == 1) {
        printf("Suddenly, you are surrounded by ghosts!\n");
        printf("You are trapped in the room with no way out...\n");
        printf("-----------------------------------------------------\n");
        printGhost(count+1);
        visitRoom(roomNumber, count+1);
    } else if (roomNumber == 2) {
        int chance = rand() % 2;
        if (chance == 0) {
            printf("You hear a strange sound coming from behind the closet.\n");
            delay(1);
            printf("You slowly open the closet and find nothing...\n");
        } else {
            printf("You hear a strange sound coming from behind the closet.\n");
            delay(1);
            printf("You slowly open the closet and find a ghost staring back at you!\n");
            printf("-----------------------------------------------------\n");
            printGhost(count+1);
            visitRoom(roomNumber, count+1);
        }
    } else if (roomNumber == 3) {
        int chance = rand() % 2;
        if (chance == 0) {
            printf("You notice a shadow moving on the wall.\n");
            delay(1);
            printf("You turn around and see nothing there.\n");
        } else {
            printf("You notice a shadow moving on the wall.\n");
            delay(1);
            printf("You turn around and come face to face with a ghost!\n");
            printf("-----------------------------------------------------\n");
            printGhost(count+1);
            visitRoom(roomNumber, count+1);
        }
    }
    printf("You have left room %d.\n", roomNumber);
    printf("-----------------------------------------------------\n");
}

int main() {
    srand(time(NULL)); // Seed the random number generator with current time

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are entering a haunted house and need to find your way out.\n");
    printf("There are three rooms in the house, each with its own ghostly surprise.\n");

    int roomNumber = 1;
    visitRoom(roomNumber, 0);

    printf("\nCongratulations! You made it out alive.\n");
    printf("Thanks for playing the Haunted House Simulator.\n");

    return 0;
}