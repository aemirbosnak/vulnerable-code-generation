//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: complex
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
    char name[20];
    int room;
    int active;
} Ghost;

Ghost ghosts[MAX_GHOSTS] = {
    {"John Doe", 1, 1},
    {"Mary Smith", 2, 1},
    {"Peter Jones", 3, 1},
    {"Jane Doe", 4, 1},
    {"Billy Smith", 5, 0}
};

int main() {
    srand(time(NULL));
    int i, j, r, ghost_num;
    char command;

    // Print the haunted house layout
    printf("You are in the Haunted House of Oakwood Manor.\n");
    printf("The house is divided into five rooms: 1, 2, 3, 4, and 5.\n");

    // Create a loop to handle user input
    while (1) {
        // Get the user's command
        printf("Enter your command (help, move, interact): ");
        scanf("%c", &command);

        // Check if the user wants to get help
        if (command == 'h') {
            printf("Available commands:\n");
            printf("help: Display this help message\n");
            printf("move: Move to a different room\n");
            printf("interact: Interact with a ghost\n");
        }

        // Check if the user wants to move to a different room
        else if (command == 'm') {
            printf("Enter the room number you want to move to: ");
            scanf("%d", &r);

            // Check if the room number is valid
            if (r >= 1 && r <= 5) {
                // Move the user to the specified room
                printf("You have moved to room %d.\n", r);
            } else {
                printf("Invalid room number.\n");
            }
        }

        // Check if the user wants to interact with a ghost
        else if (command == 'i') {
            printf("Enter the name of the ghost you want to interact with: ");
            scanf("%s", ghosts[ghost_num].name);

            // Check if the ghost is active
            if (ghosts[ghost_num].active) {
                // Interact with the ghost
                printf("You have interacted with %s.\n", ghosts[ghost_num].name);
            } else {
                printf("The ghost is not active.\n");
            }
        }

        // Check if the user wants to quit
        else if (command == 'q') {
            printf("Thank you for visiting the Haunted House of Oakwood Manor. Goodbye!\n");
            break;
        }

        // Invalid command
        else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}