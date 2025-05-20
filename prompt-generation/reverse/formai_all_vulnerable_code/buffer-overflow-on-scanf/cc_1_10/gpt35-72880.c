//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if user wants to enter a room
bool enterRoom() {
    char answer;
    printf("\nDo you want to enter this room? [Y/N]\n");
    scanf(" %c", &answer);
    if (answer == 'y' || answer == 'Y') {
        return true;
    } else {
        return false;
    }
}

// Function to display room description
void displayRoomDescription(int room) {
    printf("\nYou enter room %d.\n", room);
    switch (room) {
        case 1:
            printf("A cold draft greets you as you step through the door.\n");
            printf("You can hear whispers and footsteps from somewhere in the room.\n");
            break;
        case 2:
            printf("A dimly lit room filled with cobwebs and old furniture.\n");
            printf("Some of the furniture appears to have been moved recently.\n");
            break;
        case 3:
            printf("A room with broken furniture and shattered glass everywhere.\n");
            printf("You can feel a strong presence in the room.\n");
            break;
        case 4:
            printf("A room with a creaking door and dusty windows.\n");
            printf("There is a strong odor of decay and rot in the air.\n");
            break;
        case 5:
            printf("A room filled with old books and artifacts.\n");
            printf("A strange symbol is etched on the wall.\n");
            break;
        default:
            printf("You are lost in the maze of the haunted house.\n");
    }
}

int main() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You find yourself standing in the entrance hall of a creepy old mansion.\n");
    printf("You can see several doors leading to different rooms.\n");

    int currentRoom = 1; // Start in entrance hall
    bool gameOver = false;

    while (!gameOver) {
        displayRoomDescription(currentRoom);
        if (currentRoom == 1) {
            printf("You can see doors leading to rooms 2, 3, and 4.\n");
            if (enterRoom()) {
                currentRoom = 2;
            } else {
                printf("You decide not to enter this room.\n");
            }
        } else if (currentRoom == 2) {
            printf("You can see doors leading to rooms 1, 4, and 5.\n");
            if (enterRoom()) {
                currentRoom = 5;
            } else {
                printf("You decide not to enter this room.\n");
            }
        } else if (currentRoom == 3) {
            printf("You can see doors leading to rooms 1 and 4.\n");
            if (enterRoom()) {
                currentRoom = 4;
            } else {
                printf("You decide not to enter this room.\n");
            }
        } else if (currentRoom == 4) {
            printf("You can see doors leading to rooms 1, 2, and 3.\n");
            if (enterRoom()) {
                currentRoom = 1;
            } else {
                printf("You decide not to enter this room.\n");
            }
        } else if (currentRoom == 5) {
            printf("You can see a door leading back to room 2.\n");
            if (enterRoom()) {
                currentRoom = 2;
            } else {
                printf("You decide not to enter this room.\n");
            }
        }

        // Game over if user enters room 3
        if (currentRoom == 3) {
            printf("\nSuddenly, you are overcome by a feeling of dread.\n");
            printf("You turn around but the door is gone. You are trapped.\n");
            printf("You hear a chilling laughter as the room starts to shake.\n");
            printf("\nGAME OVER\n");
            gameOver = true;
        }
    }

    return 0;
}