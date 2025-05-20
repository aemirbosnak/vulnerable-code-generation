//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

struct expense {
    char description[100];
    double amount;
    int date;
};

void add_expense(struct expense* expenses, int num_expenses) {
    printf("Enter expense description: ");
    scanf("%s", expenses[num_expenses].description);
    printf("Enter expense amount: ");
    scanf("%lf", &expenses[num_expenses].amount);
    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%d", &expenses[num_expenses].date);
    num_expenses++;
}

void print_expenses(struct expense* expenses, int num_expenses) {
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - $%.2lf - %d\n", expenses[i].description, expenses[i].amount, expenses[i].date);
    }
}

int main() {
    struct expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    while (num_expenses < MAX_EXPENSES) {
        printf("Enter 1 to add an expense or 0 to exit:\n");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            add_expense(expenses, num_expenses);
        } else if (choice == 0) {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    print_expenses(expenses, num_expenses);

    return 0;
}