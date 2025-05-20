//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: high level of detail
#include <stdio.h>

int main() {
    float total_expenses = 0.0;
    float total_income = 0.0;
    float savings = 0.0;
    float monthly_expenses = 0.0;
    float monthly_income = 0.0;

    printf("Welcome to your personal finance planner!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add an expense\n");
        printf("2. Add an income\n");
        printf("3. View total expenses\n");
        printf("4. View total income\n");
        printf("5. View savings\n");
        printf("6. View monthly expenses\n");
        printf("7. View monthly income\n");
        printf("8. Quit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the amount of the expense: ");
                scanf("%f", &monthly_expenses);
                total_expenses += monthly_expenses;
                break;
            case 2:
                printf("Enter the amount of the income: ");
                scanf("%f", &monthly_income);
                total_income += monthly_income;
                break;
            case 3:
                printf("Total expenses: %.2f\n", total_expenses);
                break;
            case 4:
                printf("Total income: %.2f\n", total_income);
                break;
            case 5:
                printf("Savings: %.2f\n", savings);
                break;
            case 6:
                printf("Monthly expenses: %.2f\n", total_expenses / 12);
                break;
            case 7:
                printf("Monthly income: %.2f\n", total_income / 12);
                break;
            case 8:
                printf("Thank you for using your personal finance planner! Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("Would you like to make another entry? (y/n): ");
        char answer;
        scanf(" %c", &answer);

        if (answer == 'n') {
            break;
        }
    }

    return 0;
}