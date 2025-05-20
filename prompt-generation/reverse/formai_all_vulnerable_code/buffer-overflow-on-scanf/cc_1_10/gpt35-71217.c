//FormAI DATASET v1.0 Category: Banking Record System ; Style: random
#include<stdio.h>
#include<stdlib.h>

// Structure to hold the banking record
struct account {
    char name[50];
    int account_num;
    float balance;
};

// Function to print the account details
void print_account(struct account acc) {
    printf("Account Holder Name: %s\n", acc.name);
    printf("Account Number: %d\n", acc.account_num);
    printf("Account Balance: $%.2f\n", acc.balance);
}

// Function to add a new account
void add_account(struct account *acc_ptr) {
    printf("\n=== Add New Account ===\n");
    printf("Enter Account Holder Name: ");
    scanf("%s", acc_ptr->name);
    printf("Enter Account Number: ");
    scanf("%d", &acc_ptr->account_num);
    printf("Enter Account Balance: ");
    scanf("%f", &acc_ptr->balance);
    printf("\nAccount Added Successfully!\n");
}

// Function to deposit money into an account
void deposit(struct account *acc_ptr) {
    float amount;
    printf("\n=== Deposit Money ===\n");
    printf("Enter Amount to Deposit: ");
    scanf("%f", &amount);
    acc_ptr->balance += amount;
    printf("\nDeposit Successful!\n");
    print_account(*acc_ptr);
}

// Function to withdraw money from an account
void withdraw(struct account *acc_ptr) {
    float amount;
    printf("\n=== Withdraw Money ===\n");
    printf("Enter Amount to Withdraw: ");
    scanf("%f", &amount);
    if(amount > acc_ptr->balance) {
        printf("\nInsufficient Balance!\n");
    }
    else {
        acc_ptr->balance -= amount;
        printf("\nWithdrawal Successful!\n");
        print_account(*acc_ptr);
    }
}

// Function to search for an account
int search_account(struct account *accounts, int num_accounts, int account_num) {
    int i;
    for(i = 0; i < num_accounts; i++) {
        if(accounts[i].account_num == account_num) {
            return i;
        }
    }
    return -1;
}

int main() {
    int choice, num_accounts = 0, account_num, account_index, i;
    char new_line;
    struct account *accounts = NULL;
    do {
        printf("\n");
        printf("Banking Record System\n");
        printf("======================\n");
        printf("1. Add New Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display Account Details\n");
        printf("0. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        scanf("%c", &new_line);
        switch(choice) {
            case 1:
                accounts = (struct account*)realloc(accounts, (num_accounts + 1)*sizeof(struct account));
                if(accounts != NULL) {
                    add_account(&accounts[num_accounts]);
                    num_accounts++;
                }
                else {
                    printf("\nMemory Allocation Failed!\n");
                }
                break;
            case 2:
                printf("\nEnter Account Number: ");
                scanf("%d", &account_num);
                account_index = search_account(accounts, num_accounts, account_num);
                if(account_index != -1) {
                    deposit(&accounts[account_index]);
                }
                else {
                    printf("\nAccount Not Found!\n");
                }
                break;
            case 3:
                printf("\nEnter Account Number: ");
                scanf("%d", &account_num);
                account_index = search_account(accounts, num_accounts, account_num);
                if(account_index != -1) {
                    withdraw(&accounts[account_index]);
                }
                else {
                    printf("\nAccount Not Found!\n");
                }
                break;
            case 4:
                printf("\n=== Display Account Details ===\n");
                for(i = 0; i < num_accounts; i++) {
                    printf("\nAccount %d:\n", i+1);
                    print_account(accounts[i]);
                }
                break;
            case 0:
                printf("\nExiting Program...\n");
                break;
            default:
                printf("\nInvalid Choice!\n");
        }
    } while(choice != 0);
    free(accounts);
    return 0;
}