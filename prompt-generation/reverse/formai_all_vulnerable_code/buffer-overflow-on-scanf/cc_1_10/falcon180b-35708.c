//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 1000
#define MAX_CATEGORIES 50
#define MAX_AMOUNT 9999.99
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
    char category[MAX_NAME_LENGTH];
} expense;

void add_expense(expense *expenses, int *count, char *name, float amount, char *category) {
    int i;
    for (i = 0; i < *count; i++) {
        if (strcmp(expenses[i].name, name) == 0) {
            expenses[i].amount += amount;
            return;
        }
    }
    strcpy(expenses[*count].name, name);
    strcpy(expenses[*count].category, category);
    expenses[*count].amount = amount;
    (*count)++;
}

void print_expenses(expense *expenses, int count) {
    int i;
    printf("Expense Report\n");
    printf("=================\n");
    printf("Expense\tCategory\tAmount\n");
    for (i = 0; i < count; i++) {
        printf("%s\t%s\t%.2f\n", expenses[i].name, expenses[i].category, expenses[i].amount);
    }
    printf("\n");
}

int main() {
    expense expenses[MAX_EXPENSES];
    int count = 0;
    char name[MAX_NAME_LENGTH];
    float amount;
    char category[MAX_NAME_LENGTH];

    printf("Welcome to the Expense Tracker!\n");
    while (1) {
        printf("Enter your name: ");
        scanf("%s", name);
        if (strcmp(name, "exit") == 0) {
            break;
        }
        printf("Enter expense amount: ");
        scanf("%f", &amount);
        printf("Enter expense category: ");
        scanf("%s", category);
        add_expense(expenses, &count, name, amount, category);
    }
    print_expenses(expenses, count);

    return 0;
}