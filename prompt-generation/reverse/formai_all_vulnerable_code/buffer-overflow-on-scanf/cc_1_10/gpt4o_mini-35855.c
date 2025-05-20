//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
} Expense;

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
} Income;

typedef struct {
    Expense expenses[MAX_ENTRIES];
    Income incomes[MAX_ENTRIES];
    int expense_count;
    int income_count;
} FinancePlanner;

void add_income(FinancePlanner* planner) {
    if (planner->income_count < MAX_ENTRIES) {
        printf("Enter the name of the income source: ");
        scanf("%s", planner->incomes[planner->income_count].name);
        printf("Enter the amount: ");
        scanf("%f", &planner->incomes[planner->income_count].amount);
        planner->income_count++;
        printf("Income added successfully!\n");
    } else {
        printf("Income list is full! Cannot add more incomes.\n");
    }
}

void add_expense(FinancePlanner* planner) {
    if (planner->expense_count < MAX_ENTRIES) {
        printf("Enter the name of the expense: ");
        scanf("%s", planner->expenses[planner->expense_count].name);
        printf("Enter the amount: ");
        scanf("%f", &planner->expenses[planner->expense_count].amount);
        planner->expense_count++;
        printf("Expense added successfully!\n");
    } else {
        printf("Expense list is full! Cannot add more expenses.\n");
    }
}

void view_incomes(const FinancePlanner* planner) {
    printf("\n--- List of Incomes ---\n");
    for (int i = 0; i < planner->income_count; i++) {
        printf("%s: $%.2f\n", planner->incomes[i].name, planner->incomes[i].amount);
    }
}

void view_expenses(const FinancePlanner* planner) {
    printf("\n--- List of Expenses ---\n");
    for (int i = 0; i < planner->expense_count; i++) {
        printf("%s: $%.2f\n", planner->expenses[i].name, planner->expenses[i].amount);
    }
}

void calculate_balance(const FinancePlanner* planner) {
    float total_income = 0;
    float total_expense = 0;

    for (int i = 0; i < planner->income_count; i++) {
        total_income += planner->incomes[i].amount;
    }
    for (int i = 0; i < planner->expense_count; i++) {
        total_expense += planner->expenses[i].amount;
    }

    float balance = total_income - total_expense;
    printf("\n--- Your Balance ---\n");
    printf("Total Income: $%.2f\n", total_income);
    printf("Total Expenses: $%.2f\n", total_expense);
    printf("Your Balance: $%.2f\n", balance);
}

void display_menu() {
    printf("\n--- Personal Finance Planner Menu ---\n");
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. View Incomes\n");
    printf("4. View Expenses\n");
    printf("5. Calculate Balance\n");
    printf("6. Exit\n");
    printf("Please choose an option (1-6): ");
}

int main() {
    FinancePlanner planner = { .expense_count = 0, .income_count = 0 };
    int choice;

    printf("🎉 Welcome to Your Happy Finance Planner! 🎉\n");

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_income(&planner);
                break;
            case 2:
                add_expense(&planner);
                break;
            case 3:
                view_incomes(&planner);
                break;
            case 4:
                view_expenses(&planner);
                break;
            case 5:
                calculate_balance(&planner);
                break;
            case 6:
                printf("🌟 Thank you for using your Happy Finance Planner! Have a great day! 🌟\n");
                exit(0);
            default:
                printf("🚫 Invalid option. Please try again! 🚫\n");
                break;
        }
    }

    return 0;
}