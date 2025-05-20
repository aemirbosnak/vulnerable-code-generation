//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses;

void add_expense() {
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);
    printf("Enter expense amount: $");
    scanf("%f", &expenses[num_expenses].amount);
    num_expenses++;
}

void display_expenses() {
    printf("\nExpenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - $%.2f\n", expenses[i].name, expenses[i].amount);
    }
}

void calculate_total_expenses() {
    float total_expenses = 0;
    for (int i = 0; i < num_expenses; i++) {
        total_expenses += expenses[i].amount;
    }
    printf("\nTotal expenses: $%.2f\n", total_expenses);
}

int main() {
    printf("Welcome to the Personal Finance Planner!\n");
    printf("Please enter your name: ");
    char name[50];
    scanf("%s", name);
    printf("\nHello, %s! Let's get started.\n", name);

    int choice;
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Add an expense\n");
        printf("2. Display expenses\n");
        printf("3. Calculate total expenses\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                display_expenses();
                break;
            case 3:
                calculate_total_expenses();
                break;
            case 4:
                printf("\nThank you for using the Personal Finance Planner, %s!\n", name);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 4);

    return 0;
}