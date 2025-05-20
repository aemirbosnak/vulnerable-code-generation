//Code Llama-13B DATASET v1.0 Category: Dice Roller ; Style: complete
/*
 * Dice Roller Example Program
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_DICE 100

int roll_dice(int num_dice, int num_sides);
void print_dice(int num_dice, int num_sides);

int main() {
    int num_dice, num_sides;

    srand(time(NULL));

    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);

    printf("Enter the number of sides: ");
    scanf("%d", &num_sides);

    int total = roll_dice(num_dice, num_sides);

    print_dice(num_dice, num_sides);

    printf("Total: %d\n", total);

    return 0;
}

int roll_dice(int num_dice, int num_sides) {
    int i, roll, total = 0;

    for (i = 0; i < num_dice; i++) {
        roll = rand() % num_sides + 1;
        total += roll;
    }

    return total;
}

void print_dice(int num_dice, int num_sides) {
    int i, roll;

    for (i = 0; i < num_dice; i++) {
        roll = rand() % num_sides + 1;
        printf("%d ", roll);
    }

    printf("\n");
}