//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 1000
#define MAX_DICE 100

struct dice {
    int sides;
    int value;
};

void roll_dice(struct dice *dice, int num_dice) {
    for (int i = 0; i < num_dice; i++) {
        dice[i].value = rand() % dice[i].sides + 1;
    }
}

void print_dice(struct dice *dice, int num_dice) {
    for (int i = 0; i < num_dice; i++) {
        printf("%d-sided die rolled %d\n", dice[i].sides, dice[i].value);
    }
}

int main() {
    struct dice dice[MAX_DICE];
    int num_dice = 0;

    srand(time(NULL));

    while (num_dice < MAX_DICE) {
        int sides;
        printf("Enter the number of sides for the die (1-1000): ");
        scanf("%d", &sides);

        if (sides < 1 || sides > MAX_SIDES) {
            printf("Invalid number of sides.\n");
        } else {
            dice[num_dice].sides = sides;
            dice[num_dice].value = 0;
            num_dice++;
        }

        printf("Do you want to add another die? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice!= 'y' && choice!= 'Y') {
            break;
        }
    }

    printf("Rolling the dice...\n");
    roll_dice(dice, num_dice);

    printf("The dice have been rolled:\n");
    print_dice(dice, num_dice);

    return 0;
}