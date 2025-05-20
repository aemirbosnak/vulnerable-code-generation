//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
    char owner[50];
    double balance;
    struct account *next;
};

struct account *head = NULL;

void add_account(char owner[50], double balance) {
    struct account *new_account = (struct account *)malloc(sizeof(struct account));
    if (new_account == NULL) {
        printf("Error: Memory allocation failed.\n");
        return;
    }
    strcpy(new_account->owner, owner);
    new_account->balance = balance;
    new_account->next = NULL;

    if (head == NULL) {
        head = new_account;
        return;
    }

    struct account *temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_account;
}

void deposit(char owner[50], double amount) {
    struct account *current = head;
    while (current!= NULL) {
        if (strcmp(current->owner, owner) == 0) {
            current->balance += amount;
            break;
        }
        current = current->next;
    }
}

void withdraw(char owner[50], double amount) {
    struct account *current = head;
    while (current!= NULL) {
        if (strcmp(current->owner, owner) == 0) {
            if (current->balance >= amount) {
                current->balance -= amount;
                break;
            } else {
                printf("Error: Insufficient funds.\n");
                break;
            }
        }
        current = current->next;
    }
}

void view_balance(char owner[50]) {
    struct account *current = head;
    while (current!= NULL) {
        if (strcmp(current->owner, owner) == 0) {
            printf("Owner: %s\n", current->owner);
            printf("Balance: %.2lf\n", current->balance);
            break;
        }
        current = current->next;
    }
}

int main() {
    char owner[50];
    double balance;

    printf("Enter owner name: ");
    scanf("%s", owner);

    printf("Enter initial balance: ");
    scanf("%lf", &balance);

    add_account(owner, balance);

    printf("Account created.\n");

    while (1) {
        char option;
        printf("1. Deposit\n2. Withdraw\n3. View Balance\n4. Exit\n");
        scanf(" %c", &option);

        if (option == '1') {
            printf("Enter amount to deposit: ");
            scanf("%lf", &balance);
            deposit(owner, balance);
            printf("Amount deposited successfully.\n");
        } else if (option == '2') {
            printf("Enter amount to withdraw: ");
            scanf("%lf", &balance);
            withdraw(owner, balance);
            printf("Amount withdrawn successfully.\n");
        } else if (option == '3') {
            view_balance(owner);
        } else if (option == '4') {
            printf("Goodbye!\n");
            break;
        }
    }

    return 0;
}