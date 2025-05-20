//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main() {
    float savings, income, expenses, total_income, total_expenses, net_balance;
    int option, i = 0;

    printf("*** PERSONAL FINANCE PLANNER ***\n\n");

    while (i == 0) {
        printf("Please select an option:\n");
        printf("1. Add Income\n");
        printf("2. Add Expenses\n");
        printf("3. View Summary\n");
        printf("4. Exit\n");
        printf("Option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Enter income amount: $");
                scanf("%f", &income);
                savings += income;
                total_income += income;
                printf("Income added successfully!\n\n");
                break;

            case 2:
                printf("Enter expense amount: $");
                scanf("%f", &expenses);
                savings -= expenses;
                total_expenses += expenses;
                printf("Expense added successfully!\n\n");
                break;

            case 3:
                if (total_income == 0 && total_expenses == 0) {
                    printf("No income or expenses have been added yet!\n\n");
                }
                else {
                    net_balance = total_income - total_expenses;
                    printf("\n*** CURRENT FINANCIAL SUMMARY ***\n\n");
                    printf("Total Income: $%.2f\n", total_income);
                    printf("Total Expenses: $%.2f\n", total_expenses);
                    printf("Net Balance: $%.2f\n\n", net_balance);
                }
                break;

            case 4:
                printf("Thank you for using the Personal Finance Planner!\n");
                i = 1;
                break;

            default:
                printf("Invalid option selected! Please try again.\n\n");
        }
    }

    return 0;
}