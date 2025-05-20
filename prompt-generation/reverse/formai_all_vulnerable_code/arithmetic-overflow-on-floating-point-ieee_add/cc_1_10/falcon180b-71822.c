//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int account_number;
    float balance;
    time_t creation_date;
} account_t;

void create_account(account_t *account) {
    printf("Enter your name: ");
    scanf("%s", account->name);

    srand(time(NULL));
    account->account_number = rand() % 100000;

    printf("Your account number is: %d\n", account->account_number);
}

void deposit(account_t *account, float amount) {
    account->balance += amount;
    printf("Deposit successful! New balance: $%.2f\n", account->balance);
}

void withdraw(account_t *account, float amount) {
    if (account->balance >= amount) {
        account->balance -= amount;
        printf("Withdrawal successful! New balance: $%.2f\n", account->balance);
    } else {
        printf("Insufficient funds.\n");
    }
}

void check_balance(account_t *account) {
    printf("Current balance: $%.2f\n", account->balance);
}

int main() {
    account_t my_account;
    create_account(&my_account);

    int choice;
    do {
        printf("\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter deposit amount: ");
                scanf("%f", &my_account.balance);
                deposit(&my_account, my_account.balance);
                break;
            case 2:
                printf("Enter withdrawal amount: ");
                scanf("%f", &my_account.balance);
                withdraw(&my_account, my_account.balance);
                break;
            case 3:
                check_balance(&my_account);
                break;
            case 4:
                printf("Thank you for using our banking system!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 4);

    return 0;
}