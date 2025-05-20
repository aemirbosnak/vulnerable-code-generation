//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_welcome_message() {
    printf("🎲🎉 Welcome to the Cheerful Dice Roller! 🎉🎲\n");
    printf("Let’s roll some dice and have fun!\n\n");
}

int roll_die(int sides) {
    return (rand() % sides) + 1;
}

void display_rolls(int num_rolls, int sides) {
    printf("You've chosen to roll a %d-sided die %d times!\n", sides, num_rolls);
    printf("Here are your results:\n");

    for (int i = 0; i < num_rolls; i++) {
        int result = roll_die(sides);
        printf("Roll %d: You rolled a 🎲 %d\n", i + 1, result);
    }

    printf("\nThat was so fun! 🎉 Would you like to roll again?\n");
}

int get_number_of_rolls() {
    int num_rolls;
    printf("How many times would you like to roll? (1-10): ");
    scanf("%d", &num_rolls);
    while (num_rolls < 1 || num_rolls > 10) {
        printf("Let's keep it between 1 and 10! How many times would you like to roll? ");
        scanf("%d", &num_rolls);
    }
    return num_rolls;
}

int get_die_sides() {
    int sides;
    printf("How many sides does your die have? (4, 6, 8, 10, 12, 20): ");
    scanf("%d", &sides);
    while (sides != 4 && sides != 6 && sides != 8 && sides != 10 && sides != 12 && sides != 20) {
        printf("Oops! That's not a standard die. Please choose 4, 6, 8, 10, 12, or 20: ");
        scanf("%d", &sides);
    }
    return sides;
}

char ask_to_roll_again() {
    char choice;
    printf("Would you like to roll again? (y/n): ");
    scanf(" %c", &choice);
    return choice;
}

int main() {
    srand(time(NULL)); // Seed for randomness
    print_welcome_message();

    do {
        int sides = get_die_sides();
        int num_rolls = get_number_of_rolls();
        display_rolls(num_rolls, sides);
    } while (ask_to_roll_again() == 'y');

    printf("Thanks for playing the Cheerful Dice Roller! 🎲✨ Goodbye!\n");
    return 0;
}