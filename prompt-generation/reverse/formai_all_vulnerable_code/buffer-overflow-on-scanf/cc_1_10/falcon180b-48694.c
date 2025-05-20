//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    char category[50];
    float amount;
    char date[20];
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense() {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Max expenses limit reached. ");
        return;
    }

    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);

    printf("Enter expense category: ");
    scanf("%s", expenses[num_expenses].category);

    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);

    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%s", expenses[num_expenses].date);

    num_expenses++;
}

void view_expenses() {
    printf("\nExpense Name\tExpense Category\tExpense Amount\tExpense Date\n");

    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t\t%s\t\t%.2f\t\t%s\n", expenses[i].name, expenses[i].category, expenses[i].amount, expenses[i].date);
    }
}

void search_expense() {
    char search_name[50];

    printf("Enter expense name to search: ");
    scanf("%s", search_name);

    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].name, search_name) == 0) {
            printf("\nExpense Name\tExpense Category\tExpense Amount\tExpense Date\n");
            printf("%s\t\t%s\t\t%.2f\t\t%s\n", expenses[i].name, expenses[i].category, expenses[i].amount, expenses[i].date);
        }
    }
}

int main() {
    printf("Welcome to Expense Tracker!\n\n");

    while (1) {
        printf("\nChoose an option:\n");
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
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. ");
        }
    }

    return 0;
}