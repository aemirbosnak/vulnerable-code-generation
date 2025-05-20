//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a single die
int roll_die(int sides) {
    return (rand() % sides) + 1;
}

// Function to roll multiple dice
void roll_multiple_dice(int dice_count, int sides) {
    int total = 0;
    printf("Rolling %d dice with %d sides:\n", dice_count, sides);
    for (int i = 0; i < dice_count; i++) {
        int result = roll_die(sides);
        printf("Die %d: %d\n", i + 1, result);
        total += result;
    }
    printf("Total: %d\n\n", total);
}

// Function to display user instructions
void display_instructions() {
    printf("Welcome to the C Dice Roller!\n");
    printf("You can roll various dice with this program.\n");
    printf("Enter the number of dice and the number of sides to roll them.\n");
    printf("Type 'exit' to quit the program at any time.\n");
}

// Function to handle user input
void user_input() {
    char input[100];
    int dice_count, sides;

    while (1) {
        printf("Enter the number of dice and sides (e.g., '2 6'): ");
        fgets(input, sizeof(input), stdin);

        if (sscanf(input, "%d %d", &dice_count, &sides) != 2) {
            if (strncmp(input, "exit", 4) == 0) {
                printf("Exiting the Dice Roller. Thank you for playing!\n");
                break;
            } else {
                printf("Invalid input format. Please enter two numbers, or 'exit' to quit.\n");
                continue;
            }
        }

        if (dice_count <= 0 || sides <= 0) {
            printf("Both the number of dice and the number of sides must be positive integers.\n\n");
            continue;
        }

        roll_multiple_dice(dice_count, sides);
    }
}

// Main function to setup and start the program
int main() {
    srand(time(NULL));  // Seed for random number generation
    display_instructions();
    user_input();
    return 0;
}