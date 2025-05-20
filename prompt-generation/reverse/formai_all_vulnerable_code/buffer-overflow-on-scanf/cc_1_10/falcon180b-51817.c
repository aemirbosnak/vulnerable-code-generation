//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 100
#define MAX_DICE 100

typedef struct {
    int num_sides;
    int value;
} Die;

typedef struct {
    int num_dice;
    Die dice[MAX_DICE];
} Roll;

void init_die(Die* die, int num_sides, int value) {
    die->num_sides = num_sides;
    die->value = value;
}

void init_roll(Roll* roll, int num_dice) {
    roll->num_dice = num_dice;
    for (int i = 0; i < num_dice; i++) {
        init_die(&roll->dice[i], 6, 1);
    }
}

int roll_dice(Roll* roll) {
    int total = 0;
    for (int i = 0; i < roll->num_dice; i++) {
        int result = rand() % roll->dice[i].num_sides + 1;
        total += result;
        printf("%d ", result);
    }
    printf("\nTotal: %d\n", total);
    return total;
}

int main() {
    srand(time(NULL));

    int num_dice;
    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);

    Roll roll;
    init_roll(&roll, num_dice);

    int total = 0;
    int max_total = 0;

    for (int i = 0; i < 10; i++) {
        total = roll_dice(&roll);
        if (total > max_total) {
            max_total = total;
        }
    }

    printf("Max total: %d\n", max_total);

    return 0;
}