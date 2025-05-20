//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: complete
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    float income;
    float expenses;
} User;

void welcomeScreen() {
    printf("===================================\n");
    printf("     Personal Finance Planner      \n");
    printf("===================================\n");
}

void getUserDetails(User *user) {
    printf("Enter your name: ");
    fgets(user->name, sizeof(user->name), stdin);
    user->name[strcspn(user->name, "\n")] = 0; // Removing newline character

    printf("Enter your monthly income: ");
    scanf("%f", &user->income);

    printf("Enter your monthly expenses: ");
    scanf("%f", &user->expenses);
}

void displayBudgetSummary(User user) {
    float remaining = user.income - user.expenses;
    
    printf("\n=== Budget Summary for %s ===\n", user.name);
    printf("Monthly Income: $%.2f\n", user.income);
    printf("Monthly Expenses: $%.2f\n", user.expenses);
    printf("Remaining Income: $%.2f\n", remaining);

    if (remaining > 0) {
        printf("You are saving money! Consider investing it.\n");
    } else if (remaining < 0) {
        printf("You are overspending! Review your expenses.\n");
    } else {
        printf("You are breaking even. Consider adjusting your budget.\n");
    }
}

void trackExpenses(float *expenses) {
    char category[50];
    float amount;

    printf("=== Expense Tracker ===\n");
    while (1) {
        printf("Enter expense category (or 'exit' to stop): ");
        scanf("%s", category);

        if (strcmp(category, "exit") == 0) break;

        printf("Enter the amount spent on %s: ", category);
        scanf("%f", &amount);

        *expenses += amount;
        printf("Added $%.2f to %s. Total expenses now: $%.2f\n", amount, category, *expenses);
    }
}

void investmentRecommendations(float remaining) {
    printf("=== Investment Recommendations ===\n");
    if (remaining > 0) {
        printf("Consider allocating your remaining $%.2f towards:\n", remaining);
        printf("- Stock Market\n");
        printf("- Bonds\n");
        printf("- Mutual Funds\n");
    }
    else {
        printf("No available funds for investment. Focus on reducing expenses.\n");
    }
}

int main() {
    User user;
    user.expenses = 0;

    welcomeScreen();
    getUserDetails(&user);
    trackExpenses(&user.expenses);
    displayBudgetSummary(user);
    investmentRecommendations(user.income - user.expenses);

    return 0;
}