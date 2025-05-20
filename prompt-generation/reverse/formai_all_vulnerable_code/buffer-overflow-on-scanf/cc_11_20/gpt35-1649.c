//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Define our room variables
    int roomNumber = 1;
    int ghostCount = 0;
    int trapCount = 0;
    int itemCount = 0;
    int exitRoom = 0;

    // Welcome the player
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You wake up in a dark room with no memory of how you got there.\n");
    printf("You notice a list of instructions on the wall:\n");
    printf("1. Find the exit room and escape.\n");
    printf("2. Avoid traps.\n");
    printf("3. Collect items.\n");
    printf("4. Beware of ghosts.\n\n");

    // Start the game loop
    while (roomNumber != exitRoom) {
        // Print the current room number
        printf("You are in room %d.\n", roomNumber);

        // Generate random events
        int randomEvent = rand() % 4;
        switch (randomEvent) {
            case 0:
                // Ghost room
                printf("This room is haunted by a ghost!\n");
                ghostCount++;
                break;
            case 1:
                // Trap room
                printf("This room is filled with traps!\n");
                trapCount++;
                break;
            case 2:
                // Item room
                printf("You have found an item!\n");
                itemCount++;
                break;
            case 3:
                // Empty room
                printf("This room is empty.\n");
                break;
        }

        // Check if the room has an exit
        if (roomNumber == 10) {
            exitRoom = 10;
        }

        // Prompt the player
        printf("What would you like to do?\n");
        printf("1. Move to the next room\n");
        printf("2. Check your inventory\n");
        int choice;
        scanf("%d", &choice);

        // Handle the player's choice
        switch (choice) {
            case 1:
                // Move to the next room
                if (randomEvent != 1 && randomEvent != 0) {
                  roomNumber++;
                }
                else if (randomEvent == 1) {
                  printf("You fell into a trap! You are sent back to the first room.\n");
                  roomNumber = 1;
                }
                else if (randomEvent == 0) {
                  printf("You were scared by the ghost and ran back to the first room.\n");
                  roomNumber = 1;
                }
                break;
            case 2:
                // Check inventory
                printf("Inventory: \n");
                printf("- %d ghost(s) avoided\n", ghostCount);
                printf("- %d trap(s) avoided\n", trapCount);
                printf("- %d item(s) collected\n", itemCount);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    // Game over
    printf("You escaped the haunted house! Congratulations!\n");
    printf("Final inventory: \n");
    printf("- %d ghost(s) avoided\n", ghostCount);
    printf("- %d trap(s) avoided\n", trapCount);
    printf("- %d item(s) collected\n", itemCount);

    return 0;
}