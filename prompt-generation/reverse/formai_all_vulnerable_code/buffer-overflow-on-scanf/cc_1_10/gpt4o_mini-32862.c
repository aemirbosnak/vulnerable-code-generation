//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float amount;
} Income;

typedef struct {
    char name[50];
    float amount;
} Expense;

typedef struct {
    char name[50];
    float goal_amount;
    float current_amount;
} SavingsGoal;

Income incomes[MAX_ITEMS];
Expense expenses[MAX_ITEMS];
SavingsGoal savingsGoals[MAX_ITEMS];
int incomeCount = 0, expenseCount = 0, savingsGoalCount = 0;

void addIncome();
void addExpense();
void addSavingsGoal();
void displayFinances();
void displayHelp();

int main() {
    int choice;

    do {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. Add Savings Goal\n");
        printf("4. Display Finances\n");
        printf("5. Help\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addIncome();
                break;
            case 2:
                addExpense();
                break;
            case 3:
                addSavingsGoal();
                break;
            case 4:
                displayFinances();
                break;
            case 5:
                displayHelp();
                break;
            case 6:
                printf("Exiting. Have a great day!\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void addIncome() {
    if (incomeCount < MAX_ITEMS) {
        printf("Enter income source name: ");
        scanf("%s", incomes[incomeCount].name);
        printf("Enter amount: ");
        scanf("%f", &incomes[incomeCount].amount);
        incomeCount++;
        printf("Income added successfully!\n");
    } else {
        printf("Income list is full, cannot add more incomes.\n");
    }
}

void addExpense() {
    if (expenseCount < MAX_ITEMS) {
        printf("Enter expense name: ");
        scanf("%s", expenses[expenseCount].name);
        printf("Enter amount: ");
        scanf("%f", &expenses[expenseCount].amount);
        expenseCount++;
        printf("Expense added successfully!\n");
    } else {
        printf("Expense list is full, cannot add more expenses.\n");
    }
}

void addSavingsGoal() {
    if (savingsGoalCount < MAX_ITEMS) {
        printf("Enter savings goal name: ");
        scanf("%s", savingsGoals[savingsGoalCount].name);
        printf("Enter goal amount: ");
        scanf("%f", &savingsGoals[savingsGoalCount].goal_amount);
        savingsGoals[savingsGoalCount].current_amount = 0; // Start with 0 saved
        savingsGoalCount++;
        printf("Savings goal added successfully!\n");
    } else {
        printf("Savings goals list is full, cannot add more goals.\n");
    }
}

void displayFinances() {
    float totalIncome = 0, totalExpenses = 0;
    
    printf("\n=== Financial Summary ===\n");
    
    printf("\nIncomes:\n");
    for (int i = 0; i < incomeCount; i++) {
        printf("%s: $%.2f\n", incomes[i].name, incomes[i].amount);
        totalIncome += incomes[i].amount;
    }
    printf("Total Income: $%.2f\n", totalIncome);

    printf("\nExpenses:\n");
    for (int i = 0; i < expenseCount; i++) {
        printf("%s: $%.2f\n", expenses[i].name, expenses[i].amount);
        totalExpenses += expenses[i].amount;
    }
    printf("Total Expenses: $%.2f\n", totalExpenses);

    printf("\nSavings Goals:\n");
    for (int i = 0; i < savingsGoalCount; i++) {
        printf("%s - Goal: $%.2f, Saved: $%.2f\n", savingsGoals[i].name, savingsGoals[i].goal_amount, savingsGoals[i].current_amount);
    }

    float balance = totalIncome - totalExpenses;
    printf("\nOverall Balance: $%.2f\n", balance);
}

void displayHelp() {
    printf("\n=== Help ===\n");
    printf("Use the options to manage your personal finances.\n");
    printf("1 - Add your income sources and amounts.\n");
    printf("2 - Record your expenses.\n");
    printf("3 - Set savings goals and track them.\n");
    printf("4 - View the overview of your finances.\n");
    printf("5 - Shows this help menu.\n");
    printf("6 - Exit the application.\n");
}