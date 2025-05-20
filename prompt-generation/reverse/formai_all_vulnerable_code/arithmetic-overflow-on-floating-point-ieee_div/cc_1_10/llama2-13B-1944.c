//LLAMA2-13B DATASET v1.0 Category: Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define PI 3.14159

int main() {
    int chance, rolls;
    float total, average;
    char name[50];

    // Welcome to the magic dice game!
    printf("Welcome, adventurer, to the enchanted realm of dice! \n");
    printf("I am the Dice Wizard, and I will guide you through a world of \n");
    printf("magical dice rolls and fantastical outcomes. Are you ready to begin? \n\n");

    // Ask the player for their name.
    printf("What is your name, brave adventurer? (up to 50 characters)\n");
    scanf("%49s", name);

    // Ask the player how many rolls they would like to make.
    printf("How many rolls would you like to make? (enter a positive integer)\n");
    scanf("%d", &rolls);

    // Ask the player if they want to roll for a specific number or just keep rolling.
    printf("Do you want to roll for a specific number or just keep rolling? (enter 'specific' or 'keep')\n");
    scanf("%s", &chance);

    // Initialize the total and average.
    total = 0;
    average = 0;

    // Start rolling!
    for (int i = 0; i < rolls; i++) {
        // Roll the dice!
        int die1 = rand() % 6 + 1;
        int die2 = rand() % 6 + 1;
        int roll = die1 + die2;

        // Add the roll to the total and average.
        total += roll;
        average = (total / i) * 100;

        // Print the roll and the average.
        printf("Roll %d: %d + %d = %d\n", i + 1, die1, die2, roll);
        printf("Average: %3.2f%%\n", average);

        // Check if the player wants to stop.
        if (chance == "specific") {
            break;
        }
    }

    // Print the final total and average.
    printf("Total: %d\nAverage: %3.2f%%\n", total, average);

    // Thank the player for playing.
    printf("Thanks for playing the magic dice game, %s! May the rolls be ever in your favor. \n\n", name);

    return 0;
}