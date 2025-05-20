//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    float balance;
    int account_number;
} account;

void create_account(account* a) {
    printf("Enter account holder name: ");
    scanf("%s", a->name);
    printf("Enter account number: ");
    scanf("%d", &a->account_number);
    printf("Enter initial balance: ");
    scanf("%f", &a->balance);
}

void deposit(account* a, float amount) {
    a->balance += amount;
    printf("%s deposited $%.2f into account %d\n", a->name, amount, a->account_number);
}

void withdraw(account* a, float amount) {
    if (a->balance >= amount) {
        a->balance -= amount;
        printf("%s withdrew $%.2f from account %d\n", a->name, amount, a->account_number);
    } else {
        printf("Insufficient funds\n");
    }
}

void check_balance(account* a) {
    printf("%s's balance in account %d is $%.2f\n", a->name, a->account_number, a->balance);
}

int main() {
    int choice;
    account a;

    do {
        printf("\nPersonal Finance Planner\n");
        printf("1. Create Account\n2. Deposit\n3. Withdraw\n4. Check Balance\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account(&a);
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d", &a.account_number);
                printf("Enter amount to deposit: ");
                scanf("%f", &a.balance);
                deposit(&a, a.balance);
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &a.account_number);
                printf("Enter amount to withdraw: ");
                scanf("%f", &a.balance);
                withdraw(&a, a.balance);
                break;
            case 4:
                printf("Enter account number: ");
                scanf("%d", &a.account_number);
                check_balance(&a);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 5);

    return 0;
}