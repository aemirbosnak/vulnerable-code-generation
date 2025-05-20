//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
    int date;
} expense;

void add_expense(expense* expenses, int num_expenses, char* name, float amount, int date) {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached!\n");
        return;
    }

    strncpy(expenses[num_expenses].name, name, MAX_NAME_LENGTH);
    expenses[num_expenses].amount = amount;
    expenses[num_expenses].date = date;

    num_expenses++;
}

void print_expenses(expense* expenses, int num_expenses) {
    printf("Total expenses: %d\n", num_expenses);
    printf("Name\tAmount\tDate\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t%.2f\t%d\n", expenses[i].name, expenses[i].amount, expenses[i].date);
    }
}

int main() {
    expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    while (1) {
        printf("1. Add expense\n2. Print expenses\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[MAX_NAME_LENGTH];
                float amount;
                int date;

                printf("Enter expense name: ");
                scanf("%s", name);
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                printf("Enter expense date (YYYY-MM-DD): ");
                scanf("%d", &date);

                add_expense(expenses, num_expenses, name, amount, date);
                break;
            }
            case 2: {
                print_expenses(expenses, num_expenses);
                break;
            }
            case 3: {
                exit(0);
            }
            default: {
                printf("Invalid choice!\n");
            }
        }
    }

    return 0;
}