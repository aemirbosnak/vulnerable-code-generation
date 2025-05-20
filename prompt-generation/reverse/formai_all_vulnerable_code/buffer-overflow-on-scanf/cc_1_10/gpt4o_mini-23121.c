//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define BUFFER_SIZE 256

typedef struct {
    int account_number;
    char name[50];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int account_count = 0;

void load_accounts() {
    FILE *file = fopen("accounts.dat", "rb");
    if (file) {
        fread(&account_count, sizeof(int), 1, file);
        fread(accounts, sizeof(Account), account_count, file);
        fclose(file);
    }
}

void save_accounts() {
    FILE *file = fopen("accounts.dat", "wb");
    if (file) {
        fwrite(&account_count, sizeof(int), 1, file);
        fwrite(accounts, sizeof(Account), account_count, file);
        fclose(file);
    }
}

void create_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached.\n");
        return;
    }
    Account new_account;
    new_account.account_number = account_count + 1;
    printf("Enter the name of the account holder: ");
    scanf(" %[^\n]", new_account.name);
    new_account.balance = 0.0;
    
    accounts[account_count++] = new_account;
    save_accounts();
    
    printf("Account created successfully. Account Number: %d\n", new_account.account_number);
}

void deposit() {
    int account_number;
    float amount;
    
    printf("Enter account number: ");
    scanf("%d", &account_number);
    
    if (account_number < 1 || account_number > account_count) {
        printf("Invalid account number.\n");
        return;
    }
    
    printf("Enter deposit amount: ");
    scanf("%f", &amount);
    
    if (amount <= 0) {
        printf("Invalid amount. Please enter a positive value.\n");
        return;
    }
    
    accounts[account_number - 1].balance += amount;
    save_accounts();
    
    printf("Deposited successfully. New balance: $%.2f\n", accounts[account_number - 1].balance);
}

void withdraw() {
    int account_number;
    float amount;
    
    printf("Enter account number: ");
    scanf("%d", &account_number);
    
    if (account_number < 1 || account_number > account_count) {
        printf("Invalid account number.\n");
        return;
    }
    
    printf("Enter withdrawal amount: ");
    scanf("%f", &amount);
    
    if (amount <= 0) {
        printf("Invalid amount. Please enter a positive value.\n");
        return;
    }
    
    if (amount > accounts[account_number - 1].balance) {
        printf("Insufficient balance.\n");
        return;
    }

    accounts[account_number - 1].balance -= amount;
    save_accounts();
    
    printf("Withdrawn successfully. New balance: $%.2f\n", accounts[account_number - 1].balance);
}

void view_account() {
    int account_number;
    
    printf("Enter account number: ");
    scanf("%d", &account_number);
    
    if (account_number < 1 || account_number > account_count) {
        printf("Invalid account number.\n");
        return;
    }
    
    Account acc = accounts[account_number - 1];
    printf("Account Number: %d\n", acc.account_number);
    printf("Account Holder: %s\n", acc.name);
    printf("Balance: $%.2f\n", acc.balance);
}

int main() {
    load_accounts();
    
    int choice;
    do {
        printf("\n*** Banking Record System ***\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. View Account\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: create_account(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: view_account(); break;
            case 5: printf("Exiting..."); break;
            default: printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 5);
    
    return 0;
}