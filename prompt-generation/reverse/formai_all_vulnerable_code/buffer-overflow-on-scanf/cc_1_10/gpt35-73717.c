//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: interoperable
#include<stdio.h>

//Function to calculate the total expenses
float calculateExpenses(float rent, float utilities, float groceries, float transportation, float others){
    float totalExpenses = rent + utilities + groceries + transportation + others;
    return totalExpenses;
}

//Function to calculate the total income
float calculateIncome(float salary, float bonuses, float others){
    float totalIncome = salary + bonuses + others;
    return totalIncome;
}

//Function to calculate the savings
float calculateSavings(float income, float expenses){
    float savings = income - expenses;
    return savings;
}

int main(){
    float rent, utilities, groceries, transportation, others;
    float salary, bonuses, otherIncome;
    
    printf("Enter your monthly rent: ");
    scanf("%f", &rent);
    
    printf("Enter your monthly utilities bill: ");
    scanf("%f", &utilities);
    
    printf("Enter your monthly grocery expenses: ");
    scanf("%f", &groceries);
    
    printf("Enter your monthly transportation expenses: ");
    scanf("%f", &transportation);
    
    printf("Enter your other monthly expenses: ");
    scanf("%f", &others);
    
    printf("Enter your monthly salary: ");
    scanf("%f", &salary);
    
    printf("Enter your monthly bonuses: ");
    scanf("%f", &bonuses);
    
    printf("Enter your other monthly income: ");
    scanf("%f", &otherIncome);
    
    float totalExpenses = calculateExpenses(rent, utilities, groceries, transportation, others);
    float totalIncome = calculateIncome(salary, bonuses, otherIncome);
    float savings = calculateSavings(totalIncome, totalExpenses);
    
    printf("\nTotal expenses: %.2f\n", totalExpenses);
    printf("Total income: %.2f\n", totalIncome);
    
    if(savings < 0){
        printf("You have a debt of %.2f\n", savings);
    }
    else if(savings == 0){
        printf("You do not have any savings yet.\n");
    }
    else{
        printf("Your monthly savings: %.2f\n", savings);
    }
    
    return 0;
}