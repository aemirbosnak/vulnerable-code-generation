//FormAI DATASET v1.0 Category: Digital signal processing ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    printf("Welcome to the infamous DSP Casino!\n");
    int bet;
    int balance = 500;
    int choice;
    while (1) {
        printf("Your current balance is %d\n", balance);
        printf("\nChoose your game of choice:\n");
        printf("1. Blackjack\n");
        printf("2. Slot Machine\n");
        printf("3. Quit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                bet = rand() % balance;
                printf("You place a bet of %d\n", bet);
                if (rand() % 2) {
                    printf("You win! Your balance is now %d\n", balance + bet * 2);
                    balance += bet * 2;
                } else {
                    printf("You lose! Your balance is now %d\n", balance - bet);
                    balance -= bet;
                }
                break;
            case 2:
                printf("You pull the lever...\n");
                int a = rand() % 3 + 1;
                int b = rand() % 3 + 1;
                int c = rand() % 3 + 1;
                printf("||%d||%d||%d||\n", a, b, c);
                if (a == b && b == c) {
                    printf("JACKPOT! Your balance is now %d\n", balance + bet * 10);
                    balance += bet * 10;
                } else {
                    printf("Sorry, try again! Your balance is now %d\n", balance - bet);
                    balance -= bet;
                }
                break;
            case 3:
                printf("Thanks for playing at DSP Casino, come back soon!\n");
                return 0;
            default:
                printf("Invalid choice, try again.\n");
                break;
        }
        if (balance <= 0) {
            printf("Sorry, you have run out of money. Better luck next time!\n");
            return 0;
        }
    }

}