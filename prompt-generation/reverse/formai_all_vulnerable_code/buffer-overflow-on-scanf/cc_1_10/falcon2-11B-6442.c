//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char choice;
    char direction[5];
    char room[10];

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are in a dark and spooky forest.\n");
    printf("What direction do you want to go?\n");

    scanf(" %c", &choice);

    while (choice!= 'q') {
        switch (choice) {
            case 'n':
                strcpy(direction, "north");
                break;
            case's':
                strcpy(direction, "south");
                break;
            case 'e':
                strcpy(direction, "east");
                break;
            case 'w':
                strcpy(direction, "west");
                break;
            default:
                printf("Invalid direction. Try again.\n");
                break;
        }

        printf("You walk %s.\n", direction);

        if (strcmp(direction, "north") == 0) {
            printf("You are now in a dark and spooky cave.\n");
            printf("What do you want to do?\n");
            scanf(" %c", &choice);
        } else if (strcmp(direction, "south") == 0) {
            printf("You are now in a dark and spooky castle.\n");
            printf("What do you want to do?\n");
            scanf(" %c", &choice);
        } else if (strcmp(direction, "east") == 0) {
            printf("You are now in a dark and spooky graveyard.\n");
            printf("What do you want to do?\n");
            scanf(" %c", &choice);
        } else if (strcmp(direction, "west") == 0) {
            printf("You are now in a dark and spooky swamp.\n");
            printf("What do you want to do?\n");
            scanf(" %c", &choice);
        }
    }

    printf("Thanks for playing!\n");

    return 0;
}