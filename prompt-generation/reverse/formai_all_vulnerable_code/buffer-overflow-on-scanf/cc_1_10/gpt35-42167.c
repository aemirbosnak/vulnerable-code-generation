//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Linus Torvalds
/*
 * Linux Torvalds Style Personal Finance Planner Example Program
 */

#include <stdio.h>
#include <stdlib.h>

#define MONTHS 12

int main(int argc, char *argv[]) {
    int income[MONTHS], expenses[MONTHS], savings[MONTHS];
    int yearly_income = 0, yearly_expenses = 0, yearly_savings = 0;
    int i;

    printf("Welcome to the Personal Finance Planner!\n\n");

    // Getting income data from the user
    printf("Please enter your monthly income for each month: \n");
    for (i = 0; i < MONTHS; i++) {
        printf("Month %d: ", i+1);
        scanf("%d", &income[i]);
        yearly_income += income[i];
    }

    // Getting expenses data from the user
    printf("\nPlease enter your monthly expenses for each month: \n");
    for (i = 0; i < MONTHS; i++) {
        printf("Month %d: ", i+1);
        scanf("%d", &expenses[i]);
        yearly_expenses += expenses[i];
    }

    // Calculating savings data
    for (i = 0; i < MONTHS; i++) {
        savings[i] = income[i] - expenses[i];
        yearly_savings += savings[i];
    }

    // Printing yearly data
    printf("\nYour total yearly income is: %d\n", yearly_income);
    printf("Your total yearly expenses is: %d\n", yearly_expenses);
    printf("Your total yearly savings is: %d\n\n", yearly_savings);

    // Printing monthly data
    printf("\tMonthly\t\tYearly\n");
    printf("--------------------------------------\n");
    for (i = 0; i < MONTHS; i++) {
        printf("Month %d:\t%d\t\t%d\n", i+1, savings[i], savings[i]*MONTHS);
    }

    return 0;
}