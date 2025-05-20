//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define R 0
#define P 1
#define S 2

int main() {
    srand(time(NULL));
    int choice;

    printf("Welcome to the Enchanted Forest!\n");
    printf("You are a brave adventurer on a quest for treasure.\n");
    printf("Choose your path wisely...\n");

    int room = R;

    while (room!= S) {
        printf("\nYou are in room %d.\n", room);

        switch (room) {
            case R:
                printf("There is a door to the east and a door to the west.\n");
                break;
            case P:
                printf("You see a glittering treasure chest!\n");
                break;
            default:
                printf("This room is empty.\n");
        }

        printf("What do you do? ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (room == R) {
                    room = P;
                } else {
                    printf("There's no door here.\n");
                }
                break;
            case 2:
                if (room == R) {
                    room = R;
                } else if (room == P) {
                    printf("You open the treasure chest and find a magical amulet!\n");
                    room = S;
                } else {
                    printf("There's no door here.\n");
                }
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    printf("\nCongratulations! You have found the treasure and completed your quest.\n");

    return 0;
}