//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIDES 6
#define MAX_DICE 50

int roll_dice(int num_dice, int sides) {
    int i, total = 0;
    for (i = 0; i < num_dice; i++) {
        total += rand() % sides + 1;
    }
    return total;
}

void print_dice(int num_dice, int sides) {
    int i;
    for (i = 0; i < num_dice; i++) {
        printf("%d ", rand() % sides + 1);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int num_dice, sides, total;

    printf("Welcome to the Future Dice Roller!\n");
    printf("How many dice do you want to roll? ");
    scanf("%d", &num_dice);

    if (num_dice > MAX_DICE) {
        printf("Sorry, you can only roll up to %d dice at a time.\n", MAX_DICE);
        return 1;
    }

    printf("How many sides do your dice have? ");
    scanf("%d", &sides);

    if (sides <= 0) {
        printf("Invalid number of sides. Please enter a positive integer.\n");
        return 1;
    }

    total = roll_dice(num_dice, sides);
    printf("You rolled %d dice with %d sides each.\n", num_dice, sides);
    printf("The total of all dice rolls is: %d\n", total);

    print_dice(num_dice, sides);

    return 0;
}