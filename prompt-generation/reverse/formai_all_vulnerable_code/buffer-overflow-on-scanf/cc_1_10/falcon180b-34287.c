//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    double income, expense, balance;

    printf("Welcome to the Personal Finance Planner!\n");
    printf("Please enter your monthly income: ");
    scanf("%lf", &income);
    balance = income;

    while(1) {
        printf("\nPlease choose an option:\n");
        printf("1. Add expense\n");
        printf("2. Remove expense\n");
        printf("3. View expenses\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter expense amount: ");
                scanf("%lf", &expense);
                balance -= expense;
                printf("Expense added successfully!\n");
                printf("Current balance: $%.2lf\n", balance);
                break;

            case 2:
                printf("Enter expense amount to remove: ");
                scanf("%lf", &expense);
                if(balance >= expense) {
                    balance += expense;
                    printf("Expense removed successfully!\n");
                    printf("Current balance: $%.2lf\n", balance);
                } else {
                    printf("Insufficient balance to remove expense.\n");
                }
                break;

            case 3:
                printf("Expenses:\n");
                printf("-----------------\n");
                printf("1. Expense 1: $%.2lf\n", balance);
                printf("2. Expense 2: $%.2lf\n", balance);
                printf("3. Expense 3: $%.2lf\n", balance);
                printf("4. Expense 4: $%.2lf\n", balance);
                printf("5. Expense 5: $%.2lf\n", balance);
                break;

            case 4:
                printf("Thank you for using the Personal Finance Planner!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}