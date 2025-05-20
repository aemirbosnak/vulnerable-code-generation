//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: portable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int accountNumber;
    char name[50];
    float balance;
} Account;

typedef struct {
    int numberOfAccounts;
    Account* accounts;
} Bank;

Bank* createBank(int numberOfAccounts) {
    Bank* bank = malloc(sizeof(Bank));
    bank->numberOfAccounts = numberOfAccounts;
    bank->accounts = malloc(numberOfAccounts * sizeof(Account));
    return bank;
}

void addAccount(Bank* bank, int accountNumber, char name[50], float balance) {
    bank->accounts[bank->numberOfAccounts].accountNumber = accountNumber;
    strcpy(bank->accounts[bank->numberOfAccounts].name, name);
    bank->accounts[bank->numberOfAccounts].balance = balance;
    bank->numberOfAccounts++;
}

void printAccounts(Bank* bank) {
    for (int i = 0; i < bank->numberOfAccounts; i++) {
        printf("Account Number: %d\n", bank->accounts[i].accountNumber);
        printf("Name: %s\n", bank->accounts[i].name);
        printf("Balance: %.2f\n", bank->accounts[i].balance);
        printf("\n");
    }
}

int main() {
    int numberOfAccounts;
    printf("Enter the number of accounts: ");
    scanf("%d", &numberOfAccounts);

    Bank* bank = createBank(numberOfAccounts);

    int accountNumber, balance;
    char name[50];

    printf("Enter account number:\n");
    scanf("%d", &accountNumber);

    printf("Enter name:\n");
    gets(name);

    printf("Enter initial balance:\n");
    scanf("%f", &balance);

    addAccount(bank, accountNumber, name, balance);

    printf("Accounts:\n");
    printAccounts(bank);

    free(bank->accounts);
    free(bank);

    return 0;
}