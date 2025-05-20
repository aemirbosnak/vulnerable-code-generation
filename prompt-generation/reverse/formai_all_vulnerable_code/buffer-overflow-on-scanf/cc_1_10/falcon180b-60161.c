//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// struct for user's financial information
struct user_info {
    char name[50];
    int age;
    float income;
    float expenses;
    float savings;
};

// function to get user input for name, age, income, expenses, and savings
void get_user_info(struct user_info *user) {
    printf("Enter your name: ");
    scanf("%s", user->name);

    printf("Enter your age: ");
    scanf("%d", &user->age);

    printf("Enter your monthly income: ");
    scanf("%f", &user->income);

    printf("Enter your monthly expenses: ");
    scanf("%f", &user->expenses);

    printf("Enter your monthly savings: ");
    scanf("%f", &user->savings);
}

// function to calculate user's net income
float calculate_net_income(struct user_info user) {
    return user.income - user.expenses;
}

// function to calculate user's savings percentage
float calculate_savings_percentage(struct user_info user) {
    return (user.savings / user.income) * 100;
}

// main function
int main() {
    struct user_info user;

    // get user input
    get_user_info(&user);

    // calculate net income and savings percentage
    float net_income = calculate_net_income(user);
    float savings_percentage = calculate_savings_percentage(user);

    // print results
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Monthly Income: $%.2f\n", user.income);
    printf("Monthly Expenses: $%.2f\n", user.expenses);
    printf("Monthly Savings: $%.2f\n", user.savings);
    printf("Net Income: $%.2f\n", net_income);
    printf("Savings Percentage: %.2f%%\n", savings_percentage);

    return 0;
}