//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int room = 1;
    int scared = 0;
    int found_ghost = 0;

    srand(time(NULL));

    printf("Welcome to the Haunted House!\n");

    while (room <= 5) {
        printf("You are in room %d.\n", room);

        if (room == 1) {
            printf("There is a door to your left and a door to your right.\n");
        } else if (room == 2) {
            printf("There is a staircase going up and a door to your right.\n");
        } else if (room == 3) {
            printf("There is a long hallway with several doors on each side.\n");
        } else if (room == 4) {
            printf("There is a room with a fireplace and a door to your left.\n");
        } else if (room == 5) {
            printf("You have reached the end of the house.\n");
        }

        printf("What would you like to do?\n");
        printf("1. Go left\n");
        printf("2. Go right\n");
        printf("3. Go up the stairs\n");
        printf("4. Open a door\n");
        printf("5. Leave the house\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (room == 1) {
                    room++;
                } else {
                    printf("There is no door to your left.\n");
                }
                break;
            case 2:
                if (room == 1) {
                    room++;
                } else {
                    printf("There is no door to your right.\n");
                }
                break;
            case 3:
                if (room == 2) {
                    room++;
                } else {
                    printf("There are no stairs here.\n");
                }
                break;
            case 4:
                if (room == 3) {
                    int ghost = rand() % 2;
                    if (ghost == 0) {
                        printf("You open the door and find nothing.\n");
                    } else {
                        printf("You open the door and find a ghost! You are now scared.\n");
                        scared = 1;
                    }
                } else {
                    printf("There are no doors here.\n");
                }
                break;
            case 5:
                printf("You leave the haunted house.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    if (scared == 0) {
        printf("You made it through the haunted house without getting scared!\n");
    } else {
        printf("You got scared in the haunted house.\n");
    }

    return 0;
}