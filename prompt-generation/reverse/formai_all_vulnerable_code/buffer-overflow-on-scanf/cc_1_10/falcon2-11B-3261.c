//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store user information
struct user_info {
    char name[100];
    int age;
    float income;
    float expenses[5];
};

// Function to get user information
void get_user_info(struct user_info *info) {
    printf("Enter your name: ");
    fgets(info->name, sizeof(info->name), stdin);
    
    printf("Enter your age: ");
    scanf("%d", &info->age);
    
    printf("Enter your monthly income: $");
    scanf("%f", &info->income);
    
    printf("Enter your monthly expenses:\n");
    for (int i = 0; i < 5; i++) {
        printf("Expense %d: $", i + 1);
        scanf("%f", &info->expenses[i]);
    }
}

// Function to calculate net income
float calculate_net_income(struct user_info *info) {
    int total_expenses = 0;
    for (int i = 0; i < 5; i++) {
        total_expenses += info->expenses[i];
    }
    
    float net_income = info->income - total_expenses;
    return net_income;
}

// Function to print user information
void print_user_info(struct user_info *info) {
    printf("Name: %s\n", info->name);
    printf("Age: %d\n", info->age);
    printf("Monthly income: $%.2f\n", info->income);
    printf("Monthly expenses:\n");
    for (int i = 0; i < 5; i++) {
        printf("Expense %d: $%.2f\n", i + 1, info->expenses[i]);
    }
    printf("Net income: $%.2f\n", calculate_net_income(info));
}

// Main function
int main() {
    struct user_info user;
    get_user_info(&user);
    print_user_info(&user);
    return 0;
}