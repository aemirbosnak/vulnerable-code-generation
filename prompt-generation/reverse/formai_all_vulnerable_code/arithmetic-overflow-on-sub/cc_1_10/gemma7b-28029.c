//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Budget Module
void budget(int budget_amount) {
    int category_amount, total_amount = 0;
    char category_name[20];

    printf("Enter the category name: ");
    scanf("%s", category_name);

    printf("Enter the category amount: ");
    scanf("%d", &category_amount);

    total_amount += category_amount;

    printf("Total amount: $%d\n", total_amount);
}

// Define the Savings Module
void savings(int savings_goal) {
    int current_savings, target_savings, monthly_contribution;

    printf("Enter your current savings: ");
    scanf("%d", &current_savings);

    printf("Enter your target savings: ");
    scanf("%d", &target_savings);

    monthly_contribution = (target_savings - current_savings) / 12;

    printf("Monthly contribution: $%d\n", monthly_contribution);
}

// Define the Investment Module
void investment(int investment_amount) {
    int asset_type, return_on_investment;

    printf("Enter the asset type (e.g. stocks, bonds): ");
    scanf("%s", asset_type);

    printf("Enter the return on investment: ");
    scanf("%d", &return_on_investment);

    investment_amount = investment_amount * (1 + return_on_investment / 100);

    printf("Projected value: $%d\n", investment_amount);
}

int main() {
    int choice;

    printf("Enter 1 to budget, 2 to save, 3 to invest: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            budget(1000);
            break;
        case 2:
            savings(5000);
            break;
        case 3:
            investment(2000);
            break;
        default:
            printf("Invalid input\n");
            break;
    }

    return 0;
}