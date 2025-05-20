//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    double balance;
    double interest;
} Account;

void createAccount(Account* account) {
    printf("Enter account name: ");
    scanf("%s", account->name);
    printf("Enter account balance: ");
    scanf("%lf", &account->balance);
    printf("Enter account interest rate: ");
    scanf("%lf", &account->interest);
}

void displayAccount(Account account) {
    printf("Account Name: %s\n", account.name);
    printf("Account Balance: $%.2lf\n", account.balance);
    printf("Account Interest Rate: %.2lf%%\n", account.interest * 100);
}

void deposit(Account* account, double amount) {
    account->balance += amount;
}

void withdraw(Account* account, double amount) {
    if (account->balance - amount >= 0) {
        account->balance -= amount;
    } else {
        printf("Insufficient balance.\n");
    }
}

void calculateInterest(Account* account) {
    account->balance += account->balance * account->interest;
}

int main() {
    Account myAccount;
    createAccount(&myAccount);
    displayAccount(myAccount);

    deposit(&myAccount, 1000);
    displayAccount(myAccount);

    withdraw(&myAccount, 500);
    displayAccount(myAccount);

    calculateInterest(&myAccount);
    displayAccount(myAccount);

    return 0;
}