//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORY 30

typedef struct {
    char category[MAX_CATEGORY];
    float amount;
} Expense;

typedef struct {
    float income;
    Expense expenses[MAX_EXPENSES];
    int expense_count;
} Finance;

// Function prototypes
void inputFinance(Finance* finance);
void displayReport(const Finance* finance);
float calculateTotalExpenses(const Finance* finance);
float calculateBalance(const Finance* finance);
void displayExpenseBreakdown(const Finance* finance);

int main() {
    Finance finance = {0, {}, 0};
    
    printf("Welcome to the Personal Finance Planner!\n");
    inputFinance(&finance);
    displayReport(&finance);
    
    return 0;
}

void inputFinance(Finance* finance) {
    printf("Enter your monthly income: ");
    scanf("%f", &finance->income);

    printf("Enter the number of expense categories: ");
    scanf("%d", &finance->expense_count);
    
    // Input expenses
    for (int i = 0; i < finance->expense_count; i++) {
        printf("Enter category name for expense %d: ", (i + 1));
        scanf("%s", finance->expenses[i].category);
        printf("Enter amount for %s: ", finance->expenses[i].category);
        scanf("%f", &finance->expenses[i].amount);
    }
}

void displayReport(const Finance* finance) {
    printf("\n--- Personal Finance Report ---\n");
    printf("Total Income: $%.2f\n", finance->income);
    
    float totalExpenses = calculateTotalExpenses(finance);
    float balance = calculateBalance(finance);
    
    printf("Total Expenses: $%.2f\n", totalExpenses);
    printf("Balance: $%.2f\n", balance);
   
    displayExpenseBreakdown(finance);
    
    if (balance < 0) {
        printf("Warning: Your expenses exceed your income!\n");
    } else {
        printf("Good job! You are within your budget.\n");
    }
}

float calculateTotalExpenses(const Finance* finance) {
    float total = 0;
    for (int i = 0; i < finance->expense_count; i++) {
        total += finance->expenses[i].amount;
    }
    return total;
}

float calculateBalance(const Finance* finance) {
    return finance->income - calculateTotalExpenses(finance);
}

void displayExpenseBreakdown(const Finance* finance) {
    printf("\n--- Expense Breakdown ---\n");
    
    for (int i = 0; i < finance->expense_count; i++) {
        float percentage = (finance->expenses[i].amount / calculateTotalExpenses(finance)) * 100;
        printf("Category: %s, Amount: $%.2f, Percentage of Total Expenses: %.2f%%\n", 
               finance->expenses[i].category, 
               finance->expenses[i].amount, 
               percentage);
    }
}