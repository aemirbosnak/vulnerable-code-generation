//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMenu() {
    printf("Welcome to the Dice Roller!\n");
    printf("Choose the type of dice to roll:\n");
    printf("1. D4\n");
    printf("2. D6\n");
    printf("3. D8\n");
    printf("4. D10\n");
    printf("5. D12\n");
    printf("6. D20\n");
    printf("7. Quit\n");
}

int rollDice(int sides) {
    return (rand() % sides) + 1;
}

void rollSpecificDice(int sides) {
    int rolls;
    printf("How many D%d would you like to roll? ", sides);
    scanf("%d", &rolls);

    printf("Rolling %d D%d!\n", rolls, sides);
    for (int i = 0; i < rolls; i++) {
        int result = rollDice(sides);
        printf("Roll %d: %d\n", i + 1, result);
    }
}

int main() {
    srand(time(NULL));
    int choice;

    while (1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                rollSpecificDice(4);
                break;
            case 2:
                rollSpecificDice(6);
                break;
            case 3:
                rollSpecificDice(8);
                break;
            case 4:
                rollSpecificDice(10);
                break;
            case 5:
                rollSpecificDice(12);
                break;
            case 6:
                rollSpecificDice(20);
                break;
            case 7:
                printf("Thank you for using the Dice Roller. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    }

    return 0;
}