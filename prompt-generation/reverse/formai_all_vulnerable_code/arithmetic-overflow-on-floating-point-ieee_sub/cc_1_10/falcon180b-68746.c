//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double budget, income, expenses, savings;
    int choice;

    printf("Welcome to the Personal Finance Planner!\n");
    printf("Please enter your monthly budget: ");
    scanf("%lf", &budget);

    while (1) {
        printf("\nPlease choose an option:\n");
        printf("1. Enter income\n");
        printf("2. Enter expenses\n");
        printf("3. View savings\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your monthly income: ");
                scanf("%lf", &income);
                printf("Your monthly income is $%.2lf.\n", income);
                break;

            case 2:
                printf("Enter your monthly expenses: ");
                scanf("%lf", &expenses);
                printf("Your monthly expenses are $%.2lf.\n", expenses);
                break;

            case 3:
                if (income > expenses) {
                    savings = income - expenses;
                    printf("Your monthly savings are $%.2lf.\n", savings);
                } else {
                    printf("You are spending more than you earn.\n");
                }
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