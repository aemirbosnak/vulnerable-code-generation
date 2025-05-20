//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

enum {
    NORTH, SOUTH, EAST, WEST, UP, DOWN
};

int isValidDirection(char direction) {
    if (direction == 'N' || direction == 'S' || direction == 'E' || direction == 'W' || direction == 'U' || direction == 'D') {
        return 1;
    }
    return 0;
}

void printRoom(char* roomDescription) {
    printf("You are in the %s.\n", roomDescription);
}

void move(char direction) {
    if (isValidDirection(direction)) {
        printf("You move %c.\n", direction);
    } else {
        printf("You can't go that way.\n");
    }
}

int main() {
    char roomDescription[100];
    char direction;
    int choice;

    while (1) {
        printf("Choose a direction: N, S, E, W, U, D, or Q to quit.\n");
        scanf(" %c", &direction);

        if (direction == 'Q') {
            break;
        }

        if (isValidDirection(direction)) {
            strcpy(roomDescription, "You enter a dark room.");
            printRoom(roomDescription);
            move(direction);
            printf("You enter a brightly lit room.\n");
            strcpy(roomDescription, "You enter a brightly lit room.");
            printRoom(roomDescription);
        } else {
            printf("You can't go that way.\n");
        }

        printf("Do you want to continue? (Y/N)\n");
        scanf(" %c", &choice);

        if (choice == 'N') {
            break;
        }
    }

    return 0;
}