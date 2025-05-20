//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 1000

struct Expense {
    int id;
    char name[20];
    float amount;
    char category[20];
    char date[11];
};

struct Expense expenses[MAX_EXPENSES];
int expense_count = 0;

void add_expense() {
    printf("Enter expense name: ");
    scanf("%s", expenses[expense_count].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[expense_count].amount);
    printf("Enter expense category: ");
    scanf("%s", expenses[expense_count].category);
    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%s", expenses[expense_count].date);
    expenses[expense_count].id = expense_count;
    expense_count++;
    printf("Expense added successfully!\n");
}

void print_expenses() {
    printf("ID\tName\tAmount\tCategory\tDate\n");
    for (int i = 0; i < expense_count; i++) {
        printf("%d\t%s\t%.2f\t%s\t%s\n", expenses[i].id, expenses[i].name, expenses[i].amount, expenses[i].category, expenses[i].date);
    }
}

void search_expense() {
    char category[20];
    printf("Enter expense category to search: ");
    scanf("%s", category);
    printf("ID\tName\tAmount\tCategory\tDate\n");
    for (int i = 0; i < expense_count; i++) {
        if (strcmp(expenses[i].category, category) == 0) {
            printf("%d\t%s\t%.2f\t%s\t%s\n", expenses[i].id, expenses[i].name, expenses[i].amount, expenses[i].category, expenses[i].date);
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add expense\n");
        printf("2. Print all expenses\n");
        printf("3. Search expense by category\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                print_expenses();
                break;
            case 3:
                search_expense();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}