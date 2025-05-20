//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIDES 6
#define MAX_DICE 100

// Function to roll a single die
int roll_die() {
    return rand() % SIDES + 1;
}

// Function to roll multiple dice and return their total value
int roll_dice(int num_dice) {
    int total = 0;
    for (int i = 0; i < num_dice; i++) {
        total += roll_die();
    }
    return total;
}

// Function to print a single die roll
void print_die(int roll) {
    printf("%d", roll);
}

// Function to print the results of rolling multiple dice
void print_dice(int num_dice, int *rolls) {
    printf("Rolling %d dice...\n", num_dice);
    for (int i = 0; i < num_dice; i++) {
        printf("Die %d: %d\n", i + 1, rolls[i]);
    }
    printf("Total: %d\n", rolls[0]);
}

int main() {
    srand(time(NULL));

    int num_dice;
    printf("How many dice do you want to roll? ");
    scanf("%d", &num_dice);

    int rolls[MAX_DICE];
    for (int i = 0; i < num_dice; i++) {
        rolls[i] = roll_die();
    }

    print_dice(num_dice, rolls);

    return 0;
}