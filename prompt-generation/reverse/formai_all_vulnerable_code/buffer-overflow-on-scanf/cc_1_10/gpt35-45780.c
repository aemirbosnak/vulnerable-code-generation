//FormAI DATASET v1.0 Category: Dice Roller ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to roll a dice
int rollDice() {
    return (rand() % 6) + 1; // return a random number between 1 and 6
}

// function to print a visual representation of a dice face
void printDice(int num) {
    printf("+-------+\n");
    if (num == 1) {
        printf("|       |\n");
        printf("|   *   |\n");
        printf("|       |\n");
    } else if (num == 2) {
        printf("| *     |\n");
        printf("|       |\n");
        printf("|     * |\n");
    } else if (num == 3) {
        printf("| *     |\n");
        printf("|   *   |\n");
        printf("|     * |\n");
    } else if (num == 4) {
        printf("| *   * |\n");
        printf("|       |\n");
        printf("| *   * |\n");
    } else if (num == 5) {
        printf("| *   * |\n");
        printf("|   *   |\n");
        printf("| *   * |\n");
    } else if (num == 6) {
        printf("| *   * |\n");
        printf("| *   * |\n");
        printf("| *   * |\n");
    }
    printf("+-------+\n");
}

int main() {
    srand(time(0)); // seed the random number generator
    char choice;
    printf("Welcome to the Dice Roller Program!\n");
    do {
        int roll1 = rollDice(); // first roll
        int roll2 = rollDice(); // second roll
        printf("Rolling the dice...\n");
        printf("Dice 1: ");
        printDice(roll1); // print visual representation of the first dice face
        printf("Dice 2: ");
        printDice(roll2); // print visual representation of the second dice face
        printf("Total: %d\n", roll1 + roll2); // print the sum of the two rolls
        printf("Do you want to roll again? (Y/N) ");
        scanf(" %c", &choice); // read user input for whether they want to roll again
    } while (choice == 'Y' || choice == 'y');
    printf("Thank you for using the Dice Roller Program!\n");
    return 0;
}