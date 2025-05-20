//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_EXPENSE_NAME_LENGTH 50

typedef struct {
    char name[MAX_EXPENSE_NAME_LENGTH];
    double amount;
    int date;
} Expense;

int main() {
    int choice, i;
    char name[MAX_EXPENSE_NAME_LENGTH];
    double amount;
    int date;
    Expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    while (1) {
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter expense name: ");
            scanf("%s", name);
            printf("Enter amount: ");
            scanf("%lf", &amount);
            printf("Enter date (YYYY-MM-DD): ");
            scanf("%d", &date);

            if (num_expenses >= MAX_EXPENSES) {
                printf("Error: Maximum expenses reached\n");
            } else {
                strcpy(expenses[num_expenses].name, name);
                expenses[num_expenses].amount = amount;
                expenses[num_expenses].date = date;
                num_expenses++;
            }

            break;

        case 2:
            printf("Expenses:\n");
            for (i = 0; i < num_expenses; i++) {
                printf("%s - %.2lf - %d\n", expenses[i].name, expenses[i].amount, expenses[i].date);
            }

            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}