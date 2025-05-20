//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>

void main() {
    int choice, room_num, inventory[] = {0, 0, 0}, flag = 0;
    char name[20];

    // Intro
    printf("Welcome to the mysterious mansion, %s. You have no memory of how you ended up here.\n", name);

    // Main loop
    while (!flag) {
        // Display available rooms
        printf("Available rooms: 1 - Dining Hall, 2 - Library, 3 - Ballroom\n");

        // Get user choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Switch case for user choice
        switch (choice) {
            case 1:
                room_num = 1;
                break;
            case 2:
                room_num = 2;
                break;
            case 3:
                room_num = 3;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                continue;
        }

        // Enter the chosen room
        switch (room_num) {
            case 1:
                printf("You are in the Dining Hall. There is a table with a feast, but it is not yours.\n");
                break;
            case 2:
                printf("You are in the Library. There are bookshelves and a fireplace. You find a hidden key.\n");
                inventory[0] = 1;
                break;
            case 3:
                printf("You are in the Ballroom. There is a grand piano and a stage. You hear footsteps approaching.\n");
                break;
        }

        // Check if the user has found the key
        if (inventory[0] == 1) {
            flag = 1;
            printf("You have found the key and escaped the mansion.\n");
        }
    }
}