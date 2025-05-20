//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Finance {
    char name[50];
    double amount;
};

void add_expense(struct Finance *finance, int num_expenses) {
    printf("Enter expense name: ");
    scanf("%s", finance[num_expenses].name);

    printf("Enter expense amount: ");
    scanf("%lf", &finance[num_expenses].amount);

    printf("Expense added!\n");
}

void display_expenses(struct Finance *finance, int num_expenses) {
    printf("******EXPENSES******\n");

    for (int i = 0; i < num_expenses; i++) {
        printf("%s: $%.2f\n", finance[i].name, finance[i].amount);
    }

    printf("\n");
}

void calculate_total(struct Finance *finance, int num_expenses) {
    double total = 0;

    for (int i = 0; i < num_expenses; i++) {
        total += finance[i].amount;
    }

    printf("Total expenses: $%.2f\n", total);
}

int main() {
    int num_expenses = 0;
    struct Finance *expenses = malloc(sizeof(struct Finance));

    char choice = '0';

    while (choice != '4') {
        printf("Please pick an option:\n1. Add expense\n2. Display expenses\n3. Calculate total\n4. Exit\n");

        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                expenses = realloc(expenses, sizeof(struct Finance) * (num_expenses + 1));
                add_expense(expenses, num_expenses);
                num_expenses++;
                break;
            case '2':
                display_expenses(expenses, num_expenses);
                break;
            case '3':
                calculate_total(expenses, num_expenses);
                break;
            case '4':
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    printf("Goodbye!\n");
    free(expenses);
    return 0;
}