//FormAI DATASET v1.0 Category: Banking Record System ; Style: random
#include <stdio.h>
#include <stdlib.h>

struct client {
    int id;
    char name[50];
    float balance;
};

void create_account(struct client *c) {
    printf("\nEnter client id: ");
    scanf("%d", &c->id);
    printf("Enter client name: ");
    scanf("%s", c->name);
    printf("Enter initial account balance: ");
    scanf("%f", &c->balance);
    printf("\nAccount successfully created!");
}

void withdraw(struct client *c) {
    float amount;
    printf("\nEnter amount to withdraw: ");
    scanf("%f", &amount);
    if (c->balance < amount) {
        printf("Insufficient balance!\n");
    } else {
        c->balance -= amount;
        printf("Transaction successful!\n");
    }
}

void deposit(struct client *c) {
    float amount;
    printf("\nEnter amount to deposit: ");
    scanf("%f", &amount);
    c->balance += amount;
    printf("Transaction successful!\n");
}

void display_balance(struct client *c) {
    printf("\nClient ID: %d\n", c->id);
    printf("Client Name: %s\n", c->name);
    printf("Account Balance: %.2f\n", c->balance);
}

int main() {
    int choice;
    struct client c;
    int account_created = 0;
    while (1) {
        printf("\n-- Bank Record System --\n");
        printf("1. Create Account\n");
        printf("2. Withdraw\n");
        printf("3. Deposit\n");
        printf("4. Display Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (account_created) {
                    printf("\nAccount already created!\n");
                    break;
                }
                create_account(&c);
                account_created = 1;
                break;
            case 2:
                if (!account_created) {
                    printf("\nNo account found!\n");
                    break;
                }
                withdraw(&c);
                break;
            case 3:
                if (!account_created) {
                    printf("\nNo account found!\n");
                    break;
                }
                deposit(&c);
                break;
            case 4:
                if (!account_created) {
                    printf("\nNo account found!\n");
                    break;
                }
                display_balance(&c);
                break;
            case 5:
                printf("\nThank you for using our system!\n");
                exit(0);
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }
    return 0;
}