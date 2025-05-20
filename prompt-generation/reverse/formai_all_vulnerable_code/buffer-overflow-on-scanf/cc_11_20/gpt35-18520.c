//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct {
    char name[50];
    double amount;
} Expense;

int main() {
    int num_expenses = 0;
    int choice = 0;

    Expense expenses[MAX_ITEMS];
    double total_expenses = 0.0;
    double monthly_income = 0.0;
    double monthly_savings = 0.0;

    printf("Welcome to the Personal Finance Planner!\n\n");

    while (choice != 4) {

        printf("What would you like to do?\n");
        printf("1. Add an expense\n");
        printf("2. Remove an expense\n");
        printf("3. View expenses\n");
        printf("4. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                if (num_expenses < MAX_ITEMS) {
                    printf("Enter name of expense: ");
                    scanf("%s", expenses[num_expenses].name);

                    printf("Enter amount of expense: ");
                    scanf("%lf", &expenses[num_expenses].amount);

                    total_expenses += expenses[num_expenses].amount;
                    num_expenses++;

                    printf("Expense added successfully!\n\n");
                } else {
                    printf("You have reached the maximum number of expenses!\n\n");
                }
                break;
            case 2:
                if (num_expenses > 0) {
                    int i;
                    printf("Which expense would you like to remove? (enter index)\n");

                    for (i = 0; i < num_expenses; i++) {
                        printf("%d. %s ($%.2lf)\n", i, expenses[i].name, expenses[i].amount);
                    }

                    int expense_to_remove;
                    scanf("%d", &expense_to_remove);
                    
                    if (expense_to_remove >= 0 && expense_to_remove < num_expenses) {
                        total_expenses -= expenses[expense_to_remove].amount;

                        for (i = expense_to_remove; i < num_expenses - 1; i++) {
                            expenses[i] = expenses[i + 1];
                        }

                        num_expenses--;

                        printf("Expense removed successfully!\n\n");
                    } else {
                        printf("Invalid input! Please choose again.\n\n");
                    }
                } else {
                    printf("There are no expenses to remove!\n\n");
                }
                break;
            case 3:
                printf("Expenses:\n");

                if (num_expenses == 0) {
                    printf("No expenses have been added yet.\n");
                } else {
                    int i;

                    for (i = 0; i < num_expenses; i++) {
                        printf("%d. %s ($%.2lf)\n", i, expenses[i].name, expenses[i].amount);
                    }

                    printf("Total expenses: $%.2lf\n", total_expenses);

                    printf("Enter your monthly income: ");
                    scanf("%lf", &monthly_income);

                    monthly_savings = monthly_income - total_expenses;
                    printf("Your monthly savings: $%.2lf\n\n", monthly_savings);
                }
                break;
            case 4:
                printf("Thank you for using the Personal Finance Planner!\n");
                break;
            default:
                printf("Invalid input! Please choose again.\n\n");
                break;
        }
    }

    return 0;
}