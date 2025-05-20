//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct customer {
    char name[50];
    char address[100];
    char phone[20];
    int balance;
} customer;

void create_customer(customer *c) {
    printf("Enter name: ");
    scanf(" %[^\n]s", c->name);
    printf("Enter address: ");
    scanf(" %[^\n]s", c->address);
    printf("Enter phone: ");
    scanf(" %[^\n]s", c->phone);
    c->balance = 0;
}

void deposit(customer *c) {
    int amount;
    printf("Enter amount to deposit: ");
    scanf("%d", &amount);
    c->balance += amount;
}

void withdraw(customer *c) {
    int amount;
    printf("Enter amount to withdraw: ");
    scanf("%d", &amount);
    if (amount <= c->balance) {
        c->balance -= amount;
    } else {
        printf("Insufficient funds.\n");
    }
}

void transfer(customer *c1, customer *c2) {
    int amount;
    printf("Enter amount to transfer: ");
    scanf("%d", &amount);
    if (amount <= c1->balance) {
        c1->balance -= amount;
        c2->balance += amount;
    } else {
        printf("Insufficient funds.\n");
    }
}

void print_customer(customer *c) {
    printf("Name: %s\n", c->name);
    printf("Address: %s\n", c->address);
    printf("Phone: %s\n", c->phone);
    printf("Balance: %d\n", c->balance);
}

int main() {
    customer c1, c2;
    int choice;

    while (1) {
        printf("1. Create customer\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Transfer\n");
        printf("5. Print customer\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_customer(&c1);
                break;
            case 2:
                deposit(&c1);
                break;
            case 3:
                withdraw(&c1);
                break;
            case 4:
                transfer(&c1, &c2);
                break;
            case 5:
                print_customer(&c1);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}