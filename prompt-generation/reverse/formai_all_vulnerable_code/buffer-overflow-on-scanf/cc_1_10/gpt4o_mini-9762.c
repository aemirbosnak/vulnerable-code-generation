//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50

typedef struct {
    char category[NAME_LENGTH];
    float amount;
} Expense;

typedef struct {
    char category[NAME_LENGTH];
    float amount;
} Income;

Expense expenses[MAX_ENTRIES];
Income incomes[MAX_ENTRIES];
int expense_count = 0, income_count = 0;

void add_expense() {
    if (expense_count >= MAX_ENTRIES) {
        printf("Cannot add more expenses.\n");
        return;
    }
    printf("Enter expense category: ");
    scanf("%s", expenses[expense_count].category);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[expense_count].amount);
    expense_count++;
    printf("Expense added successfully!\n");
}

void add_income() {
    if (income_count >= MAX_ENTRIES) {
        printf("Cannot add more incomes.\n");
        return;
    }
    printf("Enter income category: ");
    scanf("%s", incomes[income_count].category);
    printf("Enter income amount: ");
    scanf("%f", &incomes[income_count].amount);
    income_count++;
    printf("Income added successfully!\n");
}

void display_expenses() {
    printf("\n--- Expenses ---\n");
    for (int i = 0; i < expense_count; i++) {
        printf("Category: %s, Amount: %.2f\n", expenses[i].category, expenses[i].amount);
    }
}

void display_incomes() {
    printf("\n--- Incomes ---\n");
    for (int i = 0; i < income_count; i++) {
        printf("Category: %s, Amount: %.2f\n", incomes[i].category, incomes[i].amount);
    }
}

float calculate_total_expenses() {
    float total = 0;
    for (int i = 0; i < expense_count; i++) {
        total += expenses[i].amount;
    }
    return total;
}

float calculate_total_incomes() {
    float total = 0;
    for (int i = 0; i < income_count; i++) {
        total += incomes[i].amount;
    }
    return total;
}

void display_summary() {
    float total_income = calculate_total_incomes();
    float total_expense = calculate_total_expenses();
    float balance = total_income - total_expense;

    printf("\n--- Summary ---\n");
    printf("Total Income: %.2f\n", total_income);
    printf("Total Expenses: %.2f\n", total_expense);
    printf("Balance: %.2f\n", balance);
}

int main() {
    int choice;
    do {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. Display Incomes\n");
        printf("4. Display Expenses\n");
        printf("5. Display Summary\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_income();
                break;
            case 2:
                add_expense();
                break;
            case 3:
                display_incomes();
                break;
            case 4:
                display_expenses();
                break;
            case 5:
                display_summary();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    } while (choice != 6);

    return 0;
}