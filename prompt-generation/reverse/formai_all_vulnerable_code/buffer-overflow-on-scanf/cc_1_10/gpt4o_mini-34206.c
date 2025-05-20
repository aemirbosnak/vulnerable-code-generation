//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define MAX_FACES 20

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape codes to clear the terminal screen
}

void printMenu() {
    printf("=====================================\n");
    printf("          DICE ROLLER APP           \n");
    printf("=====================================\n");
    printf("1. Roll Dice\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

void rollDice(int numberOfDice, int faces) {
    int total = 0;

    printf("Rolling %d dice with %d faces...\n", numberOfDice, faces);
    for (int i = 0; i < numberOfDice; i++) {
        int roll = (rand() % faces) + 1;
        printf("Dice %d: %d\n", i + 1, roll);
        total += roll;
    }
    printf("Total: %d\n", total);
}

int main() {
    srand(time(NULL)); // Seed for random number generator
    int choice, numDice, numFaces;

    clearScreen();

    while (1) {
        printMenu();
        scanf("%d", &choice);
        
        if (choice == 2) {
            printf("Exiting the program. Goodbye!\n");
            break;
        } else if (choice != 1) {
            printf("Invalid Choice! Please try again.\n");
            continue;
        }

        printf("Enter number of dice (1 to %d): ", MAX_DICE);
        scanf("%d", &numDice);
        if (numDice < 1 || numDice > MAX_DICE) {
            printf("Invalid number of dice! Please choose between 1 and %d.\n", MAX_DICE);
            continue;
        }

        printf("Enter number of faces per die (2 to %d): ", MAX_FACES);
        scanf("%d", &numFaces);
        if (numFaces < 2 || numFaces > MAX_FACES) {
            printf("Invalid number of faces! Please choose between 2 and %d.\n", MAX_FACES);
            continue;
        }

        rollDice(numDice, numFaces);
        printf("Press Enter to continue...\n");
        getchar(); // clear the newline character after number input
        getchar(); // wait for the user to press enter
        clearScreen();
    }
    
    return 0;
}