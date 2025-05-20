//FormAI DATASET v1.0 Category: Banking Record System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 1000

struct Account {
    char name[50];
    int accountNumber;
    double balance;
};

struct Bank {
    struct Account accounts[MAX_ACCOUNTS];
    int numAccounts;
};

void addAccount(struct Bank *bank, struct Account newAccount) {
    if (bank->numAccounts >= MAX_ACCOUNTS) {
        printf("Error: too many accounts\n");
        return;
    }
    bank->accounts[bank->numAccounts] = newAccount;
    bank->numAccounts++;
}

void printAccount(struct Account account) {
    printf("Name: %s\n", account.name);
    printf("Account Number: %d\n", account.accountNumber);
    printf("Current Balance: $%.2lf\n", account.balance);
}

int findAccount(struct Bank bank, int accountNumber) {
    for (int i = 0; i < bank.numAccounts; i++) {
        if (bank.accounts[i].accountNumber == accountNumber) {
            return i;
        }
    }
    return -1;
}

void deposit(struct Bank *bank, int accountNumber, double amount) {
    int i = findAccount(*bank, accountNumber);
    if (i < 0) {
        printf("Error: account not found\n");
        return;
    }
    bank->accounts[i].balance += amount;
    printf("Deposited $%.2lf into account %d. New balance: $%.2lf\n", amount, accountNumber, bank->accounts[i].balance);
}

void withdraw(struct Bank *bank, int accountNumber, double amount) {
    int i = findAccount(*bank, accountNumber);
    if (i < 0) {
        printf("Error: account not found\n");
        return;
    }
    if (bank->accounts[i].balance < amount) {
        printf("Error: insufficient funds\n");
        return;
    }
    bank->accounts[i].balance -= amount;
    printf("Withdrew $%.2lf from account %d. New balance: $%.2lf\n", amount, accountNumber, bank->accounts[i].balance);
}

void transfer(struct Bank *bank, int fromAccountNumber, int toAccountNumber, double amount) {
    int fromIndex = findAccount(*bank, fromAccountNumber);
    int toIndex = findAccount(*bank, toAccountNumber);
    if (fromIndex < 0) {
        printf("Error: source account not found\n");
        return;
    }
    if (toIndex < 0) {
        printf("Error: destination account not found\n");
        return;
    }
    if (bank->accounts[fromIndex].balance < amount) {
        printf("Error: insufficient funds\n");
        return;
    }
    bank->accounts[fromIndex].balance -= amount;
    bank->accounts[toIndex].balance += amount;
    printf("Transferred $%.2lf from account %d to account %d. New balance for account %d: $%.2lf. New balance for account %d: $%.2lf\n", amount, fromAccountNumber, toAccountNumber, fromAccountNumber, bank->accounts[fromIndex].balance, toAccountNumber, bank->accounts[toIndex].balance);
}

void printAllAccounts(struct Bank bank) {
    for (int i = 0; i < bank.numAccounts; i++) {
        printAccount(bank.accounts[i]);
        printf("\n");
    }
}

int main() {
    struct Bank bank;
    bank.numAccounts = 0;
    
    while (1) {
        printf("Enter command (\"help\" for list of commands): ");
        char command[50];
        scanf("%s", command);
        
        if (strcmp(command, "help") == 0) {
            printf("\nCommands:\n");
            printf("add [name] [account number] [balance]: adds an account\n");
            printf("deposit [account number] [amount]: makes a deposit\n");
            printf("withdraw [account number] [amount]: makes a withdrawal\n");
            printf("transfer [source account number] [destination account number] [amount]: transfers funds from one account to another\n");
            printf("printall: prints information for all accounts\n");
            printf("quit: exits the program\n\n");
        }
        else if (strcmp(command, "add") == 0) {
            char name[50];
            int accountNumber;
            double balance;
            scanf("%s %d %lf", name, &accountNumber, &balance);
            struct Account newAccount = {name, accountNumber, balance};
            addAccount(&bank, newAccount);
            printf("Added account for %s with account number %d and initial balance $%.2lf\n", name, accountNumber, balance);
        }
        else if (strcmp(command, "deposit") == 0) {
            int accountNumber;
            double amount;
            scanf("%d %lf", &accountNumber, &amount);
            deposit(&bank, accountNumber, amount);
        }
        else if (strcmp(command, "withdraw") == 0) {
            int accountNumber;
            double amount;
            scanf("%d %lf", &accountNumber, &amount);
            withdraw(&bank, accountNumber, amount);
        }
        else if (strcmp(command, "transfer") == 0) {
            int fromAccountNumber, toAccountNumber;
            double amount;
            scanf("%d %d %lf", &fromAccountNumber, &toAccountNumber, &amount);
            transfer(&bank, fromAccountNumber, toAccountNumber, amount);
        }
        else if (strcmp(command, "printall") == 0) {
            printAllAccounts(bank);
        }
        else if (strcmp(command, "quit") == 0) {
            printf("Exiting program\n");
            break;
        }
        else {
            printf("Error: invalid command\n");
        }
    }
    
    return 0;
}