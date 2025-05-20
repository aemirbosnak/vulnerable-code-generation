//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: romantic
#include <stdio.h>
#include <string.h>

struct BankAccount {
    char name[100];
    int balance;
};

void displayMenu() {
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Check Balance\n");
    printf("4. Exit\n");
}

void deposit(struct BankAccount* account) {
    int amount;
    printf("Enter the amount to be deposited: ");
    scanf("%d", &amount);
    account->balance += amount;
}

void withdraw(struct BankAccount* account) {
    int amount;
    printf("Enter the amount to be withdrawn: ");
    scanf("%d", &amount);
    if (amount > account->balance) {
        printf("Insufficient balance.\n");
    } else {
        account->balance -= amount;
    }
}

void checkBalance(struct BankAccount* account) {
    printf("Balance: %d\n", account->balance);
}

int main() {
    struct BankAccount account;
    int choice;
    printf("Enter your name: ");
    scanf("%s", account.name);
    account.balance = 0;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                deposit(&account);
                break;
            case 2:
                withdraw(&account);
                break;
            case 3:
                checkBalance(&account);
                break;
            case 4:
                printf("Thank you for using our banking system.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}