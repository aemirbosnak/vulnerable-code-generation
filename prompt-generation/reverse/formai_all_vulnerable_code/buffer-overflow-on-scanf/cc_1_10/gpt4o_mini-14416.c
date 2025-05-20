//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define MAX_SIDES 20

void clear_input_buffer() {
    while (getchar() != '\n') { }
}

void display_welcome_message() {
    printf("========================================\n");
    printf("            Dice Roller Program          \n");
    printf("========================================\n");
    printf("Welcome! Roll dice with various sides and quantities!\n");
}

int get_number_of_dice() {
    int num_dice;

    do {
        printf("Enter the number of dice to roll (1 - %d): ", MAX_DICE);
        scanf("%d", &num_dice);
        clear_input_buffer();
        if (num_dice < 1 || num_dice > MAX_DICE) {
            printf("Invalid number! Please try again.\n");
        }
    } while (num_dice < 1 || num_dice > MAX_DICE);

    return num_dice;
}

int get_number_of_sides() {
    int num_sides;

    do {
        printf("Enter the number of sides for the dice (1 - %d): ", MAX_SIDES);
        scanf("%d", &num_sides);
        clear_input_buffer();
        if (num_sides < 1 || num_sides > MAX_SIDES) {
            printf("Invalid number! Please try again.\n");
        }
    } while (num_sides < 1 || num_sides > MAX_SIDES);

    return num_sides;
}

void roll_dice(int num_dice, int num_sides) {
    int i;
    int sum = 0;

    printf("Rolling %d dice with %d sides...\n", num_dice, num_sides);
    for (i = 0; i < num_dice; i++) {
        int roll = (rand() % num_sides) + 1; // Roll the dice
        printf("Die %d: %d\n", i + 1, roll);
        sum += roll;
    }

    printf("Total: %d\n", sum);
}

char ask_to_continue() {
    char choice;

    printf("Do you want to roll again? (y/n): ");
    scanf(" %c", &choice);
    clear_input_buffer();

    while (choice != 'y' && choice != 'n') {
        printf("Invalid input! Please type 'y' for Yes or 'n' for No: ");
        scanf(" %c", &choice);
        clear_input_buffer();
    }

    return choice;
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    char continue_choice = 'y';

    display_welcome_message();

    while (continue_choice == 'y') {
        int num_dice = get_number_of_dice();
        int num_sides = get_number_of_sides();
        roll_dice(num_dice, num_sides);
        continue_choice = ask_to_continue();
    }

    printf("Thank you for using the Dice Roller Program. Goodbye!\n");
    return 0;
}