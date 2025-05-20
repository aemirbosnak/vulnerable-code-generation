//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct expense {
    char name[50];
    float amount;
    char category[20];
} Expense;

int main() {
    int choice, num_expenses = 0;
    Expense *expenses = NULL;
    float total_spent = 0;

    printf("===== Expense Tracker =====\n");

    do {
        printf("\nOPTIONS:\n");
        printf("1. Add an expense\n");
        printf("2. View expenses\n");
        printf("3. View expenses by category\n");
        printf("4. Quit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add an expense
                num_expenses++;
                expenses = realloc(expenses, num_expenses * sizeof(Expense));

                printf("\nEnter expense name: ");
                scanf("%s", expenses[num_expenses-1].name);

                printf("Enter amount spent: $");
                scanf("%f", &expenses[num_expenses-1].amount);
                total_spent += expenses[num_expenses-1].amount;

                printf("Enter category (Food, Rent, Utilities, Entertainment): ");
                scanf("%s", expenses[num_expenses-1].category);

                printf("\nExpense added successfully!\n");
                break;

            case 2: // View all expenses
                if (num_expenses == 0) {
                    printf("\nNo expenses added yet!\n");
                } else {
                    printf("\nAll expenses:\n\n");
                    for (int i = 0; i < num_expenses; i++) {
                        printf("%s $%.2f %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
                    }
                    printf("\nTotal amount spent: $%.2f\n", total_spent);
                }
                break;

            case 3: // View expenses by category
                if (num_expenses == 0) {
                    printf("\nNo expenses added yet!\n");
                } else {
                    char category[20];
                    printf("\nEnter category name: ");
                    scanf("%s", category);

                    printf("\nExpenses in %s category:\n\n", category);
                    for (int i = 0; i < num_expenses; i++) {
                        if (strcmp(expenses[i].category, category) == 0) {
                            printf("%s $%.2f %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
                        }
                    }
                    printf("\n");
                }
                break;

            case 4: // Quit
                printf("\nThank you for using Expense Tracker!\n");
                break;

            default: // Invalid choice
                printf("\nInvalid choice! Please try again.\n");
                break;
        }

    } while (choice != 4);

    free(expenses);
    return 0;
}