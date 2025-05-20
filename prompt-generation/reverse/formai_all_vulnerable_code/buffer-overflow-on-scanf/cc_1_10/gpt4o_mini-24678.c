//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define MIN_DICE 1
#define MAX_SIDES 20
#define MIN_SIDES 4

void clear_input_buffer() {
    while(getchar() != '\n') {}
}

int get_positive_integer(const char *prompt) {
    int value;
    printf("%s", prompt);
    while(1) {
        if(scanf("%d", &value) != 1 || value < 1) {
            clear_input_buffer();
            printf("Invalid input. Please enter a positive integer: ");
        } else {
            clear_input_buffer();
            return value;
        }
    }
}

int roll_dice(int sides, int num_dice) {
    int total = 0;
    for(int i = 0; i < num_dice; i++) {
        total += (rand() % sides) + 1;
    }
    return total;
}

void display_results(int num_dice, int sides, int result) {
    printf("You rolled %d dice with %d sides each. Total: %d\n", num_dice, sides, result);
}

void save_rolls_to_file(const char *filename, int num_dice, int sides, int result) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    fprintf(file, "Rolled %d dice with %d sides: Total = %d\n", num_dice, sides, result);
    fclose(file);
}

void print_saved_rolls(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    
    char line[256];
    printf("Saved rolls:\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

int get_dice_sides() {
    int sides;
    printf("Enter the number of sides on the dice (4, 6, 8, 10, 12, 20): ");
    while(1) {
        if(scanf("%d", &sides) != 1 || (sides != 4 && sides != 6 && sides != 8 && sides != 10 && sides != 12 && sides != 20)) {
            clear_input_buffer();
            printf("Invalid input. Please enter a valid number of sides (4, 6, 8, 10, 12, 20): ");
        } else {
            clear_input_buffer();
            return sides;
        }
    }
}

int main() {
    srand(time(NULL));
    int num_dice, dice_sides, total_roll;
    char option;
    const char *filename = "dice_rolls.txt";

    printf("Welcome to the Dice Roller!\n");

    do {
        num_dice = get_positive_integer("How many dice would you like to roll? ");
        dice_sides = get_dice_sides();

        total_roll = roll_dice(dice_sides, num_dice);
        display_results(num_dice, dice_sides, total_roll);
        save_rolls_to_file(filename, num_dice, dice_sides, total_roll);

        printf("Would you like to roll again? (y/n): ");
        while(1) {
            option = getchar();
            if(option == 'y' || option == 'n') {
                clear_input_buffer();
                break;
            } else {
                clear_input_buffer();
                printf("Invalid input. Please enter 'y' to roll again or 'n' to quit: ");
            }
        }
    } while(option == 'y');

    print_saved_rolls(filename);
    printf("Thank you for using the Dice Roller! Goodbye.\n");

    return 0;
}