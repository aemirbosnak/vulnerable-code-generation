//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    char category[50];
    double amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense() {
    printf("Enter name: ");
    scanf("%s", expenses[num_expenses].name);
    printf("Enter category: ");
    scanf("%s", expenses[num_expenses].category);
    printf("Enter amount: ");
    scanf("%lf", &expenses[num_expenses].amount);
    num_expenses++;
}

void display_expenses() {
    printf("\nExpenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - %s - $%.2lf\n", expenses[i].name, expenses[i].category, expenses[i].amount);
    }
}

void display_total_expenses() {
    double total_expenses = 0;
    for (int i = 0; i < num_expenses; i++) {
        total_expenses += expenses[i].amount;
    }
    printf("\nTotal expenses: $%.2lf\n", total_expenses);
}

int main() {
    int choice;
    do {
        printf("\nExpense Tracker\n");
        printf("1. Add expense\n");
        printf("2. Display expenses\n");
        printf("3. Display total expenses\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                display_expenses();
                break;
            case 3:
                display_total_expenses();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}