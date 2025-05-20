//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ROLLS 100

typedef struct {
    int sides;
    int rolls[MAX_ROLLS];
    int num_rolls;
} Dice;

void initialize_dice(Dice* dice, int sides) {
    dice->sides = sides;
    dice->num_rolls = 0;
}

void roll_dice(Dice* dice, int num_rolls) {
    for (int i = 0; i < num_rolls; i++) {
        dice->rolls[i] = (rand() % dice->sides) + 1;
    }
    dice->num_rolls = num_rolls;
}

void print_rolls(const Dice* dice) {
    printf("You rolled a %d-sided die:\n", dice->sides);
    for (int i = 0; i < dice->num_rolls; i++) {
        printf("Roll %d: %d\n", i + 1, dice->rolls[i]);
    }
}

double calculate_average(const Dice* dice) {
    if (dice->num_rolls == 0) return 0.0;
    double sum = 0.0;
    for (int i = 0; i < dice->num_rolls; i++) {
        sum += dice->rolls[i];
    }
    return sum / dice->num_rolls;
}

void display_stats(const Dice* dice) {
    double average = calculate_average(dice);
    printf("Total Rolls: %d\n", dice->num_rolls);
    printf("Average Roll: %.2f\n", average);
}

void display_menu() {
    printf("\n=== Dice Roller Menu ===\n");
    printf("1. Roll Dice\n");
    printf("2. View Statistics\n");
    printf("3. Exit\n");
    printf("========================\n");
}

int main() {
    srand(time(NULL));
    Dice dice;
    int sides, num_rolls, option;

    printf("Welcome to the Dice Roller!\n");
    printf("Enter the number of sides on the die (e.g., 6): ");
    scanf("%d", &sides);
    
    initialize_dice(&dice, sides);

    do {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter number of rolls (max %d): ", MAX_ROLLS);
                scanf("%d", &num_rolls);
                if (num_rolls > MAX_ROLLS) {
                    printf("You can roll a maximum of %d times.\n", MAX_ROLLS);
                    continue;
                }
                roll_dice(&dice, num_rolls);
                print_rolls(&dice);
                break;
            case 2:
                display_stats(&dice);
                break;
            case 3:
                printf("Thank you for using the Dice Roller. Goodbye!\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    } while (option != 3);

    return 0;
}