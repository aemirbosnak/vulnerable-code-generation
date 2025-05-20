//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    float amount;
} Expense;

typedef struct {
    char name[50];
    float amount;
} Income;

typedef struct {
    float totalIncome;
    float totalExpenses;
    float savingsGoal;
    float savingsAchieved;
    Expense expenses[100];
    Income incomes[100];
    int expenseCount;
    int incomeCount;
} Finance;

void addIncome(Finance *finance) {
    Income income;
    printf("Enter income source: ");
    scanf("%s", income.name);
    printf("Enter income amount: ");
    scanf("%f", &income.amount);
    finance->incomes[finance->incomeCount++] = income;
    finance->totalIncome += income.amount;
    printf("Income added successfully!\n\n");
}

void addExpense(Finance *finance) {
    Expense expense;
    printf("Enter expense category: ");
    scanf("%s", expense.name);
    printf("Enter expense amount: ");
    scanf("%f", &expense.amount);
    finance->expenses[finance->expenseCount++] = expense;
    finance->totalExpenses += expense.amount;
    printf("Expense added successfully!\n\n");
}

void setSavingsGoal(Finance *finance) {
    printf("Enter your savings goal: ");
    scanf("%f", &finance->savingsGoal);
    printf("Savings goal set to: %.2f\n\n", finance->savingsGoal);
}

void recordSavings(Finance *finance) {
    printf("Enter amount saved this month: ");
    scanf("%f", &finance->savingsAchieved);
    printf("Savings recorded successfully! You have saved: %.2f\n\n", finance->savingsAchieved);
}

void generateReport(Finance finance) {
    printf("------- Financial Report -------\n");
    printf("Total Income: %.2f\n", finance.totalIncome);
    printf("Total Expenses: %.2f\n", finance.totalExpenses);
    printf("Savings Goal: %.2f\n", finance.savingsGoal);
    printf("Savings Achieved: %.2f\n", finance.savingsAchieved);
    
    printf("\nExpenses Breakdown:\n");
    for (int i = 0; i < finance.expenseCount; i++) {
        printf("- %s: %.2f\n", finance.expenses[i].name, finance.expenses[i].amount);
    }
    
    printf("\nIncome Sources:\n");
    for (int i = 0; i < finance.incomeCount; i++) {
        printf("- %s: %.2f\n", finance.incomes[i].name, finance.incomes[i].amount);
    }
    
    float balance = finance.totalIncome - finance.totalExpenses;
    if (balance > 0) {
        printf("\nYou have a positive balance of: %.2f\n", balance);
    } else if (balance < 0) {
        printf("\nYou have a negative balance of: %.2f\n", balance);
    } else {
        printf("\nYour balance is balanced (Zero).\n");
    }

    printf("Thank you for using this personal finance planner! Keep staying financially conscious!\n");
}

int main() {
    Finance myFinance = {0, 0, 0, 0, {}, {}, 0, 0};
    int choice;

    while (1) {
        printf("\n--- Personal Finance Planner ---\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. Set Savings Goal\n");
        printf("4. Record Savings\n");
        printf("5. Generate Report\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addIncome(&myFinance);
                break;
            case 2:
                addExpense(&myFinance);
                break;
            case 3:
                setSavingsGoal(&myFinance);
                break;
            case 4:
                recordSavings(&myFinance);
                break;
            case 5:
                generateReport(myFinance);
                break;
            case 6:
                printf("Thank you for using the planner! Have a prosperous day!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}