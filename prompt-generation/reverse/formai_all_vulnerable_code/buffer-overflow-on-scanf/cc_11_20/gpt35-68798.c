//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are about to embark on a scary adventure...\n\n");

    // Random seed for spooky events
    srand(time(NULL));

    // Initialize variables
    int room = 1;
    int flashlight = 0;
    int ghost = 0;
    int spider = 0;
    int trap = 0;

    // Game loop
    while (1) {
        printf("You are in room %d\n", room);

        // Check for and handle events
        if (flashlight == 0 && room == 1) {
            printf("There is a flashlight on the table.\n");
        } else if (room == ghost) {
            printf("You have encountered a spooky ghost!\n");
        } else if (room == spider) {
            printf("You have walked into a spider web!\n");
        } else if (room == trap) {
            printf("You have fallen into a trap!\n");
            break;
        }

        // Handle player input
        printf("What do you want to do?\n");
        printf("1. Move to next room\n");
        printf("2. Pick up flashlight\n");
        printf("3. Use flashlight\n");
        printf("4. Quit game\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            room++;
        } else if (choice == 2 && flashlight == 0 && room == 1) {
            printf("You picked up the flashlight.\n");
            flashlight = 1;
        } else if (choice == 3 && flashlight == 1) {
            printf("You turned on the flashlight.\n");
            int event = rand() % 3 + 2;
            if (event == 2) {
                ghost = room;
            } else if (event == 3) {
                spider = room;
            } else {
                printf("There are no spooky events in this room.\n");
            }
        } else if (choice == 4) {
            printf("You have quit the game.\n");
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    printf("Thank you for playing!\n");
    return 0;
}