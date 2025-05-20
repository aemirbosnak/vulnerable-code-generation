//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: expert-level
#include <stdio.h>

float calculateTotalMonthlyExpenses(float rent, float utilities, float food, float transportation, float miscellaneous) {
    return rent + utilities + food + transportation + miscellaneous;
}

float calculateTotalMonthlyIncome(float primaryIncome, float secondaryIncome) {
    return primaryIncome + secondaryIncome;
}

float calculateTotalMonthlySavings(float totalIncome, float totalExpenses) {
    return totalIncome - totalExpenses;
}

int main() {
    float rent, utilities, food, transportation, miscellaneous;
    float primaryIncome, secondaryIncome;

    printf("Please enter your monthly expenses:\n");
    printf("Rent: ");
    scanf("%f", &rent);
    printf("Utilities: ");
    scanf("%f", &utilities);
    printf("Food: ");
    scanf("%f", &food);
    printf("Transportation: ");
    scanf("%f", &transportation);
    printf("Miscellaneous: ");
    scanf("%f", &miscellaneous);

    float totalExpenses = calculateTotalMonthlyExpenses(rent, utilities, food, transportation, miscellaneous);

    printf("\nPlease enter your monthly income:\n");
    printf("Primary Income: ");
    scanf("%f", &primaryIncome);
    printf("Secondary Income: ");
    scanf("%f", &secondaryIncome);

    float totalIncome = calculateTotalMonthlyIncome(primaryIncome, secondaryIncome);
    float totalSavings = calculateTotalMonthlySavings(totalIncome, totalExpenses);

    printf("\nExpenses: $%.2f\n", totalExpenses);
    printf("Income: $%.2f\n", totalIncome);
    printf("Savings: $%.2f\n", totalSavings);

    if (totalSavings < 0) {
        printf("Warning: You have a negative monthly savings balance!\n");
    }

    return 0;
}