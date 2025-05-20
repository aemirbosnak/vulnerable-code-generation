//FormAI DATASET v1.0 Category: Banking Record System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

struct bank_record {
    int account_number;
    char client_name[20];
    double balance;
};

void create_account(struct bank_record *ptr, int num_accounts) {
    printf("Enter account number: ");
    scanf("%d", &ptr[num_accounts].account_number);
    printf("Enter client name: ");
    scanf("%s", ptr[num_accounts].client_name);
    printf("Enter balance: ");
    scanf("%lf", &ptr[num_accounts].balance);
}

void display_account(struct bank_record *ptr, int num_accounts) {
    printf("Account Number: %d\n", ptr[num_accounts].account_number);
    printf("Client Name: %s\n", ptr[num_accounts].client_name);
    printf("Balance: %.2lf\n", ptr[num_accounts].balance);
}

void deposit_balance(struct bank_record *ptr, int num_accounts) {
    double deposit_amount;
    printf("Enter deposit amount: ");
    scanf("%lf", &deposit_amount);
    ptr[num_accounts].balance += deposit_amount;
    printf("Deposit successful. Current balance: %.2lf\n", ptr[num_accounts].balance);
}

void withdraw_balance(struct bank_record *ptr, int num_accounts) {
    double withdraw_amount;
    printf("Enter withdraw amount: ");
    scanf("%lf", &withdraw_amount);
    if (withdraw_amount > ptr[num_accounts].balance) {
        printf("Insufficient balance. Please try again.\n");
    } else {
        ptr[num_accounts].balance -= withdraw_amount;
        printf("Withdrawal successful. Current balance: %.2lf\n", ptr[num_accounts].balance);
    }
}

int main() {
    int num_accounts = 0;
    struct bank_record accounts[100];
    int choice;
    int account_number;
    while(1) {
        printf("\n===== BANKING RECORD SYSTEM =====\n");
        printf("1. Create account\n");
        printf("2. Display account\n");
        printf("3. Deposit balance\n");
        printf("4. Withdraw balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create_account(accounts, num_accounts);
                num_accounts++;
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                for(int i = 0; i < num_accounts; i++) {
                    if(accounts[i].account_number == account_number) {
                        display_account(accounts, i);
                        break;
                    }
                    if(i == num_accounts - 1) {
                        printf("Account not found. Please try again.\n");
                    }
                }
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                for(int i = 0; i < num_accounts; i++) 
                {
                    if(accounts[i].account_number == account_number) 
                    {
                        deposit_balance(accounts, i);
                        break;
                    }
                    if(i == num_accounts - 1) 
                    {
                        printf("Account not found. Please try again.\n");
                    }
                }
                break;
            case 4:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                for(int i = 0; i < num_accounts; i++) 
                {
                    if(accounts[i].account_number == account_number) 
                    {
                        withdraw_balance(accounts, i);
                        break;
                    }
                    if(i == num_accounts - 1) 
                    {
                        printf("Account not found. Please try again.\n");
                    }
                }
                break;
            case 5:
                printf("Thank you for choosing our bank! Goodbye.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}