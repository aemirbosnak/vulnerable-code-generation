//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50
#define MAX_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char amount[MAX_AMOUNT_LENGTH];
} expense;

expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense() {
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);

    printf("Enter expense amount: ");
    scanf("%s", expenses[num_expenses].amount);

    num_expenses++;
}

void display_expenses() {
    printf("\nExpenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%d. %s: $%s\n", i+1, expenses[i].name, expenses[i].amount);
    }
}

void delete_expense() {
    int index;
    printf("Enter expense index to delete: ");
    scanf("%d", &index);

    if (index >= 0 && index < num_expenses) {
        for (int i = index; i < num_expenses-1; i++) {
            strcpy(expenses[i].name, expenses[i+1].name);
            strcpy(expenses[i].amount, expenses[i+1].amount);
        }
        num_expenses--;
    } else {
        printf("Invalid expense index.\n");
    }
}

void calculate_total_expenses() {
    float total_expenses = 0.0;
    for (int i = 0; i < num_expenses; i++) {
        total_expenses += atof(expenses[i].amount);
    }
    printf("\nTotal expenses: $%.2f\n", total_expenses);
}

int main() {
    int choice;

    do {
        printf("\nExpense Tracker\n");
        printf("1. Add expense\n");
        printf("2. Display expenses\n");
        printf("3. Delete expense\n");
        printf("4. Calculate total expenses\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                display_expenses();
                break;
            case 3:
                delete_expense();
                break;
            case 4:
                calculate_total_expenses();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}