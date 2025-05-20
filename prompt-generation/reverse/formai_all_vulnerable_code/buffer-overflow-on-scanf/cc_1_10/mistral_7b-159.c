//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DICE 5
#define MAX_SIDES 6

typedef struct {
    int sides;
    int roll;
} Die;

void roll_dice(Die *dice, int num_dice);
void print_dice(Die *dice, int num_dice);
void menu();

int main() {
    Die dice[NUM_DICE];

    srand(time(NULL));

    menu();

    return 0;
}

void roll_dice(Die *dice, int num_dice) {
    for (int i = 0; i < num_dice; i++) {
        dice[i].sides = 6; // default to 6-sided dice
        dice[i].roll = rand() % dice[i].sides + 1;
    }
}

void print_dice(Die *dice, int num_dice) {
    for (int i = 0; i < num_dice; i++) {
        printf("Die %d rolled a %d\n", i+1, dice[i].roll);
    }
}

void menu() {
    int num_dice, sides;

    printf("Welcome to the Dice Roller!\n");
    printf("1. Roll Dice\n");
    printf("2. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &num_dice);

    if (num_dice != 1) {
        printf("Invalid choice. Exiting program...\n");
        return;
    }

    printf("How many sides does each die have? (default is 6): ");
    scanf("%d", &sides);

    Die dice[NUM_DICE];
    roll_dice(dice, NUM_DICE);

    printf("The results are:\n");
    print_dice(dice, NUM_DICE);

    menu();
}