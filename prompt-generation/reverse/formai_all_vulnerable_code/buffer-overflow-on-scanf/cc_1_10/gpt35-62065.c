//FormAI DATASET v1.0 Category: Banking Record System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define ACCOUNT_NUMBER_SIZE 8

struct BankAccount {
    char account_number[ACCOUNT_NUMBER_SIZE];
    char first_name[20];
    char last_name[20];
    double balance;
};

void print_account(struct BankAccount account) {
    printf("Account Number: %s\n", account.account_number);
    printf("First Name: %s\n", account.first_name);
    printf("Last Name: %s\n", account.last_name);
    printf("Balance: $%.2lf\n", account.balance);
}

void print_menu() {
    printf("1. Add an account\n");
    printf("2. Print an account\n");
    printf("3. Deposit into an account\n");
    printf("4. Withdraw from an account\n");
    printf("5. Exit\n");
}

int main() {
    struct BankAccount accounts[MAX_ACCOUNTS];
    int num_accounts = 0;
    
    while (1) {
        printf("Welcome to the Banking Record System\n");
        printf("----------------------------------\n");
        print_menu();
        
        int choice;
        printf("Enter a choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("Enter account number: ");
            scanf("%s", accounts[num_accounts].account_number);
            printf("Enter first name: ");
            scanf("%s", accounts[num_accounts].first_name);
            printf("Enter last name: ");
            scanf("%s", accounts[num_accounts].last_name);
            accounts[num_accounts].balance = 0;
            printf("Account added!\n");
            num_accounts++;
        } else if (choice == 2) {
            printf("Enter account number: ");
            char account_number_to_find[ACCOUNT_NUMBER_SIZE];
            scanf("%s", account_number_to_find);
            
            int account_found = 0;
            for (int i = 0; i < num_accounts; i++) {
                if (strcmp(accounts[i].account_number, account_number_to_find) == 0) {
                    printf("Account found:\n");
                    print_account(accounts[i]);
                    account_found = 1;
                    break;
                }
            }
            
            if (!account_found) {
                printf("Sorry, that account does not exist\n");
            }
        } else if (choice == 3) {
            printf("Enter account number: ");
            char account_number_to_find[ACCOUNT_NUMBER_SIZE];
            scanf("%s", account_number_to_find);
            
            int account_found = 0;
            for (int i = 0; i < num_accounts; i++) {
                if (strcmp(accounts[i].account_number, account_number_to_find) == 0) {
                    printf("Enter deposit amount: ");
                    double deposit_amount;
                    scanf("%lf", &deposit_amount);
                    accounts[i].balance += deposit_amount;
                    printf("Deposit successful!\n");
                    account_found = 1;
                    break;
                }
            }
            
            if (!account_found) {
                printf("Sorry, that account does not exist\n");
            }
        } else if (choice == 4) {
            printf("Enter account number: ");
            char account_number_to_find[ACCOUNT_NUMBER_SIZE];
            scanf("%s", account_number_to_find);
            
            int account_found = 0;
            for (int i = 0; i < num_accounts; i++) {
                if (strcmp(accounts[i].account_number, account_number_to_find) == 0) {
                    printf("Enter withdrawal amount: ");
                    double withdrawal_amount;
                    scanf("%lf", &withdrawal_amount);
                    if (withdrawal_amount > accounts[i].balance) {
                        printf("Sorry, insufficient funds\n");
                    } else {
                        accounts[i].balance -= withdrawal_amount;
                        printf("Withdrawal successful!\n");
                    }
                    account_found = 1;
                    break;
                }
            }
            
            if (!account_found) {
                printf("Sorry, that account does not exist\n");
            }
        } else if (choice == 5) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid choice\n");
        }
        
        printf("\n");
    }
    
    return 0;
}