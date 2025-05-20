//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50

typedef struct {
    int account_number;
    char name[NAME_LENGTH];
    float balance;
} BankAccount;

BankAccount accounts[MAX_ACCOUNTS];
int account_count = 0;

void create_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Max accounts reached. Cannot create more.\n");
        return;
    }
    
    BankAccount new_account;
    printf("Enter Account Number: ");
    scanf("%d", &new_account.account_number);
    printf("Enter Your Name: ");
    getchar(); // Clear buffer
    fgets(new_account.name, NAME_LENGTH, stdin);
    // Remove trailing newline character added by fgets
    new_account.name[strcspn(new_account.name, "\n")] = 0;

    new_account.balance = 0.0;
    accounts[account_count++] = new_account;
    printf("Account created successfully!\n");
}

void deposit() {
    int acc_number;
    float amount;
    
    printf("Enter Account Number: ");
    scanf("%d", &acc_number);

    for(int i = 0; i < account_count; i++) {
        if (accounts[i].account_number == acc_number) {
            printf("Enter Deposit Amount: ");
            scanf("%f", &amount);

            if (amount > 0) {
                accounts[i].balance += amount;
                printf("Successfully deposited %.2f. New Balance: %.2f\n", amount, accounts[i].balance);
            } else {
                printf("Invalid deposit amount.\n");
            }
            return;
        }
    }
    printf("Account not found.\n");
}

void withdraw() {
    int acc_number;
    float amount;

    printf("Enter Account Number: ");
    scanf("%d", &acc_number);

    for(int i = 0; i < account_count; i++) {
        if (accounts[i].account_number == acc_number) {
            printf("Enter Withdrawal Amount: ");
            scanf("%f", &amount);

            if (amount > 0 && amount <= accounts[i].balance) {
                accounts[i].balance -= amount;
                printf("Successfully withdrawn %.2f. New Balance: %.2f\n", amount, accounts[i].balance);
            } else {
                printf("Invalid withdrawal amount.\n");
            }
            return;
        }
    }
    printf("Account not found.\n");
}

void check_balance() {
    int acc_number;

    printf("Enter Account Number: ");
    scanf("%d", &acc_number);

    for(int i = 0; i < account_count; i++) {
        if (accounts[i].account_number == acc_number) {
            printf("Account Holder: %s, Current Balance: %.2f\n", accounts[i].name, accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void list_accounts() {
    if (account_count == 0) {
        printf("No accounts available.\n");
        return;
    }
    printf("List of Accounts:\n");
    for(int i = 0; i < account_count; i++) {
        printf("Account Number: %d, Name: %s, Balance: %.2f\n", 
               accounts[i].account_number, accounts[i].name, accounts[i].balance);
    }
}

void display_menu() {
    printf("\n--- Welcome to the Banking Record System ---\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Check Balance\n");
    printf("5. List all Accounts\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    while (1) {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                check_balance();
                break;
            case 5:
                list_accounts();
                break;
            case 6:
                printf("Thank you for using the Banking Record System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}