//FormAI DATASET v1.0 Category: Banking Record System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct record {
    int id;
    char name[MAX];
    float balance;
};

void new_account(struct record *r) {
    printf("Enter Account ID: ");
    scanf("%d", &r->id);
    printf("Enter Account Name: ");
    scanf("%s", r->name);
    printf("Enter Account Balance: ");
    scanf("%f", &r->balance);
    printf("Account Created!\n");
}

void display_account(struct record r) {
    printf("Account ID: %d\n", r.id);
    printf("Account Name: %s\n", r.name);
    printf("Account Balance: %.2f\n", r.balance);
}

void withdraw(struct record *r) {
    float amount;
    printf("Enter Amount to Withdraw: ");
    scanf("%f", &amount);
    if (amount > r->balance) {
        printf("Insufficient Balance!\n");
    } else {
        r->balance -= amount;
        printf("Transaction Successful!\n");
    }
}

void deposit(struct record *r) {
    float amount;
    printf("Enter Amount to Deposit: ");
    scanf("%f", &amount);
    r->balance += amount;
    printf("Transaction Successful!\n");
}

void menu() {
    printf("===================================\n");
    printf("           BANKING SYSTEM           \n");
    printf("===================================\n");
    printf("\n");
    printf("1. Create a New Account\n");
    printf("2. Display Account Details\n");
    printf("3. Withdraw Money\n");
    printf("4. Deposit Money\n");
    printf("5. Exit\n");
}

int main() {
    struct record r;
    int choice;
    char loop = 1;

    menu();

    while (loop) {
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                new_account(&r);
                break;
            case 2:
                display_account(r);
                break;
            case 3:
                withdraw(&r);
                break;
            case 4:
                deposit(&r);
                break;
            case 5:
                printf("Exiting program...");
                loop = 0;
                break;
            default:
                printf("Invalid Choice!\n");
        }

        printf("\n");
        system("pause");
        system("cls"); // clear the console screen
        menu();
    }

    return 0;
}