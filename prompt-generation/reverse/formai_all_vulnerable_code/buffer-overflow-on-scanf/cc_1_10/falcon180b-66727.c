//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50
#define MAX_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
    char category[MAX_NAME_LENGTH];
} Expense;

int main() {
    int num_categories, num_expenses;
    char categories[MAX_CATEGORIES][MAX_NAME_LENGTH];
    Expense expenses[MAX_EXPENSES];

    printf("Welcome to the Expense Tracker!\n");
    printf("Please enter the number of categories you would like to use: ");
    scanf("%d", &num_categories);

    for (int i = 0; i < num_categories; i++) {
        printf("Category %d name: ", i + 1);
        scanf("%s", categories[i]);
    }

    printf("\nPlease enter the number of expenses you would like to add: ");
    scanf("%d", &num_expenses);

    for (int i = 0; i < num_expenses; i++) {
        printf("\nExpense %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", expenses[i].name);
        printf("Amount: ");
        scanf("%f", &expenses[i].amount);
        printf("Category: ");
        scanf("%s", expenses[i].category);
    }

    printf("\nExpenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("Name: %s\n", expenses[i].name);
        printf("Amount: $%.2f\n", expenses[i].amount);
        printf("Category: %s\n\n", expenses[i].category);
    }

    return 0;
}