//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int money = 1000;
int bet;

void play()
{
    int number;

    printf("\nGuess a lucky number between 1 and 10: ");
    scanf("%d", &number);

    if (number < 1 || number > 10) {
        printf("\nInvalid input! Please enter a number between 1 and 10.\n");
        return;
    }

    srand(time(NULL));
    int luckyNumber = rand() % 10 + 1;

    if (number == luckyNumber) {
        printf("\nCongratulations! You won %d dollars!\n", bet * 5);
        money += bet * 5;
    } else {
        printf("\nSorry, you lost your bet of %d dollars. The lucky number was %d.\n", bet, luckyNumber);
        money -= bet;
    }

    printf("You now have %d dollars.\n", money);

    if (money <= 0) {
        printf("You have run out of money. Game over!\n");
        exit(0);
    }
}

int main()
{
    printf("Welcome to the Lucky Number Game! You have 1000 dollars to start.\n");

    while (1) {
        printf("Place your bet (minimum 50 dollars): ");
        scanf("%d", &bet);

        if (bet < 50) {
            printf("\nInvalid input! Please enter a bet of at least 50 dollars.\n");
            continue;
        }

        if (bet > money) {
            printf("\nSorry, you don't have enough money to place that bet. You currently have %d dollars.\n", money);
            continue;
        }

        play();
    }

    return 0;
}