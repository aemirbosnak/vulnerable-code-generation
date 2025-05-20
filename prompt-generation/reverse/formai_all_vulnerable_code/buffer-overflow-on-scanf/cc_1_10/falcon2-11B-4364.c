//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ACCOUNT 100

struct Account {
    char account_number[11];
    float balance;
    char customer_name[30];
    int account_type;
};

void create_account() {
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    char account_name[30];
    printf("Enter customer name: ");
    scanf("%s", account_name);
    int account_type;
    printf("Enter account type (1 for savings, 2 for current): ");
    scanf("%d", &account_type);
    struct Account account[MAX_ACCOUNT];
    for(int i=0; i<MAX_ACCOUNT; i++) {
        account[i].account_number[10] = '\0';
        account[i].balance = 0.0;
        account[i].customer_name[29] = '\0';
        account[i].account_type = account_type;
    }
    account[account_number].account_number[10] = '\0';
    account[account_number].balance = 0.0;
    account[account_number].customer_name[29] = '\0';
    account[account_number].account_type = account_type;
}

void deposit() {
    int account_number;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    struct Account account[MAX_ACCOUNT];
    for(int i=0; i<MAX_ACCOUNT; i++) {
        if(account[i].account_number[10] == '\0') {
            printf("Invalid account number.\n");
            return;
        }
        if(account[i].account_number[10] == account_number) {
            account[i].balance += amount;
            printf("Deposit successful.\n");
            return;
        }
    }
    printf("Account not found.\n");
}

void withdraw() {
    int account_number;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    struct Account account[MAX_ACCOUNT];
    for(int i=0; i<MAX_ACCOUNT; i++) {
        if(account[i].account_number[10] == '\0') {
            printf("Invalid account number.\n");
            return;
        }
        if(account[i].account_number[10] == account_number) {
            if(account[i].balance >= amount) {
                account[i].balance -= amount;
                printf("Withdrawal successful.\n");
                return;
            }
            printf("Insufficient balance.\n");
            return;
        }
    }
    printf("Account not found.\n");
}

void display() {
    struct Account account[MAX_ACCOUNT];
    for(int i=0; i<MAX_ACCOUNT; i++) {
        if(account[i].account_number[10] == '\0') {
            printf("Invalid account number.\n");
            return;
        }
        printf("Account %d: ", account[i].account_number[10]);
        printf("Customer name: %s\n", account[i].customer_name);
        printf("Balance: %.2f\n", account[i].balance);
    }
}

int main() {
    int choice, account_number;
    char account_name[30];
    int account_type;
    while(1) {
        printf("1. Create an account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display accounts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
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
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}