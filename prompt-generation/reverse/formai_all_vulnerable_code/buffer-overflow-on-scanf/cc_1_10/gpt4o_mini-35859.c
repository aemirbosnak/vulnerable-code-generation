//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int account_number;
    char name[100];
    float balance;
} Account;

typedef struct {
    Account accounts[MAX_ACCOUNTS];
    int count;
} Bank;

void initializeBank(Bank* bank) {
    bank->count = 0;
}

int createAccount(Bank* bank, int account_number, const char* name, float initial_balance) {
    if (bank->count >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached.\n");
        return -1;
    }
    for (int i = 0; i < bank->count; i++) {
        if (bank->accounts[i].account_number == account_number) {
            printf("Account number %d already exists.\n", account_number);
            return -1;
        }
    }
    Account new_account = {account_number, "", initial_balance};
    strcpy(new_account.name, name);
    bank->accounts[bank->count++] = new_account;
    printf("Account created successfully: %s (Account No: %d) with balance: %.2f\n", name, account_number, initial_balance);
    return 0;
}

void deposit(Bank* bank, int account_number, float amount) {
    for (int i = 0; i < bank->count; i++) {
        if (bank->accounts[i].account_number == account_number) {
            bank->accounts[i].balance += amount;
            printf("Deposited %.2f to account number %d. New balance: %.2f\n", amount, account_number, bank->accounts[i].balance);
            return;
        }
    }
    printf("Account number %d not found.\n", account_number);
}

void withdraw(Bank* bank, int account_number, float amount) {
    for (int i = 0; i < bank->count; i++) {
        if (bank->accounts[i].account_number == account_number) {
            if (bank->accounts[i].balance >= amount) {
                bank->accounts[i].balance -= amount;
                printf("Withdrew %.2f from account number %d. New balance: %.2f\n", amount, account_number, bank->accounts[i].balance);
            } else {
                printf("Insufficient funds in account number %d.\n", account_number);
            }
            return;
        }
    }
    printf("Account number %d not found.\n", account_number);
}

void displayAccount(const Account* account) {
    printf("Account No: %d\n", account->account_number);
    printf("Account Name: %s\n", account->name);
    printf("Balance: %.2f\n", account->balance);
}

void showAccounts(const Bank* bank) {
    if (bank->count == 0) {
        printf("No accounts available.\n");
        return;
    }
    for (int i = 0; i < bank->count; i++) {
        displayAccount(&bank->accounts[i]);
        printf("-------------------------\n");
    }
}

int main() {
    Bank bank;
    initializeBank(&bank);

    int choice, account_number;
    char name[100];
    float amount;

    while (1) {
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display All Accounts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Account Number: ");
                scanf("%d", &account_number);
                printf("Enter Account Holder Name: ");
                scanf(" %[^\n]", name); // Read string with spaces
                printf("Enter Initial Deposit Amount: ");
                scanf("%f", &amount);
                createAccount(&bank, account_number, name, amount);
                break;
            case 2:
                printf("Enter Account Number: ");
                scanf("%d", &account_number);
                printf("Enter Amount to Deposit: ");
                scanf("%f", &amount);
                deposit(&bank, account_number, amount);
                break;
            case 3:
                printf("Enter Account Number: ");
                scanf("%d", &account_number);
                printf("Enter Amount to Withdraw: ");
                scanf("%f", &amount);
                withdraw(&bank, account_number, amount);
                break;
            case 4:
                showAccounts(&bank);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    }

    return 0;
}