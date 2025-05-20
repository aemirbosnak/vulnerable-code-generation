//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM 10

struct Room {
    char description[256];
    int hasMonster;
};

void initializeRooms(struct Room rooms[]) {
    snprintf(rooms[0].description, sizeof(rooms[0].description), "You find yourself in a dimly lit hallway. Shadows dance on the wall.");
    rooms[0].hasMonster = 0;

    snprintf(rooms[1].description, sizeof(rooms[1].description), "A dusty library filled with cobwebs. Books lie scattered across the floor.");
    rooms[1].hasMonster = 1;

    snprintf(rooms[2].description, sizeof(rooms[2].description), "The once grand dining hall now stands in decay. A long table is set for an eerie feast.");
    rooms[2].hasMonster = 0;

    snprintf(rooms[3].description, sizeof(rooms[3].description), "A narrow staircase spirals downwards into darkness. You hear faint whispers.");
    rooms[3].hasMonster = 1;

    snprintf(rooms[4].description, sizeof(rooms[4].description), "An old kitchen, where the smell of rot hangs in the air. A pot bubbles ominously.");
    rooms[4].hasMonster = 0;

    snprintf(rooms[5].description, sizeof(rooms[5].description), "The cellar, cold and damp. You hear the sound of dripping water and muffled cries.");
    rooms[5].hasMonster = 1;

    snprintf(rooms[6].description, sizeof(rooms[6].description), "A decrepit bedroom, the bed is covered in dust. You sense an unseen presence.");
    rooms[6].hasMonster = 0;

    snprintf(rooms[7].description, sizeof(rooms[7].description), "An attic filled with old trunks and broken furniture. Ghostly laughter echoes.");
    rooms[7].hasMonster = 1;

    snprintf(rooms[8].description, sizeof(rooms[8].description), "A hallway with portraits watching you. Their eyes seem to follow your every move.");
    rooms[8].hasMonster = 0;

    snprintf(rooms[9].description, sizeof(rooms[9].description), "The front door is locked tight. A chilling wind threatens to sweep you away.");
    rooms[9].hasMonster = 0;
}

void encounterMonster() {
    printf("A monster appears! Do you want to (f)ight or (r)un? ");
    char choice;
    scanf(" %c", &choice);

    if (choice == 'f') {
        printf("You bravely fought the monster and emerged victorious! But you are injured...\n");
        // Add injury logic here if needed
    } else if (choice == 'r') {
        printf("You ran away safely... for now.\n");
    } else {
        printf("Invalid choice! The monster has caught you!\n");
        exit(0);
    }
}

void playGame() {
    struct Room rooms[MAX_ROOM];
    int currentRoom = 0;
    initializeRooms(rooms);
    char command[10];

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You will explore a series of rooms. Type 'look' to see your surroundings, 'exit' to leave the game, or 'next' to proceed to the next room.\n");

    while (1) {
        printf("\nRoom: %s\n", rooms[currentRoom].description);
        if (rooms[currentRoom].hasMonster) {
            encounterMonster();
        }

        printf("What will you do? (look/next/exit): ");
        scanf("%s", command);

        if (strcmp(command, "look") == 0) {
            printf("You look around and see: %s\n", rooms[currentRoom].description);
        } else if (strcmp(command, "next") == 0) {
            if (currentRoom < MAX_ROOM - 1) {
                currentRoom++;
            } else {
                printf("You have reached the end of the house. You are now outside, safe at last!\n");
                break;
            }
        } else if (strcmp(command, "exit") == 0) {
            printf("Thank you for playing! Goodbye!\n");
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
}

int main() {
    srand(time(NULL));
    playGame();
    return 0;
}