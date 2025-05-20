//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: unmistakable
#include <stdio.h>

typedef struct account {
    char account_holder[30];
    int account_number;
    float balance;
    int transaction_count;
} account;

void create_account(account* a) {
    printf("Please enter the account holder's name: ");
    scanf("%s", a->account_holder);
    printf("Please enter the account number: ");
    scanf("%d", &a->account_number);
    a->balance = 0.0;
    a->transaction_count = 0;
}

void deposit(account* a, float amount) {
    if (amount <= 0) {
        printf("Invalid amount!\n");
        return;
    }
    a->balance += amount;
    a->transaction_count++;
}

void withdraw(account* a, float amount) {
    if (amount <= 0 || amount > a->balance) {
        printf("Invalid amount!\n");
        return;
    }
    a->balance -= amount;
    a->transaction_count++;
}

void display_account(account a) {
    printf("Account Holder: %s\n", a.account_holder);
    printf("Account Number: %d\n", a.account_number);
    printf("Balance: %.2f\n", a.balance);
    printf("Transaction Count: %d\n", a.transaction_count);
}

int main() {
    account account1;
    create_account(&account1);
    deposit(&account1, 1000);
    withdraw(&account1, 500);
    display_account(account1);
    return 0;
}