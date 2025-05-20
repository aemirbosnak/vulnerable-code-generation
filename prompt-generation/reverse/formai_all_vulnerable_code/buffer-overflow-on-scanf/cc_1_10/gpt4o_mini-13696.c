//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_menu() {
    printf("\n===========================\n");
    printf("        Dice Roller        \n");
    printf("===========================\n");
    printf("1. Roll a Dice\n");
    printf("2. Roll Multiple Dice\n");
    printf("3. Exit\n");
    printf("===========================\n");
    printf("Choose an option: ");
}

int roll_dice() {
    return (rand() % 6) + 1;  // Generate a number between 1 and 6
}

void roll_multiple_dice(int count) {
    printf("\nRolling %d dice...\n", count);
    for (int i = 0; i < count; i++) {
        int result = roll_dice();
        printf("Dice %d rolled: %d\n", i + 1, result);
    }
}

void roll_single_dice() {
    int result = roll_dice();
    printf("\nYou rolled a %d!\n", result);
    
    // Fun messages based on the dice result
    switch (result) {
        case 1:
            printf("Oh no! You rolled a 1! Better luck next time!\n");
            break;
        case 2:
            printf("You rolled a 2! Not bad, keep it rolling!\n");
            break;
        case 3:
            printf("You've got a 3! A solid middle ground!\n");
            break;
        case 4:
            printf("A 4! You're getting closer to greatness!\n");
            break;
        case 5:
            printf("Wow! A 5! You're almost there!\n");
            break;
        case 6:
            printf("Amazing! A 6! You're on fire!\n");
            break;
    }
}

int main() {
    srand(time(0));  // Seed the random number generator
    int choice;

    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                roll_single_dice();
                break;
            case 2: {
                int count;
                printf("How many dice would you like to roll? ");
                scanf("%d", &count);
                if (count > 0) {
                    roll_multiple_dice(count);
                } else {
                    printf("Please enter a valid number of dice to roll!\n");
                }
                break;
            }
            case 3:
                printf("Goodbye! May the odds be ever in your favor!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}