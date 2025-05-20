//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: real-life
// C Personal Finance Planner Example Program

#include <stdio.h>
#include <stdlib.h>

// Struct to store user input
typedef struct {
    char name[50];
    int age;
    float income;
    float expenses;
    float savings;
} User;

// Function to print the user's financial information
void printUserInfo(User user) {
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Income: $%.2f\n", user.income);
    printf("Expenses: $%.2f\n", user.expenses);
    printf("Savings: $%.2f\n", user.savings);
}

// Function to calculate the user's net worth
float calculateNetWorth(User user) {
    return user.income - user.expenses + user.savings;
}

int main() {
    // Get user input
    User user;
    printf("Enter your name: ");
    scanf("%s", user.name);
    printf("Enter your age: ");
    scanf("%d", &user.age);
    printf("Enter your annual income: ");
    scanf("%f", &user.income);
    printf("Enter your annual expenses: ");
    scanf("%f", &user.expenses);
    printf("Enter your savings: ");
    scanf("%f", &user.savings);

    // Print the user's financial information
    printUserInfo(user);

    // Calculate the user's net worth
    float netWorth = calculateNetWorth(user);
    printf("Net worth: $%.2f\n", netWorth);

    return 0;
}