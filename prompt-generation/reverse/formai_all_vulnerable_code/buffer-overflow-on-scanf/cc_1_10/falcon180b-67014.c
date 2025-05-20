//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_DICE 100
#define MAX_SIDES 100
#define MAX_ROLLS 100
#define MAX_NAME 20

typedef struct {
    char name[MAX_NAME];
    int num_dice;
    int num_sides;
} dice_t;

int roll_dice(int num_dice, int num_sides) {
    int i, sum = 0;
    for (i = 0; i < num_dice; i++) {
        int roll = rand() % num_sides + 1;
        sum += roll;
    }
    return sum;
}

int main() {
    int num_dice, num_sides, num_rolls, i, j, k, max_rolls = 0;
    char input[100];
    dice_t dice[MAX_DICE];
    int rolls[MAX_DICE][MAX_ROLLS];

    srand(time(NULL));

    // Get number of dice
    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);

    // Get number of sides for each dice
    for (i = 0; i < num_dice; i++) {
        printf("Enter the number of sides for dice %d: ", i+1);
        scanf("%d", &num_sides);

        // Check if number of sides is valid
        if (num_sides <= 0 || num_sides > MAX_SIDES) {
            printf("Invalid number of sides.\n");
            exit(1);
        }

        // Get name for each dice
        printf("Enter the name for dice %d: ", i+1);
        scanf("%s", dice[i].name);

        // Initialize rolls array
        for (j = 0; j < MAX_ROLLS; j++) {
            rolls[i][j] = 0;
        }
    }

    // Get number of rolls
    printf("Enter the number of rolls: ");
    scanf("%d", &num_rolls);

    // Roll the dice
    for (i = 0; i < num_dice; i++) {
        for (j = 0; j < num_rolls; j++) {
            rolls[i][j] = roll_dice(num_sides, num_sides);
        }
    }

    // Print the results
    for (i = 0; i < num_dice; i++) {
        printf("Results for dice %s:\n", dice[i].name);
        for (j = 0; j < num_rolls; j++) {
            printf("%d\n", rolls[i][j]);
        }
        printf("\n");
    }

    return 0;
}