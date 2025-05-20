//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// structure to hold financial information
struct PersonalFinance {
    double monthly_income;
    double monthly_expenses;
    double savings_goal;
    double current_savings;
};

// function to display main menu
void displayMenu() {
    printf("\n#### PERSONAL FINANCE PLANNER ####\n\n");
    printf("1. View Financial Information\n");
    printf("2. Update Monthly Income\n");
    printf("3. Update Monthly Expenses\n");
    printf("4. Update Savings Goal\n");
    printf("5. Make a Deposit\n");
    printf("6. Make a Withdrawal\n");
    printf("7. Exit\n\n");
}

// function to display current financial information
void viewInformation(struct PersonalFinance finance) {
    printf("\n#### FINANCIAL INFORMATION ####\n\n");
    printf("Monthly Income: %.2lf\n", finance.monthly_income);
    printf("Monthly Expenses: %.2lf\n", finance.monthly_expenses);
    printf("Savings Goal: %.2lf\n", finance.savings_goal);
    printf("Current Savings: %.2lf\n\n", finance.current_savings);
}

// function to update monthly income
void updateIncome(struct PersonalFinance *finance) {
    double new_income;
    printf("Enter new monthly income: ");
    scanf("%lf", &new_income);
    finance->monthly_income = new_income;
    printf("Monthly income updated successfully!\n\n");
}

// function to update monthly expenses
void updateExpenses(struct PersonalFinance *finance) {
    double new_expenses;
    printf("Enter new monthly expenses: ");
    scanf("%lf", &new_expenses);
    finance->monthly_expenses = new_expenses;
    printf("Monthly expenses updated successfully!\n\n");
}

// function to update savings goal
void updateSavingsGoal(struct PersonalFinance *finance) {
    double new_goal;
    printf("Enter new savings goal: ");
    scanf("%lf", &new_goal);
    finance->savings_goal = new_goal;
    printf("Savings goal updated successfully!\n\n");
}

// function to make a deposit
void makeDeposit(struct PersonalFinance *finance) {
    double deposit_amount;
    printf("Enter deposit amount: ");
    scanf("%lf", &deposit_amount);
    finance->current_savings += deposit_amount;
    printf("Deposit made successfully!\n\n");
}

// function to make a withdrawal
void makeWithdrawal(struct PersonalFinance *finance) {
    double withdraw_amount;
    printf("Enter withdrawal amount: ");
    scanf("%lf", &withdraw_amount);
    if (finance->current_savings >= withdraw_amount) {
        finance->current_savings -= withdraw_amount;
        printf("Withdrawal made successfully!\n\n");
    } else {
        printf("Insufficient funds for withdrawal.\n\n");
    }
}

// main function
int main() {
    struct PersonalFinance finance = {
        .monthly_income = 5000.0,
        .monthly_expenses = 3000.0,
        .savings_goal = 20000.0,
        .current_savings = 5000.0
    };
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                viewInformation(finance);
                break;
            case 2:
                updateIncome(&finance);
                break;
            case 3:
                updateExpenses(&finance);
                break;
            case 4:
                updateSavingsGoal(&finance);
                break;
            case 5:
                makeDeposit(&finance);
                break;
            case 6:
                makeWithdrawal(&finance);
                break;
            case 7:
                printf("Exiting Personal Finance Planner. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 7);
    return 0;
}