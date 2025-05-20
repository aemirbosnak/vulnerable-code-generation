//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float amount;
} Income;

typedef struct {
    char name[NAME_LENGTH];
    float amount;
} Expense;

void add_income(Income incomes[], int *income_count) {
    if (*income_count >= MAX_ITEMS) {
        printf("The income list is full! Can't add more incomes.\n");
        return;
    }
    printf("Enter income source name: ");
    scanf("%s", incomes[*income_count].name);
    printf("Enter income amount: ");
    scanf("%f", &incomes[*income_count].amount);
    (*income_count)++;
    printf("Income successfully added! 🎉\n");
}

void add_expense(Expense expenses[], int *expense_count) {
    if (*expense_count >= MAX_ITEMS) {
        printf("The expense list is full! Can't add more expenses.\n");
        return;
    }
    printf("Enter expense name: ");
    scanf("%s", expenses[*expense_count].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[*expense_count].amount);
    (*expense_count)++;
    printf("Expense successfully added! 🌈\n");
}

void display_summary(Income incomes[], int income_count, Expense expenses[], int expense_count) {
    float total_income = 0.0, total_expenses = 0.0;

    printf("\n✨ Income Summary:\n");
    for (int i = 0; i < income_count; i++) {
        printf("- %s: $%.2f\n", incomes[i].name, incomes[i].amount);
        total_income += incomes[i].amount;
    }

    printf("\n✨ Expense Summary:\n");
    for (int i = 0; i < expense_count; i++) {
        printf("- %s: $%.2f\n", expenses[i].name, expenses[i].amount);
        total_expenses += expenses[i].amount;
    }

    float remaining_budget = total_income - total_expenses;
    printf("\n✨ Total Income: $%.2f\n", total_income);
    printf("✨ Total Expenses: $%.2f\n", total_expenses);
    printf("✨ Remaining Budget: $%.2f\n", remaining_budget);

    if (remaining_budget > 0) {
        printf("🎈 Hooray! You're within budget! 🎈\n");
    } else if (remaining_budget < 0) {
        printf("🚩 Oops! You're over budget! 🚩\n");
    } else {
        printf("🎊 You're perfectly balanced! 🎊\n");
    }
}

int main() {
    Income incomes[MAX_ITEMS];
    Expense expenses[MAX_ITEMS];
    int income_count = 0, expense_count = 0;
    int choice;

    printf("🤑 Welcome to the Personal Finance Planner! 🤑\n");
    
    do {
        printf("\n📊 Menu:\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. Display Summary\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_income(incomes, &income_count);
                break;
            case 2:
                add_expense(expenses, &expense_count);
                break;
            case 3:
                display_summary(incomes, income_count, expenses, expense_count);
                break;
            case 4:
                printf("🎉 Thank you for using the Personal Finance Planner! Goodbye! 🎉\n");
                break;
            default:
                printf("❌ Invalid option! Please choose again. ❌\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}