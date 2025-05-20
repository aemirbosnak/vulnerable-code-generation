//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    char category[50];
    double amount;
    int date;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense() {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Sorry, you cannot add more expenses.\n");
        return;
    }

    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);

    printf("Enter expense category: ");
    scanf("%s", expenses[num_expenses].category);

    printf("Enter expense amount: ");
    scanf("%lf", &expenses[num_expenses].amount);

    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%d", &expenses[num_expenses].date);

    num_expenses++;
}

void view_expenses() {
    if (num_expenses == 0) {
        printf("You have no expenses.\n");
        return;
    }

    for (int i = 0; i < num_expenses; i++) {
        printf("%s (%s) - $%.2f on %d\n", expenses[i].name, expenses[i].category, expenses[i].amount, expenses[i].date);
    }
}

void delete_expense() {
    if (num_expenses == 0) {
        printf("You have no expenses.\n");
        return;
    }

    int id;
    printf("Enter expense ID: ");
    scanf("%d", &id);

    for (int i = 0; i < num_expenses; i++) {
        if (expenses[i].date == id) {
            memmove(&expenses[i], &expenses[i+1], sizeof(Expense) * (num_expenses - i - 1));
            num_expenses--;
            break;
        }
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n");

    int choice;
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Delete expense\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                view_expenses();
                break;
            case 3:
                delete_expense();
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}