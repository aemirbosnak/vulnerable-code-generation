//FormAI DATASET v1.0 Category: Banking Record System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int accNum;
    float balance;
} Account;

void openAccount(Account *list, int *size) {
    int accNum = (*size) + 1;
    float balance;
    printf("Enter opening balance: ");
    scanf("%f", &balance);
    list[*size].accNum = accNum;
    list[*size].balance = balance;
    printf("Account %d is created successfully.\n", accNum);
    (*size)++;
}

void deposit(Account *list, int size) {
    int accNum, i;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNum);
    for (i = 0; i < size; i++) {
        if (list[i].accNum == accNum) {
            printf("Enter deposit amount: ");
            scanf("%f", &amount);
            list[i].balance += amount;
            printf("Deposit of %.2f is successful.\n", amount);
            return;
        }
    }
    printf("Account number not found.\n");
}

void withdraw(Account *list, int size) {
    int accNum, i;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNum);
    for (i = 0; i < size; i++) {
        if (list[i].accNum == accNum) {
            printf("Enter withdraw amount: ");
            scanf("%f", &amount);
            if (list[i].balance < amount) {
                printf("Insufficient balance.\n");
            } else {
                list[i].balance -= amount;
                printf("Withdraw of %.2f is successful.\n", amount);
            }
            return;
        }
    }
    printf("Account number not found.\n");
}

void displayDetails(Account *list, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("Account number: %d\tBalance: %.2f\n", list[i].accNum, list[i].balance);
    }
}

int main() {
    int size = 0;
    Account list[10];
    int choice;
    while (1) {
        printf("\n1. Open account\n2. Deposit\n3. Withdraw\n4. Display details\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (size == 10) {
                    printf("Cannot open more than 10 accounts.\n");
                } else {
                    openAccount(list, &size);
                }
                break;
            case 2:
                deposit(list, size);
                break;
            case 3:
                withdraw(list, size);
                break;
            case 4:
                displayDetails(list, size);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}