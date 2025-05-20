//FormAI DATASET v1.0 Category: Expense Tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Expense {
    int day;
    int month;
    int year;
    char category[20];
    char description[50];
    float amount;
};

void display_expense(struct Expense expense);
void list_expenses(struct Expense expenses[], int num_expenses);
void add_expense(struct Expense expenses[], int *num_expenses);
float calculate_total_expenses(struct Expense expenses[], int num_expenses);

int main() {
    struct Expense expenses[100];
    int num_expenses = 0;
    char action[10];
    while (true) {
        printf("Choose an action (list, add, total, quit): ");
        scanf("%s", action);
        if (strcmp(action, "list") == 0) {
            list_expenses(expenses, num_expenses);
        }
        else if (strcmp(action, "add") == 0) {
            add_expense(expenses, &num_expenses);
        }
        else if (strcmp(action, "total") == 0) {
            float total = calculate_total_expenses(expenses, num_expenses);
            printf("Total expenses: $%.2f\n", total);
        }
        else if (strcmp(action, "quit") == 0) {
            printf("Goodbye!\n");
            break;
        }
        else {
            printf("Invalid action. Please try again.\n");
        }
    }
    return 0;
}

void display_expense(struct Expense expense) {
    printf("%02d/%02d/%d - %s - %s - $%.2f\n", expense.day, expense.month, expense.year, expense.category, expense.description, expense.amount);
}

void list_expenses(struct Expense expenses[], int num_expenses) {
    if (num_expenses == 0) {
        printf("No expenses found.\n");
        return;
    }
    for (int i = 0; i < num_expenses; i++) {
        display_expense(expenses[i]);
    }
}

void add_expense(struct Expense expenses[], int *num_expenses) {
    struct Expense new_expense;
    printf("Enter date (DD MM YYYY): ");
    scanf("%d %d %d", &new_expense.day, &new_expense.month, &new_expense.year);
    printf("Enter category: ");
    scanf("%s", new_expense.category);
    printf("Enter description: ");
    scanf("%s", new_expense.description);
    printf("Enter amount: ");
    scanf("%f", &new_expense.amount);
    expenses[*num_expenses] = new_expense;
    *num_expenses += 1;
    printf("Expense added successfully.\n");
}

float calculate_total_expenses(struct Expense expenses[], int num_expenses) {
    float total = 0;
    for (int i = 0; i < num_expenses; i++) {
        total += expenses[i].amount;
    }
    return total;
}