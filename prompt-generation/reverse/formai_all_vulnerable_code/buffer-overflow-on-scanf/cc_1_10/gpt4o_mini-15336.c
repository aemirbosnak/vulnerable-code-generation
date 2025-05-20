//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 100

// Function prototypes
void addIncome(float incomes[], int *incomeCount);
void addExpense(float expenses[], int *expenseCount);
void displaySummary(float incomes[], int incomeCount, float expenses[], int expenseCount);
void budgetGoal(float savingsGoal, float totalSavings);
void displayMenu();
float calculateTotal(float arr[], int count);

int main() {
    printf("🎉 Welcome to the Happy Personal Finance Planner! 🎉\n");
    
    float incomes[MAX_ENTRIES] = {0};
    float expenses[MAX_ENTRIES] = {0};
    int incomeCount = 0;
    int expenseCount = 0;
    float savingsGoal = 0.0;
    char choice;

    while (1) {
        displayMenu();
        printf("Please select an option: ");
        choice = getchar();
        getchar(); // Consume newline character

        switch (choice) {
            case '1':
                addIncome(incomes, &incomeCount);
                break;
            case '2':
                addExpense(expenses, &expenseCount);
                break;
            case '3':
                displaySummary(incomes, incomeCount, expenses, expenseCount);
                break;
            case '4':
                printf("💰 Enter your savings goal: ");
                scanf("%f", &savingsGoal);
                getchar(); // Consume newline
                budgetGoal(savingsGoal, calculateTotal(incomes, incomeCount) - calculateTotal(expenses, expenseCount));
                break;
            case '5':
                printf("🎈 Thank you for using the Happy Personal Finance Planner! Goodbye! 🎈\n");
                exit(0);
            default:
                printf("🚫 Invalid option. Please choose again!\n");
                break;
        }
    }
    return 0;
}

void addIncome(float incomes[], int *incomeCount) {
    if (*incomeCount >= MAX_ENTRIES) {
        printf("🛑 Income entries are full! Please clear some entries to add new ones.\n");
        return;
    }
    printf("🎉 Enter the income amount: ");
    scanf("%f", &incomes[*incomeCount]);
    getchar(); // Consume newline
    (*incomeCount)++;
    printf("✅ Income added successfully!\n");
}

void addExpense(float expenses[], int *expenseCount) {
    if (*expenseCount >= MAX_ENTRIES) {
        printf("🛑 Expense entries are full! Please clear some entries to add new ones.\n");
        return;
    }
    printf("💸 Enter the expense amount: ");
    scanf("%f", &expenses[*expenseCount]);
    getchar(); // Consume newline
    (*expenseCount)++;
    printf("✅ Expense added successfully!\n");
}

void displaySummary(float incomes[], int incomeCount, float expenses[], int expenseCount) {
    printf("\n📊 Financial Summary 📊\n");
    
    float totalIncome = calculateTotal(incomes, incomeCount);
    float totalExpense = calculateTotal(expenses, expenseCount);
    float balance = totalIncome - totalExpense;

    printf("🏦 Total Income: $%.2f\n", totalIncome);
    printf("💳 Total Expense: $%.2f\n", totalExpense);
    printf("💰 Balance: $%.2f\n\n", balance);
}

void budgetGoal(float savingsGoal, float totalSavings) {
    printf("🌟 Your savings goal is: $%.2f\n", savingsGoal);
    printf("🌈 Your current savings: $%.2f\n", totalSavings);

    if (totalSavings >= savingsGoal) {
        printf("🎉 Congratulations! You've reached your savings goal! 🎉\n");
    } else {
        printf("📉 You still need $%.2f to reach your goal. Keep saving! 💪\n", savingsGoal - totalSavings);
    }
}

void displayMenu() {
    printf("\n🎈 Menu 🎈\n");
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. Display Summary\n");
    printf("4. Set Savings Goal\n");
    printf("5. Exit\n");
}

float calculateTotal(float arr[], int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += arr[i];
    }
    return total;
}