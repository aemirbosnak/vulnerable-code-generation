//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 1000
#define MAX_ROLLS 100

typedef struct {
    int num_sides;
    int num_rolls;
    int *rolls;
} Dice;

int main() {
    srand(time(NULL));

    int num_dice;
    printf("Enter the number of dice to roll: ");
    scanf("%d", &num_dice);

    Dice *dice = malloc(num_dice * sizeof(Dice));

    for (int i = 0; i < num_dice; i++) {
        printf("Enter the number of sides for dice %d: ", i+1);
        scanf("%d", &dice[i].num_sides);

        printf("Enter the number of rolls for dice %d: ", i+1);
        scanf("%d", &dice[i].num_rolls);

        dice[i].rolls = malloc(dice[i].num_rolls * sizeof(int));
    }

    for (int i = 0; i < num_dice; i++) {
        for (int j = 0; j < dice[i].num_rolls; j++) {
            dice[i].rolls[j] = rand() % dice[i].num_sides + 1;
        }
    }

    printf("Dice Rolls:\n");
    for (int i = 0; i < num_dice; i++) {
        printf("Dice %d:\n", i+1);
        for (int j = 0; j < dice[i].num_rolls; j++) {
            printf("%d ", dice[i].rolls[j]);
        }
        printf("\n");
    }

    for (int i = 0; i < num_dice; i++) {
        free(dice[i].rolls);
        free(dice + i);
    }

    return 0;
}