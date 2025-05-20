//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("Hey there, welcome to our Personal Finance Planner Program!\n");
    printf("We are all about helping you reach your financial goals\n");
    printf("We can help you with budgeting, saving, investing and more!\n\n");

    int choice;
    float budget, expense, goal, savings, interest_rate, investment_return, years;
    float interest, total_savings, total_investment;

    printf("Let's get started! Please choose an option below:\n");
    printf("1. Create a budget plan\n");
    printf("2. Calculate savings plan\n");
    printf("3. Calculate investment growth plan\n");

    scanf("%d",&choice);

    switch(choice) {

        case 1:
        printf("You have chosen to create a budget plan. Please enter your monthly income:\n");
        scanf("%f",&budget);
        printf("Enter your estimated monthly expenses:\n");
        scanf("%f",&expense);
        printf("Your monthly budget is %f\n",budget-expense);
        break;

        case 2:
        printf("You have chosen to calculate your savings plan\n");
        printf("Please enter your savings goal:\n");
        scanf("%f",&goal);
        printf("Enter your monthly savings amount:\n");
        scanf("%f",&savings);
        printf("Enter your expected interest rate per annum:\n");
        scanf("%f",&interest_rate);
        printf("Enter the number of years you plan to save for:\n");
        scanf("%f",&years);

        total_savings = savings * 12 * years;
        interest = (interest_rate/100) * total_savings;
        total_savings += interest;

        printf("Your total savings after %f years with an annual interest rate of %f percent is: %f\n", years, interest_rate, total_savings);
        printf("You need to save %f per month to reach your goal of %f in %f years with an interest rate of %f percent\n", goal/(12*years), goal, years, interest_rate);

        break;

        case 3:
        printf("You have chosen to calculate your investment growth plan\n");
        printf("Please enter your initial investment amount:\n");
        scanf("%f",&investment_return);
        printf("Enter your expected annual investment return rate:\n");
        scanf("%f",&interest_rate);
        printf("Enter the number of years you plan to invest for:\n");
        scanf("%f",&years);

        total_investment = investment_return;
        for(int i=1;i<=years;i++) {
            total_investment += (interest_rate/100) * total_investment;
        }

        printf("Your total investment return in %f years with an annual return rate of %f percent is: %f\n", years, interest_rate, total_investment);
        printf("Your investment will be worth %f after %f years with an annual interest rate of %f percent\n", total_investment, years, interest_rate);
        break;

        default:
        printf("Invalid choice\n");
        break;
    }

    printf("Thank you for using our Personal Finance Planner Program! Good bye!\n");

    return 0;
}