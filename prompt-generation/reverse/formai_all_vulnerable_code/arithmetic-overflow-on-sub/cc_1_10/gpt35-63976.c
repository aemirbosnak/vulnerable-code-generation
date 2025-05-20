//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main() {
    int income, savings, loan, rent, utilities, groceries, entertainment, emergency_fund;
    char answer;

    printf("Welcome to the Personal Finance Planner!\n");
    printf("Answer the following questions to get started.\n");
    
    printf("\nWhat is your monthly income? $");
    scanf("%d", &income);

    printf("\nWhat percentage of your income do you want to put towards savings? ");
    scanf("%d", &savings);

    printf("\nDo you have any outstanding loans? (y/n) ");
    scanf(" %c", &answer);
    if (answer == 'y') {
        printf("\nHow much is your monthly loan payment? $");
        scanf("%d", &loan);
    } else {
        loan = 0;
    }

    printf("\nWhat is your monthly rent/mortgage payment? $");
    scanf("%d", &rent);

    printf("\nWhat is your average monthly utility bill? $");
    scanf("%d", &utilities);

    printf("\nWhat is your average monthly grocery bill? $");
    scanf("%d", &groceries);

    printf("\nWhat is your monthly entertainment budget? $");
    scanf("%d", &entertainment);

    printf("\nHow much money do you want to keep in your emergency fund? $");
    scanf("%d", &emergency_fund);

    int expenses = rent + utilities + groceries + entertainment + loan;
    int left_over = income - savings - expenses;
    
    printf("\nHere is your monthly budget breakdown:\n");
    printf("--------------------------------------------------\n");
    printf("INCOME: $%d\n", income);
    printf("SAVINGS: $%d (%d%%)\n", (income * savings)/100, savings);
    printf("EXPENSES: $%d\n", expenses);
    printf("LEFT OVER: $%d\n", left_over);
    printf("EMERGENCY FUND: $%d\n", emergency_fund);
    printf("--------------------------------------------------\n");

    if (left_over >= emergency_fund) {
        printf("\nYou have enough left over to meet your emergency fund goal.\n");
    } else {
        int needed = emergency_fund - left_over;
        printf("\nYou need $%d more left over each month to meet your emergency fund goal.\n", needed);
    }

    return 0;
}