//FormAI DATASET v1.0 Category: Expense Tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

struct expense {
    char item[50];
    float cost;
};

void add_expense(int *num_expenses, struct expense expenses[]) {
    char item[50];
    float cost;

    printf("\nEnter item name: ");
    scanf("%s", item);

    printf("Enter cost: ");
    scanf("%f", &cost);

    struct expense new_expense = {item, cost};
    expenses[*num_expenses] = new_expense;
    *num_expenses = *num_expenses + 1;

    printf("Expense added successfully.\n");
}

void view_expense(int num_expenses, struct expense expenses[]) {
    if (num_expenses == 0) {
        printf("There are no expenses to view.\n");
        return;
    }

    printf("\nItem\tCost\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t%.2f\n", expenses[i].item, expenses[i].cost);
    }
}

float calculate_total(int num_expenses, struct expense expenses[]) {
    float total = 0.0;
    for (int i = 0; i < num_expenses; i++) {
        total = total + expenses[i].cost;
    }

    return total;
}

void remove_expense(int *num_expenses, struct expense expenses[]) {
    if (*num_expenses == 0) {
        printf("There are no expenses to remove.\n");
        return;
    }

    char item_to_remove[50];
    printf("\nEnter item name to remove: ");
    scanf("%s", item_to_remove);

    for (int i = 0; i < *num_expenses; i++) {
        if (strcmp(expenses[i].item, item_to_remove) == 0) {
            for (int j = i; j < *num_expenses - 1; j++) {
                expenses[j] = expenses[j+1];
            }

            *num_expenses = *num_expenses - 1;
            printf("Expense removed successfully.\n");
            return;
        }
    }

    printf("Could not find expense with item name '%s'.\n", item_to_remove);
}

int main() {
    int choice;
    int num_expenses = 0;
    struct expense expenses[100];

    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. View Total\n");
        printf("4. Remove Expense\n");
        printf("5. Quit\n");
        printf("Enter choice (1-5): ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense(&num_expenses, expenses);
                break;
            case 2:
                view_expense(num_expenses, expenses);
                break;
            case 3:
                printf("\nTotal Expenses: $%.2f\n", calculate_total(num_expenses, expenses));
                break;
            case 4:
                remove_expense(&num_expenses, expenses);
                break;
            case 5:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}