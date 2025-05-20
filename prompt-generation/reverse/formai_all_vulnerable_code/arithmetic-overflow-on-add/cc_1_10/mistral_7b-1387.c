//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int roll_dice(int faces) {
    int roll;
    time_t seed;
    char message[256];

    seed = time(NULL);
    srand(seed);
    roll = (rand() % faces) + 1;

    sprintf(message, "The mystical winds of Eldoria have whispered a secret number to the Enchanted Dice...\nThe number rolled is: %d\n", roll);
    printf("%s", message);

    return roll;
}

// Function to simulate rolling multiple dice
void roll_dice_set(int num_dice, int num_faces, int *rolls, int rolls_count) {
    int i, roll;

    for (i = 0; i < rolls_count; i++) {
        roll = roll_dice(num_faces);
        rolls[i] = roll;
    }
}

int main() {
    int i, num_dice, num_faces, rolls_count, *rolls;

    printf("\n*************************************************************************\n");
    printf("* Welcome, brave adventurer, to the Enchanted Dice Roller of Eldoria! *\n");
    printf("*************************************************************************\n");
    printf("\nPlease enter the number of dice you wish to roll: ");
    scanf("%d", &num_dice);
    printf("\nPlease enter the number of faces on each die: ");
    scanf("%d", &num_faces);
    printf("\nHow many times do you wish to roll the dice? ");
    scanf("%d", &rolls_count);

    rolls = (int *) malloc(rolls_count * sizeof(int));

    printf("\nRolling the dice...\n");
    roll_dice_set(num_dice, num_faces, rolls, rolls_count);

    printf("\nYour rolls are:\n");
    for (i = 0; i < rolls_count; i++) {
        printf("- Roll %d: %d\n", i + 1, rolls[i]);
    }

    free(rolls);

    return 0;
}