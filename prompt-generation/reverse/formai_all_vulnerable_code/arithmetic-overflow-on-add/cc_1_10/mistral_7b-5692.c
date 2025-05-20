//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DICE_SIDE 6
#define DICE_PAIR 2

// Struct to represent a single die
typedef struct {
    int sides;
    int value;
} Die;

// Function to roll a single die
int roll_die(Die *d) {
    d->value = rand() % (d->sides + 1);
    return d->value;
}

// Function to roll a pair of dice
void roll_dice(Die *dice1, Die *dice2) {
    printf("Rolling the dice...\n");
    roll_die(dice1);
    roll_die(dice2);
    printf("Die 1 rolled a %d, Die 2 rolled a %d.\n", dice1->value, dice2->value);
}

// Function to check if two dice have the same value
int dice_match(Die *dice1, Die *dice2) {
    return dice1->value == dice2->value;
}

// Function to simulate rolling a pair of dice and checking for a match
int main() {
    srand(time(NULL));

    Die dice1, dice2;

    printf("Starting the game...\n");

    roll_dice(&dice1, &dice2);

    if (dice_match(&dice1, &dice2)) {
        printf("You rolled a pair! Congratulations!\n");
    } else {
        printf("Sorry, you didn't roll a pair this time.\n");
    }

    return 0;
}