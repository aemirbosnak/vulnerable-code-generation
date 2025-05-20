//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    double amount;
} Expense;

typedef struct {
    double income;
    Expense expenses[MAX_EXPENSES];
    int expense_count;
    double savings_goal;
} PersonalFinance;

void initialize_finance(PersonalFinance *finance) {
    finance->income = 0.0;
    finance->expense_count = 0;
    finance->savings_goal = 0.0;
}

void add_income(PersonalFinance *finance) {
    printf("Enter your monthly income: $");
    scanf("%lf", &finance->income);
    printf("Income updated to: $%.2lf\n", finance->income);
}

void add_expense(PersonalFinance *finance) {
    if (finance->expense_count >= MAX_EXPENSES) {
        printf("Maximum number of expenses reached.\n");
        return;
    }
    
    Expense new_expense;
    printf("Enter the name of the expense: ");
    scanf("%s", new_expense.name);
    printf("Enter the amount for %s: $", new_expense.name);
    scanf("%lf", &new_expense.amount);
    
    finance->expenses[finance->expense_count] = new_expense;
    finance->expense_count++;
    printf("%s added with an amount of: $%.2lf\n", new_expense.name, new_expense.amount);
}

void set_savings_goal(PersonalFinance *finance) {
    printf("Enter your savings goal: $");
    scanf("%lf", &finance->savings_goal);
    printf("Savings goal set to: $%.2lf\n", finance->savings_goal);
}

void display_summary(PersonalFinance *finance) {
    double total_expenses = 0.0;
    printf("\n--- Financial Summary ---\n");
    printf("Monthly Income: $%.2lf\n", finance->income);
    
    printf("Expenses:\n");
    for (int i = 0; i < finance->expense_count; i++) {
        printf(" - %s: $%.2lf\n", finance->expenses[i].name, finance->expenses[i].amount);
        total_expenses += finance->expenses[i].amount;
    }
    
    printf("Total Expenses: $%.2lf\n", total_expenses);
    printf("Savings Goal: $%.2lf\n", finance->savings_goal);
    
    double remaining_balance = finance->income - total_expenses;
    printf("Remaining Balance: $%.2lf\n", remaining_balance);
    
    if (remaining_balance >= finance->savings_goal) {
        printf("Congratulations! You can achieve your savings goal!\n");
    } else {
        printf("You are short of your savings goal by: $%.2lf\n", finance->savings_goal - remaining_balance);
    }
}

void display_menu() {
    printf("\n--- Personal Finance Planner ---\n");
    printf("1. Set Income\n");
    printf("2. Add Expense\n");
    printf("3. Set Savings Goal\n");
    printf("4. View Summary\n");
    printf("5. Exit\n");
}

int main() {
    PersonalFinance finance;
    initialize_finance(&finance);
    
    int choice;
    do {
        display_menu();
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_income(&finance);
                break;
            case 2:
                add_expense(&finance);
                break;
            case 3:
                set_savings_goal(&finance);
                break;
            case 4:
                display_summary(&finance);
                break;
            case 5:
                printf("Exiting the planner. Goodbye!\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}