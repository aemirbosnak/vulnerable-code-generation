//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

struct expenses {
    float rent;
    float utilities;
    float groceries;
    float transportation;
    float entertainment;
};

struct income {
    float salary;
    float freelance_income;
    float rental_income;
};

float calculate_savings(struct expenses expenses, struct income income) {
    float total_expenses = expenses.rent + expenses.utilities + expenses.groceries + expenses.transportation + expenses.entertainment;
    float total_income = income.salary + income.freelance_income + income.rental_income;
    float savings = total_income - total_expenses;
    return savings;
}

int main() {
    struct expenses my_expenses;
    struct income my_income;

    printf("Enter your monthly rent: ");
    scanf("%f", &my_expenses.rent);
    printf("Enter your monthly utilities bills: ");
    scanf("%f", &my_expenses.utilities);
    printf("Enter your monthly groceries budget: ");
    scanf("%f", &my_expenses.groceries);
    printf("Enter your monthly transportation costs: ");
    scanf("%f", &my_expenses.transportation);
    printf("Enter your monthly entertainment expenses: ");
    scanf("%f", &my_expenses.entertainment);

    printf("Enter your monthly salary: ");
    scanf("%f", &my_income.salary);
    printf("Enter your monthly freelance income: ");
    scanf("%f", &my_income.freelance_income);
    printf("Enter your monthly rental income: ");
    scanf("%f", &my_income.rental_income);

    float savings = calculate_savings(my_expenses, my_income);
    printf("Your monthly savings: $%.2f\n", savings);

    float annual_savings = savings * 12;
    printf("Your annual savings: $%.2f\n", annual_savings);

    return 0;
}