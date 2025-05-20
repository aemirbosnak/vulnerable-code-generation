//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DICE_MAX 10 // Maximum number of dice to roll
#define DICE_TYPES 5 // Number of different dice types
#define SIDES_MAX 20 // Maximum number of sides on a die

typedef struct {
    int type; // Die type
    int sides; // Number of sides
} Dice;

Dice dice[DICE_MAX];

void roll_dice(int dice_count, int roll_count, Dice* dice) {
    int total = 0;
    for (int i = 0; i < dice_count; i++) {
        for (int j = 0; j < roll_count; j++) {
            int roll = rand() % (dice[i].sides + 1);
            total += roll;
            printf("Rolled %d on die type %d\n", roll, dice[i].type);
        }
    }
    printf("Total: %d\n", total);
}

int main() {
    srand(time(NULL));

    printf("Enter number of dice to roll (max %d): ", DICE_MAX);
    scanf("%d", &dice[0].type);

    if (dice[0].type > DICE_MAX) {
        printf("Error: Too many dice to roll.\n");
        return 1;
    }

    for (int i = 0; i < dice[0].type; i++) {
        printf("Enter die type %d (sides max %d): ", i + 1, SIDES_MAX);
        scanf("%d", &dice[i].sides);
        if (dice[i].sides > SIDES_MAX) {
            printf("Error: Invalid number of sides.\n");
            return 1;
        }
        dice[i].type = i + 1;
    }

    printf("Enter number of rolls for each die: ");
    int rolls[DICE_MAX];
    for (int i = 0; i < dice[0].type; i++) {
        scanf("%d", &rolls[i]);
    }

    roll_dice(dice[0].type, rolls, dice);

    return 0;
}