//FormAI DATASET v1.0 Category: Expense Tracker ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

struct expense {
    char category[20];
    float amount;
};

int main() {
    struct expense expenses[MAX_EXPENSES];
    int count = 0;
    float total_expense = 0;

    // Display menu
    printf("Expense Tracker\n");
    printf("================\n");
    printf("1. Add expense\n");
    printf("2. View expenses\n");
    printf("3. Exit\n");

    while (1) {
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count >= MAX_EXPENSES) {
                    printf("Error: Maximum number of expenses reached\n");
                    break;
                }

                // Add expense
                printf("Enter category: ");
                scanf("%s", expenses[count].category);
                
                printf("Enter amount: ");
                scanf("%f", &expenses[count].amount);
                total_expense += expenses[count].amount;

                count++;
                printf("Expense added successfully\n");
                break;

            case 2:
                if (count == 0) {
                    printf("No expenses to show\n");
                    break;
                }

                // Display expenses
                printf("%-20s%-10s\n", "Category", "Amount");
                printf("--------------------------------------\n");
                for (int i = 0; i < count; i++) {
                    printf("%-20s$%-10.2f\n", expenses[i].category, expenses[i].amount);
                }
                printf("--------------------------------------\n");
                printf("Total expense: $%.2f\n", total_expense);
                break;

            case 3:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}