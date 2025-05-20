//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_SIZE 50

typedef struct {
    char name[NAME_SIZE];
    float amount;
} Entry;

Entry income[MAX_ENTRIES];
int income_count = 0;

Entry expenses[MAX_ENTRIES];
int expense_count = 0;

void add_income();
void add_expense();
void view_summary();
float calculate_total(Entry entries[], int count);

int main() {
    int choice;

    printf("=== Personal Finance Planner ===\n");
    do {
        printf("\nMenu:\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. View Summary\n");
        printf("4. Exit\n");
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
                view_summary();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void add_income() {
    if (income_count >= MAX_ENTRIES) {
        printf("You have reached the maximum number of income entries.\n");
        return;
    }

    printf("Enter income name: ");
    scanf(" %[^\n]", income[income_count].name);
    printf("Enter income amount: ");
    scanf("%f", &income[income_count].amount);
    
    income_count++;
    printf("Income added successfully!\n");
}

void add_expense() {
    if (expense_count >= MAX_ENTRIES) {
        printf("You have reached the maximum number of expense entries.\n");
        return;
    }

    printf("Enter expense name: ");
    scanf(" %[^\n]", expenses[expense_count].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[expense_count].amount);
    
    expense_count++;
    printf("Expense added successfully!\n");
}

void view_summary() {
    float total_income = calculate_total(income, income_count);
    float total_expenses = calculate_total(expenses, expense_count);
    float balance = total_income - total_expenses;

    printf("\n=== Financial Summary ===\n");
    printf("Total Income: $%.2f\n", total_income);
    printf("Total Expenses: $%.2f\n", total_expenses);
    printf("Balance: $%.2f\n", balance);

    if (balance >= 0) {
        printf("You are within your budget!\n");
    } else {
        printf("You are over your budget! Consider reducing expenses.\n");
    }
}

float calculate_total(Entry entries[], int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += entries[i].amount;
    }
    return total;
}