//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

int main() {
    float monthlySalary, rent, groceries, transportation, internet, utilities, entertainment, savings;
    int numDaysInMonth = 30;
    float dailyBudget, remainingBudget;
    
    printf("Welcome to the Personal Finance Planner!\n");
    
    printf("Please enter your monthly salary: ");
    scanf("%f", &monthlySalary);
    
    printf("Please enter your monthly rent payment: ");
    scanf("%f", &rent);
    
    printf("Please enter your estimated monthly grocery expenses: ");
    scanf("%f", &groceries);
    
    printf("Please enter your estimated monthly transportation expenses: ");
    scanf("%f", &transportation);
    
    printf("Please enter your monthly internet bill: ");
    scanf("%f", &internet);
    
    printf("Please enter your estimated monthly utilities bill: ");
    scanf("%f", &utilities);
    
    printf("Please enter your estimated monthly entertainment expenses: ");
    scanf("%f", &entertainment);
    
    printf("Please enter the percentage of your monthly salary you want to save: ");
    scanf("%f", &savings);
    
    dailyBudget = (monthlySalary - rent - groceries - transportation - internet - utilities - entertainment - (savings/100*monthlySalary)) / numDaysInMonth;
    
    printf("Your daily budget is: $%.2f\n", dailyBudget);
    
    printf("How many days are left in the current month? ");
    int numDaysRemaining;
    scanf("%d", &numDaysRemaining);
    
    remainingBudget = dailyBudget * numDaysRemaining;
    
    printf("Your remaining budget for this month is: $%.2f\n", remainingBudget);
    
    printf("Thank you for using the Personal Finance Planner!\n");
    
    return 0;
}