//FormAI DATASET v1.0 Category: Banking Record System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_ACCOUNTS 1000

typedef struct {
    int account_number;
    char name[100];
    float balance;
} Account;

int num_accounts = 0;
Account accounts[MAX_ACCOUNTS];

void create_account() {
    Account temp_account;
    printf("Enter account number: ");
    scanf("%d", &temp_account.account_number);
    getchar(); // consume newline character
    
    // check if account already exists
    for (int i = 0; i < num_accounts; i++) {
        if (temp_account.account_number == accounts[i].account_number) {
            printf("Account with same number already exists!\n");
            return;
        }
    }
    
    printf("Enter name: ");
    fgets(temp_account.name, 100, stdin);
    printf("Enter balance: ");
    scanf("%f", &temp_account.balance);
    getchar(); // consume newline character
    
    accounts[num_accounts++] = temp_account;
    printf("Account created successfully!\n");
}

void view_account() {
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    
    // search for account
    int account_found = 0;
    for (int i = 0; i < num_accounts; i++) {
        if (account_number == accounts[i].account_number) {
            printf("Account number: %d\nName: %sBalance: %.2f\n", accounts[i].account_number, accounts[i].name, accounts[i].balance);
            account_found = 1;
            break;
        }
    }
    
    if (!account_found) {
        printf("Account not found!\n");
    }
}

void deposit() {
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    
    // search for account
    int account_found = 0;
    for (int i = 0; i < num_accounts; i++) {
        if (account_number == accounts[i].account_number) {
            float amount;
            printf("Enter amount to be deposited: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Deposit successful! New balance: %.2f\n", accounts[i].balance);
            account_found = 1;
            break;
        }
    }
    
    if (!account_found) {
        printf("Account not found!\n");
    }
}

void withdraw() {
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    
    // search for account
    int account_found = 0;
    for (int i = 0; i < num_accounts; i++) {
        if (account_number == accounts[i].account_number) {
            float amount;
            printf("Enter amount to be withdrawn: ");
            scanf("%f", &amount);
            if (amount <= accounts[i].balance) {
                accounts[i].balance -= amount;
                printf("Withdrawal successful! New balance: %.2f\n", accounts[i].balance);
            } else {
                printf("Insufficient balance!\n");
            }
            account_found = 1;
            break;
        }
    }
    
    if (!account_found) {
        printf("Account not found!\n");
    }
}

void print_menu() {
    printf("Menu:\n");
    printf("1. Create Account\n");
    printf("2. View Account Details\n");
    printf("3. Deposit Amount\n");
    printf("4. Withdraw Amount\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    while (1) {
        print_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline character
        
        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                view_account();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}