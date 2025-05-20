//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LEN 50
#define MAX_CATEGORY_LEN 50
#define MAX_DATE_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    char date[MAX_DATE_LEN];
    double amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense() {
    if (num_expenses == MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }

    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);

    printf("Enter expense category: ");
    scanf("%s", expenses[num_expenses].category);

    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%s", expenses[num_expenses].date);

    printf("Enter expense amount: $");
    scanf("%lf", &expenses[num_expenses].amount);

    num_expenses++;
}

void print_expenses() {
    if (num_expenses == 0) {
        printf("No expenses found.\n");
        return;
    }

    printf("\nExpense Report:\n\n");
    printf("Name\tCategory\tDate\tAmount\n");

    for (int i = 0; i < num_expenses; i++) {
        printf("%-20s%-20s%-20s$%.2f\n", expenses[i].name, expenses[i].category, expenses[i].date, expenses[i].amount);
    }
}

void filter_expenses(char *name, char *category, char *date) {
    int filtered_expenses = 0;

    printf("\nFilter Results:\n\n");
    printf("Name\tCategory\tDate\tAmount\n");

    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].name, name) == 0 || strcmp(expenses[i].category, category) == 0 || strcmp(expenses[i].date, date) == 0) {
            printf("%-20s%-20s%-20s$%.2f\n", expenses[i].name, expenses[i].category, expenses[i].date, expenses[i].amount);
            filtered_expenses++;
        }
    }

    if (filtered_expenses == 0) {
        printf("\nNo expenses found.\n");
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n");

    while (1) {
        printf("\nMenu:\n1. Add expense\n2. Print expenses\n3. Filter expenses\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_expense();
            break;
        case 2:
            print_expenses();
            break;
        case 3:
            printf("Enter name to filter by: ");
            char name[MAX_NAME_LEN];
            scanf("%s", name);

            printf("Enter category to filter by: ");
            char category[MAX_CATEGORY_LEN];
            scanf("%s", category);

            printf("Enter date to filter by (YYYY-MM-DD): ");
            char date[MAX_DATE_LEN];
            scanf("%s", date);

            filter_expenses(name, category, date);
            break;
        case 4:
            printf("Exiting program...\n");
            return 0;
        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    }

    return 0;
}