//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: safe
// Personal Finance Planner in a safe style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct to store the data
typedef struct {
    char name[50];
    int age;
    float income;
    float expenses;
} User;

// Function to get user input
void getUserInput(User *user) {
    printf("Enter your name: ");
    scanf("%s", user->name);
    printf("Enter your age: ");
    scanf("%d", &user->age);
    printf("Enter your monthly income: ");
    scanf("%f", &user->income);
    printf("Enter your monthly expenses: ");
    scanf("%f", &user->expenses);
}

// Function to calculate the net income
float calculateNetIncome(User *user) {
    return user->income - user->expenses;
}

// Function to calculate the savings rate
float calculateSavingsRate(User *user) {
    return calculateNetIncome(user) / user->income;
}

// Function to calculate the retirement fund
float calculateRetirementFund(User *user) {
    return calculateNetIncome(user) * 0.1;
}

// Function to calculate the investment return
float calculateInvestmentReturn(User *user) {
    return calculateNetIncome(user) * 0.05;
}

// Function to print the results
void printResults(User *user) {
    printf("Name: %s\n", user->name);
    printf("Age: %d\n", user->age);
    printf("Monthly income: %.2f\n", user->income);
    printf("Monthly expenses: %.2f\n", user->expenses);
    printf("Net income: %.2f\n", calculateNetIncome(user));
    printf("Savings rate: %.2f%%\n", calculateSavingsRate(user) * 100);
    printf("Retirement fund: %.2f\n", calculateRetirementFund(user));
    printf("Investment return: %.2f\n", calculateInvestmentReturn(user));
}

int main() {
    User user;
    getUserInput(&user);
    printResults(&user);
    return 0;
}