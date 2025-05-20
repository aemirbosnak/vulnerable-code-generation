//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
    char name[50];
    char account_number[20];
    double balance;
};

int main() {
    // Initialize the bank database
    struct account accounts[100];
    int num_accounts = 0;

    // Get the user's input
    char input[100];
    while (1) {
        printf("Enter a command (add, deposit, withdraw, balance, quit): ");
        scanf("%s", input);

        // Add a new account
        if (strcmp(input, "add") == 0) {
            printf("Enter the account holder's name: ");
            scanf("%s", accounts[num_accounts].name);

            printf("Enter the account number: ");
            scanf("%s", accounts[num_accounts].account_number);

            printf("Enter the initial balance: ");
            scanf("%lf", &accounts[num_accounts].balance);

            num_accounts++;
        } 

        // Deposit money into an account
        else if (strcmp(input, "deposit") == 0) {
            char account_number[20];
            double amount;

            printf("Enter the account number: ");
            scanf("%s", account_number);

            printf("Enter the amount to deposit: ");
            scanf("%lf", &amount);

            // Find the account
            int i;
            for (i = 0; i < num_accounts; i++) {
                if (strcmp(accounts[i].account_number, account_number) == 0) {
                    accounts[i].balance += amount;
                    break;
                }
            }

            // Print a success message
            if (i < num_accounts) {
                printf("Deposit successful!\n");
            } else {
                printf("Account not found!\n");
            }
        } 

        // Withdraw money from an account
        else if (strcmp(input, "withdraw") == 0) {
            char account_number[20];
            double amount;

            printf("Enter the account number: ");
            scanf("%s", account_number);

            printf("Enter the amount to withdraw: ");
            scanf("%lf", &amount);

            // Find the account
            int i;
            for (i = 0; i < num_accounts; i++) {
                if (strcmp(accounts[i].account_number, account_number) == 0) {
                    if (accounts[i].balance >= amount) {
                        accounts[i].balance -= amount;
                        break;
                    } else {
                        printf("Insufficient funds!\n");
                        break;
                    }
                }
            }

            // Print a success message
            if (i < num_accounts) {
                printf("Withdrawal successful!\n");
            } else {
                printf("Account not found!\n");
            }
        } 

        // Get the balance of an account
        else if (strcmp(input, "balance") == 0) {
            char account_number[20];

            printf("Enter the account number: ");
            scanf("%s", account_number);

            // Find the account
            int i;
            for (i = 0; i < num_accounts; i++) {
                if (strcmp(accounts[i].account_number, account_number) == 0) {
                    printf("The balance is: %.2lf\n", accounts[i].balance);
                    break;
                }
            }

            // Print a not found message
            if (i == num_accounts) {
                printf("Account not found!\n");
            }
        } 

        // Quit the program
        else if (strcmp(input, "quit") == 0) {
            break;
        } 

        // Invalid input
        else {
            printf("Invalid command!\n");
        }
    }

    return 0;
}