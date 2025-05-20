//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MAX_SIDES 1000

typedef struct {
    int num_dice;
    int num_sides;
    char *name;
} dice_t;

void roll_dice(dice_t *dice) {
    int i, j, total = 0;
    for (i = 0; i < dice->num_dice; i++) {
        for (j = 1; j <= dice->num_sides; j++) {
            if (rand() % dice->num_sides == j) {
                total += j;
                break;
            }
        }
    }
    printf("You rolled %d with %d %s-sided dice.\n", total, dice->num_dice, dice->name);
}

void main() {
    srand(time(NULL));
    dice_t dice1 = {.num_dice = 2,.num_sides = 6,.name = "six-sided"};
    dice_t dice2 = {.num_dice = 3,.num_sides = 20,.name = "twenty-sided"};
    dice_t dice3 = {.num_dice = 4,.num_sides = 4,.name = "four-sided"};
    int choice;
    
    printf("Welcome to the Dice Roller!\n");
    printf("Choose a dice:\n1. %s\n2. %s\n3. %s\n", dice1.name, dice2.name, dice3.name);
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            roll_dice(&dice1);
            break;
        case 2:
            roll_dice(&dice2);
            break;
        case 3:
            roll_dice(&dice3);
            break;
        default:
            printf("Invalid choice.\n");
    }
}