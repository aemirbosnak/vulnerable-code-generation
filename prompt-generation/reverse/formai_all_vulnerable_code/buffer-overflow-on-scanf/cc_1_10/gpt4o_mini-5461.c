//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50
#define TRANS_HISTORY_LENGTH 10

typedef struct {
    char name[NAME_LENGTH];
    int accountNumber;
    float balance;
    char transactionHistory[TRANS_HISTORY_LENGTH][50];
    int transactionCount;
} Account;

Account accounts[MAX_ACCOUNTS];
int numAccounts = 0;

// Function Prototypes
void createAccount();
void deposit(int accountIndex);
void withdraw(int accountIndex);
void viewAccount(int accountIndex);
void viewAllAccounts();
int findAccountIndex(int accountNumber);

int main() {
    int choice;

    while (1) {
        printf("\n***** Banking Record System *****\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. View Account\n");
        printf("5. View All Accounts\n");
        printf("6. Exit\n");
        printf("Please select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2: {
                int accountIndex;
                printf("Enter account number: ");
                scanf("%d", &accountIndex);
                int index = findAccountIndex(accountIndex);
                if(index >= 0) {
                    deposit(index);
                } else {
                    printf("Account not found!\n");
                }
                break;
            }
            case 3: {
                int accountIndex;
                printf("Enter account number: ");
                scanf("%d", &accountIndex);
                int index = findAccountIndex(accountIndex);
                if(index >= 0) {
                    withdraw(index);
                } else {
                    printf("Account not found!\n");
                }
                break;
            }
            case 4: {
                int accountIndex;
                printf("Enter account number: ");
                scanf("%d", &accountIndex);
                int index = findAccountIndex(accountIndex);
                if(index >= 0) {
                    viewAccount(index);
                } else {
                    printf("Account not found!\n");
                }
                break;
            }
            case 5:
                viewAllAccounts();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void createAccount() {
    if(numAccounts >= MAX_ACCOUNTS) {
        printf("Account limit reached. Cannot create more accounts.\n");
        return;
    }
    
    Account newAccount;
    newAccount.balance = 0.0;
    newAccount.transactionCount = 0;
    
    printf("Enter account name: ");
    scanf("%s", newAccount.name);
    newAccount.accountNumber = numAccounts + 1001;  // Unique account number
    
    accounts[numAccounts] = newAccount;
    numAccounts++;
    
    printf("Account created successfully! Account Number: %d\n", newAccount.accountNumber);
}

void deposit(int accountIndex) {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    
    if(amount <= 0) {
        printf("Invalid deposit amount!\n");
        return;
    }

    accounts[accountIndex].balance += amount;
    snprintf(accounts[accountIndex].transactionHistory[accounts[accountIndex].transactionCount], 50, "Deposited: %.2f", amount);
    accounts[accountIndex].transactionCount++;
    printf("Deposited %.2f. New Balance: %.2f\n", amount, accounts[accountIndex].balance);
}

void withdraw(int accountIndex) {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    
    if(amount <= 0 || amount > accounts[accountIndex].balance) {
        printf("Invalid withdraw amount!\n");
        return;
    }

    accounts[accountIndex].balance -= amount;
    snprintf(accounts[accountIndex].transactionHistory[accounts[accountIndex].transactionCount], 50, "Withdrew: %.2f", amount);
    accounts[accountIndex].transactionCount++;
    printf("Withdrew %.2f. New Balance: %.2f\n", amount, accounts[accountIndex].balance);
}

void viewAccount(int accountIndex) {
    printf("\n***** Account Details *****\n");
    printf("Name: %s\n", accounts[accountIndex].name);
    printf("Account Number: %d\n", accounts[accountIndex].accountNumber);
    printf("Balance: %.2f\n", accounts[accountIndex].balance);
    printf("Transaction History:\n");
    for(int i = 0; i < accounts[accountIndex].transactionCount; i++) {
        printf("  %s\n", accounts[accountIndex].transactionHistory[i]);
    }
}

void viewAllAccounts() {
    printf("\n***** All Accounts *****\n");
    for(int i = 0; i < numAccounts; i++) {
        printf("Account Number: %d, Name: %s, Balance: %.2f\n", 
               accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
}

int findAccountIndex(int accountNumber) {
    for(int i = 0; i < numAccounts; i++) {
        if(accounts[i].accountNumber == accountNumber) {
            return i;  // Return the index if found
        }
    }
    return -1;  // Return -1 if not found
}