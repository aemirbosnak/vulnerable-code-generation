//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int room = 1;
    int scared = 0;

    srand(time(NULL));

    printf("Welcome to the Haunted House!\n");

    while (room <= 10) {
        printf("You are in room %d.\n", room);
        printf("What would you like to do?\n");
        printf("1. Open the door\n");
        printf("2. Look around the room\n");
        printf("3. Turn back\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (scared == 0) {
                    printf("You open the door and enter the next room.\n");
                    room++;
                } else {
                    printf("You are too scared to open the door.\n");
                }
                break;
            case 2:
                printf("You look around the room and see...\n");
                if (room == 1) {
                    printf("A creepy painting on the wall.\n");
                } else if (room == 2) {
                    printf("A dusty old bookshelf.\n");
                } else if (room == 3) {
                    printf("A flickering candle on a table.\n");
                } else if (room == 4) {
                    printf("A mysterious locked chest.\n");
                } else if (room == 5) {
                    printf("A spooky grandfather clock.\n");
                } else if (room == 6) {
                    printf("A cobweb-covered chandelier.\n");
                } else if (room == 7) {
                    printf("A dusty old piano.\n");
                } else if (room == 8) {
                    printf("A creepy antique mirror.\n");
                } else if (room == 9) {
                    printf("A dusty old fireplace.\n");
                } else if (room == 10) {
                    printf("A mysterious locked door.\n");
                }
                break;
            case 3:
                printf("You turn back and leave the haunted house.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

        if (room == 2 || room == 4 || room == 6 || room == 8 || room == 10) {
            scared = 1;
        } else {
            scared = 0;
        }
    }

    return 0;
}