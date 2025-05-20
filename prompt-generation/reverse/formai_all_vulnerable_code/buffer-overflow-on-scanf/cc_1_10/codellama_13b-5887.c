//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Structure to store user data
struct UserData {
    char name[50];
    int age;
    float income;
    float expenses[5];
};

// Function to display the user data
void displayUserData(struct UserData data) {
    printf("Name: %s\n", data.name);
    printf("Age: %d\n", data.age);
    printf("Income: %.2f\n", data.income);
    printf("Expenses:\n");
    for (int i = 0; i < 5; i++) {
        printf("  %d: %.2f\n", i, data.expenses[i]);
    }
}

// Function to calculate the user's net income
float calculateNetIncome(struct UserData data) {
    float netIncome = data.income;
    for (int i = 0; i < 5; i++) {
        netIncome -= data.expenses[i];
    }
    return netIncome;
}

// Function to calculate the user's savings rate
float calculateSavingsRate(struct UserData data) {
    float savingsRate = calculateNetIncome(data) / data.income;
    return savingsRate;
}

// Function to calculate the user's financial goals
void calculateFinancialGoals(struct UserData data) {
    float savingsRate = calculateSavingsRate(data);
    float financialGoals[] = {0.5, 0.75, 1.0};
    for (int i = 0; i < 3; i++) {
        printf("Financial Goal %d: %.2f\n", i + 1, financialGoals[i] * savingsRate);
    }
}

int main() {
    struct UserData data;
    printf("Enter your name: ");
    scanf("%s", data.name);
    printf("Enter your age: ");
    scanf("%d", &data.age);
    printf("Enter your income: ");
    scanf("%f", &data.income);
    printf("Enter your expenses: ");
    for (int i = 0; i < 5; i++) {
        scanf("%f", &data.expenses[i]);
    }
    displayUserData(data);
    printf("Net Income: %.2f\n", calculateNetIncome(data));
    printf("Savings Rate: %.2f\n", calculateSavingsRate(data));
    calculateFinancialGoals(data);
    return 0;
}