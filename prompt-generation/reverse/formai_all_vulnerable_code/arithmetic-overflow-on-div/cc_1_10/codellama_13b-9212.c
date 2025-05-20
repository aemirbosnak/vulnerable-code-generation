//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: beginner-friendly
// C Personal Finance Planner Example Program

#include <stdio.h>

// Define structure for finance plan
struct FinancePlan {
    int income;
    int expenses;
    int savings;
};

// Define structure for financial goal
struct FinancialGoal {
    int amount;
    int frequency;
    int startDate;
    int endDate;
};

// Define function to create finance plan
void createFinancePlan(struct FinancePlan *plan) {
    // Get income from user
    printf("Enter your monthly income: ");
    scanf("%d", &plan->income);

    // Get expenses from user
    printf("Enter your monthly expenses: ");
    scanf("%d", &plan->expenses);

    // Get savings from user
    printf("Enter your desired savings amount: ");
    scanf("%d", &plan->savings);
}

// Define function to create financial goal
void createFinancialGoal(struct FinancialGoal *goal) {
    // Get goal amount from user
    printf("Enter your financial goal amount: ");
    scanf("%d", &goal->amount);

    // Get goal frequency from user
    printf("Enter your financial goal frequency (daily, weekly, monthly, yearly): ");
    scanf("%d", &goal->frequency);

    // Get start date from user
    printf("Enter your financial goal start date (YYYY-MM-DD): ");
    scanf("%d", &goal->startDate);

    // Get end date from user
    printf("Enter your financial goal end date (YYYY-MM-DD): ");
    scanf("%d", &goal->endDate);
}

// Define function to calculate progress
void calculateProgress(struct FinancialGoal *goal, struct FinancePlan *plan) {
    // Calculate progress
    float progress = (goal->amount / plan->income) * 100;

    // Print progress
    printf("Your progress is %f%%\n", progress);
}

int main() {
    // Create finance plan
    struct FinancePlan plan;
    createFinancePlan(&plan);

    // Create financial goal
    struct FinancialGoal goal;
    createFinancialGoal(&goal);

    // Calculate progress
    calculateProgress(&goal, &plan);

    return 0;
}