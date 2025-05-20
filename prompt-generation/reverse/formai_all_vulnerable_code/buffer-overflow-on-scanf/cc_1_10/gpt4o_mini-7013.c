//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROOMS 5

void enterRoom(int room);
void showRoomDescription(int room);
int randomEvent();

int main() {
    int choice = 0;
    srand(time(NULL)); // Seed the random number generator

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You will navigate through various spooky rooms.\n");
    printf("Prepare for unexpected events!\n");

    while (choice != -1) {
        printf("\nChoose a room to enter (0-%d) or -1 to exit: ", NUM_ROOMS - 1);
        scanf("%d", &choice);

        if (choice >= 0 && choice < NUM_ROOMS) {
            enterRoom(choice);
        } else if (choice != -1) {
            printf("Invalid choice! Please choose a valid room.\n");
        }
    }

    printf("Thank you for playing! Come back for more scares!\n");
    return 0;
}

void enterRoom(int room) {
    showRoomDescription(room);
    int event = randomEvent();

    switch (event) {
        case 0:
            printf("You found a friendly ghost! He gives you a treasure!\n");
            break;
        case 1:
            printf("A skeleton jumps out at you! You scream and run away!\n");
            break;
        case 2:
            printf("You hear strange whispers... It's just the wind.\n");
            break;
        case 3:
            printf("A trapdoor opens beneath you! Whoa!\n");
            break;
        default:
            break;
    }
}

void showRoomDescription(int room) {
    switch (room) {
        case 0:
            printf("You enter the living room. Cobwebs hang from the ceilings and a chandelier swings.\n");
            break;
        case 1:
            printf("You step into the kitchen. The smell of something rotten fills the air.\n");
            break;
        case 2:
            printf("You find yourself in the dining room. A long table is set for a ghostly dinner.\n");
            break;
        case 3:
            printf("You wander into the basement. It's dark and damp, a chill runs down your spine.\n");
            break;
        case 4:
            printf("You enter the attic. Old chests are piled high, and the air is thick with dust.\n");
            break;
        default:
            printf("This room doesn't exist.\n");
            break;
    }
}

int randomEvent() {
    return rand() % 4; // Generate a random event between 0 and 3
}