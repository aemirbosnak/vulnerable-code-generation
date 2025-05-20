//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE_SIDES 100
#define MAX_DICE_COUNT 10

struct Dice {
    int sides;
    int value;
};

struct DiceRoller {
    struct Dice dice[MAX_DICE_COUNT];
    int count;
};

void dice_init(struct DiceRoller *roller, int sides, int count) {
    if (sides < 2 || sides > MAX_DICE_SIDES) {
        fprintf(stderr, "Invalid dice sides count: %d\n", sides);
        exit(EXIT_FAILURE);
    }

    if (count < 1 || count > MAX_DICE_COUNT) {
        fprintf(stderr, "Invalid dice count: %d\n", count);
        exit(EXIT_FAILURE);
    }

    roller->count = count;
    for (int i = 0; i < count; i++) {
        roller->dice[i].sides = sides;
        roller->dice[i].value = 0;
    }
}

void dice_roll(struct DiceRoller *roller) {
    for (int i = 0; i < roller->count; i++) {
        roller->dice[i].value = rand() % roller->dice[i].sides + 1;
    }
}

void dice_print(struct DiceRoller *roller) {
    for (int i = 0; i < roller->count; i++) {
        printf("Die %d: %d\n", i + 1, roller->dice[i].value);
    }
}

int main(void) {
    srand(time(NULL));

    int sides, count;

    printf("Enter the number of sides for each die: ");
    if (scanf("%d", &sides) != 1) {
        fprintf(stderr, "Invalid input\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter the number of dice to roll: ");
    if (scanf("%d", &count) != 1) {
        fprintf(stderr, "Invalid input\n");
        exit(EXIT_FAILURE);
    }

    struct DiceRoller roller;
    dice_init(&roller, sides, count);

    dice_roll(&roller);
    dice_print(&roller);

    return 0;
}