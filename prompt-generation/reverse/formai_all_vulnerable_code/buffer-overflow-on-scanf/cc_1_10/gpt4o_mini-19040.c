//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 5

const char *rooms[MAX_ROOMS] = {
    "Dark Living Room",
    "Creepy Kitchen",
    "Haunted Hallway",
    "Spooky Basement",
    "Chilling Attic"
};

void displayWelcomeMessage() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("Can you survive the night?\n\n");
}

void displayRoom(int roomIndex) {
    printf("You enter the %s...\n", rooms[roomIndex]);
    printf("What will you do?\n");
    printf("1. Explore\n");
    printf("2. Run away!\n");
}

int randomEvent() {
    return rand() % 3; // Random event: 0, 1, or 2
}

void handleChoice(int choice, int roomIndex) {
    switch (choice) {
        case 1: // Explore
            if (randomEvent() == 0) {
                printf("You found a hidden treasure! 🎉\n");
            } else if (randomEvent() == 1) {
                printf("A ghost jumps out at you! 👻 You faint!\n");
                printf("Game Over!\n");
                exit(0);
            } else {
                printf("You hear spooky whispers, but it's just the wind...\n");
            }
            break;
        case 2: // Run away
            printf("You run out of the Haunted House, heart racing!\n");
            printf("You are safe... for now! 😅\n");
            exit(0);
            break;
        default:
            printf("Invalid choice! Try again!\n");
            break;
    }
}

void playGame() {
    srand(time(NULL));
    int currentRoom = 0;

    while (currentRoom < MAX_ROOMS) {
        displayRoom(currentRoom);
        int choice;
        printf("Enter your choice (1 or 2): ");
        scanf("%d", &choice);
        handleChoice(choice, currentRoom);
        currentRoom++;
        printf("\n");
    }

    printf("Congratulations! You explored all the rooms of the Haunted House! 🎊\n");
}

int main() {
    displayWelcomeMessage();
    playGame();
    return 0;
}