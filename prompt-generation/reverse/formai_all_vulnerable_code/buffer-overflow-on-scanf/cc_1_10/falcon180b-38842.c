//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 6 (inclusive)
int roll_die() {
    return rand() % 6 + 1;
}

// Function to simulate a dice roll
void simulate_roll(int num_dice, int num_sides) {
    int i, total = 0;

    for (i = 0; i < num_dice; i++) {
        total += roll_die();
    }

    printf("Rolling %d %d-sided dice...\n", num_dice, num_sides);
    printf("Total: %d\n", total);
}

int main() {
    int num_dice, num_sides, choice;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Main menu loop
    while (1) {
        printf("Dice Roller Menu:\n");
        printf("1. Roll dice\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            // Roll dice submenu
            printf("Dice Rolling Submenu:\n");
            printf("1. Roll 1 6-sided die\n");
            printf("2. Roll 2 6-sided dice\n");
            printf("3. Roll 3 6-sided dice\n");
            printf("4. Roll 1 20-sided die\n");
            printf("5. Roll 2 20-sided dice\n");
            printf("6. Roll 3 20-sided dice\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
            case 1:
                num_dice = 1;
                num_sides = 6;
                break;
            case 2:
                num_dice = 2;
                num_sides = 6;
                break;
            case 3:
                num_dice = 3;
                num_sides = 6;
                break;
            case 4:
                num_dice = 1;
                num_sides = 20;
                break;
            case 5:
                num_dice = 2;
                num_sides = 20;
                break;
            case 6:
                num_dice = 3;
                num_sides = 20;
                break;
            default:
                printf("Invalid choice.\n");
                break;
            }

            simulate_roll(num_dice, num_sides);
            break;

        case 2:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}