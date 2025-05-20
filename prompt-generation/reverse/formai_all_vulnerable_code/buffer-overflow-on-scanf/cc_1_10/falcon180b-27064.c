//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 1000
#define MAX_DICE 100

typedef struct {
    int sides;
    int value;
} Die;

typedef struct {
    Die dice[MAX_DICE];
    int num_dice;
} Roll;

void init_die(Die *die, int sides) {
    die->sides = sides;
    die->value = rand() % sides + 1;
}

void init_roll(Roll *roll, int num_dice, int sides) {
    roll->num_dice = num_dice;
    for (int i = 0; i < num_dice; i++) {
        init_die(&roll->dice[i], sides);
    }
}

int roll_dice(Roll *roll) {
    int total = 0;
    for (int i = 0; i < roll->num_dice; i++) {
        total += roll->dice[i].value;
    }
    return total;
}

int main() {
    srand(time(NULL));

    int num_dice, sides;
    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);
    printf("Enter the number of sides per die: ");
    scanf("%d", &sides);

    Roll roll;
    init_roll(&roll, num_dice, sides);

    int total = 0;
    for (int i = 0; i < 10; i++) {
        total += roll_dice(&roll);
        printf("Roll %d: %d\n", i+1, total);
    }

    return 0;
}