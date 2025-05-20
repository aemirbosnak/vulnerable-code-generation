//FormAI DATASET v1.0 Category: Table Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void displayMenu();
void rollDice(int *dice1, int *dice2);
int calculateSum(int dice1, int dice2);
void playGame();

int main()
{
    srand(time(NULL)); // Use current time as seed for random number generator
    displayMenu();
    return 0;
}

/**
 * Displays the game menu
 */
void displayMenu()
{
    int choice;
    printf("Welcome to the C Table Game!\n");
    printf("1. Play Game\n");
    printf("2. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            playGame();
            break;
        case 2:
            printf("Thanks for playing!\n");
            break;
        default:
            printf("Invalid choice, please try again.\n");
            displayMenu();
            break;
    }
}

/**
 * Rolls two dice and updates their values using pointers
 */
void rollDice(int *dice1, int *dice2)
{
    *dice1 = (rand() % 6) + 1; // Generate random number between 1 and 6
    *dice2 = (rand() % 6) + 1;
    printf("Dice 1: %d, Dice 2: %d\n", *dice1, *dice2);
}

/**
 * Calculates the sum of two dice
 */
int calculateSum(int dice1, int dice2)
{
    return dice1 + dice2;
}

/**
 * Executes the main game loop
 */
void playGame()
{
    int money = 100;
    int bet;
    int dice1, dice2, sum;
    printf("You have $%d. Good luck!\n", money);
    while (money > 0) {
        printf("Enter your bet: ");
        scanf("%d", &bet);
        if (bet > money) {
            printf("You don't have enough money to bet that much.\n");
            continue;
        }
        rollDice(&dice1, &dice2);
        sum = calculateSum(dice1, dice2);
        if (sum < 7) {
            printf("You lose!\n");
            money -= bet;
        } else {
            printf("You win!\n");
            money += bet;
        }
        printf("You now have $%d.\n", money);
    }
    printf("You're out of money, better luck next time.\n");
    displayMenu();
}