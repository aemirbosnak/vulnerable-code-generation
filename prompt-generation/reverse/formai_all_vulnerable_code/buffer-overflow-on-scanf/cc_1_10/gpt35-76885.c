//FormAI DATASET v1.0 Category: Expense Tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

struct Expense {
    int id;
    char date[11];
    char item[50];
    float cost;
};

int num_expenses = 0;
struct Expense expenses[MAX_EXPENSES];

void print_menu() {
    printf("\n\nEXPENSE TRACKER\n");
    printf("-------------------------\n");
    printf("1. Add expense\n");
    printf("2. View all expenses\n");
    printf("3. View expenses by date range\n");
    printf("4. View expenses by item name\n");
    printf("5. Exit\n");
    printf("-------------------------\n");
    printf("Enter your choice: ");
}

void add_expense() {
    printf("\nADD NEW EXPENSE\n");
    if (num_expenses == MAX_EXPENSES) {
        printf("Maximum number of expenses reached.\n");
        return;
    }
    struct Expense new_expense;
    printf("Enter date (MM/DD/YYYY): ");
    scanf("%s", new_expense.date);
    printf("Enter item name: ");
    scanf("%s", new_expense.item);
    printf("Enter cost: $");
    scanf("%f", &new_expense.cost);
    new_expense.id = num_expenses + 1;
    expenses[num_expenses] = new_expense;
    num_expenses++;
    printf("New Expense added successfully.\n");
}

void view_all_expenses() {
    printf("\nVIEW ALL EXPENSES\n");
    if (num_expenses == 0) {
        printf("No expenses found.\n");
        return;
    }
    printf("| ID |    DATE    |            ITEM            |   COST   |\n");
    printf("|----------------------------------------------------------|\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("| %2d | %10s | %-25s | $%-7.2f |\n", expenses[i].id, expenses[i].date, expenses[i].item, expenses[i].cost);
    }
}

void view_expenses_by_date_range() {
    printf("\nVIEW EXPENSES BY DATE RANGE\n");
    if (num_expenses == 0) {
        printf("No expenses found.\n");
        return;
    }
    char start_date[11], end_date[11];
    printf("Enter starting date (MM/DD/YYYY): ");
    scanf("%s", start_date);
    printf("Enter ending date (MM/DD/YYYY): ");
    scanf("%s", end_date);
    printf("| ID |    DATE    |            ITEM            |   COST   |\n");
    printf("|----------------------------------------------------------|\n");
    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].date, start_date) >= 0 && strcmp(expenses[i].date, end_date) <= 0) {
            printf("| %2d | %10s | %-25s | $%-7.2f |\n", expenses[i].id, expenses[i].date, expenses[i].item, expenses[i].cost);
        }
    }
}

void view_expenses_by_item_name() {
    printf("\nVIEW EXPENSES BY ITEM NAME\n");
    if (num_expenses == 0) {
        printf("No expenses found.\n");
        return;
    }
    char item_name[50];
    printf("Enter item name: ");
    scanf("%s", item_name);
    printf("| ID |    DATE    |            ITEM            |   COST   |\n");
    printf("|----------------------------------------------------------|\n");
    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].item, item_name) == 0) {
            printf("| %2d | %10s | %-25s | $%-7.2f |\n", expenses[i].id, expenses[i].date, expenses[i].item, expenses[i].cost);
        }
    }
}

int main() {
    int choice = 0;
    while (choice != 5) {
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                view_all_expenses();
                break;
            case 3:
                view_expenses_by_date_range();
                break;
            case 4:
                view_expenses_by_item_name();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}