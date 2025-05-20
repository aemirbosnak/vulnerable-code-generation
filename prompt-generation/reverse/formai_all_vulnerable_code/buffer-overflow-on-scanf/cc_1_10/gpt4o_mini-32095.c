//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DICE 5
#define MAX_SIDES 6
#define MAX_ROLLS 20

void print_intro();
void roll_dice(int dice[], int num_dice);
void print_results(int dice[], int num_dice);
void calculate_statistics(int rolls[], int num_rolls);

int main() {
    int dice[NUM_DICE];
    int roll_history[MAX_ROLLS] = {0};
    int num_rolls = 0;
    char choice;

    print_intro();

    srand(time(NULL)); // Seed the random number generator
    do {
        roll_dice(dice, NUM_DICE);
        print_results(dice, NUM_DICE);

        // Store the rolls for statistics
        if (num_rolls < MAX_ROLLS) {
            for (int i = 0; i < NUM_DICE; i++) {
                roll_history[num_rolls] += dice[i];
            }
            num_rolls++;
        }

        printf("\nDo you want to roll again? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    // Calculate statistics
    if (num_rolls > 0) {
        calculate_statistics(roll_history, num_rolls);
    } else {
        printf("No rolls were made.\n");
    }

    printf("Thank you for using the dice roller!\n");
    return 0;
}

void print_intro() {
    printf("Welcome to the Dice Roller Program!\n");
    printf("You can roll up to %d dice at a time.\n", NUM_DICE);
    printf("Each die has %d sides.\n", MAX_SIDES);
    printf("Let's start rolling!\n");
}

void roll_dice(int dice[], int num_dice) {
    printf("\nRolling the dice...\n");
    for (int i = 0; i < num_dice; i++) {
        dice[i] = (rand() % MAX_SIDES) + 1; // Generate dice roll
    }
}

void print_results(int dice[], int num_dice) {
    printf("You rolled: ");
    for (int i = 0; i < num_dice; i++) {
        printf("%d ", dice[i]);
    }
    printf("\n");
}

void calculate_statistics(int rolls[], int num_rolls) {
    int total = 0, highest = 0, lowest = 999; // Initial high and low values
    for (int i = 0; i < num_rolls; i++) {
        total += rolls[i];
        if (rolls[i] > highest) {
            highest = rolls[i];
        }
        if (rolls[i] < lowest) {
            lowest = rolls[i];
        }
    }

    float average = (float) total / num_rolls;
    printf("Statistics of your rolls:\n");
    printf("Total: %d\n", total);
    printf("Average: %.2f\n", average);
    printf("Highest roll: %d\n", highest);
    printf("Lowest roll: %d\n", lowest);
}