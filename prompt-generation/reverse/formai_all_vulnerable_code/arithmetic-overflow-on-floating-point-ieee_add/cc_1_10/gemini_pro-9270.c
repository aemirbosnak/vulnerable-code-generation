//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
    char name[50];
    char account_number[20];
    double balance;
    int is_active;
};

void create_account(struct account *a) {
    printf("Enter Name: ");
    scanf(" %[^\n]%*c", a->name);
    printf("Enter Account Number: ");
    scanf("%s", a->account_number);
    printf("Enter Initial Balance: ");
    scanf("%lf", &a->balance);
    a->is_active = 1;
}

void deposit(struct account *a) {
    double amount;
    printf("Enter Amount to Deposit: ");
    scanf("%lf", &amount);
    a->balance += amount;
}

void withdraw(struct account *a) {
    double amount;
    printf("Enter Amount to Withdraw: ");
    scanf("%lf", &amount);
    if (amount <= a->balance) {
        a->balance -= amount;
    } else {
        printf("Insufficient Funds\n");
    }
}

void print_account(struct account *a) {
    printf("Name: %s\n", a->name);
    printf("Account Number: %s\n", a->account_number);
    printf("Balance: %.2lf\n", a->balance);
    printf("Is Active: %d\n", a->is_active);
}

void main() {
    int choice;
    struct account a;
    while (1) {
        printf("1. Create Account\n2. Deposit\n3. Withdraw\n4. Print Account\n5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create_account(&a);
                break;
            case 2:
                deposit(&a);
                break;
            case 3:
                withdraw(&a);
                break;
            case 4:
                print_account(&a);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
}