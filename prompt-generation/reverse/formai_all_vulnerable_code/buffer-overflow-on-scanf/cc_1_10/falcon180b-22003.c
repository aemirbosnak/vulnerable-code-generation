//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

struct expense {
    char *description;
    float amount;
    int date;
};

void add_expense(struct expense *expenses, int num_expenses) {
    char description[50];
    float amount;
    int date;

    printf("Enter expense description: ");
    scanf("%s", description);

    printf("Enter expense amount: ");
    scanf("%f", &amount);

    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%d-%d-%d", &date, &date + 1, &date + 2);

    for (int i = 0; i < num_expenses; i++) {
        if (expenses[i].date == date) {
            printf("Expense already exists for date %d-%d-%d.\n", date % 100, (date % 10000) / 100, date / 1000000);
            return;
        }
    }

    expenses[num_expenses].description = malloc(strlen(description) + 1);
    strcpy(expenses[num_expenses].description, description);
    expenses[num_expenses].amount = amount;
    expenses[num_expenses].date = date;

    num_expenses++;
}

void display_expenses(struct expense *expenses, int num_expenses) {
    printf("Expenses for the month:\n");

    for (int i = 0; i < num_expenses; i++) {
        printf("%s: $%.2f on %d-%d-%d\n", expenses[i].description, expenses[i].amount, expenses[i].date % 100, (expenses[i].date % 10000) / 100, expenses[i].date / 1000000);
    }
}

int main() {
    struct expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    while (num_expenses < MAX_EXPENSES) {
        int choice;

        printf("\nExpense Tracker\n");
        printf("1. Add expense\n");
        printf("2. Display expenses\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense(expenses, num_expenses);
                break;
            case 2:
                display_expenses(expenses, num_expenses);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}