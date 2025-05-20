//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to simulate a dice roll
int rollDice() {
    int result = randInt(1, 6);
    printf("You rolled a %d!\n", result);
    return result;
}

// Function to simulate a card draw
int drawCard() {
    int result = randInt(1, 13);
    printf("You drew a card with a value of %d!\n", result);
    return result;
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    // Cyberpunk-style ASCII art
    printf("_______\n");
    printf("|       |\n");
    printf("|       | ___\n");
    printf("|  _    | |  |\n");
    printf("| | |   | |  |\n");
    printf("| |_|   |___|\n");
    printf("|       |   |\n");
    printf("|       |\n");
    printf("|_______|___|\n");

    // Game loop
    int choice;
    int credits = 100; // Starting credits for the player
    do {
        printf("\n");
        printf("You have %d credits.\n", credits);
        printf("What would you like to do?\n");
        printf("1. Roll the dice\n");
        printf("2. Draw a card\n");
        printf("3. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                credits -= 10; // Cost of rolling the dice
                rollDice();
                break;
            case 2:
                credits -= 20; // Cost of drawing a card
                drawCard();
                break;
            case 3:
                printf("Thanks for playing!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
        printf("\n");
    } while (credits >= 0);

    return 0;
}