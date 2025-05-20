//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_NAME_LENGTH 50
#define FILENAME "bank_records.txt"

typedef struct {
    char name[MAX_NAME_LENGTH];
    float balance;
} Account;

// Function prototypes
void createAccount();
void deposit();
void withdraw();
void checkBalance();
void showAccounts();

// Helper functions
int findAccountIndex(const char *name);
void writeAccountsToFile(Account accounts[], int count);
int readAccountsFromFile(Account accounts[]);

int main() {
    int choice;

    while (1) {
        printf("\n=== Decentralized Banking System ===\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Show All Accounts\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: checkBalance(); break;
            case 5: showAccounts(); break;
            case 6: exit(0);
            default: printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}

// Function Definitions
void createAccount() {
    Account newAccount;
    FILE *file = fopen(FILENAME, "a");

    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter your name: ");
    scanf("%s", newAccount.name);
    newAccount.balance = 0.0;

    fprintf(file, "%s %.2f\n", newAccount.name, newAccount.balance);
    fclose(file);
    printf("Account created for %s with an initial balance of %.2f\n", newAccount.name, newAccount.balance);
}

void deposit() {
    char name[MAX_NAME_LENGTH];
    float amount;
    Account accounts[MAX_USERS];
    int count = readAccountsFromFile(accounts);
    int index;

    printf("Enter account holder's name: ");
    scanf("%s", name);
    index = findAccountIndex(name);
    
    if (index == -1) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    accounts[index].balance += amount;
    writeAccountsToFile(accounts, count);
    printf("Deposited %.2f to %s's account. New balance: %.2f\n", amount, name, accounts[index].balance);
}

void withdraw() {
    char name[MAX_NAME_LENGTH];
    float amount;
    Account accounts[MAX_USERS];
    int count = readAccountsFromFile(accounts);
    int index;

    printf("Enter account holder's name: ");
    scanf("%s", name);
    index = findAccountIndex(name);

    if (index == -1) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount > accounts[index].balance) {
        printf("Insufficient balance!\n");
    } else {
        accounts[index].balance -= amount;
        writeAccountsToFile(accounts, count);
        printf("Withdrew %.2f from %s's account. New balance: %.2f\n", amount, name, accounts[index].balance);
    }
}

void checkBalance() {
    char name[MAX_NAME_LENGTH];
    Account accounts[MAX_USERS];
    int count = readAccountsFromFile(accounts);
    int index;

    printf("Enter account holder's name: ");
    scanf("%s", name);
    index = findAccountIndex(name);

    if (index == -1) {
        printf("Account not found!\n");
    } else {
        printf("The balance of %s is: %.2f\n", name, accounts[index].balance);
    }
}

void showAccounts() {
    Account accounts[MAX_USERS];
    int count = readAccountsFromFile(accounts);

    printf("\n=== List of Accounts ===\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Balance: %.2f\n", accounts[i].name, accounts[i].balance);
    }
}

int findAccountIndex(const char *name) {
    Account accounts[MAX_USERS];
    int count = readAccountsFromFile(accounts);

    for (int i = 0; i < count; i++) {
        if (strcmp(accounts[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void writeAccountsToFile(Account accounts[], int count) {
    FILE *file = fopen(FILENAME, "w");

    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %.2f\n", accounts[i].name, accounts[i].balance);
    }
    fclose(file);
}

int readAccountsFromFile(Account accounts[]) {
    FILE *file = fopen(FILENAME, "r");
    int count = 0;

    if (!file) {
        return 0;
    }
    
    while (fscanf(file, "%s %f", accounts[count].name, &accounts[count].balance) != EOF && count < MAX_USERS) {
        count++;
    }
    fclose(file);
    return count;
}