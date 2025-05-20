//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

float calculateIncome(float hourlyWage, int hoursWorked, int daysWorked){
    float income = hourlyWage * hoursWorked * daysWorked;
    return income;
}

float calculateExpenses(float rent, float groceries, float transportation, float miscellaneous){
    float expenses = rent + groceries + transportation + miscellaneous;
    return expenses;
}

void displayResult(float income, float expenses){
    float savings = income - expenses;
    if(savings > 0){
        printf("Your income for this period is $%.2f\n", income);
        printf("Your expenses for this period is $%.2f\n", expenses);
        printf("You have a savings of $%.2f\n", savings);
    }else if(savings == 0){
        printf("Your income for this period is $%.2f\n", income);
        printf("Your expenses for this period is $%.2f\n", expenses);
        printf("You have no savings this period\n");
    }else{
        printf("Your income for this period is $%.2f\n", income);
        printf("Your expenses for this period is $%.2f\n", expenses);
        printf("You have a deficit of $%.2f\n", abs(savings));
    }
}

int main(){
    float hourlyWage, rent, groceries, transportation, miscellaneous;
    int hoursWorked, daysWorked;

    printf("---- Personal Finance Planner ----\n\n");
    printf("Enter your hourly wage:\n");
    scanf("%f", &hourlyWage);
    printf("Enter the number of hours worked per day:\n");
    scanf("%d", &hoursWorked);
    printf("Enter the number of days worked this period:\n");
    scanf("%d", &daysWorked);
    printf("Enter your rent expense:\n");
    scanf("%f", &rent);
    printf("Enter your groceries expense:\n");
    scanf("%f", &groceries);
    printf("Enter your transportation expense:\n");
    scanf("%f", &transportation);
    printf("Enter your miscellaneous expense:\n");
    scanf("%f", &miscellaneous);

    float income = calculateIncome(hourlyWage, hoursWorked, daysWorked);
    float expenses = calculateExpenses(rent, groceries, transportation, miscellaneous);
    displayResult(income, expenses);

    return 0;
}