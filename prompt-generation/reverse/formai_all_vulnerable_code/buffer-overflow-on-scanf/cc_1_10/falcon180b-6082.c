//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: synchronous
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DICE 1000
#define MAX_SIDES 1000

// Data structure to store dice information
typedef struct {
    int num_sides;
    int value;
} Dice;

// Function to roll a single dice
int roll_dice(Dice dice) {
    return rand() % dice.num_sides + 1;
}

// Function to roll multiple dice
int roll_dices(Dice dices[], int num_dices) {
    int total = 0;
    for (int i = 0; i < num_dices; i++) {
        total += roll_dice(dices[i]);
    }
    return total;
}

// Function to print the result of dice rolling
void print_result(int result, int num_dices) {
    printf("Result: %d\n", result);
    if (num_dices > 1) {
        printf("Dice values:");
        for (int i = 0; i < num_dices; i++) {
            printf(" %d", i + 1);
        }
        printf("\n");
    }
}

// Main function
int main() {
    srand(time(NULL));

    // Initialize dice information
    Dice dices[MAX_DICE];
    int num_dices = 0;

    // Prompt user for dice information
    while (num_dices < MAX_DICE) {
        printf("Enter the number of sides for the dice (1-1000): ");
        scanf("%d", &dices[num_dices].num_sides);
        if (dices[num_dices].num_sides < 1 || dices[num_dices].num_sides > MAX_SIDES) {
            printf("Invalid number of sides.\n");
            num_dices--;
        } else {
            printf("Enter the value for the dice (1-%d): ", dices[num_dices].num_sides);
            scanf("%d", &dices[num_dices].value);
            num_dices++;
        }
    }

    // Prompt user for number of dice to roll
    printf("Enter the number of dice to roll (1-%d): ", num_dices);
    scanf("%d", &num_dices);

    // Roll the dice
    int result = roll_dices(dices, num_dices);

    // Print the result
    print_result(result, num_dices);

    return 0;
}