//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50
#define FILE_NAME "bank_accounts.txt"

typedef struct {
    int account_number;
    char name[NAME_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int account_count = 0;

// Function declarations
void load_accounts();
void save_accounts();
int create_account();
void deposit_money(int account_number);
void withdraw_money(int account_number);
void check_balance(int account_number);
void display_accounts();

int main() {
    int choice;
    load_accounts();
    
    do {
        printf("\n=== Simple Banking System ===\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                create_account();
                break;
            case 2: {
                int acc_num;
                printf("Enter account number: ");
                scanf("%d", &acc_num);
                deposit_money(acc_num);
                break;
            }
            case 3: {
                int acc_num;
                printf("Enter account number: ");
                scanf("%d", &acc_num);
                withdraw_money(acc_num);
                break;
            }
            case 4: {
                int acc_num;
                printf("Enter account number: ");
                scanf("%d", &acc_num);
                check_balance(acc_num);
                break;
            }
            case 5:
                display_accounts();
                break;
            case 6:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while(choice != 6);
    
    save_accounts();
    return 0;
}

// Load accounts from the file
void load_accounts() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file != NULL) {
        fread(&account_count, sizeof(int), 1, file);
        fread(accounts, sizeof(Account), account_count, file);
        fclose(file);
    }
}

// Save accounts to the file
void save_accounts() {
    FILE *file = fopen(FILE_NAME, "wb");
    if (file != NULL) {
        fwrite(&account_count, sizeof(int), 1, file);
        fwrite(accounts, sizeof(Account), account_count, file);
        fclose(file);
    }
}

// Create a new account
int create_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Account limit reached. Cannot create more accounts.\n");
        return -1;
    }
    
    Account new_account;
    new_account.account_number = account_count + 1;
    new_account.balance = 0.0;
    
    printf("Enter name for account holder: ");
    scanf(" %[^\n]s", new_account.name);
    
    accounts[account_count] = new_account;
    account_count++;
    
    printf("Account created successfully! Account Number: %d\n", new_account.account_number);
    return new_account.account_number;
}

// Deposit money into an account
void deposit_money(int account_number) {
    if (account_number > account_count || account_number <= 0) {
        printf("Account not found.\n");
        return;
    }

    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount.\n");
        return;
    }

    accounts[account_number - 1].balance += amount;
    printf("Successfully deposited %.2f to account %d.\n", amount, account_number);
}

// Withdraw money from an account
void withdraw_money(int account_number) {
    if (account_number > account_count || account_number <= 0) {
        printf("Account not found.\n");
        return;
    }

    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount.\n");
        return;
    }

    if (accounts[account_number - 1].balance < amount) {
        printf("Insufficient balance.\n");
        return;
    }

    accounts[account_number - 1].balance -= amount;
    printf("Successfully withdrew %.2f from account %d.\n", amount, account_number);
}

// Check the balance of an account
void check_balance(int account_number) {
    if (account_number > account_count || account_number <= 0) {
        printf("Account not found.\n");
        return;
    }
    
    printf("Account Holder: %s\n", accounts[account_number - 1].name);
    printf("Balance: %.2f\n", accounts[account_number - 1].balance);
}

// Display all accounts
void display_accounts() {
    if (account_count == 0) {
        printf("No accounts available.\n");
        return;
    }
    
    printf("\n=== List of Accounts ===\n");
    for (int i = 0; i < account_count; i++) {
        printf("Account Number: %d, Name: %s, Balance: %.2f\n", 
                accounts[i].account_number, accounts[i].name, accounts[i].balance);
    }
}