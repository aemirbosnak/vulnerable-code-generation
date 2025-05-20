//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_CATEGORY_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    float cost;
} Expense;

void addExpense(Expense expenses[], int count) {
    printf("Enter expense name: ");
    scanf("%s", expenses[count].name);

    printf("Enter expense category: ");
    scanf("%s", expenses[count].category);

    printf("Enter expense cost: ");
    scanf("%f", &expenses[count].cost);

    count++;
}

void printExpenses(Expense expenses[], int count) {
    printf("\nExpenses:\n");
    printf("------------------------\n");
    printf("Name\t\tCategory\t\tCost\n");
    printf("------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%s\t\t%s\t\t%.2f\n", expenses[i].name, expenses[i].category, expenses[i].cost);
    }
}

void searchExpense(Expense expenses[], int count, char search[MAX_NAME_LENGTH]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(expenses[i].name, search) == 0) {
            printf("\nExpense found:\n");
            printf("Name: %s\n", expenses[i].name);
            printf("Category: %s\n", expenses[i].category);
            printf("Cost: %.2f\n", expenses[i].cost);
            break;
        }
    }
}

int main() {
    Expense expenses[MAX_ITEMS];
    int count = 0;

    while (count < MAX_ITEMS) {
        printf("\nEnter expense details:\n");

        addExpense(expenses, count);
        count++;
    }

    printf("\nExpenses added successfully!\n");

    printExpenses(expenses, count);

    char search[MAX_NAME_LENGTH];
    printf("\nEnter expense name to search: ");
    scanf("%s", search);

    searchExpense(expenses, count, search);

    return 0;
}