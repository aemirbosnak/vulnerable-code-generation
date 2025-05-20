//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 1000
#define MAX_SIDES 1000

typedef struct {
    int num_dice;
    int num_sides;
    int total;
} DiceRoll;

int main() {
    srand(time(NULL));

    int num_dice;
    int num_sides;

    printf("Enter the number of dice to roll: ");
    scanf("%d", &num_dice);

    printf("Enter the number of sides on each die: ");
    scanf("%d", &num_sides);

    DiceRoll *rolls = malloc(num_dice * sizeof(DiceRoll));

    for (int i = 0; i < num_dice; i++) {
        rolls[i].num_dice = num_dice;
        rolls[i].num_sides = num_sides;
        rolls[i].total = 0;
    }

    for (int i = 0; i < num_dice; i++) {
        for (int j = 0; j < num_sides; j++) {
            int roll = rand() % num_sides + 1;
            rolls[i].total += roll;
        }
    }

    printf("Dice Rolls:\n");
    for (int i = 0; i < num_dice; i++) {
        printf("Dice %d rolled: ", i + 1);
        for (int j = 0; j < num_sides; j++) {
            printf("%d ", rolls[i].total / num_sides);
        }
        printf("\n");
    }

    free(rolls);

    return 0;
}