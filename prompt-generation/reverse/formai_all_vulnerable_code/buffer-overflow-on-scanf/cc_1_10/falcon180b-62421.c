//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LEN 50
#define MAX_CATEGORY_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    float amount;
    int date;
    int month;
    int year;
} Expense;

void add_expense(Expense* expenses, int num_expenses) {
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);
    printf("Enter expense category: ");
    scanf("%s", expenses[num_expenses].category);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);
    printf("Enter expense date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &expenses[num_expenses].date, &expenses[num_expenses].month, &expenses[num_expenses].year);
}

void display_expenses(Expense* expenses, int num_expenses) {
    printf("\nExpense Report\n");
    printf("--------------------\n");
    printf("Name       | Category   | Amount  | Date\n");
    printf("--------------------\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%-20s", expenses[i].name);
        printf("%-20s", expenses[i].category);
        printf("%-10.2f", expenses[i].amount);
        printf("%-10d/%d/%d\n", expenses[i].date, expenses[i].month, expenses[i].year);
    }
}

void search_expense(Expense* expenses, int num_expenses, char* name) {
    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].name, name) == 0) {
            printf("\nExpense Found:\n");
            printf("Name: %s\n", expenses[i].name);
            printf("Category: %s\n", expenses[i].category);
            printf("Amount: %.2f\n", expenses[i].amount);
            printf("Date: %d/%d/%d\n", expenses[i].date, expenses[i].month, expenses[i].year);
        }
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int num_expenses = 0;
    char choice;
    do {
        printf("\nExpense Tracker\n");
        printf("--------------------\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Search Expense\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                if (num_expenses >= MAX_EXPENSES) {
                    printf("Cannot add more expenses. Limit reached.\n");
                } else {
                    add_expense(expenses, num_expenses);
                    num_expenses++;
                }
                break;
            case '2':
                display_expenses(expenses, num_expenses);
                break;
            case '3':
                printf("Enter expense name to search: ");
                char name[MAX_NAME_LEN];
                scanf("%s", name);
                search_expense(expenses, num_expenses, name);
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= '4');
    return 0;
}