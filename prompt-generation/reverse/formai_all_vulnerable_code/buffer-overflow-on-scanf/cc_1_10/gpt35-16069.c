//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hey there, I'm the Greedy Algorithm prankster!\n");
    printf("I'm here to show you how much you can achieve with just a little bit of greed.\n");
    printf("Let's play a game: we're going to create a bank account and try to get the highest balance possible.\n");
    
    int balance = 0;
    int deposits = 0;
    int withdrawals = 0;
    
    printf("Okay, so you start with a balance of $0. How much money do you want to deposit?\n");
    scanf("%d", &deposits);
    balance += deposits;
    
    printf("Great. Your balance is now $%d. How much do you want to withdraw?\n", balance);
    scanf("%d", &withdrawals);
    balance -= withdrawals;
    
    printf("Awesome. Your balance is now $%d. Let's keep going.\n", balance);
    printf("Do you want to deposit or withdraw? (D/W)\n");
    
    char choice;
    scanf(" %c", &choice);
    
    while (balance > 0) {
        if (choice == 'D' || choice == 'd') {
            printf("How much do you want to deposit?\n");
            scanf("%d", &deposits);
            if (deposits > balance) {
                printf("Sorry, you can't deposit more than your current balance.\n");
            } else {
                balance += deposits;
                printf("Okay, your balance is now $%d.\n", balance);
            }
        } else if (choice == 'W' || choice == 'w') {
            printf("How much do you want to withdraw?\n");
            scanf("%d", &withdrawals);
            if (withdrawals > balance) {
                printf("Sorry, you can't withdraw more than your current balance.\n");
            } else {
                balance -= withdrawals;
                printf("Okay, your balance is now $%d.\n", balance);
            }
        } else {
            printf("Sorry, I didn't understand. Please enter D or W.\n");
        }
        printf("Do you want to deposit or withdraw? (D/W)\n");
        scanf(" %c", &choice);
    }
    
    printf("Oops! Looks like you're out of money. Your final balance is $%d.\n", balance);
    printf("Thanks for playing with me, and remember: sometimes being greedy can pay off!\n");
    
    return 0;
}