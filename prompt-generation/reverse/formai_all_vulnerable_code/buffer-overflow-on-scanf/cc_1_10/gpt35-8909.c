//FormAI DATASET v1.0 Category: Banking Record System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ACCOUNTS 1000

struct account {
    char name[MAX_NAME_LENGTH];
    int id;
    double balance;
};

struct account accounts[MAX_ACCOUNTS];
int num_accounts = 0;

void add_account() {
    char name[MAX_NAME_LENGTH];
    double initial_balance;
    
    printf("Enter the name of the account holder: ");
    scanf("%s", name);
    printf("Enter the initial balance: ");
    scanf("%lf", &initial_balance);
    
    struct account new_account;
    strcpy(new_account.name, name);
    new_account.id = num_accounts + 1;
    new_account.balance = initial_balance;
    
    accounts[num_accounts] = new_account;
    num_accounts++;
    
    printf("Account added successfully.\n");
}

void display_all_accounts() {
    printf("%-10s | %-20s | %-10s\n", "ID", "Name", "Balance");
    printf("------------------------------------------------\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("%-10d | %-20s | %-10.2f\n", accounts[i].id, accounts[i].name, accounts[i].balance);
    }
}

void deposit() {
    int id;
    double amount;
    
    printf("Enter the account ID to deposit: ");
    scanf("%d", &id);
    
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].id == id) {
            printf("Enter the amount to deposit: ");
            scanf("%lf", &amount);
            accounts[i].balance += amount;
            printf("Deposit successful. New balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    
    printf("Account not found.\n");
}

void withdraw() {
    int id;
    double amount;
    
    printf("Enter the account ID to withdraw: ");
    scanf("%d", &id);
    
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].id == id) {
            printf("Enter the amount to withdraw: ");
            scanf("%lf", &amount);
            if (accounts[i].balance < amount) {
                printf("Withdrawal unsuccessful. Insufficient balance.\n");
            } else {
                accounts[i].balance -= amount;
                printf("Withdrawal successful. New balance: %.2f\n", accounts[i].balance);
            }
            return;
        }
    }
    
    printf("Account not found.\n");
}

int main() {
    while (1) {
        printf("Welcome to the C Bank Record System\n");
        printf("===================================\n");
        printf("1. Add account\n");
        printf("2. Display all accounts\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("0. Exit\n");
        
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_account();
                break;
            case 2:
                display_all_accounts();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 0:
                printf("Thank you for using the C Bank Record System.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
        
        printf("\n");
    }
    
    return 0;
}