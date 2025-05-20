//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a room
    char* room_name = "Room 1";

    // Create a ghost
    char* ghost_name = "Ghost 1";

    // Print a message to indicate the start of the simulation
    printf("Welcome to the Haunted House Simulator!\n");

    // Loop through the rooms
    while(1) {
        printf("Which room would you like to visit?\n");
        printf("1. %s\n", room_name);

        // Get user input
        char room_input[20];
        scanf("%s", room_input);

        // Check if user wants to quit
        if (strcmp(room_input, "quit") == 0) {
            break;
        }

        // If user wants to visit a room
        else if (strcmp(room_input, "1") == 0) {
            // Visit the room
            printf("You have entered %s.\n", room_name);

            // If a ghost is present in the room
            if (strcmp(ghost_name, "Ghost 1") == 0) {
                printf("A ghost is present in the room.\n");
                printf("The ghost has scared you away!\n");
            }

            // Change the room name for next visit
            else {
                strcpy(room_name, "Room 2");
            }

            // Print the room name again for next visit
            printf("Which room would you like to visit?\n");
            printf("1. %s\n", room_name);
        }

        // If user wants to visit a non-existent room
        else {
            printf("Invalid room input.\n");
        }
    }

    // Print a message to indicate the end of the simulation
    printf("The Haunted House Simulator has ended.\n");

    return 0;
}