//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 10
#define MAX_ITEMS 10

int main() {
    int numRooms = 0;
    int numItems = 0;
    int numEnemies = 0;
    int numBosses = 0;

    // Display welcome message
    printf("Welcome to the Haunted House Simulator!\n");

    // Display configuration options
    printf("Please choose a configuration:\n");
    printf("1. Small House (1-3 rooms, 1-3 items, 1-3 enemies, 1 boss)\n");
    printf("2. Medium House (4-6 rooms, 2-4 items, 2-5 enemies, 2 bosses)\n");
    printf("3. Large House (7-10 rooms, 3-6 items, 3-7 enemies, 3-5 bosses)\n");
    printf("4. Quit\n");
    int choice;
    scanf("%d", &choice);

    // Execute based on user's choice
    switch (choice) {
        case 1:
            // Small house configuration
            numRooms = rand() % 3 + 1;
            numItems = rand() % 3 + 1;
            numEnemies = rand() % 3 + 1;
            numBosses = 1;
            break;
        case 2:
            // Medium house configuration
            numRooms = rand() % 4 + 1;
            numItems = rand() % 4 + 1;
            numEnemies = rand() % 4 + 1;
            numBosses = 2;
            break;
        case 3:
            // Large house configuration
            numRooms = rand() % 7 + 1;
            numItems = rand() % 6 + 1;
            numEnemies = rand() % 7 + 1;
            numBosses = 3;
            break;
        case 4:
            // Exit program
            printf("Exiting program...\n");
            break;
        default:
            // Invalid choice
            printf("Invalid choice. Please choose a valid option.\n");
            break;
    }

    // Display room information
    printf("Rooms:\n");
    for (int i = 0; i < numRooms; i++) {
        printf("Room %d: ", i + 1);
        printf("unknown\n");
    }

    // Display item information
    printf("Items:\n");
    for (int i = 0; i < numItems; i++) {
        printf("Item %d: ", i + 1);
        printf("unknown\n");
    }

    // Display enemy information
    printf("Enemies:\n");
    for (int i = 0; i < numEnemies; i++) {
        printf("Enemy %d: ", i + 1);
        printf("unknown\n");
    }

    // Display boss information
    printf("Bosses:\n");
    for (int i = 0; i < numBosses; i++) {
        printf("Boss %d: ", i + 1);
        printf("unknown\n");
    }

    // End of program
    printf("Program finished.\n");

    return 0;
}