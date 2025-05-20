//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

int main() {
    srand(time(0));

    printf("Welcome to the Personal Finance Planner!\n");
    printf("Please enter your monthly income:\n");
    int income = scanf("%d", &income);
    if (income <= 0) {
        printf("Please enter a positive value for your income.\n");
        return 1;
    }

    printf("Please enter your monthly expenses:\n");
    int expenses = scanf("%d", &expenses);
    if (expenses <= 0) {
        printf("Please enter a positive value for your expenses.\n");
        return 1;
    }

    int remaining_money = income - expenses;
    printf("Your remaining money is %d.\n", remaining_money);

    printf("Please enter the amount you want to save each month:\n");
    int savings = scanf("%d", &savings);
    if (savings <= 0) {
        printf("Please enter a positive value for your savings.\n");
        return 1;
    }

    printf("Please enter the interest rate for your savings account:\n");
    float interest_rate = scanf("%f", &interest_rate);
    if (interest_rate <= 0) {
        printf("Please enter a positive value for your interest rate.\n");
        return 1;
    }

    int savings_accumulated = 0;
    for (int i = 0; i < 12; i++) {
        int monthly_savings = savings * rand() % 100;
        if (monthly_savings < 0) {
            monthly_savings = 0;
        }
        savings_accumulated += monthly_savings;
        printf("Month %d: %.2f\n", i+1, savings_accumulated);
    }

    printf("Congratulations! You have saved a total of %.2f after 12 months.\n", savings_accumulated);

    return 0;
}