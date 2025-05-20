//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
} Expense;

typedef struct {
    char name[MAX_NAME_LENGTH];
    float income;
    Expense expenses[MAX_CATEGORIES];
    int expense_count;
} FinancialSummary;

void inputIncome(FinancialSummary *summary) {
    printf("What is your total monthly income? ");
    scanf("%f", &summary->income);
}

void inputExpenses(FinancialSummary *summary) {
    char answer;
    summary->expense_count = 0;

    do {
        if (summary->expense_count >= MAX_CATEGORIES) {
            printf("You've reached the maximum number of expense categories.\n");
            break;
        }
        
        printf("Enter the name of the expense category: ");
        scanf("%s", summary->expenses[summary->expense_count].name);

        printf("How much do you spend on %s monthly? ", summary->expenses[summary->expense_count].name);
        scanf("%f", &summary->expenses[summary->expense_count].amount);

        summary->expense_count++;

        printf("Do you have more expenses to add? (y/n): ");
        scanf(" %c", &answer);
    } while (answer == 'y' || answer == 'Y');
}

void printSummary(const FinancialSummary *summary) {
    float total_expenses = 0;

    printf("\n----- Monthly Financial Summary -----\n");
    printf("Total Income: $%.2f\n", summary->income);
    printf("Expenses:\n");

    for (int i = 0; i < summary->expense_count; i++) {
        printf("- %s: $%.2f\n", summary->expenses[i].name, summary->expenses[i].amount);
        total_expenses += summary->expenses[i].amount;
    }

    printf("Total Expenses: $%.2f\n", total_expenses);

    if (summary->income >= total_expenses) {
        printf("Congratulations! You have a surplus of: $%.2f\n", summary->income - total_expenses);
    } else {
        printf("Uh-oh! You have a deficit of: $%.2f\n", total_expenses - summary->income);
    }

    float savings_percentage = (summary->income - total_expenses) / summary->income * 100;
    printf("Your savings percentage for this month is: %.2f%%\n", savings_percentage > 0 ? savings_percentage : 0);
}

int main() {
    FinancialSummary summary;
    summary.expense_count = 0;  // Initialize the expense count

    printf("Welcome to your Personal Finance Planner!\n");
    inputIncome(&summary);
    inputExpenses(&summary);
    printSummary(&summary);

    return 0;
}