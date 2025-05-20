//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 50
#define MAX_NAME_LENGTH 50
#define MAX_CATEGORY_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense(char *name, char *category, float amount) {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Expense tracker is full.\n");
        return;
    }

    strcpy(expenses[num_expenses].name, name);
    strcpy(expenses[num_expenses].category, category);
    expenses[num_expenses].amount = amount;
    num_expenses++;
}

void print_expenses() {
    printf("\nCurrent Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%d. %s (%s) - $%.2f\n", i + 1, expenses[i].name, expenses[i].category, expenses[i].amount);
    }
}

int main() {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    float amount;
    int choice;

    while (1) {
        printf("\nExpense Tracker Menu:\n");
        printf("1. Add Expense\n");
        printf("2. Print Expenses\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Expense Name: ");
                scanf("%s", name);
                printf("Enter Expense Category: ");
                scanf("%s", category);
                printf("Enter Expense Amount: $");
                scanf("%f", &amount);
                add_expense(name, category, amount);
                break;

            case 2:
                print_expenses();
                break;

            case 3:
                printf("Exiting Expense Tracker...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}