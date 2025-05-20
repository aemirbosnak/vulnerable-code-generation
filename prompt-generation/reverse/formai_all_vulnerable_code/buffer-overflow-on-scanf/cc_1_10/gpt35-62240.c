//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: realistic
#include<stdio.h>

//Function to calculate monthly expenses
float calculateExpenses(int numExpenses) {
    float totalExpenses = 0;
    for(int i=0; i<numExpenses; i++) {
        float expense;
        printf("Enter expense %d: ", i+1);
        scanf("%f", &expense);
        totalExpenses += expense;
    }
    return totalExpenses;
}

//Function to calculate monthly income
float calculateIncome(int numSources) {
    float totalIncome = 0;
    for(int i=0; i<numSources; i++) {
        float income;
        printf("Enter income %d: ", i+1);
        scanf("%f", &income);
        totalIncome += income;
    }
    return totalIncome;
}

int main() {
    //Get user input for number of expenses and income sources
    int numExpenses, numSources;
    printf("Enter number of monthly expenses: ");
    scanf("%d", &numExpenses);
    printf("Enter number of monthly income sources: ");
    scanf("%d", &numSources);
    
    //Calculate total monthly expenses and income
    float totalExpenses = calculateExpenses(numExpenses);
    float totalIncome = calculateIncome(numSources);
    
    //Calculate net income - income minus expenses
    float netIncome = totalIncome - totalExpenses;
    
    //Output results to user
    printf("\nTotal monthly expenses: $%.2f\n", totalExpenses);
    printf("Total monthly income: $%.2f\n", totalIncome);
    if(netIncome > 0) {
        printf("Your net monthly income is: $%.2f\n", netIncome);
        printf("You have surplus income. Consider saving or investing it.\n");
    }
    else if(netIncome < 0) {
        printf("Your net monthly income is: -$%.2f\n", -netIncome);
        printf("You have a deficit in income. Consider reducing expenses or finding another source of income.\n");
    }
    else {
        printf("Your net monthly income is: $%.2f\n", netIncome);
        printf("You are breaking even. Consider finding ways to increase income or reduce expenses.\n");
    }
    
    return 0;
}