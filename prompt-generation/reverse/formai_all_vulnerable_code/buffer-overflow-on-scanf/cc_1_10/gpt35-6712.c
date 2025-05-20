//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: recursive
#include <stdio.h>

int calculateSavings(int income, int expenses) {
    if (expenses >= income) {
        printf("You are spending more than you earn!\n");
        return 0;
    }
    int savings = income - expenses;
    printf("Your monthly savings is: %d\n", savings);
    return savings;
}

void calculateBudget(int savings, int monthsLeft) {
    if (monthsLeft == 0) {
        printf("You have reached the end of your budget planning.");
        return;
    }
    printf("How much are you planning to save this month?\n");
    int plannedSavings;
    scanf("%d", &plannedSavings);
    printf("\n");
    if (plannedSavings > savings) {
        printf("You cannot save more than your monthly income!\n");
        calculateBudget(savings, monthsLeft);
    } else {
        int remainingSavings = savings - plannedSavings;
        printf("Your remaining savings for this month is: %d\n\n", remainingSavings);
        calculateBudget(remainingSavings, monthsLeft - 1);
    }
}

int main() {
    int income;
    printf("What is your monthly income?\n");
    scanf("%d", &income);

    int expenses;
    printf("\nWhat are your monthly expenses?\n");
    scanf("%d", &expenses);

    printf("\n");
    int savings = calculateSavings(income, expenses);

    int monthsLeft;
    printf("How many months would you like to plan your budget for?\n");
    scanf("%d", &monthsLeft);

    printf("\n");

    calculateBudget(savings, monthsLeft);

    return 0;
}