//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPENSES 1000

typedef struct {
    char name[50];
    double amount;
    char category[50];
} Expense;

void addExpense(Expense expenses[], int count, char* name, double amount, char* category) {
    if (count >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }
    strcpy(expenses[count].name, name);
    expenses[count].amount = amount;
    strcpy(expenses[count].category, category);
    count++;
}

void displayExpenses(Expense expenses[], int count) {
    printf("Expenses:\n");
    for (int i = 0; i < count; i++) {
        printf("%s - $%.2f - %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;
    char name[50];
    double amount;
    char category[50];

    printf("Welcome to the Personal Finance Planner!\n\n");

    while (1) {
        printf("Enter an expense:\n");
        printf("Name: ");
        scanf("%s", name);
        printf("Amount: $");
        scanf("%lf", &amount);
        printf("Category: ");
        scanf("%s", category);
        addExpense(expenses, count, name, amount, category);
        printf("\nExpense added successfully.\n");

        char choice;
        printf("Do you want to add another expense? (y/n): ");
        scanf(" %c", &choice);
        if (tolower(choice) == 'n') {
            break;
        }
    }

    displayExpenses(expenses, count);

    return 0;
}