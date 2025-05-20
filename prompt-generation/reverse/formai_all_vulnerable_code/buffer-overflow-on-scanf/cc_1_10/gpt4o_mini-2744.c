//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int accountNumber;
    char name[100];
    float balance;
} Account;

void createAccount(Account *account);
void deposit(Account *account, float amount);
void withdraw(Account *account, float amount);
void displayAccount(const Account *account);
void saveAccountToFile(const Account *account);
void loadAccountFromFile(Account *account);

int main() {
    Account myAccount;
    int choice;
    
    printf("Welcome to the C Banking Record System!\n");
    
    // Creating account
    createAccount(&myAccount);

    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Deposit Money\n");
        printf("2. Withdraw Money\n");
        printf("3. Display Account Information\n");
        printf("4. Save Account to File\n");
        printf("5. Load Account from File\n");
        printf("6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                float amount;
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(&myAccount, amount);
                break;
            }
            case 2: {
                float amount;
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(&myAccount, amount);
                break;
            }
            case 3:
                displayAccount(&myAccount);
                break;
            case 4:
                saveAccountToFile(&myAccount);
                break;
            case 5:
                loadAccountFromFile(&myAccount);
                break;
            case 6:
                printf("Thank you for using the C Banking Record System!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}

void createAccount(Account *account) {
    printf("Creating a new account...\n");
    printf("Enter account number: ");
    scanf("%d", &account->accountNumber);
    printf("Enter account holder's name: ");
    scanf(" %[^\n]", account->name);
    account->balance = 0.0; // Initial balance
    printf("Account created successfully!\n");
}

void deposit(Account *account, float amount) {
    if (amount > 0) {
        account->balance += amount;
        printf("Deposited: %.2f\n", amount);
        printf("New Balance: %.2f\n", account->balance);
    } else {
        printf("Invalid deposit amount!\n");
    }
}

void withdraw(Account *account, float amount) {
    if (amount > 0 && amount <= account->balance) {
        account->balance -= amount;
        printf("Withdrew: %.2f\n", amount);
        printf("New Balance: %.2f\n", account->balance);
    } else {
        printf("Invalid withdrawal amount!\n");
    }
}

void displayAccount(const Account *account) {
    printf("\n--- Account Information ---\n");
    printf("Account Number: %d\n", account->accountNumber);
    printf("Account Holder: %s\n", account->name);
    printf("Account Balance: %.2f\n", account->balance);
    printf("--------------------------\n");
}

void saveAccountToFile(const Account *account) {
    FILE *file = fopen("account.dat", "wb");
    if (file == NULL) {
        printf("Error saving account data.\n");
        return;
    }
    fwrite(account, sizeof(Account), 1, file);
    fclose(file);
    printf("Account data saved successfully!\n");
}

void loadAccountFromFile(Account *account) {
    FILE *file = fopen("account.dat", "rb");
    if (file == NULL) {
        printf("No account data found!\n");
        return;
    }
    fread(account, sizeof(Account), 1, file);
    fclose(file);
    printf("Account data loaded successfully!\n");
}