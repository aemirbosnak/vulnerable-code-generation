//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define MIN_SIDE 1
#define MAX_SIDE 6

int main() {
    int i, num_dice, sides, roll;
    char opcode;

    // Initialize random seed
    srand(time(NULL));

    printf("Welcome to the Invasive Dice Roller!\n");
    printf("This program will roll the dice in a way that only an insider would understand.\n");

    while (1) {
        printf("\nEnter number of dice to roll (max %d): ", MAX_DICE);
        scanf("%d%c", &num_dice, &opcode);

        if (opcode != '\n') {
            printf("Invalid input! Use Enter key only.\n");
            continue;
        }

        if (num_dice < 1 || num_dice > MAX_DICE) {
            printf("Invalid number of dice! Please enter a number between 1 and %d.\n", MAX_DICE);
            continue;
        }

        printf("\nEnter number of sides on each die (max %d): ", MAX_SIDE);
        scanf("%d%c", &sides, &opcode);

        if (opcode != '\n') {
            printf("Invalid input! Use Enter key only.\n");
            continue;
        }

        if (sides < MIN_SIDE || sides > MAX_SIDE) {
            printf("Invalid number of sides! Please enter a number between %d and %d.\n", MIN_SIDE, MAX_SIDE);
            continue;
        }

        printf("\nRolling %d %d-sided dice...\n", num_dice, sides);

        for (i = 0; i < num_dice; i++) {
            roll = rand() % sides + 1;
            printf("Die %d rolled a %d.\n", i + 1, roll);
        }

        printf("\nPress Enter to roll again or any other key to exit.\n");
        getchar();

        if (getchar() != '\n') {
            printf("Exiting program...\n");
            exit(0);
        }
    }

    return 0;
}