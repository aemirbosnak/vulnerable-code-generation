//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_menu() {
    printf("Welcome to the Enchanted Dice Roller!\n");
    printf("Choose your destiny:\n");
    printf("1. Roll a die (default: 6 sides)\n");
    printf("2. Roll a custom die\n");
    printf("3. Exit the mystical realm\n");
}

int roll_die(int sides) {
    return (rand() % sides) + 1; // Rolling a die!
}

void start_rolling(int sides) {
    char choice;
    int roll;

    printf("You have chosen to roll a %d-sided die (the fate of the dice awaits you!)\n", sides);
    do {
        roll = roll_die(sides);
        printf("You rolled: %d\n", roll);
        printf("Would you like to roll again? (y/n): ");
        getchar(); // to consume any leftover newline character
        choice = getchar();
    } while (choice == 'y' || choice == 'Y');

    printf("You wander away, leaving behind the rolled dreams...\n");
}

int main() {
    srand(time(0)); // Seed the random number generator
    int option, sides;

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                start_rolling(6); // Rolling a 6-sided die by default
                break;
            case 2:
                printf("Enter the number of sides for your mystical die: ");
                scanf("%d", &sides);
                if (sides < 1) {
                    printf("A die must have at least 1 side, wanderer!\n");
                } else {
                    start_rolling(sides);
                }
                break;
            case 3:
                printf("You have chosen to leave the Enchanted Dice Roller... Farewell, brave soul!\n");
                break;
            default:
                printf("An ancient warning bell rings: Please choose a valid option!\n");
                break;
        }

        printf("\n");
    } while (option != 3);

    return 0;
}