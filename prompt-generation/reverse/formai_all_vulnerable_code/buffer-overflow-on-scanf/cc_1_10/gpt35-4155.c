//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: random
#include <stdio.h>

int main(){
    //Greeting message
    printf("Welcome to the Personal Finance Planner!\n\n");

    //Getting user's monthly income
    double monthly_income;
    printf("What is your monthly income? ");
    scanf("%lf", &monthly_income);

    //Getting user's monthly expenses
    double monthly_expenses;
    printf("What are your monthly expenses? ");
    scanf("%lf", &monthly_expenses);

    //Calculating the user's savings per month
    double monthly_savings = monthly_income - monthly_expenses;

    //Checking if user is saving enough
    if(monthly_savings < 0) {
        printf("\nYou are spending more than you are earning, please reduce your expenses.");
        return 0;
    }
    else if(monthly_savings == 0) {
        printf("\nYou are breaking even, please consider reducing your expenses or finding ways to generate more income.");
    }
    else {
        printf("\nYou are saving %.2lf per month.\n\n", monthly_savings);
    }

    //Displaying expense categories and asking for user's input
    printf("Please categorize your expenses: \n");
    printf("1. Housing\n2. Transportation\n3. Food\n4. Entertainment\n5. Others\n\n");
    printf("Enter the number corresponding to each category:\n");

    //Creating arrays to store expense amounts and category names
    double expenses[5];
    char* categories[5] = {"Housing", "Transportation", "Food", "Entertainment", "Others"};

    //Looping through each category and getting user's input
    for(int i = 0; i < 5; i++) {
        printf("%d. %s: ", i+1, categories[i]);
        scanf("%lf", &expenses[i]);
    }

    //Calculating total expenses
    double total_expenses = 0;
    for(int i = 0; i < 5; i++) {
        total_expenses += expenses[i];
    }

    //Calculating and displaying expense percentage for each category
    printf("\nYour Expense Percentages:\n");
    for(int i = 0; i < 5; i++) {
        printf("%s: %.2lf%%\n", categories[i], expenses[i]/total_expenses*100);
    }

    //Calculating and displaying remaining monthly budget
    double remaining_budget = monthly_savings - total_expenses;
    if(remaining_budget < 0) {
        printf("\nYou have exceeded your budget by %.2lf.\n", remaining_budget*-1);
    }
    else {
        printf("\nYou have %.2lf remaining in your budget.\n", remaining_budget);
    }

    return 0;
}