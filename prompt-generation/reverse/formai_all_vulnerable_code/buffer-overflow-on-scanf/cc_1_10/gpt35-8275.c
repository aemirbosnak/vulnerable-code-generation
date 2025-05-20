//FormAI DATASET v1.0 Category: Dice Roller ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This program simulates a futuristic dice roller that can roll different types of dice

int main() {
    
    int sides, num_dice, i, roll;
    char dice_type;
    
    // Set the seed for the random number generator
    srand(time(0));
    
    // Welcome message
    printf("Welcome to the Futuristic Dice Roller!\n\n");
    
    // Prompt the user to choose a type of dice to roll
    printf("What type of dice would you like to roll?\n");
    printf("Enter 'd' for d4, 't' for d6, 'x' for d8, 'y' for d10, 'z' for d12, or 'm' for d20: ");
    scanf("%c", &dice_type);
    
    // Prompt the user to specify how many dice to roll
    printf("\nHow many dice would you like to roll? ");
    scanf("%d", &num_dice);
    
    // Roll the dice and display the results
    switch(dice_type) {
        case 'd':
            sides = 4;
            printf("\nRolling d4...\n");
            break;
        case 't':
            sides = 6;
            printf("\nRolling d6...\n");
            break;
        case 'x':
            sides = 8;
            printf("\nRolling d8...\n");
            break;
        case 'y':
            sides = 10;
            printf("\nRolling d10...\n");
            break;
        case 'z':
            sides = 12;
            printf("\nRolling d12...\n");
            break;
        case 'm':
            sides = 20;
            printf("\nRolling d20...\n");
            break;
        default:
            printf("\nInvalid input, please try again.\n");
            return 0;
    }
    
    // Display each roll
    printf("\nYou rolled:\n");
    for(i=0; i<num_dice; i++) {
        roll = rand() % sides + 1;
        printf("%d ", roll);
    }
    
    return 0;
}