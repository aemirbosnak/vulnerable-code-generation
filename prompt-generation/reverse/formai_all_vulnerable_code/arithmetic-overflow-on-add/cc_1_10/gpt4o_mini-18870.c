//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10

typedef struct {
    int sides;
    int roll_count;
    int *rolls;
} Dice;

// Function to create a dice with a specified number of sides
Dice create_dice(int sides, int roll_count) {
    Dice new_dice;
    new_dice.sides = sides;
    new_dice.roll_count = roll_count;
    new_dice.rolls = (int *)malloc(roll_count * sizeof(int));
    return new_dice;
}

// Function to roll the dice
void roll_dice(Dice *dice) {
    for (int i = 0; i < dice->roll_count; i++) {
        dice->rolls[i] = (rand() % dice->sides) + 1; // Roll a value between 1 and sides
    }
}

// Function to print the results of the rolls
void print_rolls(Dice *dice) {
    printf("Rolls for a %d-sided dice:\n", dice->sides);
    for (int i = 0; i < dice->roll_count; i++) {
        printf("Roll %d: %d\n", i + 1, dice->rolls[i]);
    }
}

void free_dice(Dice *dice) {
    free(dice->rolls);
}

// Function to display the main menu and get user input
int display_menu() {
    int selection;
    printf("\nDice Roller Menu:\n");
    printf("1. Roll a D6\n");
    printf("2. Roll a D10\n");
    printf("3. Roll a D20\n");
    printf("4. Roll custom dice\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
    scanf("%d", &selection);
    return selection;
}

// Function to roll and display a specific type of dice
void handle_selection(int selection) {
    int sides, rolls_count;
    Dice dice;
    switch (selection) {
        case 1:
            dice = create_dice(6, 1);
            break;
        case 2:
            dice = create_dice(10, 1);
            break;
        case 3:
            dice = create_dice(20, 1);
            break;
        case 4:
            printf("Enter the number of sides on the dice: ");
            scanf("%d", &sides);
            printf("Enter the number of rolls: ");
            scanf("%d", &rolls_count);
            dice = create_dice(sides, rolls_count);
            break;
        case 5:
            printf("Exiting the program. Goodbye!\n");
            return;
        default:
            printf("Invalid option! Please try again.\n");
            return;
    }

    roll_dice(&dice);
    print_rolls(&dice);
    free_dice(&dice);
}

// Main function
int main() {
    srand(time(NULL)); // Seed for random number generation
    int selection;

    while (1) {
        selection = display_menu();
        if (selection == 5) {
            break;
        }
        handle_selection(selection);
    }

    return 0;
}