//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 1000
#define MAX_DICE 1000

typedef struct {
    int numSides;
    int value;
} Die;

typedef struct {
    int numDice;
    Die dice[MAX_DICE];
} Roll;

void initDie(Die *die, int numSides, int value) {
    die->numSides = numSides;
    die->value = value;
}

void initRoll(Roll *roll, int numDice) {
    roll->numDice = numDice;
}

int rollDie(Die die) {
    return rand() % die.numSides + 1;
}

void rollDice(Roll *roll) {
    for (int i = 0; i < roll->numDice; i++) {
        roll->dice[i].value = rollDie(roll->dice[i]);
    }
}

int main() {
    srand(time(NULL));

    int numDice;
    printf("Enter the number of dice: ");
    scanf("%d", &numDice);

    Roll roll;
    initRoll(&roll, numDice);

    for (int i = 0; i < numDice; i++) {
        int numSides;
        printf("Enter the number of sides for die %d: ", i + 1);
        scanf("%d", &numSides);

        if (numSides < 1 || numSides > MAX_SIDES) {
            printf("Invalid number of sides.\n");
            return 1;
        }

        Die die;
        initDie(&die, numSides, 1);
        roll.dice[i] = die;
    }

    rollDice(&roll);

    printf("Rolled %d dice:\n", numDice);
    for (int i = 0; i < numDice; i++) {
        printf("Die %d: %d\n", i + 1, roll.dice[i].value);
    }

    return 0;
}