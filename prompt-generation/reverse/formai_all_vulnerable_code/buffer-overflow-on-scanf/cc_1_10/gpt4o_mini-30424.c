//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void welcome_message() {
    printf("====================================\n");
    printf("          Dice Roller Program       \n");
    printf("====================================\n");
    printf("Welcome, noble user! This program allows you to roll various dice.\n");
    printf("Choose the type of dice you'd like to roll, and witness the fortune unfold!\n");
    printf("====================================\n");
}

int roll_dice(int sides) {
    return (rand() % sides) + 1;
}

void display_roll_result(int dice_type, int result) {
    printf("You rolled a %d on a %d-sided die!\n", result, dice_type);
}

void show_dice_options() {
    printf("Choose your dice type:\n");
    printf("1. 4-sided die (d4)\n");
    printf("2. 6-sided die (d6)\n");
    printf("3. 8-sided die (d8)\n");
    printf("4. 10-sided die (d10)\n");
    printf("5. 12-sided die (d12)\n");
    printf("6. 20-sided die (d20)\n");
    printf("7. Exit\n");
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    welcome_message(); // Display welcome message

    int choice, rolls, i;
    
    while (1) {
        show_dice_options(); // Show available options
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("How many times would you like to roll the d4? ");
                scanf("%d", &rolls);
                for (i = 0; i < rolls; i++) {
                    display_roll_result(4, roll_dice(4));
                }
                break;
            case 2:
                printf("How many times would you like to roll the d6? ");
                scanf("%d", &rolls);
                for (i = 0; i < rolls; i++) {
                    display_roll_result(6, roll_dice(6));
                }
                break;
            case 3:
                printf("How many times would you like to roll the d8? ");
                scanf("%d", &rolls);
                for (i = 0; i < rolls; i++) {
                    display_roll_result(8, roll_dice(8));
                }
                break;
            case 4:
                printf("How many times would you like to roll the d10? ");
                scanf("%d", &rolls);
                for (i = 0; i < rolls; i++) {
                    display_roll_result(10, roll_dice(10));
                }
                break;
            case 5:
                printf("How many times would you like to roll the d12? ");
                scanf("%d", &rolls);
                for (i = 0; i < rolls; i++) {
                    display_roll_result(12, roll_dice(12));
                }
                break;
            case 6:
                printf("How many times would you like to roll the d20? ");
                scanf("%d", &rolls);
                for (i = 0; i < rolls; i++) {
                    display_roll_result(20, roll_dice(20));
                }
                break;
            case 7:
                printf("Thank you for participating in the Dice Roller Program. Farewell!\n");
                return 0; // Exit the program
            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }
        printf("====================================\n");
    }
}