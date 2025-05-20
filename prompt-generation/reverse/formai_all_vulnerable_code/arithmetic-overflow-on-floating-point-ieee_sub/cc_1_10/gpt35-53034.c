//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

float get_income() {
    float income;
    printf("Enter your monthly income: ");
    scanf("%f", &income);
    return income;
}

float get_expenses() {
    float expenses;
    printf("Enter your monthly expenses: ");
    scanf("%f", &expenses);
    return expenses;
}

void display_menu() {
    printf("\nPersonal Finance Planner Menu\n");
    printf("-----------------------------\n");
    printf("1. Calculate monthly budget\n");
    printf("2. Display savings goal\n");
    printf("3. Exit\n");
}

void calculate_budget(float income, float expenses) {
    float budget = income - expenses;
    if (budget >= 0) {
        printf("You have a monthly budget of $%.2f\n", budget);
    } else {
        printf("You are in a deficit of $%.2f\n", budget);
    }
}

void display_goal(float income, float expenses) {
    float goal = (income - expenses) * 12;
    printf("Your annual savings goal is $%.2f\n", goal);
}

int main() {

    float income = get_income();
    float expenses = get_expenses();

    int choice = 0;
    while (choice != 3) {

        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                calculate_budget(income, expenses);
                break;
            case 2:
                display_goal(income, expenses);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}