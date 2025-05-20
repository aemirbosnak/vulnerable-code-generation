//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50

// Structure for bank account
typedef struct Account {
    int account_number;
    char name[NAME_LENGTH];
    float balance;
} Account;

// Function prototypes
void add_account(Account accounts[], int *count);
void display_accounts(Account accounts[], int count);
void deposit(Account accounts[], int count);
void withdraw(Account accounts[], int count);
int find_account(Account accounts[], int count, int account_number);

int main() {
    Account accounts[MAX_ACCOUNTS];
    int account_count = 0;
    int choice;

    do {
        printf("\n--- Simple Banking Record System ---\n");
        printf("1. Add Account\n");
        printf("2. Display All Accounts\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_account(accounts, &account_count);
                break;
            case 2:
                display_accounts(accounts, account_count);
                break;
            case 3:
                deposit(accounts, account_count);
                break;
            case 4:
                withdraw(accounts, account_count);
                break;
            case 5:
                printf("Exiting the system. Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void add_account(Account accounts[], int *count) {
    if (*count >= MAX_ACCOUNTS) {
        printf("Account limit reached! Cannot add more accounts.\n");
        return;
    }
    Account new_account;
    new_account.account_number = *count + 1;
    printf("Enter account holder's name: ");
    getchar(); // clear newline character from input buffer
    fgets(new_account.name, NAME_LENGTH, stdin);
    new_account.name[strcspn(new_account.name, "\n")] = 0; // Remove newline
    new_account.balance = 0.0;

    accounts[*count] = new_account;
    (*count)++;
    printf("Account successfully created! Account Number: %d\n", new_account.account_number);
}

void display_accounts(Account accounts[], int count) {
    if (count == 0) {
        printf("No accounts available.\n");
        return;
    }
    printf("\n--- Account List ---\n");
    for (int i = 0; i < count; i++) {
        printf("Account Number: %d | Name: %s | Balance: %.2f\n",
               accounts[i].account_number, accounts[i].name, accounts[i].balance);
    }
}

void deposit(Account accounts[], int count) {
    int account_number;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);

    int index = find_account(accounts, count, account_number);
    if (index == -1) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Invalid amount!\n");
        return;
    }
    accounts[index].balance += amount;
    printf("Successfully deposited %.2f. New balance: %.2f\n",
           amount, accounts[index].balance);
}

void withdraw(Account accounts[], int count) {
    int account_number;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);

    int index = find_account(accounts, count, account_number);
    if (index == -1) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount <= 0 || amount > accounts[index].balance) {
        printf("Invalid amount or insufficient balance!\n");
        return;
    }
    accounts[index].balance -= amount;
    printf("Successfully withdrew %.2f. New balance: %.2f\n",
           amount, accounts[index].balance);
}

int find_account(Account accounts[], int count, int account_number) {
    for (int i = 0; i < count; i++) {
        if (accounts[i].account_number == account_number) {
            return i; // Found the account at index i
        }
    }
    return -1; // Account not found
}