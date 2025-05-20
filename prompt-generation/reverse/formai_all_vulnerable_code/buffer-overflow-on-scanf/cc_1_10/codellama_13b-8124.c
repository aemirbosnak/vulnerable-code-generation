//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold information about a user's financial goals
struct FinancialGoal {
    char name[50];
    float amount;
    char frequency;
};

// Structure to hold information about a user's financial plan
struct FinancialPlan {
    struct FinancialGoal goals[5];
    float totalAmount;
};

// Function to prompt the user for financial goal information
void getFinancialGoal(struct FinancialGoal* goal) {
    printf("Enter the name of your financial goal: ");
    scanf("%s", goal->name);
    printf("Enter the amount you need to reach: ");
    scanf("%f", &goal->amount);
    printf("Enter the frequency of your savings (e.g. monthly): ");
    scanf(" %c", &goal->frequency);
}

// Function to calculate the total amount needed to reach all financial goals
float calculateTotalAmount(struct FinancialPlan* plan) {
    float total = 0;
    for (int i = 0; i < 5; i++) {
        total += plan->goals[i].amount;
    }
    return total;
}

// Function to print the financial plan
void printFinancialPlan(struct FinancialPlan* plan) {
    printf("Your financial plan:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s: %f\n", plan->goals[i].name, plan->goals[i].amount);
    }
    printf("Total amount needed: %f\n", plan->totalAmount);
}

int main() {
    struct FinancialPlan plan;
    for (int i = 0; i < 5; i++) {
        getFinancialGoal(&plan.goals[i]);
    }
    plan.totalAmount = calculateTotalAmount(&plan);
    printFinancialPlan(&plan);
    return 0;
}