//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct account {
    char name[50];
    char account_number[10];
    int balance;
};

struct account create_account(char name[], char account_number[]) {
    struct account account;
    strcpy(account.name, name);
    strcpy(account.account_number, account_number);
    account.balance = 0;
    return account;
}

void deposit(struct account *account, int amount) {
    account->balance += amount;
}

int withdraw(struct account *account, int amount) {
    if (account->balance >= amount) {
        account->balance -= amount;
        return 1;
    } else {
        return 0;
    }
}

void print_account_details(struct account account) {
    printf("Name: %s\n", account.name);
    printf("Account Number: %s\n", account.account_number);
    printf("Balance: $%d\n", account.balance);
}

int main() {
    char name[50];
    char account_number[10];
    int choice, amount;

    printf("Welcome to the Mind-Bending Banking System!\n");

    do {
        printf("Enter your name: ");
        scanf("%s", name);
        printf("Enter your account number: ");
        scanf("%s", account_number);

        struct account account = create_account(name, account_number);
        print_account_details(account);

        do {
            printf("\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    printf("Enter the amount to deposit: ");
                    scanf("%d", &amount);
                    deposit(&account, amount);
                    print_account_details(account);
                    break;

                case 2:
                    printf("Enter the amount to withdraw: ");
                    scanf("%d", &amount);
                    if (withdraw(&account, amount)) {
                        print_account_details(account);
                    } else {
                        printf("Insufficient balance.\n");
                    }
                    break;

                case 3:
                    print_account_details(account);
                    break;

                case 4:
                    printf("Thank you for using the Mind-Bending Banking System!\n");
                    break;

                default:
                    printf("Invalid choice. Please try again.\n");
            }
        } while(choice!= 4);

    } while(1);

    return 0;
}