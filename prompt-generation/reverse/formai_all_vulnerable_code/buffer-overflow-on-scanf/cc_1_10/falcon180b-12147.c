//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

struct expense {
    char description[50];
    double amount;
    int date;
};

void add_expense(struct expense expenses[], int *num_expenses) {
    printf("Enter expense description: ");
    scanf("%s", expenses[*num_expenses].description);

    printf("Enter expense amount: ");
    scanf("%lf", &expenses[*num_expenses].amount);

    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%d-%d-%d", &expenses[*num_expenses].date);

    (*num_expenses)++;
}

void display_expenses(struct expense expenses[], int num_expenses) {
    printf("\nExpenses:\n");
    printf("Date\tDescription\tAmount\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%d-%02d-%02d\t%s\t%.2lf\n", expenses[i].date / 10000,
               (expenses[i].date / 100) % 100, expenses[i].date % 100,
               expenses[i].description, expenses[i].amount);
    }
}

void sort_expenses(struct expense expenses[], int num_expenses) {
    for (int i = 0; i < num_expenses - 1; i++) {
        for (int j = i + 1; j < num_expenses; j++) {
            if (expenses[i].date > expenses[j].date) {
                struct expense temp = expenses[i];
                expenses[i] = expenses[j];
                expenses[j] = temp;
            }
        }
    }
}

int main() {
    struct expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    printf("Welcome to the Expense Tracker!\n");

    while (num_expenses < MAX_EXPENSES) {
        printf("\nEnter 1 to add an expense, 2 to display expenses, 3 to sort expenses, or 0 to exit:\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_expense(expenses, &num_expenses);
            break;
        case 2:
            display_expenses(expenses, num_expenses);
            break;
        case 3:
            sort_expenses(expenses, num_expenses);
            printf("\nExpenses sorted by date:\n");
            display_expenses(expenses, num_expenses);
            break;
        case 0:
            printf("Thank you for using the Expense Tracker!\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}