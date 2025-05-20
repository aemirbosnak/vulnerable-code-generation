//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LEN 50

typedef struct {
    int account_no;
    char name[NAME_LEN];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int account_count = 0;

void create_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Maximum accounts reached.\n");
        return;
    }
    
    Account new_account;
    new_account.account_no = account_count + 1;
    printf("Enter account holder name: ");
    scanf("%s", new_account.name);
    new_account.balance = 0.0;
    
    accounts[account_count++] = new_account;
    printf("Account created successfully. Your account number is: %d\n", new_account.account_no);
}

void display_accounts() {
    printf("\n--- Account List ---\n");
    for (int i = 0; i < account_count; i++) {
        printf("Account No: %d | Name: %s | Balance: %.2f\n",
               accounts[i].account_no, accounts[i].name, accounts[i].balance);
    }
}

void deposit() {
    int acc_no;
    float amount;
    
    printf("Enter account number: ");
    scanf("%d", &acc_no);
    
    if (acc_no <= 0 || acc_no > account_count) {
        printf("Invalid account number.\n");
        return;
    }
    
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    
    if (amount <= 0) {
        printf("Invalid amount.\n");
        return;
    }
    
    accounts[acc_no - 1].balance += amount;
    printf("Successfully deposited %.2f to account %d. New balance: %.2f\n", 
           amount, acc_no, accounts[acc_no - 1].balance);
}

void withdraw() {
    int acc_no;
    float amount;
    
    printf("Enter account number: ");
    scanf("%d", &acc_no);
    
    if (acc_no <= 0 || acc_no > account_count) {
        printf("Invalid account number.\n");
        return;
    }
    
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    
    if (amount <= 0 || amount > accounts[acc_no - 1].balance) {
        printf("Invalid amount.\n");
        return;
    }
    
    accounts[acc_no - 1].balance -= amount;
    printf("Successfully withdrew %.2f from account %d. New balance: %.2f\n", 
           amount, acc_no, accounts[acc_no - 1].balance);
}

void account_summary() {
    int acc_no;
    printf("Enter account number for summary: ");
    scanf("%d", &acc_no);
    
    if (acc_no <= 0 || acc_no > account_count) {
        printf("Invalid account number.\n");
        return;
    }

    printf("\n--- Account Summary ---\n");
    printf("Account No: %d\n", accounts[acc_no - 1].account_no);
    printf("Name: %s\n", accounts[acc_no - 1].name);
    printf("Balance: %.2f\n", accounts[acc_no - 1].balance);
}

void menu() {
    int choice;
    do {
        printf("\n--- Banking System Menu ---\n");
        printf("1. Create Account\n");
        printf("2. Display Accounts\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Account Summary\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: create_account(); break;
            case 2: display_accounts(); break;
            case 3: deposit(); break;
            case 4: withdraw(); break;
            case 5: account_summary(); break;
            case 6: printf("Exiting... goodbye!\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
}

int main() {
    menu();
    return 0;
}