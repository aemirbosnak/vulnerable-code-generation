//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 1000
#define MAX_DICE 1000

typedef struct {
    int sides;
    int value;
} Die;

typedef struct {
    int num_dice;
    Die dice[MAX_DICE];
} Roll;

void init_die(Die *die, int sides) {
    die->sides = sides;
    die->value = rand() % sides + 1;
}

void init_roll(Roll *roll, int num_dice) {
    roll->num_dice = num_dice;
    for (int i = 0; i < num_dice; i++) {
        init_die(&roll->dice[i], rand() % MAX_SIDES + 1);
    }
}

void roll_dice(Roll *roll) {
    for (int i = 0; i < roll->num_dice; i++) {
        roll->dice[i].value = rand() % roll->dice[i].sides + 1;
    }
}

void print_roll(Roll *roll) {
    for (int i = 0; i < roll->num_dice; i++) {
        printf("%d ", roll->dice[i].value);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int num_dice;
    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);

    Roll roll;
    init_roll(&roll, num_dice);

    int num_rolls;
    printf("Enter the number of rolls: ");
    scanf("%d", &num_rolls);

    for (int i = 0; i < num_rolls; i++) {
        roll_dice(&roll);
        print_roll(&roll);
    }

    return 0;
}