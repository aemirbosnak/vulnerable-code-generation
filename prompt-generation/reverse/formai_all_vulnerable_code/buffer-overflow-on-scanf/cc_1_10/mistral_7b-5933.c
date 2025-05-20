//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float income;
    float expenses;
    float savings;
} Account;

void print_account(Account acc) {
    printf("\nName: %s", acc.name);
    printf("\nIncome: %.2f", acc.income);
    printf("\nExpenses: %.2f", acc.expenses);
    printf("\nSavings: %.2f\n", acc.savings);
}

void add_income(Account *acc, float amount) {
    acc->income += amount;
    acc->savings += amount;
}

void add_expense(Account *acc, float amount) {
    acc->expenses += amount;
    acc->savings -= amount;
}

int main() {
    Account my_account = {"John Doe", 0, 0, 0};
    int choice;

    while (1) {
        printf("\n1. Add Income\n2. Add Expense\n3. Print Account\n4. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                float income;
                printf("Enter income amount: ");
                scanf("%f", &income);
                add_income(&my_account, income);
                break;
            }
            case 2: {
                float expense;
                printf("Enter expense amount: ");
                scanf("%f", &expense);
                add_expense(&my_account, expense);
                break;
            }
            case 3: {
                print_account(my_account);
                break;
            }
            case 4: {
                printf("Quitting...\n");
                exit(0);
            }
            default: {
                printf("Invalid choice. Please try again.\n");
            }
        }
    }

    return 0;
}