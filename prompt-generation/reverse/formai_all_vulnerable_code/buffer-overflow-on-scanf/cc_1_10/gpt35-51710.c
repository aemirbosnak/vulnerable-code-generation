//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float income, expenses, savings, total_expenses = 0;

    printf("Welcome to the Personal Finance Planner!\n");
    printf("Please enter your monthly income: ");
    scanf("%f", &income);

    // BUDGETING //
    printf("\n*** BUDGETING ***\n");
    printf("Please enter your monthly expenses. To exit enter 0.\n");

    while(1) {
        printf("Expense: ");
        scanf("%f", &expenses);
        if(expenses == 0) {
            break;
        } else {
            total_expenses += expenses;
        }
    }

    savings = income - total_expenses; 

    printf("\n*** RESULTS ***\n");
    printf("Your total monthly expenses: $%.2f\n", total_expenses);
    printf("Your monthly income: $%.2f\n", income);
    printf("Your total savings: $%.2f\n", savings);

    // FINANCIAL GOALS //
    printf("\n*** FINANCIAL GOALS ***\n");
    int decision;

    printf("Do you have any financial goals this month? (1 for YES, 0 for NO)\n");
    scanf("%d", &decision);

    while(decision == 1) {

        int goal;
        float amount;
        printf("\nWhat is your financial goal? (1 for savings, 2 for investment, 3 for paying off debt): ");
        scanf("%d", &goal);

        if(goal == 1) {
            printf("\nHow much do you want to save? ");
            scanf("%f", &amount);
            if(amount > savings) {
                printf("Sorry, your savings is not enough for that goal.\n");
            } else {
                savings -= amount;
                printf("Your savings after this goal will be: $%.2f\n", savings);
            }
        } else if(goal == 2) {
            printf("\nHow much do you want to invest? ");
            scanf("%f", &amount);
            if(amount > savings) {
                printf("Sorry, your savings is not enough for that goal.\n");
            } else {
                savings -= amount;
                printf("\nYour savings after this goal will be: $%.2f\n", savings);
            }
        } else if(goal == 3) {
            printf("\nHow much do you want to pay off? ");
            scanf("%f", &amount);
            if(amount > total_expenses) {
                printf("Sorry, your expenses is not enough for that goal.\n");
            } else {
                total_expenses -= amount;
                printf("\nYour total expenses after this goal will be: $%.2f\n", total_expenses);
            }
        } else {
            printf("\nInvalid option.\n");
        }

        printf("\nDo you have any other financial goals? (1 for YES, 0 for NO)\n");
        scanf("%d", &decision);
    }

    printf("\n*** FINAL RESULTS ***\n");
    printf("Your total monthly expenses: $%.2f\n", total_expenses);
    printf("Your monthly income: $%.2f\n", income);
    printf("Your total savings: $%.2f\n", savings);

    return 0;
}