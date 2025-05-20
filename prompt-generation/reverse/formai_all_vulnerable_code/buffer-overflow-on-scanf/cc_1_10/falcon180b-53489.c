//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Romeo and Juliet's personal finance planner

int main() {
    int choice;
    double income, expense, balance;

    // Initializing Romeo and Juliet's income
    income = 5000.00;

    // Displaying the initial balance
    printf("Romeo and Juliet's initial balance: $%.2f\n", income);

    do {
        // Displaying the menu options
        printf("\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. View Balance\n");
        printf("4. Exit\n");
        printf("\n");

        // Taking user's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Executing the chosen option
        switch(choice) {
            case 1:
                // Adding income
                printf("Enter the amount of income: $");
                scanf("%lf", &income);
                printf("\n");
                printf("Income added successfully.\n");
                break;

            case 2:
                // Adding expense
                printf("Enter the amount of expense: $");
                scanf("%lf", &expense);
                printf("\n");

                // Deducting expense from income
                balance = income - expense;

                // Displaying the updated balance
                printf("Expense added successfully.\n");
                printf("Romeo and Juliet's updated balance: $%.2f\n", balance);
                break;

            case 3:
                // Viewing balance
                printf("\n");
                printf("Romeo and Juliet's current balance: $%.2f\n", income);
                break;

            case 4:
                // Exiting the program
                printf("\n");
                printf("Thank you for using Romeo and Juliet's personal finance planner.\n");
                break;

            default:
                // Displaying an error message for invalid choice
                printf("\n");
                printf("Invalid choice. Please try again.\n");
        }

    } while(choice!= 4);

    return 0;
}