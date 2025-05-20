//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100

enum {
    IN_ROOM1,
    IN_ROOM2,
    IN_ROOM3,
};

int main() {
    char choice;
    int room = IN_ROOM1;

    printf("Welcome to the Text Adventure Game!\n");
    printf("You are in a dark forest. You can go left or right.\n");

    while (1) {
        printf("What do you want to do?\n");
        scanf("%c", &choice);

        switch (choice) {
            case 'l':
                if (room == IN_ROOM1) {
                    room = IN_ROOM2;
                    printf("You go left and find a cave.\n");
                } else if (room == IN_ROOM2) {
                    room = IN_ROOM3;
                    printf("You go left and find a castle.\n");
                } else {
                    printf("You can't go left from here.\n");
                }
                break;
            case 'r':
                if (room == IN_ROOM1) {
                    room = IN_ROOM3;
                    printf("You go right and find a castle.\n");
                } else if (room == IN_ROOM2) {
                    room = IN_ROOM1;
                    printf("You go right and find a cave.\n");
                } else {
                    printf("You can't go right from here.\n");
                }
                break;
            default:
                printf("Invalid choice.\n");
        }

        printf("You are now in %s.\n", room == IN_ROOM1? "the cave" : room == IN_ROOM2? "the castle" : "the forest");
    }

    return 0;
}