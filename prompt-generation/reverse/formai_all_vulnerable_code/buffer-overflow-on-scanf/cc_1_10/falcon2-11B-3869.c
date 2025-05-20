//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int account_number;
    char name[100];
    double balance;
} Account;

void create_account(Account* account) {
    printf("Enter account number: ");
    scanf("%d", &account->account_number);
    printf("Enter name: ");
    scanf("%s", account->name);
    printf("Enter initial balance: ");
    scanf("%lf", &account->balance);
}

void display_account(Account account) {
    printf("Account Number: %d\n", account.account_number);
    printf("Name: %s\n", account.name);
    printf("Balance: $%.2lf\n", account.balance);
}

void deposit(Account* account, double amount) {
    account->balance += amount;
    printf("Deposit of $%.2lf was successful.\n", amount);
}

void withdraw(Account* account, double amount) {
    if (amount > account->balance) {
        printf("Insufficient funds. Withdrawal was unsuccessful.\n");
    } else {
        account->balance -= amount;
        printf("Withdrawal of $%.2lf was successful.\n", amount);
    }
}

void transfer(Account* account, Account* other_account, double amount) {
    if (amount > account->balance) {
        printf("Insufficient funds. Transfer was unsuccessful.\n");
    } else {
        account->balance -= amount;
        other_account->balance += amount;
        printf("Transfer of $%.2lf was successful.\n", amount);
    }
}

int main() {
    Account accounts[10];
    int choice = 0;
    int num_accounts = 0;
    int index = 0;

    while (choice!= 4) {
        printf("1. Create Account\n");
        printf("2. Display Account\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Transfer\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account(&accounts[index]);
                index++;
                num_accounts++;
                break;
            case 2:
                if (index >= num_accounts) {
                    printf("No accounts to display.\n");
                } else {
                    display_account(accounts[index - 1]);
                }
                break;
            case 3:
                if (index >= num_accounts) {
                    printf("No accounts to deposit.\n");
                } else {
                    double amount;
                    printf("Enter amount to deposit: ");
                    scanf("%lf", &amount);
                    deposit(&accounts[index - 1], amount);
                }
                break;
            case 4:
                if (index >= num_accounts) {
                    printf("No accounts to withdraw.\n");
                } else {
                    double amount;
                    printf("Enter amount to withdraw: ");
                    scanf("%lf", &amount);
                    withdraw(&accounts[index - 1], amount);
                }
                break;
            case 5:
                if (index >= num_accounts) {
                    printf("No accounts to transfer.\n");
                } else {
                    double amount;
                    printf("Enter amount to transfer: ");
                    scanf("%lf", &amount);
                    transfer(&accounts[index - 1], &accounts[num_accounts - 1], amount);
                }
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}