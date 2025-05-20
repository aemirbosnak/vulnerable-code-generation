//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INCOME 10000
#define MAX_EXPENSES 1000
#define MAX_SAVINGS 1000

struct finance_planner {
    int income;
    int expenses;
    int savings;
};

void print_menu() {
    printf("1. View Finance Planner\n");
    printf("2. Add Income\n");
    printf("3. Add Expenses\n");
    printf("4. Add Savings\n");
    printf("5. Exit\n");
}

void print_finance_planner(struct finance_planner *planner) {
    printf("Income: %d\n", planner->income);
    printf("Expenses: %d\n", planner->expenses);
    printf("Savings: %d\n", planner->savings);
}

void add_income(struct finance_planner *planner, int amount) {
    planner->income += amount;
}

void add_expenses(struct finance_planner *planner, int amount) {
    planner->expenses += amount;
}

void add_savings(struct finance_planner *planner, int amount) {
    planner->savings += amount;
}

int main() {
    struct finance_planner planner;
    planner.income = 0;
    planner.expenses = 0;
    planner.savings = 0;

    int option;
    do {
        print_menu();
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                print_finance_planner(&planner);
                break;
            case 2:
                printf("Enter income amount: ");
                int income;
                scanf("%d", &income);
                add_income(&planner, income);
                break;
            case 3:
                printf("Enter expenses amount: ");
                int expenses;
                scanf("%d", &expenses);
                add_expenses(&planner, expenses);
                break;
            case 4:
                printf("Enter savings amount: ");
                int savings;
                scanf("%d", &savings);
                add_savings(&planner, savings);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    } while (option != 5);

    return 0;
}