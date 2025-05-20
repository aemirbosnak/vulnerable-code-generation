//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 20
#define MIN_SIDES 4

void display_menu();
int roll_dice(int sides);
void play_game();
void print_instructions();
void clear_buffer();

int main() {
    srand(time(NULL)); // Seed the random number generator

    int choice;
    do {
        display_menu();
        printf("Enter your choice: ");
        choice = 0;
        while (choice <= 0) { // Ensure choice is positive
            scanf("%d", &choice);
            if (choice <= 0) {
                printf("Please enter a valid choice: ");
                clear_buffer();
            }
        }

        switch (choice) {
            case 1:
                play_game();
                break;
            case 2:
                print_instructions();
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}

void display_menu() {
    printf("\n--- Dice Roller Menu ---\n");
    printf("1. Roll a dice\n");
    printf("2. Instructions\n");
    printf("3. Exit\n");
}

int roll_dice(int sides) {
    return (rand() % sides) + 1; // Roll the dice
}

void play_game() {
    int sides;
    char choice;

    do {
        printf("Enter the number of sides on the dice (between %d and %d): ", MIN_SIDES, MAX_SIDES);
        scanf("%d", &sides);
        if (sides < MIN_SIDES || sides > MAX_SIDES) {
            printf("Invalid number of sides! Please enter a number between %d and %d.\n", MIN_SIDES, MAX_SIDES);
            continue;
        }

        int result = roll_dice(sides);
        printf("You rolled a %d on a %d-sided dice!\n", result, sides);

        printf("Would you like to roll again? (y/n): ");
        clear_buffer(); // Clear the input buffer
        scanf("%c", &choice);
    } while (choice == 'y' || choice == 'Y');
}

void print_instructions() {
    printf("\n--- Dice Roller Instructions ---\n");
    printf("1. Choose the number of sides on the dice (between 4 and 20).\n");
    printf("2. Hit 'Enter' to roll the dice.\n");
    printf("3. You will see the result of your roll.\n");
    printf("4. You can choose to roll again or return to the main menu.\n");
    printf("5. Select 'Exit' to close the program.\n");
}

void clear_buffer() {
    while(getchar() != '\n'); // Clear the input buffer
}