//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

//function to calculate total expenses
float total_expenses(float food, float bills, float transportation, float entertainment){
    float total = food + bills + transportation + entertainment;
    return total;
}

//function to calculate total income
float total_income(float salary, float side_income){
    float total = salary + side_income;
    return total;
}

//function to calculate net savings
float net_savings(float total_income, float total_expenses){
    float net_savings = total_income - total_expenses;
    return net_savings;
}

int main()
{
    float salary, side_income, food, bills, transportation, entertainment, total_spent, net_saved;

    printf("\t Welcome to your personal finance planner!\n\n");

    //gather user input for income and expenses
    printf("Enter your monthly salary: ");
    scanf("%f", &salary);

    printf("Enter your monthly side income (if any): ");
    scanf("%f", &side_income);

    printf("\n");

    printf("Enter your monthly food expenses: ");
    scanf("%f", &food);

    printf("Enter your monthly bills expenses: ");
    scanf("%f", &bills);

    printf("Enter your monthly transportation expenses: ");
    scanf("%f", &transportation);

    printf("Enter your monthly entertainment expenses: ");
    scanf("%f", &entertainment);

    printf("\n");

    //call functions and print results
    total_spent = total_expenses(food, bills, transportation, entertainment);
    printf("You spend a total of $%.2f each month.\n", total_spent);

    net_saved = net_savings(total_income(salary, side_income), total_spent);
    if (net_saved < 0){
        printf("WARNING: You are spending more than you are earning!\n");
    }
    printf("Your net savings each month is $%.2f.\n\n", net_saved);

    //provide financial advice
    if (net_saved > (0.2 * total_spent)){
        printf("Congratulations! You are saving more than 20%% of your total expenses. Keep it up!\n");
    } else if (net_saved > (0.1 * total_spent)){
        printf("Good job! You are saving between 10%% and 20%% of your total expenses.\n");
    } else {
        printf("You should consider cutting back on your expenses. Try to save at least 10%% of your total expenses.\n");
    }

    return 0;
}