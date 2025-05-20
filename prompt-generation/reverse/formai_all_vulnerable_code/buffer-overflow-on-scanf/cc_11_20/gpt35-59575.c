//FormAI DATASET v1.0 Category: Expense Tracker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100 // limit of expenses
#define MAX_DESCRIPTION_LENGTH 50 // limit of description length

struct Expense {
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
};

int main() {
    struct Expense expenses[MAX_EXPENSES];
    int num_expenses = 0; // number of expenses currently in array

    int choice;
    do {
        printf("Expense Tracker\n"
               "------------------------------------------------\n"
               "1. Add Expense\n"
               "2. Delete Expense\n"
               "3. View Expenses\n"
               "4. Quit\n\n"
               "Enter choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                if (num_expenses >= MAX_EXPENSES) {
                    printf("Error: Maximum number of expenses reached\n\n");
                    break;
                }
                struct Expense new_expense;
                printf("Enter expense description (Max %d characters): ", MAX_DESCRIPTION_LENGTH - 1);
                scanf("%s", new_expense.description);
                
                printf("Enter expense amount: ");
                scanf("%f", &new_expense.amount);
                
                expenses[num_expenses++] = new_expense;
                printf("Expense added successfully\n\n");
                break;
            case 2:
                if (num_expenses == 0) {
                    printf("Error: There are no expenses to delete\n\n");
                    break;
                }
                int expense_index;
                printf("Enter index of expense to delete (0-%d): ", num_expenses - 1);
                scanf("%d", &expense_index);
                if (expense_index < 0 || expense_index >= num_expenses) {
                    printf("Error: Invalid index entered\n\n");
                    break;
                }
                for (int i = expense_index; i < num_expenses - 1; i++) {
                    expenses[i] = expenses[i + 1];
                }
                num_expenses--;
                printf("Expense deleted successfully\n\n");
                break;
            case 3:
                if (num_expenses == 0) {
                    printf("No Expenses Recorded\n\n");
                    break;
                }
                printf("Index  Description           Amount\n");
                printf("------------------------------------\n");
                for (int i = 0; i < num_expenses; i++) {
                    printf("%-6d %-20s %7.2f\n", i, expenses[i].description, expenses[i].amount);
                }
                printf("\n");
                break;
            case 4:
                printf("Exiting program...\n\n");
                break;
            default:
                printf("Invalid choice entered\n\n");
                break;
        }
    } while (choice != 4);

    return 0;
}