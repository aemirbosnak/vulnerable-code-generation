//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int choice;
    int room = 1; // Starting room
    int status = 0; // 0 = Alive, 1 = Dead

    srand(time(NULL)); // Seed random number generator

    printf("Welcome to the Haunted House!\n");
    printf("You find yourself in room %d.\n", room);

    while(status == 0) {

        printf("\n");
        printf("What would you like to do?\n");
        printf("1. Move to another room\n");
        printf("2. Search for clues\n");
        printf("3. Defend yourself\n");
        printf("4. Quit\n");
        printf("\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\n");
                printf("You move to room %d.\n", (room % 10) + 1);
                break;
            case 2:
                printf("\n");
                printf("You search for clues and find a key!\n");
                break;
            case 3:
                printf("\n");
                printf("You defend yourself against a ghost!\n");
                break;
            case 4:
                printf("\n");
                printf("You quit the game.\n");
                status = 1; // Set status to dead
                break;
            default:
                printf("\n");
                printf("Invalid choice, try again.\n");
        }

        room++; // Move to next room
    }

    return 0;
}