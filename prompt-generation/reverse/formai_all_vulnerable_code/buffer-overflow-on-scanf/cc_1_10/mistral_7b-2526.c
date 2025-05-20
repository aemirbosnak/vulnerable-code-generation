//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct {
    char name[50];
    float income;
    float expenses;
    float savings;
} Person;

typedef struct {
    char category[50];
    float amount;
} Transaction;

Person user;
Transaction transactions[100];
int transactionCount = 0;

void displayMenu() {
    printf("====== PERSONAL FINANCE PLANNER ======\n");
    printf("1. Add income\n");
    printf("2. Add expense\n");
    printf("3. View transactions\n");
    printf("4. Calculate savings\n");
    printf("5. Exit\n");
}

void addIncome(float amount) {
    strcpy(user.name, "John Doe");
    user.income += amount;
}

void addExpense(float amount, char* category) {
    strcpy(transactions[transactionCount].category, category);
    transactions[transactionCount].amount = amount;
    user.expenses += amount;
    transactionCount++;
}

void viewTransactions() {
    if (transactionCount == 0) {
        printf("No transactions yet.\n");
        return;
    }
    printf("\nTransactions:\n");
    for (int i = 0; i < transactionCount; i++) {
        printf("%s: %.2f\n", transactions[i].category, transactions[i].amount);
    }
}

void calculateSavings() {
    user.savings = user.income - user.expenses;
    printf("Savings: %.2f\n", user.savings);
}

int main() {
    srand(time(NULL));
    int choice;
    char category[50];
    float amount;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter income amount: ");
                scanf("%f", &amount);
                addIncome(amount);
                break;
            case 2:
                printf("Enter expense category: ");
                scanf("%s", category);
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                addExpense(amount, category);
                break;
            case 3:
                viewTransactions();
                break;
            case 4:
                calculateSavings();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}