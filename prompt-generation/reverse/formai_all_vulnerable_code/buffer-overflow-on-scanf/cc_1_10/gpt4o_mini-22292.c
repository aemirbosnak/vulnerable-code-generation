//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a single dice with specified sides
int roll_dice(int sides) {
    return (rand() % sides) + 1; // Returns a number between 1 and sides
}

// Function to roll multiple dice
void roll_multiple_dice(int dice_count, int sides) {
    printf("Rolling %d d%s... \n", dice_count, sides == 6 ? "6" : (sides == 10 ? "10" : "20"));
    int total = 0;
    for (int i = 0; i < dice_count; i++) {
        int result = roll_dice(sides);
        printf("Roll %d: %d\n", i + 1, result);
        total += result; // Summing up the rolls
    }
    printf("Total: %d\n", total);
}

void display_menu() {
    printf("=== Welcome to the Dice Roller! ===\n");
    printf("1. Roll a D6\n");
    printf("2. Roll a D10\n");
    printf("3. Roll a D20\n");
    printf("4. Roll Multiple Dice\n");
    printf("5. Exit\n");
    printf("=====================================\n");
}

int main() {
    srand(time(NULL)); // Seed random number generator
    int choice = 0;

    while (choice != 5) {
        display_menu();
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                roll_multiple_dice(1, 6);
                break;
            case 2:
                roll_multiple_dice(1, 10);
                break;
            case 3:
                roll_multiple_dice(1, 20);
                break;
            case 4: {
                int dice_count, sides;
                printf("Enter the number of dice to roll: ");
                scanf("%d", &dice_count);
                printf("Enter the type of dice (6, 10, or 20): ");
                scanf("%d", &sides);
                if (sides == 6 || sides == 10 || sides == 20) {
                    roll_multiple_dice(dice_count, sides);
                } else {
                    printf("Invalid dice type selected.\n");
                }
                break;
            }
            case 5:
                printf("Exiting the Dice Roller. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}