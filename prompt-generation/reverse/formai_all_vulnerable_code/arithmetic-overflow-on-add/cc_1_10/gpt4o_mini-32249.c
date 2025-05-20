//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10

// Function to display the menu
void displayMenu() {
    printf("Welcome to the Dice Roller!\n");
    printf("Choose the type of dice you want to roll:\n");
    printf("1. d4\n");
    printf("2. d6\n");
    printf("3. d8\n");
    printf("4. d10\n");
    printf("5. d12\n");
    printf("6. d20\n");
    printf("7. Roll multiple dice\n");
    printf("8. Exit\n");
}

// Function to roll a single die
int rollDie(int sides) {
    return (rand() % sides) + 1;
}

// Function to roll multiple dice
void rollMultipleDice(int sides, int numberOfDice) {
    int results[MAX_DICE];
    printf("You rolled %d d%d: ", numberOfDice, sides);
    for (int i = 0; i < numberOfDice; i++) {
        results[i] = rollDie(sides);
        printf("%d ", results[i]);
    }
    printf("\n");
}

int main() {
    srand(time(0)); // Seed the random number generator
    int choice, sides, numberOfDice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: sides = 4; break;
            case 2: sides = 6; break;
            case 3: sides = 8; break;
            case 4: sides = 10; break;
            case 5: sides = 12; break;
            case 6: sides = 20; break;
            case 7:
                printf("How many dice do you want to roll (1 - %d)? ", MAX_DICE);
                scanf("%d", &numberOfDice);
                if (numberOfDice < 1 || numberOfDice > MAX_DICE) {
                    printf("Please roll between 1 and %d dice.\n\n", MAX_DICE);
                } else {
                    rollMultipleDice(sides, numberOfDice);
                }
                break;
            case 8:
                printf("Exiting the Dice Roller. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n\n");
        }
        
        if (choice >= 1 && choice <= 6) {
            int roll = rollDie(sides);
            printf("You rolled a d%d and got: %d\n\n", sides, roll);
        } else if (choice == 8) {
            break;
        }

    } while (choice != 8);

    return 0;
}