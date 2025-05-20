//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Budget {
    float expenses;
    float income;
} myBudget;

int main() {
    char name[20], response;
    float savings, totalSavings, netIncome, netExpenses;
    
    printf("Welcome to your Personal Finance Planner!\n");
    
    printf("\nPlease enter your name: ");
    scanf("%s", name);
    
    printf("\nHello %s! Let's get started with your budget.\n", name);
    
    printf("\nWhat is your monthly income? ");
    scanf("%f", &myBudget.income);
    
    printf("\nGreat! What are your total monthly expenses? ");
    scanf("%f", &myBudget.expenses);
    
    netIncome = myBudget.income - myBudget.expenses;
    
    printf("\nYour net income for the month is: $%.2f\n", netIncome);
    
    printf("\nDo you have any additional savings or investments? (Y/N) ");
    scanf(" %c", &response);
    
    if(response == 'Y' || response == 'y') {
        printf("\nWhat is your current total savings? ");
        scanf("%f", &savings);
        totalSavings = netIncome + savings;
        printf("\nYour total savings for the month is: $%.2f\n", totalSavings);
    } else {
        printf("\nNo problem, let's continue with your budget.\n");
    }
    
    printf("\nWhat is your desired allocation for monthly savings? (%%) ");
    int allocation;
    scanf("%d", &allocation);
    
    float savingsAllocation = (float) allocation / 100 * netIncome;
    printf("\nYour monthly savings allocation is: $%.2f\n", savingsAllocation);
    
    if(savingsAllocation > totalSavings) {
        printf("\nWarning: You do not have enough savings to meet your desired allocation.\n");
    }
    
    netExpenses = myBudget.expenses - savingsAllocation;
    
    printf("\nYour net expenses for the month are: $%.2f\n", netExpenses);
    
    printf("\nThank you for using the Personal Finance Planner! Goodbye!\n");
    
    return 0;
}