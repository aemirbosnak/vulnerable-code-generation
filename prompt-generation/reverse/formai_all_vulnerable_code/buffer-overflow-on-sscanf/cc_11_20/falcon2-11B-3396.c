//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    double amount;
    int category;
} expense_record;

int main() {
    expense_record expenses[100];
    int n_expenses = 0;
    char input[100];
    int choice;

    printf("Welcome to the Expense Tracker!\n");
    printf("Please enter your name: ");
    fgets(expenses[n_expenses].name, sizeof(expenses[n_expenses].name), stdin);
    expenses[n_expenses].amount = 0.0;
    expenses[n_expenses].category = 0;
    n_expenses++;

    while (1) {
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Edit Expense\n");
        printf("4. Delete Expense\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter expense name: ");
                fgets(expenses[n_expenses].name, sizeof(expenses[n_expenses].name), stdin);
                printf("Enter expense amount: ");
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%lf", &expenses[n_expenses].amount);
                printf("Enter expense category (1-5): ");
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%d", &expenses[n_expenses].category);
                n_expenses++;
                break;
            case 2:
                printf("Expenses:\n");
                for (int i = 0; i < n_expenses; i++) {
                    printf("%s: %lf, %d\n", expenses[i].name, expenses[i].amount, expenses[i].category);
                }
                break;
            case 3:
                printf("Enter expense name to edit: ");
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%s", expenses[n_expenses].name);
                printf("Enter new expense name: ");
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%s", expenses[n_expenses].name);
                printf("Enter new expense amount: ");
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%lf", &expenses[n_expenses].amount);
                printf("Enter new expense category (1-5): ");
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%d", &expenses[n_expenses].category);
                break;
            case 4:
                printf("Enter expense name to delete: ");
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%s", expenses[n_expenses].name);
                for (int i = n_expenses - 1; i >= 0; i--) {
                    if (strcmp(expenses[i].name, input) == 0) {
                        for (int j = i; j < n_expenses - 1; j++) {
                            expenses[j] = expenses[j + 1];
                        }
                        n_expenses--;
                        break;
                    }
                }
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}