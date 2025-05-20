//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char category[50];
    char description[100];
    float amount;
    time_t date;
} Expense;

void add_expense(Expense* expenses, int num_expenses, char category[50], char description[100], float amount) {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }
    strcpy(expenses[num_expenses].category, category);
    strcpy(expenses[num_expenses].description, description);
    expenses[num_expenses].amount = amount;
    time(&expenses[num_expenses].date);
    num_expenses++;
}

void display_expenses(Expense* expenses, int num_expenses) {
    printf("Category\tDescription\tAmount\tDate\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t%s\t%.2f\t%s", expenses[i].category, expenses[i].description, expenses[i].amount, ctime(&expenses[i].date));
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int num_expenses = 0;
    char category[50];
    char description[100];
    float amount;

    while (1) {
        printf("Enter expense category: ");
        scanf("%s", category);
        if (strcmp(category, "quit") == 0) {
            break;
        }
        printf("Enter expense description: ");
        scanf("%s", description);
        printf("Enter expense amount: ");
        scanf("%f", &amount);
        add_expense(expenses, num_expenses, category, description, amount);
    }

    printf("\nExpenses:\n");
    display_expenses(expenses, num_expenses);

    return 0;
}