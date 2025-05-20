//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

// This program simulates a simple ATM machine

int main() {
    int pin, choice, account_type;
    float balance, deposit_amount, withdrawal_amount, interest_rate, monthly_interest, total_withdrawal;
    char name[50], account_number[20];
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    srand(t->tm_sec);

    // Initialize variables
    pin = rand() % 1000 + 1;
    balance = 1000;
    interest_rate = 0.05;
    monthly_interest = interest_rate / 12;
    total_withdrawal = 0;

    // Print welcome message
    printf("Welcome to the ATM!\n");
    printf("Enter your PIN: ");
    scanf("%d", &pin);

    // Check if PIN is correct
    if (pin!= 1234) {
        printf("Invalid PIN. Exiting...\n");
        return 0;
    }

    // Display menu
    printf("\nSelect an option:\n");
    printf("1. Check Balance\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Perform selected operation
    switch (choice) {
        case 1:
            printf("\nYour current balance is $%.2f\n", balance);
            break;
        case 2:
            printf("\nEnter deposit amount: ");
            scanf("%f", &deposit_amount);
            balance += deposit_amount;
            printf("\nDeposit successful! Your new balance is $%.2f\n", balance);
            break;
        case 3:
            printf("\nEnter withdrawal amount: ");
            scanf("%f", &withdrawal_amount);
            if (withdrawal_amount > balance) {
                printf("\nInsufficient funds. Withdrawal cancelled.\n");
            } else {
                balance -= withdrawal_amount;
                total_withdrawal += withdrawal_amount;
                printf("\nWithdrawal successful! Your new balance is $%.2f\n", balance);
            }
            break;
        case 4:
            printf("\nThank you for using our ATM. Goodbye!\n");
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
    }

    return 0;
}