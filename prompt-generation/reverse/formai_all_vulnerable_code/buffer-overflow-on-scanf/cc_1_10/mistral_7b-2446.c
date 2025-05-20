//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MAX_SIDES 30
#define MAX_ROLLS 10

typedef struct {
    int sides;
    int rolls[MAX_ROLLS];
    int total;
} Die;

void roll_die(Die *dice) {
    dice->rolls[dice->total++] = rand() % (dice->sides + 1);
}

void print_die(const Die *dice) {
    printf("Die %d: %d sides, Rolls: [", dice - &dice[0], dice->sides);
    for (int i = 0; i < dice->total; i++) {
        printf("%d", dice->rolls[i]);
        if (i < dice->total - 1) {
            printf(", ");
        }
    }
    printf("], Total: %d\n", dice->total);
}

int main() {
    srand(time(NULL));

    Die dice[MAX_DICE];

    for (int i = 0; i < MAX_DICE; i++) {
        printf("Enter the number of sides for Die %d: ", i + 1);
        scanf("%d", &dice[i].sides);

        if (dice[i].sides <= 0) {
            printf("Invalid number of sides. Exiting.\n");
            return 1;
        }

        dice[i].total = 0;
        roll_die(&dice[i]);
    }

    printf("\nDie statistics:\n");
    for (int i = 0; i < MAX_DICE; i++) {
        print_die(&dice[i]);
    }

    return 0;
}