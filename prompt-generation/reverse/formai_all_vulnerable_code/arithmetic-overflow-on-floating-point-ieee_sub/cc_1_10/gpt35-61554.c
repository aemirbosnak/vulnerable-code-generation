//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    printf("\n\nWelcome to your Personal Finance Planner!\n\n");

    float income, expenses, savings;
    float rent, utilities, transportation, food, entertainment, others;
    float total_expenses;
    bool repeat = true;

    while(repeat){

        //Query user for their monthly income
        printf("Enter your monthly income:\n");
        scanf("%f", &income);

        //Query user for monthly expenses
        printf("Enter your monthly expenses:\n");
        printf("---------------------------------------\n");
        printf("Rent/Mortgage:\n");
        scanf("%f", &rent);
        printf("Utilities:\n");
        scanf("%f", &utilities);
        printf("Transportation:\n");
        scanf("%f", &transportation);
        printf("Food:\n");
        scanf("%f", &food);
        printf("Entertainment:\n");
        scanf("%f", &entertainment);
        printf("Others:\n");
        scanf("%f", &others);

        //Calculate total monthly expenses
        total_expenses = rent + utilities + transportation + food + entertainment + others;

        //Calculate monthly savings
        expenses = total_expenses;
        savings = income - expenses;

        //Display budget summary
        printf("Your monthly budget summary:\n");
        printf("---------------------------------------\n");
        printf("Monthly Income: $%.2f\n", income);
        printf("Total Monthly Expenses: $%.2f\n", total_expenses);
        printf("Monthly Savings: $%.2f\n", savings);

        //Ask user if they want to repeat or end the program
        char answer;
        printf("Do you want to create another budget? Enter Y or N: ");
        scanf("%s", &answer);
        if(answer == 'N' || answer == 'n'){
            printf("\nThank you for using Personal Finance Planner!\n");
            repeat = false;
        }
    }
    return 0;
}