//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are about to embark on a terrifying journey through a haunted house...\n\n");

    int num_rooms = 10;
    int current_room = 1;
    int has_key = 0;
    int has_flashlight = 0;

    srand(time(NULL)); // Set seed for random number generation

    while (current_room <= num_rooms) {
        printf("You are currently in Room %d.\n", current_room);

        int rand_number = rand() % 3; // Generate random number between 0-2

        if (rand_number == 0) {
            printf("This room is empty. Keep moving.\n\n");
        } else if (rand_number == 1) {
            printf("You found a key! Take it with you.\n\n");
            has_key = 1;
        } else {
            printf("You found a flashlight! Take it with you.\n\n");
            has_flashlight = 1;
        }

        current_room++;

        if (current_room > num_rooms) {
            break; // End loop if player reaches final room
        }

        // Ask player for next move
        printf("What would you like to do? (0: Keep moving, 1: Try to unlock door)\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            if (has_key) {
                printf("Congratulations! You have unlocked the door and escaped the haunted house.\n");
                break; // End game
            } else {
                printf("You do not have a key. Keep searching for one.\n");
            }
        }
    }

    if (!has_key) {
        printf("Game over. You were unable to escape the haunted house.\n");
    }

    return 0;
}