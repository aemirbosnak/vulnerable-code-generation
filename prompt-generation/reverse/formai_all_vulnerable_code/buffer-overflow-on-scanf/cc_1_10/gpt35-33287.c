//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random number between min and max
int randomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    int balance = 100;
    int bet;

    printf("\nWelcome to the Casino!\n");

    while (balance > 0) {
        printf("\nYour balance: %d\n", balance);

        printf("Enter your bet (minimum bet is 10): ");
        scanf("%d", &bet);

        if (bet < 10) {
            printf("Minimum bet is 10!\n");
            continue;
        }

        if (bet > balance) {
            printf("Insufficient balance!\n");
            continue;
        }

        int dice1 = randomNumber(1, 6);
        int dice2 = randomNumber(1, 6);
        int sum = dice1 + dice2;

        printf("You rolled a %d and a %d, totalling %d\n", dice1, dice2, sum);

        if (sum == 7) {
            balance += bet;
            printf("You win! You now have %d\n", balance);
        } else {
            balance -= bet;
            printf("You lose! You now have %d\n", balance);
        }
    }

    printf("\nSorry, you ran out of money!\n");

    return 0;
}