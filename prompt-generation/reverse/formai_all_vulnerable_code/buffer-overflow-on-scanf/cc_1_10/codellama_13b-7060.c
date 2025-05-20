//Code Llama-13B DATASET v1.0 Category: Expense Tracker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char name[256];
    float amount;
    char date[16];
};

void add_expense(struct expense *expenses, int *num_expenses) {
    printf("Enter name of expense: ");
    scanf("%s", expenses[*num_expenses].name);
    printf("Enter amount: ");
    scanf("%f", &expenses[*num_expenses].amount);
    printf("Enter date: ");
    scanf("%s", expenses[*num_expenses].date);
    *num_expenses += 1;
}

void view_expenses(struct expense *expenses, int num_expenses) {
    for (int i = 0; i < num_expenses; i++) {
        printf("Name: %s\n", expenses[i].name);
        printf("Amount: %.2f\n", expenses[i].amount);
        printf("Date: %s\n", expenses[i].date);
        printf("\n");
    }
}

int main() {
    struct expense expenses[100];
    int num_expenses = 0;

    while (1) {
        printf("Enter 1 to add an expense, 2 to view expenses, 3 to exit: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add_expense(expenses, &num_expenses);
            break;
        case 2:
            view_expenses(expenses, num_expenses);
            break;
        case 3:
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }

    return 0;
}