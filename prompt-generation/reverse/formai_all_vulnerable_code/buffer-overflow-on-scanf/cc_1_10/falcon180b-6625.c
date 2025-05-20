//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    char category[50];
} expense;

void add_expense(expense *expenses, int *num_expenses, char *name, float amount, char *category) {
    if (*num_expenses >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }
    strcpy(expenses[*num_expenses].name, name);
    expenses[*num_expenses].amount = amount;
    strcpy(expenses[*num_expenses].category, category);
    (*num_expenses)++;
}

void display_expenses(expense *expenses, int num_expenses) {
    printf("Expense Report:\n");
    printf("-----------------------------------------------------\n");
    printf("Name                 Amount           Category\n");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%-20s $%-10.2f %-20s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

void calculate_total_expenses(expense *expenses, int num_expenses, char *category, float *total) {
    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].category, category) == 0) {
            *total += expenses[i].amount;
        }
    }
}

int main() {
    expense expenses[MAX_EXPENSES];
    int num_expenses = 0;
    char name[50];
    float amount;
    char category[50];
    int choice;
    float total_expenses = 0;

    do {
        printf("Enter 1 to add an expense\n");
        printf("Enter 2 to display expenses\n");
        printf("Enter 3 to calculate total expenses\n");
        printf("Enter 4 to exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter amount: ");
            scanf("%f", &amount);
            printf("Enter category: ");
            scanf("%s", category);
            add_expense(expenses, &num_expenses, name, amount, category);
            break;
        case 2:
            display_expenses(expenses, num_expenses);
            break;
        case 3:
            printf("Enter category: ");
            scanf("%s", category);
            calculate_total_expenses(expenses, num_expenses, category, &total_expenses);
            printf("Total expenses for %s: $%.2f\n", category, total_expenses);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}