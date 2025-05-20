//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: complete
#include <stdio.h>

int main() {
    float salary, expenses;
    printf("Enter your monthly salary: $");
    scanf("%f", &salary);
    printf("Enter your monthly expenses: $");
    scanf("%f", &expenses);
    
    float savings = salary - expenses;
    printf("\nYour monthly savings is: $%.2f\n", savings);

    const float investment_percentage = 0.2;
    float investment_amount = savings * investment_percentage;
    printf("You should invest at least 20%% of your savings each month. That is: $%.2f\n", investment_amount);

    printf("\nHow much money do you want to save this month? $");
    float goal;
    scanf("%f", &goal);

    if (goal > savings) {
        printf("You need to increase your income or decrease your expenses.\n");
    } else {
        float remaining = savings - goal;
        printf("You still have $%.2f to spare this month.\n", remaining);
    }

    printf("\nDo you want to see a breakdown of your expenses? (y/n) ");
    char response;
    scanf(" %c", &response);

    if (response == 'y' || response == 'Y') {
        printf("\n--- EXPENSES BREAKDOWN ---\n");

        printf("\nHousing/rent: $");
        float housing;
        scanf("%f", &housing);

        printf("Utilities (gas, water, electricity, etc.): $");
        float utilities;
        scanf("%f", &utilities);

        printf("Food/groceries: $");
        float food;
        scanf("%f", &food);

        printf("Transportation (gas, maintenance, public transit, etc.): $");
        float transportation;
        scanf("%f", &transportation);

        printf("Entertainment/leisure: $");
        float entertainment;
        scanf("%f", &entertainment);

        float total_expenses = housing + utilities + food + transportation + entertainment;
        printf("\nTOTAL EXPENSES: $%.2f\n", total_expenses);

        float savings_percentage = (savings / salary) * 100;
        printf("You are saving %.2f%% of your income each month.\n", savings_percentage);
    }

    return 0;
}