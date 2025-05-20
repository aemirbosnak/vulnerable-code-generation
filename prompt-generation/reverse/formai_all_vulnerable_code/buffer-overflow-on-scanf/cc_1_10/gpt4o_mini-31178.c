//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayWelcome();
void rollDice(int diceType);
void playAgain();
void displayResult(int roll);

int main() {
    srand(time(NULL));  // seed the random number generator
    displayWelcome();

    int choice = 0;
    while (choice != 4) {
        printf("\nChoose a dice to roll:\n");
        printf("1. D4\n");
        printf("2. D6\n");
        printf("3. D20\n");
        printf("4. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                rollDice(4);
                break;
            case 2:
                rollDice(6);
                break;
            case 3:
                rollDice(20);
                break;
            case 4:
                printf("Thank you for playing! Have a great day!\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
                break;
        }
    }
    return 0;
}

void displayWelcome() {
    printf("=================================\n");
    printf("       Welcome to Dice Roller!   \n");
    printf("=================================\n");
    printf("Feeling lucky? Let's roll some dice!\n");
}

void rollDice(int diceType) {
    printf("\nRolling a D%d...\n", diceType);
    int roll = (rand() % diceType) + 1;  // Generate random number based on the dice type
    displayResult(roll);
    playAgain();
}

void displayResult(int roll) {
    printf("You rolled a: %d\n", roll);
    if (roll == 1) {
        printf("Critical fail! What a disaster!\n");
    } else if (roll == 6) {
        printf("Lucky number six! Everyone loves six!\n");
    } else if (roll == 20) {
        printf("Wow! A natural 20! You're a wizard!\n");
    } else {
        printf("Not bad! Keep rolling!\n");
    }
}

void playAgain() {
    char response;
    printf("Would you like to roll again? (y/n): ");
    scanf(" %c", &response);  // Notice the space before %c to consume any newline characters.

    if(response == 'y' || response == 'Y') {
        printf("Great! Let's get those dice rolling again!\n");
    } else if(response == 'n' || response == 'N') {
        printf("Alright, see you next time!\n");
    } else {
        printf("Invalid input! Defaulting to no. See you next time!\n");
    }
}