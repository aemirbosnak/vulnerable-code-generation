//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_instructions() {
    printf("\nWelcome to the Dice Roller!\n");
    printf("Instructions:\n");
    printf("1. Enter the number of dice to roll (1-5).\n");
    printf("2. Choose the type of dice (4, 6, 8, 10, 12, 20).\n");
    printf("3. Press Enter to roll the dice.\n");
    printf("4. To exit, enter 0 as the number of dice.\n");
}

void roll_dice(int num_dice, int sides) {
    int total = 0;
    printf("\nRolling %d %d-sided dice...\n", num_dice, sides);
    for (int i = 0; i < num_dice; i++) {
        int roll = (rand() % sides) + 1; // Roll the dice
        printf("Die %d: %d\n", i + 1, roll);
        total += roll; // Add to total
    }
    printf("Total: %d\n\n", total);
}

int main() {
    int num_dice, sides;
    
    // Seed the random number generator
    srand(time(NULL));

    print_instructions();
    
    while (1) {
        printf("Enter number of dice (0 to exit): ");
        scanf("%d", &num_dice);
        
        if (num_dice == 0) {
            printf("Exiting the Dice Roller. Thank you!\n");
            break;
        } else if (num_dice < 1 || num_dice > 5) {
            printf("Please enter a valid number of dice (between 1 and 5).\n");
            continue;
        }

        printf("Choose the type of dice (4, 6, 8, 10, 12, 20): ");
        scanf("%d", &sides);
        
        if (sides != 4 && sides != 6 && sides != 8 && sides != 10 && sides != 12 && sides != 20) {
            printf("Invalid dice type. Please try again.\n");
            continue;
        }

        roll_dice(num_dice, sides);
    }
    
    return 0;
}