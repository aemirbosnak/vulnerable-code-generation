//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char description[50];
    float amount;
    int date[3]; // year, month, day
} expense;

expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense() {
    printf("Enter expense description: ");
    scanf("%s", expenses[num_expenses].description);

    printf("Enter expense amount: $");
    scanf("%f", &expenses[num_expenses].amount);

    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%d-%d-%d", &expenses[num_expenses].date[0], &expenses[num_expenses].date[1], &expenses[num_expenses].date[2]);

    num_expenses++;
}

void view_expenses() {
    if (num_expenses == 0) {
        printf("No expenses yet.\n");
        return;
    }

    printf("Expense ID | Description | Amount | Date\n");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < num_expenses; i++) {
        printf("%d | %s | $%.2f | %d-%02d-%02d\n", i+1, expenses[i].description, expenses[i].amount, expenses[i].date[0], expenses[i].date[1], expenses[i].date[2]);
    }
}

void search_expense() {
    char search_description[50];

    printf("Enter expense description to search: ");
    scanf("%s", search_description);

    int found = 0;

    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].description, search_description) == 0) {
            printf("Expense found:\n");
            printf("ID: %d\n", i+1);
            printf("Description: %s\n", expenses[i].description);
            printf("Amount: $%.2f\n", expenses[i].amount);
            printf("Date: %d-%02d-%02d\n", expenses[i].date[0], expenses[i].date[1], expenses[i].date[2]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Expense not found.\n");
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Search expense\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                view_expenses();
                break;
            case 3:
                search_expense();
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}