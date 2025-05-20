//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    char category[50];
} Expense;

void add_expense(Expense *expenses, int *num_expenses) {
    printf("Enter expense name: ");
    scanf("%s", expenses[*num_expenses].name);
    printf("Enter expense amount: $");
    scanf("%f", &expenses[*num_expenses].amount);
    printf("Enter expense category: ");
    scanf("%s", expenses[*num_expenses].category);
    (*num_expenses)++;
}

void display_expenses(Expense *expenses, int num_expenses) {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - $%.2f - %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

void display_categories(char *categories, int num_categories) {
    printf("Categories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s\n", categories[i]);
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    char categories[MAX_CATEGORIES][50];
    int num_categories = 0;

    FILE *fp;
    fp = fopen("categories.txt", "r");
    if (fp == NULL) {
        printf("Error opening categories file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s", categories[num_categories])!= EOF) {
        num_categories++;
    }

    fclose(fp);

    printf("Enter number of expenses: ");
    scanf("%d", &num_expenses);

    for (int i = 0; i < num_expenses; i++) {
        add_expense(expenses, &num_expenses);
    }

    fp = fopen("expenses.txt", "w");
    if (fp == NULL) {
        printf("Error opening expenses file.\n");
        exit(1);
    }

    for (int i = 0; i < num_expenses; i++) {
        fprintf(fp, "%s - $%.2f - %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }

    fclose(fp);

    printf("Expenses saved to expenses.txt.\n");

    return 0;
}