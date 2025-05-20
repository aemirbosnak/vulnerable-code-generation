//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50

typedef struct {
    int account_number;
    char name[NAME_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int account_count = 0;

// Function prototypes
void create_account();
void view_accounts();
void deposit();
void withdraw();
void save_data();
void load_data();

int main() {
    load_data();
    int choice;

    while (1) {
        printf("\n=== Bank Management System ===\n");
        printf("1. Create Account\n");
        printf("2. View Accounts\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Save Data\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                view_accounts();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                save_data();
                break;
            case 6:
                save_data();
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void create_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Account limit reached. Cannot create more accounts.\n");
        return;
    }

    Account new_account;
    new_account.account_number = account_count + 1;
    printf("Enter account holder name: ");
    getchar(); // Clear the newline character
    fgets(new_account.name, NAME_LENGTH, stdin);
    new_account.name[strcspn(new_account.name, "\n")] = 0; // Remove newline
    new_account.balance = 0.0;

    accounts[account_count] = new_account;
    account_count++;
    printf("Account created successfully! Account Number: %d\n", new_account.account_number);
}

void view_accounts() {
    if (account_count == 0) {
        printf("No accounts available.\n");
        return;
    }

    printf("\n=== List of Accounts ===\n");
    for (int i = 0; i < account_count; i++) {
        printf("Account Number: %d\n", accounts[i].account_number);
        printf("Account Holder: %s\n", accounts[i].name);
        printf("Balance: %.2f\n", accounts[i].balance);
        printf("-------------------------\n");
    }
}

void deposit() {
    int account_number;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &account_number);
    
    if (account_number <= 0 || account_number > account_count) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Deposit amount must be positive.\n");
        return;
    }

    accounts[account_number - 1].balance += amount;
    printf("Amount deposited successfully! New Balance: %.2f\n", accounts[account_number - 1].balance);
}

void withdraw() {
    int account_number;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &account_number);
    
    if (account_number <= 0 || account_number > account_count) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Withdrawal amount must be positive.\n");
        return;
    }

    if (accounts[account_number - 1].balance < amount) {
        printf("Insufficient balance!\n");
        return;
    }

    accounts[account_number - 1].balance -= amount;
    printf("Amount withdrawn successfully! New Balance: %.2f\n", accounts[account_number - 1].balance);
}

void save_data() {
    FILE *file = fopen("bank_data.txt", "w");
    if (file == NULL) {
        printf("Error saving data!\n");
        return;
    }
    
    for (int i = 0; i < account_count; i++) {
        fprintf(file, "%d %s %.2f\n", accounts[i].account_number, accounts[i].name, accounts[i].balance);
    }
    
    fclose(file);
    printf("Data saved successfully!\n");
}

void load_data() {
    FILE *file = fopen("bank_data.txt", "r");
    if (file == NULL) {
        printf("No existing data file found. Starting fresh.\n");
        return;
    }

    while (fscanf(file, "%d %s %f", &accounts[account_count].account_number, accounts[account_count].name, &accounts[account_count].balance) != EOF) {
        account_count++;
    }

    fclose(file);
    printf("Data loaded successfully!\n");
}