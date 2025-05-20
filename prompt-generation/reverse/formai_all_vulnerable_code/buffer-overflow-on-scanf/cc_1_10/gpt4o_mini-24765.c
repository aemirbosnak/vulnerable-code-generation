//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[30];
    float amount;
} Expense;

typedef struct {
    float income;
    Expense expenses[MAX_EXPENSES];
    int expense_count;
} Finance;

// Function declarations
void addExpense(Finance *finance);
void viewExpenses(const Finance *finance);
void calculateSavings(const Finance *finance);
void printReport(const Finance *finance);
void displayMenu();
void clearInputBuffer();

int main() {
    Finance finance = {0};
    finance.expense_count = 0;
    
    printf("Welcome to the Personal Finance Planner!\n");
    while (1) {
        displayMenu();
        int choice;
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your monthly income: ");
                scanf("%f", &finance.income);
                break;
            case 2:
                addExpense(&finance);
                break;
            case 3:
                viewExpenses(&finance);
                break;
            case 4:
                calculateSavings(&finance);
                break;
            case 5:
                printReport(&finance);
                break;
            case 6:
                printf("Exiting the program. Thank you!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n---- Menu ----\n");
    printf("1. Set Income\n");
    printf("2. Add Expense\n");
    printf("3. View Expenses\n");
    printf("4. Calculate Savings\n");
    printf("5. Print Financial Report\n");
    printf("6. Exit\n");
}

void addExpense(Finance *finance) {
    if (finance->expense_count >= MAX_EXPENSES) {
        printf("Expense limit reached. Cannot add more expenses.\n");
        return;
    }
    
    Expense new_expense;
    printf("Enter the name of the expense: ");
    clearInputBuffer();
    fgets(new_expense.name, sizeof(new_expense.name), stdin);
    
    printf("Enter the amount of the expense: ");
    scanf("%f", &new_expense.amount);
    
    finance->expenses[finance->expense_count++] = new_expense;
    printf("Expense '%s' added successfully!\n", new_expense.name);
}

void viewExpenses(const Finance *finance) {
    if (finance->expense_count == 0) {
        printf("No expenses recorded yet.\n");
        return;
    }

    printf("\n--- Expense List ---\n");
    for (int i = 0; i < finance->expense_count; i++) {
        printf("Expense %d: %s - %.2f\n", i+1, finance->expenses[i].name, finance->expenses[i].amount);
    }
}

void calculateSavings(const Finance *finance) {
    float total_expenses = 0.0;
    
    for (int i = 0; i < finance->expense_count; i++) {
        total_expenses += finance->expenses[i].amount;
    }

    float savings = finance->income - total_expenses;
    if (savings < 0) {
        printf("You are overspending by %.2f!\n", -savings);
    } else {
        printf("You are saving %.2f this month!\n", savings);
    }
}

void printReport(const Finance *finance) {
    printf("\n--- Financial Report ---\n");
    printf("Monthly Income: %.2f\n", finance->income);
    printf("Total Expenses: ");
    
    float total_expenses = 0.0;
    for (int i = 0; i < finance->expense_count; i++) {
        total_expenses += finance->expenses[i].amount;
    }
    
    printf("%.2f\n", total_expenses);
    printf("Remaining Savings: %.2f\n", finance->income - total_expenses);
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}