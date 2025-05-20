//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    char category[50];
} expense;

void add_expense(expense expenses[], int *count) {
    printf("Enter expense name: ");
    scanf("%s", expenses[*count].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[*count].amount);
    printf("Enter expense category: ");
    scanf("%s", expenses[*count].category);
    (*count)++;
}

void display_expenses(expense expenses[], int count) {
    printf("\nExpenses:\n");
    for (int i = 0; i < count; i++) {
        printf("%s - %.2f - %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

void search_expense(expense expenses[], int count, char search_name[]) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(expenses[i].name, search_name) == 0) {
            printf("\n%s - %.2f - %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
            found = 1;
        }
    }
    if (found == 0) {
        printf("Expense not found.\n");
    }
}

int main() {
    expense expenses[MAX_EXPENSES];
    int count = 0;

    printf("Welcome to the Expense Tracker!\n");

    while (count < MAX_EXPENSES) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add expense\n");
        printf("2. Display expenses\n");
        printf("3. Search expense\n");
        printf("4. Exit\n");
        scanf("%d", &count);

        switch (count) {
            case 1:
                add_expense(expenses, &count);
                break;
            case 2:
                display_expenses(expenses, count);
                break;
            case 3:
                printf("Enter expense name to search: ");
                char search_name[50];
                scanf("%s", search_name);
                search_expense(expenses, count, search_name);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}