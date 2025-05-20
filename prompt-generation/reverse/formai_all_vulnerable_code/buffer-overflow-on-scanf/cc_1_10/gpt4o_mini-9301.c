//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void startGame();
void forest();
void cave();
void village();
void printChoices();
void clearScreen();

// Main function
int main() {
    startGame();
    return 0;
}

// Function to start the game
void startGame() {
    clearScreen();
    printf("Welcome to the Adventure Game!\n");
    printf("You find yourself in a mysterious land filled with adventure.\n");
    printf("Where would you like to go?\n");
    printChoices();
}

// Function to display choices
void printChoices() {
    printf("1. Enter the Forest\n");
    printf("2. Explore the Cave\n");
    printf("3. Visit the Village\n");
    printf("4. Quit\n");

    int choice;
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            forest();
            break;
        case 2:
            cave();
            break;
        case 3:
            village();
            break;
        case 4:
            printf("Thanks for playing!\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
            printChoices();
            break;
    }
}

// Function for forest path
void forest() {
    clearScreen();
    printf("You walk into a dark forest, the trees loom high above you.\n");
    printf("You can hear rustling in the bushes.\n");
    printf("What would you like to do?\n");
    printf("1. Investigate the noise\n");
    printf("2. Continue walking deeper into the forest\n");
    printf("3. Go back\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("You discover a small fox hiding in the bushes. It seems scared.\n");
        printf("You can:\n");
        printf("1. Try to comfort the fox\n");
        printf("2. Leave it alone\n");
    } else if (choice == 2) {
        printf("You venture deeper and find a beautiful clearing with a sparkling lake.\n");
    } else {
        startGame();
    }
}

// Function for cave path
void cave() {
    clearScreen();
    printf("Entering the cave, you are greeted by damp air and a dim light.\n");
    printf("You can hear droplets of water echoing.\n");
    printf("What would you like to do?\n");
    printf("1. Explore the shadows\n");
    printf("2. Examine the strange markings on the wall\n");
    printf("3. Leave the cave\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("As you walk into the shadows, a bat flies by startling you!\n");
    } else if (choice == 2) {
        printf("The markings seem ancient; you feel a connection to the past.\n");
    } else {
        startGame();
    }
}

// Function for village path
void village() {
    clearScreen();
    printf("You arrive at a quaint village filled with kind people.\n");
    printf("The villagers greet you warmly.\n");
    printf("What would you like to do?\n");
    printf("1. Talk to the village elder\n");
    printf("2. Visit the market\n");
    printf("3. Leave the village\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("The elder shares stories of brave heroes who once lived here.\n");
    } else if (choice == 2) {
        printf("You find a stall selling beautiful handmade crafts.\n");
    } else {
        startGame();
    }
}

// Function to clear the screen
void clearScreen() {
    // Clear the console screen
    printf("\033[H\033[J");
}