//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LEN 50
#define ACC_NO_LEN 20
#define TRANSACTION_HISTORY_LENGTH 10

typedef struct {
    char transactionType[10];
    float amount;
} Transaction;

typedef struct {
    char accHolderName[NAME_LEN];
    char accNo[ACC_NO_LEN];
    float balance;
    Transaction transactionHistory[TRANSACTION_HISTORY_LENGTH];
    int transactionCount;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount();
void deposit();
void withdraw();
void viewAccount();
void viewTransactionHistory();
void menu();
void clearInputBuffer();

int main() {
    printf("Welcome to the C Banking Record System\n");
    menu();
    return 0;
}

void menu() {
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. View Account\n");
        printf("5. View Transaction History\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: viewAccount(); break;
            case 5: viewTransactionHistory(); break;
            case 6: printf("Exiting the system. Thank you!\n"); exit(0);
            default: printf("Invalid choice. Please try again.\n");
        }
    }
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached. Cannot create new account.\n");
        return;
    }
    Account newAccount;
    printf("Enter account holder's name: ");
    fgets(newAccount.accHolderName, NAME_LEN, stdin);
    newAccount.accHolderName[strcspn(newAccount.accHolderName, "\n")] = '\0'; // Remove newline

    printf("Enter account number: ");
    fgets(newAccount.accNo, ACC_NO_LEN, stdin);
    newAccount.accNo[strcspn(newAccount.accNo, "\n")] = '\0'; // Remove newline

    newAccount.balance = 0.0;
    newAccount.transactionCount = 0;

    accounts[accountCount++] = newAccount;
    printf("Account created successfully!\n");
}

void deposit() {
    char accNo[ACC_NO_LEN];
    float amount;
    int found = 0;

    printf("Enter account number for deposit: ");
    fgets(accNo, ACC_NO_LEN, stdin);
    accNo[strcspn(accNo, "\n")] = '\0'; // Remove newline

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accNo, accNo) == 0) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            clearInputBuffer();

            if (amount <= 0) {
                printf("Invalid deposit amount.\n");
            } else {
                accounts[i].balance += amount;
                strcpy(accounts[i].transactionHistory[accounts[i].transactionCount].transactionType, "Deposit");
                accounts[i].transactionHistory[accounts[i].transactionCount].amount = amount;
                accounts[i].transactionCount++;
                printf("Deposit successful! New balance: %.2f\n", accounts[i].balance);
            }
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Account not found.\n");
    }
}

void withdraw() {
    char accNo[ACC_NO_LEN];
    float amount;
    int found = 0;

    printf("Enter account number for withdrawal: ");
    fgets(accNo, ACC_NO_LEN, stdin);
    accNo[strcspn(accNo, "\n")] = '\0'; // Remove newline

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accNo, accNo) == 0) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            clearInputBuffer();

            if (amount <= 0 || amount > accounts[i].balance) {
                printf("Invalid withdrawal amount.\n");
            } else {
                accounts[i].balance -= amount;
                strcpy(accounts[i].transactionHistory[accounts[i].transactionCount].transactionType, "Withdraw");
                accounts[i].transactionHistory[accounts[i].transactionCount].amount = amount;
                accounts[i].transactionCount++;
                printf("Withdrawal successful! New balance: %.2f\n", accounts[i].balance);
            }
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Account not found.\n");
    }
}

void viewAccount() {
    char accNo[ACC_NO_LEN];
    int found = 0;

    printf("Enter account number to view details: ");
    fgets(accNo, ACC_NO_LEN, stdin);
    accNo[strcspn(accNo, "\n")] = '\0'; // Remove newline

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accNo, accNo) == 0) {
            printf("Account Holder Name: %s\n", accounts[i].accHolderName);
            printf("Account Number: %s\n", accounts[i].accNo);
            printf("Balance: %.2f\n", accounts[i].balance);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Account not found.\n");
    }
}

void viewTransactionHistory() {
    char accNo[ACC_NO_LEN];
    int found = 0;

    printf("Enter account number to view transaction history: ");
    fgets(accNo, ACC_NO_LEN, stdin);
    accNo[strcspn(accNo, "\n")] = '\0'; // Remove newline

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accNo, accNo) == 0) {
            printf("Transaction History for Account Number: %s\n", accounts[i].accNo);
            for (int j = 0; j < accounts[i].transactionCount; j++) {
                printf("%s: %.2f\n", accounts[i].transactionHistory[j].transactionType, accounts[i].transactionHistory[j].amount);
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Account not found.\n");
    }
}

void clearInputBuffer() {
    while (getchar() != '\n');
}