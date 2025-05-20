//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void welcome() {
    printf("*******************************************\n");
    printf("*         Welcome to the Dice Roller!     *\n");
    printf("*       Where fate whispers through chance *\n");
    printf("*******************************************\n");
    printf("Here you can roll various types of dice and embrace the randomness of life.\n");
}

void displayMenu() {
    printf("\nChoose the type of dice to roll:\n");
    printf("1. 4-sided Dice (D4)\n");
    printf("2. 6-sided Dice (D6)\n");
    printf("3. 8-sided Dice (D8)\n");
    printf("4. 10-sided Dice (D10)\n");
    printf("5. 12-sided Dice (D12)\n");
    printf("6. 20-sided Dice (D20)\n");
    printf("7. Exit\n");
}

int rollDice(int sides) {
    return (rand() % sides) + 1;
}

void rollPrompt() {
    printf("Press Enter to roll the dice...");
    while (getchar() != '\n');
}

void displayResult(int roll, int sides) {
    printf("You rolled a %d on a D%d!\n", roll, sides);
}

int main() {
    srand(time(0));
    welcome();

    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice (1-7): ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); // Clear invalid input
            printf("Please enter a valid number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                rollPrompt();
                displayResult(rollDice(4), 4);
                break;
            case 2:
                rollPrompt();
                displayResult(rollDice(6), 6);
                break;
            case 3:
                rollPrompt();
                displayResult(rollDice(8), 8);
                break;
            case 4:
                rollPrompt();
                displayResult(rollDice(10), 10);
                break;
            case 5:
                rollPrompt();
                displayResult(rollDice(12), 12);
                break;
            case 6:
                rollPrompt();
                displayResult(rollDice(20), 20);
                break;
            case 7:
                printf("Thank you for playing! May luck be on your side.\n");
                return 0;
            default:
                printf("Invalid choice. Please select a number between 1 and 7.\n");
        }
        printf("\n");
    }

    return 0;
}