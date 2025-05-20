//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char house[1000] = "A Haunted House Simulator";
    printf("%s\n", house);
    char* room = "Room";
    int numRooms = 10;
    int numItems = 50;
    int numScares = 100;
    int roomNum = 0;
    int itemNum = 0;
    int scareNum = 0;
    int chosenScare;

    while (roomNum < numRooms) {
        printf("You enter the %s.\n", room);
        printf("There are %d items in this room.\n", numItems);
        printf("There are %d scares in this room.\n", numScares);
        printf("You can do the following:\n");
        printf("1. Move to another room\n");
        printf("2. Pick up an item\n");
        printf("3. Use an item\n");
        printf("4. Add a scare\n");
        printf("5. Remove a scare\n");
        printf("6. Leave the room\n");

        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You move to the next room.\n");
                break;
            case 2:
                printf("You pick up an item.\n");
                break;
            case 3:
                printf("You use an item.\n");
                break;
            case 4:
                printf("You add a scare to the room.\n");
                break;
            case 5:
                printf("You remove a scare from the room.\n");
                break;
            case 6:
                printf("You leave the room.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        if (choice == 4) {
            printf("Enter a scare: ");
            scanf("%d", &chosenScare);
            scareNum++;
        }

        roomNum++;
        if (roomNum == 2) {
            numRooms++;
            roomNum = 0;
        }
    }

    printf("Thanks for playing the Haunted House Simulator!\n");
    return 0;
}