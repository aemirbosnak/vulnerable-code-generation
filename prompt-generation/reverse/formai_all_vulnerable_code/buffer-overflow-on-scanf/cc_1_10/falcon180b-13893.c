//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void hauntedHouse(int numRooms, int numGhosts) {
    int room;
    int ghost;

    srand(time(NULL));

    printf("Welcome to the Haunted House!\n");
    printf("There are %d rooms and %d ghosts.\n", numRooms, numGhosts);

    for (room = 1; room <= numRooms; room++) {
        printf("You enter room %d...\n", room);

        ghost = rand() % numGhosts;
        switch (ghost) {
            case 0:
                printf("A ghostly figure appears before you, but then disappears just as quickly.\n");
                break;
            case 1:
                printf("You hear eerie laughter coming from somewhere in the room.\n");
                break;
            case 2:
                printf("A cold wind blows through the room, chilling you to the bone.\n");
                break;
            case 3:
                printf("The door slams shut behind you, trapping you in the room.\n");
                break;
            default:
                printf("Nothing happens.\n");
                break;
        }

        printf("Do you want to continue exploring the haunted house? (y/n)\n");
        char choice;
        scanf("%c", &choice);

        if (choice == 'n') {
            printf("You leave the haunted house, feeling relieved but also a little disappointed.\n");
            return;
        }
    }

    printf("Congratulations! You have survived the Haunted House!\n");
}

int main() {
    int numRooms;
    int numGhosts;

    printf("Enter the number of rooms in the haunted house: ");
    scanf("%d", &numRooms);

    printf("Enter the number of ghosts in the haunted house: ");
    scanf("%d", &numGhosts);

    hauntedHouse(numRooms, numGhosts);

    return 0;
}