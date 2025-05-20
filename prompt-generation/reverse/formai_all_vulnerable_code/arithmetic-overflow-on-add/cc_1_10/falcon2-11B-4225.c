//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    int account_number;
    char name[50];
    int balance;
    int total_balance;
    int total_accounts;
};

int main() {
    // Initialize global variables
    int num_accounts = 0;
    int total_balance = 0;

    // Create an array to store accounts
    struct Account accounts[100];

    // Prompt user for input
    char command;
    while ((command = getchar())!= '\n') {
        switch (command) {
            case '1':
                // Create a new account
                printf("Enter account number: ");
                scanf("%d", &accounts[num_accounts].account_number);
                printf("Enter account name: ");
                fgets(accounts[num_accounts].name, sizeof(accounts[num_accounts].name), stdin);
                accounts[num_accounts].balance = 0;
                accounts[num_accounts].total_balance += accounts[num_accounts].balance;
                accounts[num_accounts].total_accounts++;
                printf("Account created\n");
                break;
            case '2':
                // Deposit money
                printf("Enter account number: ");
                scanf("%d", &accounts[num_accounts].account_number);
                printf("Enter amount to deposit: ");
                scanf("%d", &accounts[num_accounts].balance);
                accounts[num_accounts].total_balance += accounts[num_accounts].balance;
                break;
            case '3':
                // Withdraw money
                printf("Enter account number: ");
                scanf("%d", &accounts[num_accounts].account_number);
                printf("Enter amount to withdraw: ");
                scanf("%d", &accounts[num_accounts].balance);
                if (accounts[num_accounts].balance < accounts[num_accounts].balance) {
                    printf("Insufficient funds\n");
                } else {
                    accounts[num_accounts].total_balance -= accounts[num_accounts].balance;
                }
                break;
            case '4':
                // Check balance
                printf("Enter account number: ");
                scanf("%d", &accounts[num_accounts].account_number);
                printf("Balance: %d\n", accounts[num_accounts].balance);
                break;
            case '5':
                // List accounts
                printf("Total accounts: %d\n", accounts[num_accounts].total_accounts);
                printf("Total balance: %d\n", accounts[num_accounts].total_balance);
                break;
            case '6':
                // Quit program
                exit(0);
            default:
                printf("Invalid command\n");
        }
    }
    return 0;
}