//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define MAX_SIDES 20

void display_rules() {
    printf("\nWelcome to the C Dice Roller!\n");
    printf("This program allows you to roll multiple dice with various sides.\n");
    printf("You can roll up to %d dice, and each die can have up to %d sides.\n", MAX_DICE, MAX_SIDES);
    printf("Instructions:\n");
    printf("1. Enter the number of dice you want to roll (1-%d).\n", MAX_DICE);
    printf("2. Enter the number of sides for each die (1-%d).\n", MAX_SIDES);
    printf("3. The rolls will be displayed along with their total.\n");
    printf("4. To exit the program, enter 0 when asked for number of dice.\n\n");
}

int roll_die(int sides) {
    return (rand() % sides) + 1;
}

void roll_dice(int number_of_dice, int sides) {
    int rolls[MAX_DICE];
    int total = 0;

    printf("Rolling %d dice with %d sides...\n", number_of_dice, sides);
    for (int i = 0; i < number_of_dice; i++) {
        rolls[i] = roll_die(sides);
        total += rolls[i];
        printf("Die %d: %d\n", i + 1, rolls[i]);
    }
    printf("Total: %d\n", total);
}

int main() {
    srand(time(NULL));
    
    int number_of_dice, sides;

    display_rules();

    while (1) {
        printf("Enter the number of dice to roll (0 to exit): ");
        scanf("%d", &number_of_dice);
        if (number_of_dice == 0) {
            printf("Exiting the program. Thank you for playing!\n");
            break;
        }
        if (number_of_dice < 1 || number_of_dice > MAX_DICE) {
            printf("Invalid number of dice. Please enter a value between 1 and %d.\n", MAX_DICE);
            continue;
        }

        printf("Enter the number of sides for each die: ");
        scanf("%d", &sides);
        if (sides < 1 || sides > MAX_SIDES) {
            printf("Invalid number of sides. Please enter a value between 1 and %d.\n", MAX_SIDES);
            continue;
        }

        roll_dice(number_of_dice, sides);
    }

    return 0;
}