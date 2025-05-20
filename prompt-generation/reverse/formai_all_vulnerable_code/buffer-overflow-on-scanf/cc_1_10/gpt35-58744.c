//FormAI DATASET v1.0 Category: Expense Tracker ; Style: invasive
#include <stdio.h>

void add_expense(float *total, float expense) {
    *total += expense;
}

int main() {
    float total_expenses = 0.0;
    int choice = 0;

    while (choice != 4) {
        printf("\n");
        printf("1. Add Expense\n");
        printf("2. View Total Expenses\n");
        printf("3. Delete All Expenses\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                float expense;
                printf("Enter expense amount: ");
                scanf("%f", &expense);
                add_expense(&total_expenses, expense);
                printf("Expense added successfully!\n");
                break;
            }

            case 2: {
                printf("Total expenses: $%.2f\n", total_expenses);
                break;
            }

            case 3: {
                total_expenses = 0;
                printf("All expenses deleted successfully!\n");
                break;
            }

            case 4: {
                printf("Thank you for using the Expense Tracker.\n");
                break;
            }

            default: {
                printf("Invalid choice. Please choose again.\n");
                break;
            }
        }
    }

    return 0;
}