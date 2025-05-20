//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 50

typedef struct {
    char name[MAX_LENGTH];
    float amount;
} Expense;

typedef struct {
    char name[MAX_LENGTH];
    float amount;
} Income;

typedef struct {
    Expense expenses[MAX_ENTRIES];
    Income incomes[MAX_ENTRIES];
    int expense_count;
    int income_count;
} FinanceTracker;

void initialize_tracker(FinanceTracker *tracker) {
    tracker->expense_count = 0;
    tracker->income_count = 0;
}

void add_income(FinanceTracker *tracker) {
    if (tracker->income_count >= MAX_ENTRIES) {
        printf("Income entries are full!\n");
        return;
    }
    printf("Enter income source: ");
    scanf("%s", tracker->incomes[tracker->income_count].name);
    printf("Enter income amount: ");
    scanf("%f", &tracker->incomes[tracker->income_count].amount);
    tracker->income_count++;
    printf("Income added successfully!\n");
}

void add_expense(FinanceTracker *tracker) {
    if (tracker->expense_count >= MAX_ENTRIES) {
        printf("Expense entries are full!\n");
        return;
    }
    printf("Enter expense category: ");
    scanf("%s", tracker->expenses[tracker->expense_count].name);
    printf("Enter expense amount: ");
    scanf("%f", &tracker->expenses[tracker->expense_count].amount);
    tracker->expense_count++;
    printf("Expense added successfully!\n");
}

void display_incomes(FinanceTracker *tracker) {
    printf("\n---- Incomes ----\n");
    for (int i = 0; i < tracker->income_count; i++) {
        printf("%s: $%.2f\n", tracker->incomes[i].name, tracker->incomes[i].amount);
    }
}

void display_expenses(FinanceTracker *tracker) {
    printf("\n---- Expenses ----\n");
    for (int i = 0; i < tracker->expense_count; i++) {
        printf("%s: $%.2f\n", tracker->expenses[i].name, tracker->expenses[i].amount);
    }
}

float calculate_total_income(FinanceTracker *tracker) {
    float total = 0;
    for (int i = 0; i < tracker->income_count; i++) {
        total += tracker->incomes[i].amount;
    }
    return total;
}

float calculate_total_expenses(FinanceTracker *tracker) {
    float total = 0;
    for (int i = 0; i < tracker->expense_count; i++) {
        total += tracker->expenses[i].amount;
    }
    return total;
}

void calculate_balance(FinanceTracker *tracker) {
    float total_income = calculate_total_income(tracker);
    float total_expenses = calculate_total_expenses(tracker);
    float balance = total_income - total_expenses;
    
    printf("\nTotal Income: $%.2f\n", total_income);
    printf("Total Expenses: $%.2f\n", total_expenses);
    printf("Remaining Balance: $%.2f\n", balance);
}

void display_menu() {
    printf("\n--- Personal Finance Planner ---\n");
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. Display Incomes\n");
    printf("4. Display Expenses\n");
    printf("5. Calculate Balance\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    FinanceTracker tracker;
    initialize_tracker(&tracker);

    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_income(&tracker);
                break;
            case 2:
                add_expense(&tracker);
                break;
            case 3:
                display_incomes(&tracker);
                break;
            case 4:
                display_expenses(&tracker);
                break;
            case 5:
                calculate_balance(&tracker);
                break;
            case 6:
                printf("Thank you for using the Personal Finance Planner. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}