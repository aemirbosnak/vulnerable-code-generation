//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MAX_SIDES 1000

// Function to generate a random number between min and max (inclusive)
int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to roll a single die with n sides
int roll_die(int n) {
    return rand_range(1, n);
}

// Function to roll multiple dice with n sides each
int roll_dice(int n, int sides) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += roll_die(sides);
    }
    return total;
}

// Function to display the result of a dice roll
void display_roll(int n, int sides) {
    printf("Rolling %d dice with %d sides each:\n", n, sides);
    for (int i = 0; i < n; i++) {
        printf("%d ", roll_die(sides));
    }
    printf("\nTotal: %d\n", roll_dice(n, sides));
}

int main() {
    srand(time(NULL));

    int n, sides;
    printf("Enter the number of dice to roll: ");
    scanf("%d", &n);
    printf("Enter the number of sides on each die: ");
    scanf("%d", &sides);

    if (n <= 0 || sides <= 0 || n > MAX_DICE || sides > MAX_SIDES) {
        printf("Invalid input.\n");
        return 1;
    }

    display_roll(n, sides);

    return 0;
}