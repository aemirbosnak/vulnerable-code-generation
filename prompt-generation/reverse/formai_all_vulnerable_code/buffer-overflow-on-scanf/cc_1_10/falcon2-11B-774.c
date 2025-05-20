//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ACCOUNT_NUM 100
#define MAX_ACCOUNT_NAME 100
#define MAX_ACCOUNT_BALANCE 100

struct account {
    char account_number[MAX_ACCOUNT_NUM];
    char account_name[MAX_ACCOUNT_NAME];
    float account_balance;
};

int main() {
    struct account accounts[MAX_ACCOUNT_NUM];
    int num_accounts = 0;

    printf("Welcome to the Bank Record System!\n");

    // Create an account
    printf("Enter the account number (1-100): ");
    scanf("%s", accounts[num_accounts].account_number);
    printf("Enter the account name: ");
    scanf("%s", accounts[num_accounts].account_name);
    printf("Enter the initial balance (0-99999.99): ");
    scanf("%f", &accounts[num_accounts].account_balance);
    num_accounts++;

    // Deposit money into an account
    printf("Enter the account number to deposit money into: ");
    scanf("%s", accounts[num_accounts].account_number);
    printf("Enter the amount to deposit: ");
    scanf("%f", &accounts[num_accounts].account_balance);
    num_accounts++;

    // Withdraw money from an account
    printf("Enter the account number to withdraw money from: ");
    scanf("%s", accounts[num_accounts].account_number);
    printf("Enter the amount to withdraw: ");
    scanf("%f", &accounts[num_accounts].account_balance);
    num_accounts++;

    // Print account details
    for (int i = 0; i < num_accounts; i++) {
        printf("Account Number: %s\n", accounts[i].account_number);
        printf("Account Name: %s\n", accounts[i].account_name);
        printf("Account Balance: $%.2f\n", accounts[i].account_balance);
        printf("\n");
    }

    return 0;
}