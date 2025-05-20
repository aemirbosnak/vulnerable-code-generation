//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: minimalist
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
int current_expense = 0;

void add_expense(char name[], char category[], float amount) {
    if (current_expense >= MAX_EXPENSES) {
        printf("Error: Cannot add expense, array is full.\n");
        return;
    }
    strcpy(expenses[current_expense].name, name);
    strcpy(expenses[current_expense].category, category);
    expenses[current_expense++].amount = amount;
}

void print_expenses() {
    if (current_expense == 0) {
        printf("No expenses to display.\n");
        return;
    }
    printf("\nExpenses:\n");
    for (int i = 0; i < current_expense; i++) {
        printf("%d. %s - %s: %.2f\n", i+1, expenses[i].name, expenses[i].category, expenses[i].amount);
    }
}

int main() {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    float amount;

    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. Print Expenses\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter category: ");
                scanf("%s", category);
                printf("Enter amount: ");
                scanf("%f", &amount);
                add_expense(name, category, amount);
                break;
            case 2:
                print_expenses();
                break;
            case 3:
                printf("Quitting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}