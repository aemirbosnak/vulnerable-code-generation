//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: high level of detail
#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char description[50];
    float amount;
} Entry;

typedef struct {
    Entry income[MAX_ENTRIES];
    int income_count;
    Entry expenses[MAX_ENTRIES];
    int expenses_count;
} Finance;

void add_income(Finance *finance) {
    if (finance->income_count < MAX_ENTRIES) {
        printf("Enter income description: ");
        scanf(" %[^\n]", finance->income[finance->income_count].description);
        printf("Enter income amount: ");
        scanf("%f", &finance->income[finance->income_count].amount);
        finance->income_count++;
        printf("Income added successfully!\n");
    } else {
        printf("Income limit reached!\n");
    }
}

void add_expense(Finance *finance) {
    if (finance->expenses_count < MAX_ENTRIES) {
        printf("Enter expense description: ");
        scanf(" %[^\n]", finance->expenses[finance->expenses_count].description);
        printf("Enter expense amount: ");
        scanf("%f", &finance->expenses[finance->expenses_count].amount);
        finance->expenses_count++;
        printf("Expense added successfully!\n");
    } else {
        printf("Expense limit reached!\n");
    }
}

void view_summary(Finance *finance) {
    float total_income = 0, total_expenses = 0;

    printf("\nIncome Summary:\n");
    for (int i = 0; i < finance->income_count; i++) {
        printf("%s: %.2f\n", finance->income[i].description, finance->income[i].amount);
        total_income += finance->income[i].amount;
    }

    printf("\nExpenses Summary:\n");
    for (int i = 0; i < finance->expenses_count; i++) {
        printf("%s: %.2f\n", finance->expenses[i].description, finance->expenses[i].amount);
        total_expenses += finance->expenses[i].amount;
    }

    printf("\nTotal Income: %.2f\n", total_income);
    printf("Total Expenses: %.2f\n", total_expenses);
    printf("Net Income: %.2f\n", total_income - total_expenses);
}

void savings_suggestion(Finance *finance) {
    float total_income = 0, total_expenses = 0;

    for (int i = 0; i < finance->income_count; i++) {
        total_income += finance->income[i].amount;
    }

    for (int i = 0; i < finance->expenses_count; i++) {
        total_expenses += finance->expenses[i].amount;
    }

    float savings_target = total_income * 0.20; // 20% saving target
    float current_savings = total_income - total_expenses;

    printf("\nSavings Target: %.2f\n", savings_target);
    printf("Current Savings: %.2f\n", current_savings);
    
    if(current_savings < savings_target) {
        printf("Recommendation: You need to cut down on your expenses to reach your saving goal!\n");
    } else {
        printf("Great job! You are on track to meet your savings goal!\n");
    }
}

int main() {
    Finance finance;
    finance.income_count = 0;
    finance.expenses_count = 0;

    int choice;

    do {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. View Summary\n");
        printf("4. Savings Suggestion\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_income(&finance);
                break;
            case 2:
                add_expense(&finance);
                break;
            case 3:
                view_summary(&finance);
                break;
            case 4:
                savings_suggestion(&finance);
                break;
            case 5:
                printf("Exiting the program. Have a great day!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}