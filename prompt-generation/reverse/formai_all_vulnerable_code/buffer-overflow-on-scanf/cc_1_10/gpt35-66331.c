//FormAI DATASET v1.0 Category: Banking Record System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int account_number;
    char account_type[10];
    float balance;
}account;

account *create_bank_account(int acc_number, char acc_type[], float acc_bal){
    account *new_acc = malloc(sizeof(account));
    new_acc->account_number = acc_number;
    new_acc->balance = acc_bal;
    strcpy(new_acc->account_type, acc_type);
    return new_acc;
}

void deposit(account *acc, float amount){
    float new_bal = acc->balance + amount;
    acc->balance = new_bal;
}

void withdraw(account *acc, float amount){
    float new_bal = acc->balance - amount;
    acc->balance = new_bal;
}

void transfer(account *source, account *dest, float amount){
    withdraw(source, amount);
    deposit(dest, amount);
}

int main(){
    int account_no;
    char account_type[10];
    float account_balance;
    account *account1, *account2;

    printf("Welcome to the Banking Record System!\n");
    printf("Please enter details for Account 1:\n");
    printf("Account Number: ");
    scanf("%d", &account_no);
    printf("Account Type: ");
    scanf("%s", account_type);
    printf("Account Balance: ");
    scanf("%f", &account_balance);

    account1 = create_bank_account(account_no, account_type, account_balance);

    printf("\nPlease enter details for Account 2:\n");
    printf("Account Number: ");
    scanf("%d", &account_no);
    printf("Account Type: ");
    scanf("%s", account_type);
    printf("Account Balance: ");
    scanf("%f", &account_balance);

    account2 = create_bank_account(account_no, account_type, account_balance);

    printf("\nAccount 1 Details:\n");
    printf("Account Number: %d\n", account1->account_number);
    printf("Account Type: %s\n", account1->account_type);
    printf("Account Balance: %.2f\n", account1->balance);

    printf("\nAccount 2 Details:\n");
    printf("Account Number: %d\n", account2->account_number);
    printf("Account Type: %s\n", account2->account_type);
    printf("Account Balance: %.2f\n", account2->balance);

    float amount;
    printf("\nEnter amount to deposit into Account 1: ");
    scanf("%f", &amount);
    deposit(account1, amount);
    printf("Updated Account 1 Balance: %.2f\n", account1->balance);

    printf("\nEnter amount to withdraw from Account 2: ");
    scanf("%f", &amount);
    withdraw(account2, amount);
    printf("Updated Account 2 Balance: %.2f\n", account2->balance);

    printf("\nEnter amount to transfer from Account 1 to Account 2: ");
    scanf("%f", &amount);
    transfer(account1, account2, amount);
    printf("Updated Account 1 Balance: %.2f\n", account1->balance);
    printf("Updated Account 2 Balance: %.2f\n", account2->balance);

    return 0;
}