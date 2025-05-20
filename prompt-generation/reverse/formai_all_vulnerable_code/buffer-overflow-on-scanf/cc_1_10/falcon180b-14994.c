//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    int date;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense() {
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);

    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);

    printf("Enter expense date (yyyy-mm-dd): ");
    scanf("%d", &expenses[num_expenses].date);

    num_expenses++;
}

void display_expenses() {
    printf("\nExpenses:\n");
    printf("Name\tAmount\tDate\n");

    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t%.2f\t%d\n", expenses[i].name, expenses[i].amount, expenses[i].date);
    }
}

void sort_expenses_by_date() {
    for (int i = 0; i < num_expenses - 1; i++) {
        for (int j = i + 1; j < num_expenses; j++) {
            if (expenses[i].date > expenses[j].date) {
                Expense temp = expenses[i];
                expenses[i] = expenses[j];
                expenses[j] = temp;
            }
        }
    }
}

void sort_expenses_by_amount() {
    for (int i = 0; i < num_expenses - 1; i++) {
        for (int j = i + 1; j < num_expenses; j++) {
            if (expenses[i].amount > expenses[j].amount) {
                Expense temp = expenses[i];
                expenses[i] = expenses[j];
                expenses[j] = temp;
            }
        }
    }
}

int main() {
    int choice;

    do {
        printf("\nExpense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Sort by Date\n");
        printf("4. Sort by Amount\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_expense();
            break;
        case 2:
            display_expenses();
            break;
        case 3:
            sort_expenses_by_date();
            display_expenses();
            break;
        case 4:
            sort_expenses_by_amount();
            display_expenses();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 5);

    return 0;
}