//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_DICE 100
#define MIN_VALUE 1
#define MAX_VALUE 6
#define INVALID_VALUE 0

// Function to validate input
bool is_valid_input(int num_dice, int num_sides) {
    if (num_dice > MAX_DICE || num_dice <= 0) {
        printf("Invalid number of dice.\n");
        return false;
    }
    if (num_sides <= 0 || num_sides > MAX_VALUE) {
        printf("Invalid number of sides.\n");
        return false;
    }
    return true;
}

// Function to roll the dice
void roll_dice(int num_dice, int num_sides) {
    srand(time(NULL));
    int dice[MAX_DICE];
    for (int i = 0; i < num_dice; i++) {
        dice[i] = rand() % num_sides + 1;
    }
    printf("You rolled: ");
    for (int i = 0; i < num_dice; i++) {
        printf("%d ", dice[i]);
    }
    printf("\n");
}

// Function to get user input
void get_input(int *num_dice, int *num_sides) {
    printf("Enter the number of dice: ");
    scanf("%d", num_dice);
    printf("Enter the number of sides: ");
    scanf("%d", num_sides);
}

int main() {
    int num_dice = 0, num_sides = 0;
    bool valid_input = false;
    while (!valid_input) {
        get_input(&num_dice, &num_sides);
        valid_input = is_valid_input(num_dice, num_sides);
    }
    roll_dice(num_dice, num_sides);
    return 0;
}