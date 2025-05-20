//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printDiceFace(int face) {
    printf(" -----------\n");
    printf("|           |\n");

    switch (face) {
        case 1:
            printf("|     *     |\n");
            break;
        case 2:
            printf("| *         |\n");
            printf("|      *    |\n");
            break;
        case 3:
            printf("| *       * |\n");
            break;
        case 4:
            printf("| *     *   |\n");
            printf("|     *     |\n");
            break;
        case 5:
            printf("| *     *   |\n");
            printf("|   *   *   |\n");
            break;
        case 6:
            printf("| *   * *   |\n");
            printf("| *     *   |\n");
            break;
    }

    printf("|           |\n");
    printf(" -----------\n");
}

int rollDice() {
    return (rand() % 6) + 1;  // Returns a random number between 1 and 6
}

void shapeShift(int *face) {
    printf("\nShapeshifting your dice...\n");
    usleep(1000000);  // Simulate a delay of 1 second
    *face = rollDice();
}

int main() {
    int diceFace, rolls, i;
    char choice;

    srand(time(NULL));  // seed the random number generator

    printf("Welcome to the Shape Shifting Dice Roller!\n");
    printf("How many times would you like to roll the dice? ");
    
    // Input validation for the number of rolls
    while (1) {
        scanf("%d", &rolls);
        if (rolls > 0) break;
        printf("Please enter a positive number: ");
    }

    for (i = 0; i < rolls; i++) {
        shapeShift(&diceFace);
        printDiceFace(diceFace);
        printf("Do you want to roll again? (y/n): ");
        scanf(" %c", &choice);
        
        // Check if the user wants to continue rolling
        if (choice != 'y' && choice != 'Y') {
            printf("Thank you for using the Shape Shifting Dice Roller!\n");
            break;
        }
    }

    return 0;
}