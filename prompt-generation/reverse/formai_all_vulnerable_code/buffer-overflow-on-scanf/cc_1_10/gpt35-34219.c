//FormAI DATASET v1.0 Category: Banking Record System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct for bank account record */
typedef struct {
    char name[50];
    double balance;
    int account_number;
} Account;

/* Function declarations */
void displayMainMenu(void);
void openAccount(Account accounts[], int *num_accounts);
void displayAccount(Account accounts[], int num_accounts);
void deposit(Account accounts[], int num_accounts);
void withdraw(Account accounts[], int num_accounts);

/* Main function */
int main(void) {
    Account accounts[100];
    int num_accounts = 0;
    char choice;

    do {
        displayMainMenu();
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                openAccount(accounts, &num_accounts);
                break;
            case '2':
                displayAccount(accounts, num_accounts);
                break;
            case '3':
                deposit(accounts, num_accounts);
                break;
            case '4':
                withdraw(accounts, num_accounts);
                break;
            case '5':
                printf("Thank you for using the Banking Record System.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
        printf("\n");
    } while (choice != '5');

    return 0;
}

/* Function to display main menu */
void displayMainMenu(void) {
    printf("MAIN MENU\n");
    printf("1. Open new account\n");
    printf("2. Display account details\n");
    printf("3. Deposit money\n");
    printf("4. Withdraw money\n");
    printf("5. Exit\n");
}

/* Function to open new account */
void openAccount(Account accounts[], int *num_accounts) {
    Account new_account;
    printf("Enter name: ");
    scanf("%s", new_account.name);
    printf("Enter initial balance: ");
    scanf("%lf", &new_account.balance);
    new_account.account_number = *num_accounts + 1;
    accounts[*num_accounts] = new_account;
    *num_accounts += 1;
    printf("Account created successfully. Account number is %d.\n", new_account.account_number);
}

/* Function to display account details */
void displayAccount(Account accounts[], int num_accounts) {
    int account_number;
    int i;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    for (i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Account number: %d\n", accounts[i].account_number);
            printf("Name: %s\n", accounts[i].name);
            printf("Balance: %.2lf\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

/* Function to deposit money */
void deposit(Account accounts[], int num_accounts) {
    int account_number;
    double amount;
    int i;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    for (i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Enter amount to deposit: ");
            scanf("%lf", &amount);
            accounts[i].balance += amount;
            printf("Deposit successful. New balance is %.2lf.\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

/* Function to withdraw money */
void withdraw(Account accounts[], int num_accounts) {
    int account_number;
    double amount;
    int i;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    for (i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Enter amount to withdraw: ");
            scanf("%lf", &amount);
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Withdrawal successful. New balance is %.2lf.\n", accounts[i].balance);
            } else {
                printf("Insufficient balance.\n");
            }
            return;
        }
    }
    printf("Account not found.\n");
}