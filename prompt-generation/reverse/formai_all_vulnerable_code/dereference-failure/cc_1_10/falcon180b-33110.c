//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FACES 1000
#define MAX_DICE 100

typedef struct {
    int num_sides;
    int *sides;
} Die;

typedef struct {
    Die *dice;
    int num_dice;
} Roll;

void init_die(Die *die, int num_sides) {
    die->num_sides = num_sides;
    die->sides = (int *)malloc(num_sides * sizeof(int));
    for (int i = 0; i < num_sides; i++) {
        die->sides[i] = i + 1;
    }
}

void free_die(Die *die) {
    free(die->sides);
}

void init_roll(Roll *roll, int num_dice) {
    roll->dice = (Die *)malloc(num_dice * sizeof(Die));
    for (int i = 0; i < num_dice; i++) {
        init_die(&roll->dice[i], 6);
    }
    roll->num_dice = num_dice;
}

void free_roll(Roll *roll) {
    for (int i = 0; i < roll->num_dice; i++) {
        free_die(&roll->dice[i]);
    }
    free(roll->dice);
}

void roll_dice(Roll *roll) {
    srand(time(NULL));

    for (int i = 0; i < roll->num_dice; i++) {
        int result = rand() % roll->dice[i].num_sides;
        printf("Dice %d rolled %d\n", i + 1, result);
    }
}

int main() {
    Roll roll;
    init_roll(&roll, 2);

    roll_dice(&roll);

    free_roll(&roll);

    return 0;
}