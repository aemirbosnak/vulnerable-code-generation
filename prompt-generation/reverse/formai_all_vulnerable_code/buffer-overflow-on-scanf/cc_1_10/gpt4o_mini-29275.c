//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold account details
struct Account {
    int accountNumber;
    char name[50];
    float balance;
};

// Function declarations
void createAccount(struct Account accounts[], int *count);
void viewAccount(const struct Account accounts[], int count);
void depositMoney(struct Account accounts[], int count);
void withdrawMoney(struct Account accounts[], int count);
void listAllAccounts(const struct Account accounts[], int count);

int main() {
    struct Account accounts[100]; // Maximum of 100 accounts
    int count = 0; // Keeps track of the number of accounts
    int choice;

    do {
        printf("\n--- Banking Record System ---\n");
        printf("1. Create Account\n");
        printf("2. View Account\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. List All Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(accounts, &count);
                break;
            case 2:
                viewAccount(accounts, count);
                break;
            case 3:
                depositMoney(accounts, count);
                break;
            case 4:
                withdrawMoney(accounts, count);
                break;
            case 5:
                listAllAccounts(accounts, count);
                break;
            case 6:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void createAccount(struct Account accounts[], int *count) {
    if (*count >= 100) {
        printf("Maximum accounts reached. Cannot create more accounts.\n");
        return;
    }

    struct Account newAccount;
    newAccount.accountNumber = *count + 1; // Simple account numbering
    printf("Enter account holder name: ");
    scanf("%s", newAccount.name);
    newAccount.balance = 0.0; // Initial balance is zero

    accounts[*count] = newAccount;
    (*count)++;
    printf("Account created successfully! Account Number: %d\n", newAccount.accountNumber);
}

void viewAccount(const struct Account accounts[], int count) {
    if (count == 0) {
        printf("No accounts available.\n");
        return;
    }

    int accountNumber;
    printf("Enter account number to view: ");
    scanf("%d", &accountNumber);

    if (accountNumber <= 0 || accountNumber > count) {
        printf("Invalid account number.\n");
        return;
    }

    struct Account account = accounts[accountNumber - 1];
    printf("Account Number: %d\n", account.accountNumber);
    printf("Holder Name: %s\n", account.name);
    printf("Balance: %.2f\n", account.balance);
}

void depositMoney(struct Account accounts[], int count) {
    if (count == 0) {
        printf("No accounts available to deposit money.\n");
        return;
    }

    int accountNumber;
    float amount;
    printf("Enter account number to deposit money: ");
    scanf("%d", &accountNumber);

    if (accountNumber <= 0 || accountNumber > count) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Invalid deposit amount.\n");
        return;
    }

    accounts[accountNumber - 1].balance += amount;
    printf("Deposited %.2f into account number %d.\n", amount, accountNumber);
}

void withdrawMoney(struct Account accounts[], int count) {
    if (count == 0) {
        printf("No accounts available to withdraw money.\n");
        return;
    }

    int accountNumber;
    float amount;
    printf("Enter account number to withdraw money: ");
    scanf("%d", &accountNumber);

    if (accountNumber <= 0 || accountNumber > count) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Invalid withdraw amount.\n");
        return;
    }

    if (accounts[accountNumber - 1].balance < amount) {
        printf("Insufficient balance in account number %d.\n", accountNumber);
        return;
    }

    accounts[accountNumber - 1].balance -= amount;
    printf("Withdrew %.2f from account number %d.\n", amount, accountNumber);
}

void listAllAccounts(const struct Account accounts[], int count) {
    if (count == 0) {
        printf("No accounts available.\n");
        return;
    }

    printf("\n--- List of Accounts ---\n");
    for (int i = 0; i < count; i++) {
        printf("Account Number: %d | Holder Name: %s | Balance: %.2f\n",
               accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
}