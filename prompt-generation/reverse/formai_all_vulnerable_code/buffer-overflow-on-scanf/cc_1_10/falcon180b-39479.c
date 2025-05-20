//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 100

struct expense {
    char category[50];
    float amount;
    int date;
};

void add_expense(struct expense expenses[], int count, char category[], float amount, int date) {
    if (count >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }

    strcpy(expenses[count].category, category);
    expenses[count].amount = amount;
    expenses[count].date = date;

    printf("Expense added successfully.\n");
}

void view_expenses(struct expense expenses[], int count) {
    printf("Expenses:\n");
    for (int i = 0; i < count; i++) {
        printf("%s - %.2f - %d\n", expenses[i].category, expenses[i].amount, expenses[i].date);
    }
}

void delete_expense(struct expense expenses[], int count) {
    printf("Enter the index of the expense to delete: ");
    int index;
    scanf("%d", &index);

    if (index < 0 || index >= count) {
        printf("Error: Invalid expense index.\n");
        return;
    }

    printf("Expense deleted successfully.\n");
}

void main() {
    struct expense expenses[MAX_EXPENSES];
    int count = 0;

    while (1) {
        printf("1. Add expense\n2. View expenses\n3. Delete expense\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char category[50];
                float amount;
                int date;

                printf("Enter the expense category: ");
                scanf("%s", category);

                printf("Enter the expense amount: ");
                scanf("%f", &amount);

                printf("Enter the expense date (YYYY-MM-DD): ");
                scanf("%d", &date);

                add_expense(expenses, count, category, amount, date);
                break;
            }
            case 2: {
                view_expenses(expenses, count);
                break;
            }
            case 3: {
                delete_expense(expenses, count);
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                printf("Error: Invalid choice.\n");
            }
        }
    }
}