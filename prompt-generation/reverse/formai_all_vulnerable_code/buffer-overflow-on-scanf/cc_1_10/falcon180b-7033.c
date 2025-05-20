//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int account_number;
    char name[50];
    float balance;
} Account;

void create_account(Account* account) {
    printf("Enter your name: ");
    scanf("%s", account->name);
    printf("Enter your initial deposit: ");
    scanf("%f", &account->balance);
    account->account_number = rand() % 1000;
    printf("Your account number is %d.\n", account->account_number);
}

void deposit(Account* account) {
    printf("Enter amount to deposit: ");
    scanf("%f", &account->balance);
    printf("Deposit successful.\n");
}

void withdraw(Account* account) {
    printf("Enter amount to withdraw: ");
    scanf("%f", &account->balance);
    if (account->balance < 0) {
        printf("Withdrawal unsuccessful. Insufficient funds.\n");
        account->balance = 0;
    } else {
        printf("Withdrawal successful.\n");
    }
}

void check_balance(Account* account) {
    printf("Your current balance is %.2f.\n", account->balance);
}

int main() {
    Account my_account;
    int choice;

    printf("Welcome to the Sherlock Holmes Banking System!\n");
    printf("Please choose an option:\n");
    printf("1. Create account\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Check balance\n");
    printf("5. Exit\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            create_account(&my_account);
            break;
        case 2:
            deposit(&my_account);
            break;
        case 3:
            withdraw(&my_account);
            break;
        case 4:
            check_balance(&my_account);
            break;
        case 5:
            printf("Thank you for using the Sherlock Holmes Banking System. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}