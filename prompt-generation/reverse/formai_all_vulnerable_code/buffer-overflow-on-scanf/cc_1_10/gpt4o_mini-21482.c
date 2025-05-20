//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int account_number;
    char name[MAX_NAME_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int account_count = 0;

void register_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached.\n");
        return;
    }

    Account new_account;
    
    printf("Enter Account Number: ");
    scanf("%d", &new_account.account_number);
    printf("Enter Name: ");
    scanf(" %[^\n]", new_account.name); // To read string with spaces
    new_account.balance = 0; // New account starts with 0 balance
    
    accounts[account_count] = new_account;
    account_count++;
    
    printf("Account created successfully!\n");
}

void deposit() {
    int acc_number;
    float amount;
    
    printf("Enter Account Number to deposit: ");
    scanf("%d", &acc_number);
    
    for (int i = 0; i < account_count; i++) {
        if (accounts[i].account_number == acc_number) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Deposit successful! New balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    
    printf("Account not found!\n");
}

void withdraw() {
    int acc_number;
    float amount;
    
    printf("Enter Account Number to withdraw: ");
    scanf("%d", &acc_number);
    
    for (int i = 0; i < account_count; i++) {
        if (accounts[i].account_number == acc_number) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            
            if (amount > accounts[i].balance) {
                printf("Insufficient funds!\n");
            } else {
                accounts[i].balance -= amount;
                printf("Withdrawal successful! New balance: %.2f\n", accounts[i].balance);
            }
            return;
        }
    }
    
    printf("Account not found!\n");
}

void view_account() {
    int acc_number;
    
    printf("Enter Account Number to view: ");
    scanf("%d", &acc_number);
    
    for (int i = 0; i < account_count; i++) {
        if (accounts[i].account_number == acc_number) {
            printf("Account Number: %d\n", accounts[i].account_number);
            printf("Name: %s\n", accounts[i].name);
            printf("Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    
    printf("Account not found!\n");
}

void show_menu() {
    printf("\nBanking System Menu:\n");
    printf("1. Register Account\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. View Account\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    
    while (1) {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                register_account();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                view_account();
                break;
            case 5:
                printf("Exiting the system. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}