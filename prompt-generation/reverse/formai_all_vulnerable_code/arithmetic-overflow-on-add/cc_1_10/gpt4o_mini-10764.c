//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char description[100];
    float amount;
} Transaction;

typedef struct {
    Transaction income[MAX_ENTRIES];
    Transaction expenses[MAX_ENTRIES];
    int income_count;
    int expense_count;
    float savings_goal;
} FinancePlanner;

void initialize_planner(FinancePlanner* planner) {
    planner->income_count = 0;
    planner->expense_count = 0;
    planner->savings_goal = 0.0;
}

void add_income(FinancePlanner* planner) {
    if (planner->income_count < MAX_ENTRIES) {
        printf("Enter income description: ");
        scanf(" %[^\n]", planner->income[planner->income_count].description);
        printf("Enter income amount: ");
        scanf("%f", &planner->income[planner->income_count].amount);
        planner->income_count++;
    } else {
        printf("Income list is full!\n");
    }
}

void add_expense(FinancePlanner* planner) {
    if (planner->expense_count < MAX_ENTRIES) {
        printf("Enter expense description: ");
        scanf(" %[^\n]", planner->expenses[planner->expense_count].description);
        printf("Enter expense amount: ");
        scanf("%f", &planner->expenses[planner->expense_count].amount);
        planner->expense_count++;
    } else {
        printf("Expense list is full!\n");
    }
}

void set_savings_goal(FinancePlanner* planner) {
    printf("Enter your savings goal: ");
    scanf("%f", &planner->savings_goal);
}

float calculate_total_income(FinancePlanner* planner) {
    float total = 0.0;
    for (int i = 0; i < planner->income_count; i++) {
        total += planner->income[i].amount;
    }
    return total;
}

float calculate_total_expenses(FinancePlanner* planner) {
    float total = 0.0;
    for (int i = 0; i < planner->expense_count; i++) {
        total += planner->expenses[i].amount;
    }
    return total;
}

void display_summary(FinancePlanner* planner) {
    float total_income = calculate_total_income(planner);
    float total_expenses = calculate_total_expenses(planner);
    float net_savings = total_income - total_expenses;

    printf("\n--- Financial Summary ---\n");
    printf("Total Income: $%.2f\n", total_income);
    printf("Total Expenses: $%.2f\n", total_expenses);
    printf("Net Savings: $%.2f\n", net_savings);
    printf("Savings Goal: $%.2f\n", planner->savings_goal);
    if (net_savings >= planner->savings_goal) {
        printf("Congratulations! You've met your savings goal!\n");
    } else {
        printf("You are $%.2f away from your savings goal.\n", planner->savings_goal - net_savings);
    }
}

void print_transactions(FinancePlanner* planner) {
    printf("\n--- Income Transactions ---\n");
    for (int i = 0; i < planner->income_count; i++) {
        printf("%s: $%.2f\n", planner->income[i].description, planner->income[i].amount);
    }
    
    printf("\n--- Expense Transactions ---\n");
    for (int i = 0; i < planner->expense_count; i++) {
        printf("%s: $%.2f\n", planner->expenses[i].description, planner->expenses[i].amount);
    }
}

int main() {
    FinancePlanner planner;
    initialize_planner(&planner);

    int choice;
    do {
        printf("\n--- Personal Finance Planner ---\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. Set Savings Goal\n");
        printf("4. Display Summary\n");
        printf("5. Print Transactions\n");
        printf("6. Exit\n");
        printf("Choose an option (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_income(&planner);
                break;
            case 2:
                add_expense(&planner);
                break;
            case 3:
                set_savings_goal(&planner);
                break;
            case 4:
                display_summary(&planner);
                break;
            case 5:
                print_transactions(&planner);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}