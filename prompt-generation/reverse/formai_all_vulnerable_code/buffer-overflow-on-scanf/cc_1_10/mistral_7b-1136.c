//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float income;
    float expenses;
    float savings;
} Account;

void readAccountData(Account *account) {
    printf("Enter account name: ");
    fgets(account->name, sizeof(account->name), stdin);
    account->name[strlen(account->name) - 1] = '\0'; // remove newline character
    printf("Enter monthly income: ");
    scanf("%f", &account->income);
    printf("Enter monthly expenses: ");
    scanf("%f", &account->expenses);
    account->savings = account->income - account->expenses;
}

void displayAccountData(const Account *account) {
    printf("\nAccount Name: %s\n", account->name);
    printf("Monthly Income: %.2f\n", account->income);
    printf("Monthly Expenses: %.2f\n", account->expenses);
    printf("Monthly Savings: %.2f\n", account->savings);
}

int main() {
    Account myAccount;

    printf("Welcome to the Personal Finance Planner!\n");
    printf("----------------------------------------\n");

    readAccountData(&myAccount);
    printf("\nAccount data:\n");
    displayAccountData(&myAccount);

    int choice = 0;
    while (choice != 3) {
        printf("\nChoose an option:\n");
        printf("1. Update account data\n");
        printf("2. Display account data\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                readAccountData(&myAccount);
                printf("\nAccount data updated.\n");
                break;
            case 2:
                printf("\nAccount data:\n");
                displayAccountData(&myAccount);
                break;
            case 3:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid option.\n");
                break;
        }
    }

    return 0;
}