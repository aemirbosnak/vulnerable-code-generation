//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Account {
    int accountNumber;
    char name[50];
    double balance;
    double interestRate;
    int totalDeposits;
    int totalWithdrawals;
};

struct Account* createAccount() {
    struct Account* newAccount = (struct Account*)malloc(sizeof(struct Account));
    newAccount->accountNumber = -1;
    newAccount->name[0] = '\0';
    newAccount->balance = 0.0;
    newAccount->interestRate = 0.01;
    newAccount->totalDeposits = 0;
    newAccount->totalWithdrawals = 0;
    return newAccount;
}

void deleteAccount(struct Account* account) {
    free(account);
}

void printAccount(struct Account* account) {
    printf("Account Number: %d\n", account->accountNumber);
    printf("Name: %s\n", account->name);
    printf("Balance: $%.2f\n", account->balance);
    printf("Interest Rate: %.2f%%\n", account->interestRate);
    printf("Total Deposits: $%.2f\n", account->totalDeposits);
    printf("Total Withdrawals: $%.2f\n", account->totalWithdrawals);
}

void deposit(struct Account* account, double amount) {
    account->balance += amount;
    account->totalDeposits += amount;
}

void withdraw(struct Account* account, double amount) {
    if (amount > account->balance) {
        printf("Insufficient funds\n");
        return;
    }
    account->balance -= amount;
    account->totalWithdrawals += amount;
}

double calculateInterest(struct Account* account) {
    double interest = account->balance * account->interestRate;
    account->balance += interest;
    return interest;
}

int main() {
    struct Account* account1 = createAccount();
    struct Account* account2 = createAccount();

    srand(time(NULL));
    int choice;
    while (1) {
        printf("Welcome to the Bank Record System!\n");
        printf("1. Create an account\n");
        printf("2. View account details\n");
        printf("3. Deposit money\n");
        printf("4. Withdraw money\n");
        printf("5. Calculate interest\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter account number: ");
                scanf("%d", &account1->accountNumber);
                printf("Enter name: ");
                scanf("%s", account1->name);
                printf("Enter initial balance: ");
                scanf("%lf", &account1->balance);
                printf("Enter interest rate: ");
                scanf("%lf", &account1->interestRate);
                break;
            case 2:
                printAccount(account1);
                printAccount(account2);
                break;
            case 3:
                printf("Enter amount to deposit: ");
                scanf("%lf", &account1->balance);
                break;
            case 4:
                printf("Enter amount to withdraw: ");
                scanf("%lf", &account1->balance);
                break;
            case 5:
                printf("Account 1: $%.2f\n", account1->balance);
                printf("Account 2: $%.2f\n", account2->balance);
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}