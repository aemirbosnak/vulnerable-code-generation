//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 6 (inclusive)
int rollDice() {
    return rand() % 6 + 1;
}

// Function to print the result of a dice roll
void printRoll(int result) {
    switch (result) {
        case 1:
            printf("You rolled a 1.\n");
            break;
        case 2:
            printf("You rolled a 2.\n");
            break;
        case 3:
            printf("You rolled a 3.\n");
            break;
        case 4:
            printf("You rolled a 4.\n");
            break;
        case 5:
            printf("You rolled a 5.\n");
            break;
        case 6:
            printf("You rolled a 6.\n");
            break;
        default:
            printf("Invalid result.\n");
            break;
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    int numRolls;
    printf("How many times do you want to roll the dice? ");
    scanf("%d", &numRolls);

    for (int i = 0; i < numRolls; i++) {
        int result = rollDice();
        printRoll(result);
    }

    return 0;
}