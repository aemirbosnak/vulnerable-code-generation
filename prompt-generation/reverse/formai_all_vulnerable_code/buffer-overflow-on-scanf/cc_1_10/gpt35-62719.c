//FormAI DATASET v1.0 Category: Expense Tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct expense {
    int day;
    int month;
    int year;
    char category[20];
    double amount;
};

struct expense expenses[MAX_ITEMS];
int count = 0;

void add_expense() {
    if (count >= MAX_ITEMS) {
        printf("Maximum limit of expenses reached.\n");
        return;
    }

    struct expense e;

    printf("Enter expense details:\n");
    printf("Day: ");
    scanf("%d", &e.day);

    printf("Month: ");
    scanf("%d", &e.month);

    printf("Year: ");
    scanf("%d", &e.year);

    printf("Category: ");
    scanf("%s", e.category);

    printf("Amount: ");
    scanf("%lf", &e.amount);

    expenses[count] = e;
    count++;

    printf("Expense added successfully.\n");
}

void display_expenses() {
    printf("Expenses:\n");

    for (int i = 0; i < count; i++) {
        struct expense e = expenses[i];
        printf("%d/%d/%d - %s - $%.2f\n", e.day, e.month, e.year, e.category, e.amount);
    }
}

void display_total_expenses() {
    double total = 0;

    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }

    printf("Total expenses: $%.2f\n", total);
}

void display_expenses_by_category(char *category) {
    double total = 0;

    printf("Expenses for %s:\n", category);

    for (int i = 0; i < count; i++) {
        if (strcmp(expenses[i].category, category) == 0) {
            struct expense e = expenses[i];
            printf("%d/%d/%d - $%.2f\n", e.day, e.month, e.year, e.amount);
            total += e.amount;
        }
    }

    printf("Total expenses for %s: $%.2f\n", category, total);
}

int main() {
    int choice;

    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. Display All Expenses\n");
        printf("3. Display Total Expenses\n");
        printf("4. Display Expenses by Category\n");
        printf("5. Quit\n");

        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;

            case 2:
                display_expenses();
                break;

            case 3:
                display_total_expenses();
                break;

            case 4: {
                char category[20];
                printf("Enter category name: ");
                scanf("%s", category);
                display_expenses_by_category(category);
                break;
            }

            case 5:
                printf("Thank you for using Expense Tracker!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}