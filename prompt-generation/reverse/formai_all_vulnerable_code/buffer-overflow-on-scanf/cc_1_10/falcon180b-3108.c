//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    double amount;
    int date;
} expense;

void add_expense(expense* expenses, int num_expenses) {
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);
    printf("Enter expense amount: ");
    scanf("%lf", &expenses[num_expenses].amount);
    printf("Enter expense date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &expenses[num_expenses].date);
    printf("\n");
}

void print_expenses(expense* expenses, int num_expenses) {
    printf("\nExpenses:\n");
    printf("Name\tAmount\tDate\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t%.2lf\t%d/%d/%d\n", expenses[i].name, expenses[i].amount, expenses[i].date / 10000, (expenses[i].date % 10000) / 100, expenses[i].date % 100);
    }
    printf("\n");
}

void sort_expenses(expense* expenses, int num_expenses) {
    for (int i = 0; i < num_expenses - 1; i++) {
        for (int j = i + 1; j < num_expenses; j++) {
            if (expenses[i].date > expenses[j].date) {
                expense temp = expenses[i];
                expenses[i] = expenses[j];
                expenses[j] = temp;
            }
        }
    }
}

int main() {
    expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    printf("Welcome to the Expense Tracker!\n\n");
    while (num_expenses < MAX_EXPENSES) {
        printf("What would you like to do?\n1. Add expense\n2. Print expenses\n3. Sort expenses\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense(expenses, num_expenses);
                num_expenses++;
                break;
            case 2:
                print_expenses(expenses, num_expenses);
                break;
            case 3:
                sort_expenses(expenses, num_expenses);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}