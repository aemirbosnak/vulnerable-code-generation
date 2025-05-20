//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *rooms[] = {
    "You are in a dark room. There is a door to your north.",
    "You are in a hallway. There is a door to your east and another to your west.",
    "You are in a bedroom. There is a window to your north and a door to your south.",
    "You are in a kitchen. There is a door to your east and a door to your west.",
    "You are in a living room. There is a door to your south.",
    "You are in a garden. There is a door to your east.",
    "You are in a basement. There is a door to your south.",
    "You are in a garage. There is a door to your east and a door to your west."
};

char *directions[] = {
    "north", "south", "east", "west", "north", "east", "south", "west"
};

int main() {
    char choice;
    int room = 0;

    printf("Welcome to the Adventure Game!\n");
    printf("You are in a dark room. There is a door to your north.\n");

    while (1) {
        printf("Choose a direction:\n");
        scanf(" %c", &choice);

        if (choice == 'q') {
            printf("Thank you for playing!\n");
            return 0;
        }

        if (choice == 'n') {
            room++;
            if (room == 8) {
                printf("You have reached the end of the game!\n");
            } else {
                printf("You are in a dark room. There is a door to your north.\n");
            }
        } else if (choice =='s') {
            room--;
            if (room == -1) {
                printf("You have reached the beginning of the game!\n");
            } else {
                printf("You are in a dark room. There is a door to your north.\n");
            }
        } else if (choice == 'e') {
            room++;
            if (room == 0) {
                printf("You are in a dark room. There is a door to your north.\n");
            } else if (room == 1) {
                printf("You are in a hallway. There is a door to your east and another to your west.\n");
            } else if (room == 2) {
                printf("You are in a bedroom. There is a window to your north and a door to your south.\n");
            } else if (room == 3) {
                printf("You are in a kitchen. There is a door to your east and a door to your west.\n");
            } else if (room == 4) {
                printf("You are in a living room. There is a door to your south.\n");
            } else if (room == 5) {
                printf("You are in a garden. There is a door to your east.\n");
            } else if (room == 6) {
                printf("You are in a basement. There is a door to your south.\n");
            } else if (room == 7) {
                printf("You are in a garage. There is a door to your east and a door to your west.\n");
            }
        } else if (choice == 'w') {
            room--;
            if (room == 8) {
                printf("You have reached the end of the game!\n");
            } else {
                printf("You are in a dark room. There is a door to your north.\n");
            }
        } else {
            printf("Invalid input. Try again.\n");
        }
    }

    return 0;
}