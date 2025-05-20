//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the story
void printStory(int room) {
    switch(room) {
        case 1:
            printf("You are in a dark and mysterious forest. The trees loom high above you, blocking out most of the sunlight. There are three paths leading out of this clearing: one to the north, one to the east, and one to the west.\n");
            break;
        case 2:
            printf("You have entered a small cave. The air is damp and chilly. Stalactites hang from the ceiling like icicles. There is a passageway leading deeper into the cave, and another leading back out to the forest.\n");
            break;
        case 3:
            printf("This room is filled with ancient ruins. Stone pillars support the ceiling, and strange symbols are etched into the walls. There is a door to the east, and another to the west.\n");
            break;
        case 4:
            printf("You find yourself in a large chamber. A dimly lit torch flickers on the wall, casting eerie shadows across the floor. There are three doors leading out of this room: one to the north, one to the east, and one to the south.\n");
            break;
        case 5:
            printf("This room is filled with glittering treasure! Gold coins, precious gems, and valuable artifacts are piled high all around you. There is a single door leading back out to the ruins.\n");
            break;
        default:
            printf("Invalid room number.\n");
            break;
    }
}

// Function to get user input
int getInput(int min, int max) {
    int choice;
    printf("Enter your choice (%d-%d): ", min, max);
    scanf("%d", &choice);
    return choice;
}

// Function to move between rooms
void move(int currentRoom, int newRoom) {
    printf("You move from Room %d to Room %d.\n", currentRoom, newRoom);
    printf("Press ENTER to continue...\n");
    getchar();
}

int main() {
    int currentRoom = 1;
    int choice;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Main game loop
    while(currentRoom!= 5) {
        // Print the current room's story
        printStory(currentRoom);

        // Get the user's choice
        choice = getInput(1, 3);

        // Move to the chosen room
        switch(choice) {
            case 1:
                move(currentRoom, 2);
                currentRoom = 2;
                break;
            case 2:
                move(currentRoom, 3);
                currentRoom = 3;
                break;
            case 3:
                move(currentRoom, 4);
                currentRoom = 4;
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    // The player has reached the treasure room!
    printf("Congratulations! You have found the treasure!\n");

    return 0;
}