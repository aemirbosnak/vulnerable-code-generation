//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: grateful
#include <stdio.h>

int main() {
    printf("Welcome to your Personal Finance Planner!\n\n");
    printf("Let's get started by entering your monthly income: $");

    float monthlyIncome;
    scanf("%f", &monthlyIncome);

    printf("\nNext, let's enter your monthly expenses...\n\n");

    float housing;
    printf("Housing: $");
    scanf("%f", &housing);

    float utilities;
    printf("Utilities: $");
    scanf("%f", &utilities);

    float groceries;
    printf("Groceries: $");
    scanf("%f", &groceries);

    float transportation;
    printf("Transportation: $");
    scanf("%f", &transportation);

    float entertainment;
    printf("Entertainment: $");
    scanf("%f", &entertainment);

    float totalExpenses = housing + utilities + groceries + transportation + entertainment;
    float savings = monthlyIncome - totalExpenses;

    printf("\n\nBased on the numbers you entered, your personal finance plan for this month is:\n\n");
    printf("Monthly Income: $%.2f\n", monthlyIncome);
    printf("Housing: $%.2f\n", housing);
    printf("Utilities: $%.2f\n", utilities);
    printf("Groceries: $%.2f\n", groceries);
    printf("Transportation: $%.2f\n", transportation);
    printf("Entertainment: $%.2f\n\n", entertainment);

    if (savings > 0) {
        printf("Congratulations! You have $%.2f left over this month after expenses.\n", savings);
        printf("Be sure to save at least 10%% of this amount for your future goals.\n");
    } else if (savings == 0) {
        printf("You broke even this month. Don't worry, it happens to everyone!\n");
    } else {
        printf("Uh oh! It looks like you spent more than you earned this month.\n");
        printf("Consider cutting back on some of your expenses next month.\n");
    }

    return 0;
}