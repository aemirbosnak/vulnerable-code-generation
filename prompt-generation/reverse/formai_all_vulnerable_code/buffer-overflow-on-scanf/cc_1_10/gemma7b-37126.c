//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare variables
    int choice, room, inventory[] = {0, 0, 0}, item_num = 0, is_dead = 0;

    // Initialize the room number
    room = 1;

    // Start the adventure
    while (!is_dead) {
        // Display the current room
        switch (room) {
            case 1:
                printf("You are in a dimly lit tavern.\n");
                break;
            case 2:
                printf("You are in a mysterious forest.\n");
                break;
            case 3:
                printf("You are in a crumbling castle.\n");
                break;
            default:
                printf("You are dead.\n");
                is_dead = 1;
                break;
        }

        // List the available actions
        printf("What do you want to do? (1) Fight, (2) Search, (3) Leave\n");

        // Get the user's choice
        scanf("%d", &choice);

        // Process the user's choice
        switch (choice) {
            case 1:
                // Fight the enemy
                printf("You fought the enemy and won!\n");
                inventory[item_num] = 1;
                item_num++;
                break;
            case 2:
                // Search the room
                printf("You searched the room and found a hidden item.\n");
                inventory[item_num] = 1;
                item_num++;
                break;
            case 3:
                // Leave the room
                room++;
                break;
            default:
                printf("Invalid input.\n");
                break;
        }
    }

    // End the adventure
    printf("Thank you for playing!\n");

    return 0;
}