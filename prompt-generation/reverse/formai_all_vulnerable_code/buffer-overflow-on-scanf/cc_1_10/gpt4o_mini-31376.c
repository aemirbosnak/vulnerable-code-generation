//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 6

// Function to roll a single die
int roll_single_die() {
    return (rand() % MAX_DICE) + 1;
}

// Function to roll multiple dice
void roll_multiple_dice(int num_dice) {
    int total = 0;

    printf("Rolling %d dice...\n", num_dice);
    for (int i = 0; i < num_dice; i++) {
        int roll = roll_single_die();
        printf("Die %d: %d\n", i + 1, roll);
        total += roll;
    }

    printf("Total of all dice: %d\n", total);
}

// Function to print the menu
void print_menu() {
    printf("\n=== Welcome to the Dice Roller ===\n");
    printf("1. Roll a single die\n");
    printf("2. Roll multiple dice\n");
    printf("3. Exit\n");
}

// Function to prompt the user for the number of dice
int get_num_dice() {
    int num;
    printf("Enter the number of dice to roll (1-10): ");
    scanf("%d", &num);
    return num >= 1 && num <= 10 ? num : 0;
}

// Main dice roller program
int main() {
    srand(time(NULL)); // Seed the random number generator

    int choice;
    while (1) {
        print_menu();
        
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                int roll = roll_single_die();
                printf("You rolled a single die: %d\n", roll);
                break;
            }
            case 2: {
                int num_dice = get_num_dice();
                if (num_dice > 0) {
                    roll_multiple_dice(num_dice);
                } else {
                    printf("Invalid number of dice! Please choose between 1 and 10.\n");
                }
                break;
            }
            case 3:
                printf("Exiting the Dice Roller. May the odds be ever in your favor!\n");
                return 0;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}