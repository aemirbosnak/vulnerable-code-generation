//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void roll_dice(int num_dice, int sides) {
    int roll, total = 0;
    printf("Rolling %d dice with %d sides:\n", num_dice, sides);
    
    for (int i = 0; i < num_dice; i++) {
        roll = (rand() % sides) + 1; // Roll the die (1 to sides)
        printf("Die %d: %d\n", i + 1, roll);
        total += roll; // Add to total
    }
    
    printf("Total: %d\n", total);
}

int main() {
    int num_dice, sides;
    
    // Seed the random number generator
    srand(time(NULL)); 
    
    printf("Welcome to the Dice Roller!\n");
    
    while (1) {
        printf("Enter number of dice (1-10, 0 to exit): ");
        scanf("%d", &num_dice);
        
        if (num_dice == 0) {
            printf("Exiting the program. Goodbye!\n");
            break; 
        }
        
        if (num_dice < 1 || num_dice > 10) {
            printf("Invalid number of dice! Please enter a number between 1 and 10.\n");
            continue;
        }
        
        printf("Enter number of sides on each die (4, 6, 8, 10, 12, 20): ");
        scanf("%d", &sides);
        
        if (sides != 4 && sides != 6 && sides != 8 && sides != 10 && sides != 12 && sides != 20) {
            printf("Invalid number of sides! Please enter one of the allowed values.\n");
            continue;
        }
        
        // Call function to roll dice
        roll_dice(num_dice, sides);
        
        // Ask if user wants to roll again
        char roll_again;
        printf("Do you want to roll again? (y/n): ");
        scanf(" %c", &roll_again);
        
        if (roll_again != 'y' && roll_again != 'Y') {
            printf("Exiting the program. Goodbye!\n");
            break;
        }
    }
    
    return 0;
}