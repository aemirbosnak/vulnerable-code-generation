//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    double amount;
} Expense;

void add_expense(Expense* expenses, int num_expenses, int num_fields) {
    int i;
    for (i = 0; i < num_expenses; i++) {
        printf("Enter expense name: ");
        fgets(expenses[i].name, sizeof(expenses[i].name), stdin);
        printf("Enter expense amount: ");
        scanf("%lf", &expenses[i].amount);
    }
}

void display_expenses(Expense* expenses, int num_expenses) {
    int i;
    for (i = 0; i < num_expenses; i++) {
        printf("%s: $%.2lf\n", expenses[i].name, expenses[i].amount);
    }
}

int main() {
    Expense expenses[100];
    int num_expenses = 0;

    printf("Welcome to the Expense Tracker!\n");
    while (1) {
        printf("1. Add expense\n2. Display expenses\n3. Quit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_expense(expenses, num_expenses, 2);
                break;
            case 2:
                display_expenses(expenses, num_expenses);
                break;
            case 3:
                printf("Bye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}