//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 5

typedef struct {
    char* description;
    int hasMonster;
} Room;

Room rooms[MAX_ROOMS];
int currentRoom = 0;

void initializeRooms() {
    rooms[0].description = "You enter a dimly lit hallway. Shadows flicker on the walls. ";
    rooms[0].hasMonster = 0;

    rooms[1].description = "You find yourself in a dusty library filled with ancient tomes. ";
    rooms[1].hasMonster = 1;

    rooms[2].description = "A cold breeze chills you as you enter a dilapidated kitchen. ";
    rooms[2].hasMonster = 0;

    rooms[3].description = "You step into a grand ballroom, the echoes of laughter linger. ";
    rooms[3].hasMonster = 1;

    rooms[4].description = "You walk into an eerie garden, overgrown and silent. ";
    rooms[4].hasMonster = 0;
}

void printRoomDescription() {
    printf("%s\n", rooms[currentRoom].description);
    if (rooms[currentRoom].hasMonster) {
        printf("A monster lurks here!\n");
    }
}

int getMonsterReaction() {
    return rand() % 2; // 0 = flee, 1 = attack
}

void encounterMonster() {
    printf("You have encountered a monster!\n");
    int reaction = getMonsterReaction();
    if (reaction == 0) {
        printf("The monster flees in terror!\n");
    } else {
        printf("The monster attacks you! You have died.\n");
        exit(0);
    }
}

void navigate() {
    int choice;
    printf("\nWhere would you like to go?\n");
    printf("1. Move to the next room\n");
    printf("2. Move to the previous room\n");
    printf("3. Exit the house\n");
    printf("Choose an option: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            if (currentRoom < MAX_ROOMS - 1) {
                currentRoom++;
                if (rooms[currentRoom].hasMonster) {
                    encounterMonster();
                }
            } else {
                printf("You are already in the last room.\n");
            }
            break;
        case 2:
            if (currentRoom > 0) {
                currentRoom--;
                if (rooms[currentRoom].hasMonster) {
                    encounterMonster();
                }
            } else {
                printf("You are already in the first room.\n");
            }
            break;
        case 3:
            printf("You have bravely exited the haunted house. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
    }
}

int main() {
    srand(time(0));
    initializeRooms();
    
    printf("Welcome to the Haunted House Simulator!\n");
    
    while (1) {
        printRoomDescription();
        navigate();
    }

    return 0;
}