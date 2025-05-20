//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: portable
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

int main() {
    int num_categories, num_expenses;
    char categories[MAX_CATEGORIES][50];
    Expense expenses[MAX_EXPENSES];

    printf("Enter the number of categories: ");
    scanf("%d", &num_categories);

    for (int i = 0; i < num_categories; i++) {
        printf("Enter category #%d: ", i+1);
        scanf("%s", categories[i]);
    }

    printf("Enter the number of expenses: ");
    scanf("%d", &num_expenses);

    for (int i = 0; i < num_expenses; i++) {
        printf("Enter expense #%d:\n", i+1);
        printf("Name: ");
        scanf("%s", expenses[i].name);
        printf("Amount: ");
        scanf("%f", &expenses[i].amount);
        printf("Category: ");
        scanf("%s", expenses[i].category);
    }

    printf("Expenses by category:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("Category: %s\n", categories[i]);
        for (int j = 0; j < num_expenses; j++) {
            if (strcmp(categories[i], expenses[j].category) == 0) {
                printf("Expense: %s - $%.2f\n", expenses[j].name, expenses[j].amount);
            }
        }
    }

    return 0;
}