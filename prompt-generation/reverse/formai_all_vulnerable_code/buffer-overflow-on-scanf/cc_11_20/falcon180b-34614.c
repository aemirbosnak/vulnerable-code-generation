//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int room = 0;
    int ghost = 0;

    srand(time(NULL));

    printf("Welcome to the Haunted House!\n");

    while (1) {
        printf("You are in room %d.\n", room);

        if (room == 1) {
            printf("There is a door to your left and a door to your right.\n");
        } else if (room == 2) {
            printf("There is a staircase leading up and a door to your right.\n");
        } else if (room == 3) {
            printf("There is a door to your left and a staircase leading down.\n");
        }

        printf("What do you want to do?\n");
        printf("1. Go left\n");
        printf("2. Go right\n");
        printf("3. Go up\n");
        printf("4. Go down\n");
        printf("5. Quit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (room == 1) {
                    room = 2;
                } else if (room == 2) {
                    room = 3;
                } else {
                    printf("There is no door to your left.\n");
                }
                break;
            case 2:
                if (room == 1) {
                    room = 3;
                } else if (room == 2) {
                    room = 1;
                } else {
                    printf("There is no door to your right.\n");
                }
                break;
            case 3:
                if (room == 2) {
                    room = 4;
                    ghost = 1;
                } else if (room == 3) {
                    room = 1;
                } else {
                    printf("There is no staircase leading up.\n");
                }
                break;
            case 4:
                if (room == 3) {
                    room = 5;
                    ghost = 1;
                } else if (room == 4) {
                    room = 2;
                } else {
                    printf("There is no staircase leading down.\n");
                }
                break;
            case 5:
                printf("Thanks for playing!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }

        if (ghost) {
            printf("A ghost appears!\n");
            printf("You have been scared back to room 1.\n");
            room = 1;
            ghost = 0;
        }
    }

    return 0;
}