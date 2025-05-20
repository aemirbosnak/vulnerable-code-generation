//FormAI DATASET v1.0 Category: Banking Record System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

struct transaction {
    int account_number;
    char transaction_type;
    float amount;
};

struct account {
    int account_number;
    char account_holder_name[100];
    float account_balance;
    struct transaction transactions[100];
    int transaction_count;
};

struct account accounts[100];
int account_count = 0;

void create_account() {
    struct account new_account;
    printf("\nEnter Account Number: ");
    scanf("%d", &new_account.account_number);
    printf("Enter Account Holder Name: ");
    fflush(stdin);
    scanf("%[^\n]s", new_account.account_holder_name);
    printf("Enter Initial Balance: ");
    scanf("%f", &new_account.account_balance);
    new_account.transaction_count = 0;
    accounts[account_count++] = new_account;
    printf("\nAccount Created Successfully!\n");
}

void deposit() {
    int account_number, index = -1;
    float amount;
    printf("\nEnter Account Number: ");
    scanf("%d", &account_number);
    for(int i = 0; i < account_count; i++) {
        if(accounts[i].account_number == account_number) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        printf("\nAccount Not Found!\n");
        return;
    }
    printf("\nEnter Amount to Deposit: ");
    scanf("%f", &amount);
    if(amount <= 0) {
        printf("\nInvalid Amount!\n");
        return;
    }
    accounts[index].account_balance += amount;
    struct transaction new_transaction;
    new_transaction.account_number = account_number;
    new_transaction.transaction_type = 'D';
    new_transaction.amount = amount;
    accounts[index].transactions[accounts[index].transaction_count++] = new_transaction;
    printf("\nDeposit Successful!\n");
}

void withdraw() {
    int account_number, index = -1;
    float amount;
    printf("\nEnter Account Number: ");
    scanf("%d", &account_number);
    for(int i = 0; i < account_count; i++) {
        if(accounts[i].account_number == account_number) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        printf("\nAccount Not Found!\n");
        return;
    }
    printf("\nEnter Amount to Withdraw: ");
    scanf("%f", &amount);
    if(amount <= 0) {
        printf("\nInvalid Amount!\n");
        return;
    }
    if(accounts[index].account_balance - amount < 0) {
        printf("\nInsufficient Balance!\n");
        return;
    }
    accounts[index].account_balance -= amount;
    struct transaction new_transaction;
    new_transaction.account_number = account_number;
    new_transaction.transaction_type = 'W';
    new_transaction.amount = amount;
    accounts[index].transactions[accounts[index].transaction_count++] = new_transaction;
    printf("\nWithdrawal Successful!\n");
}

void view_balance() {
    int account_number, index = -1;
    printf("\nEnter Account Number: ");
    scanf("%d", &account_number);
    for(int i = 0; i < account_count; i++) {
        if(accounts[i].account_number == account_number) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        printf("\nAccount Not Found!\n");
        return;
    }
    printf("\nAccount Holder Name: %s\n", accounts[index].account_holder_name);
    printf("Account Balance: %.2f\n", accounts[index].account_balance);
    printf("Transaction History:\n");
    printf("Transaction Type\tAmount\n");
    for(int i = 0; i < accounts[index].transaction_count; i++) {
        if(accounts[index].transactions[i].transaction_type == 'D') {
            printf("Deposit\t\t%.2f\n", accounts[index].transactions[i].amount);
        }
        else {
            printf("Withdrawal\t%.2f\n", accounts[index].transactions[i].amount);
        }
    }
}

int main() {
    int choice;
    printf("\nWelcome to MyBank Ltd.\n");
    do {
        printf("\nMenu:\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. View Balance\n");
        printf("5. Exit\n");
        printf("\nEnter Your Choice: ");
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
                view_balance();
                break;
            case 5:
                printf("\nThank You for Using MyBank Ltd.\n");
                break;
            default:
                printf("\nInvalid Choice!\n");
        }
    } while(choice != 5);
    return 0;
}