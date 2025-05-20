//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: scalable
// Personal Finance Planner
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store user data
typedef struct {
    char name[256];
    float income;
    float expenses[10];
    float savings;
    float debt[10];
    int num_expenses;
    int num_debt;
} User;

// Function to calculate the total expenses
float total_expenses(User user) {
    float total = 0;
    for (int i = 0; i < user.num_expenses; i++) {
        total += user.expenses[i];
    }
    return total;
}

// Function to calculate the total debt
float total_debt(User user) {
    float total = 0;
    for (int i = 0; i < user.num_debt; i++) {
        total += user.debt[i];
    }
    return total;
}

// Function to calculate the net income
float net_income(User user) {
    return user.income - total_expenses(user) - total_debt(user);
}

// Function to calculate the savings rate
float savings_rate(User user) {
    return (user.savings / net_income(user)) * 100;
}

// Function to calculate the debt ratio
float debt_ratio(User user) {
    return total_debt(user) / net_income(user);
}

// Function to calculate the financial status
char* financial_status(User user) {
    if (net_income(user) > 0 && savings_rate(user) > 10 && debt_ratio(user) < 0.5) {
        return "Affluent";
    } else if (net_income(user) > 0 && savings_rate(user) > 5 && debt_ratio(user) < 0.5) {
        return "Comfortable";
    } else if (net_income(user) > 0 && savings_rate(user) > 2 && debt_ratio(user) < 0.5) {
        return "Stable";
    } else if (net_income(user) > 0 && savings_rate(user) > 0 && debt_ratio(user) < 0.5) {
        return "Cautious";
    } else {
        return "Risky";
    }
}

// Main function
int main() {
    User user;
    printf("Enter your name: ");
    scanf("%s", user.name);
    printf("Enter your income: ");
    scanf("%f", &user.income);
    printf("Enter the number of expenses: ");
    scanf("%d", &user.num_expenses);
    for (int i = 0; i < user.num_expenses; i++) {
        printf("Enter expense %d: ", i + 1);
        scanf("%f", &user.expenses[i]);
    }
    printf("Enter your savings: ");
    scanf("%f", &user.savings);
    printf("Enter the number of debts: ");
    scanf("%d", &user.num_debt);
    for (int i = 0; i < user.num_debt; i++) {
        printf("Enter debt %d: ", i + 1);
        scanf("%f", &user.debt[i]);
    }
    printf("Net income: %.2f\n", net_income(user));
    printf("Savings rate: %.2f%%\n", savings_rate(user));
    printf("Debt ratio: %.2f\n", debt_ratio(user));
    printf("Financial status: %s\n", financial_status(user));
    return 0;
}