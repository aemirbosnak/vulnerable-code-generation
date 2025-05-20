//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 1000
#define MAX_SIDES 1000

typedef struct {
    int num_sides;
    char *name;
} dice_t;

dice_t dice[MAX_DICE];
int num_dice = 0;

void add_dice(int num_sides, char *name) {
    if (num_dice >= MAX_DICE) {
        printf("Error: Too many dice!\n");
        return;
    }
    dice[num_dice].num_sides = num_sides;
    dice[num_dice].name = name;
    num_dice++;
}

int roll_dice(int num_rolls, int *results) {
    srand(time(NULL));
    for (int i = 0; i < num_rolls; i++) {
        results[i] = rand() % dice[0].num_sides + 1;
    }
    return 0;
}

int main() {
    add_dice(6, "Six-sided dice");
    add_dice(20, "Twenty-sided dice");
    int num_rolls = 5;
    int results[num_rolls];
    int choice;

    printf("Welcome to the Dice Roller!\n");
    printf("Enter the number of rolls you want to make: ");
    scanf("%d", &num_rolls);

    printf("Enter the number of the dice you want to use:\n");
    for (int i = 0; i < num_dice; i++) {
        printf("%d. %s (%d sides)\n", i+1, dice[i].name, dice[i].num_sides);
    }
    scanf("%d", &choice);

    roll_dice(num_rolls, results);

    printf("You rolled:\n");
    for (int i = 0; i < num_rolls; i++) {
        printf("%d\n", results[i]);
    }

    return 0;
}