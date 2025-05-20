//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: accurate
#include<stdio.h>

//Function to get user input and calculate savings
float calculateSavings(){
    float income, expenses, savings;

    printf("Enter your monthly income: ");
    scanf("%f", &income);

    printf("Enter your monthly expenses: ");
    scanf("%f", &expenses);

    savings = income - expenses;

    return savings;
}

//Function to calculate net worth
float calculateNetworth(){
    float assets, liabilities, networth;

    printf("Enter the total value of your assets: ");
    scanf("%f", &assets);

    printf("Enter the total value of your liabilities: ");
    scanf("%f", &liabilities);

    networth = assets - liabilities;

    return networth;
}

int main(){
    float savings, networth;

    //Get savings and networth
    savings = calculateSavings();
    networth = calculateNetworth();

    //Display savings and networth
    printf("Your monthly savings are: $%.2f\n", savings);
    printf("Your current net worth is: $%.2f\n", networth);

    //Determine if savings are enough
    if(savings < 0){
        printf("Oh no! You are spending more than you make\n");
    }
    else if(savings == 0){
        printf("You are just breaking even\n");
    }
    else{
        printf("Congratulations! You are saving money each month\n");
    }

    //Determine if networth is positive or negative
    if(networth < 0){
        printf("Uh oh! Your net worth is negative\n");
    }
    else{
        printf("Great job! Your net worth is positive\n");
    }

    return 0;
}