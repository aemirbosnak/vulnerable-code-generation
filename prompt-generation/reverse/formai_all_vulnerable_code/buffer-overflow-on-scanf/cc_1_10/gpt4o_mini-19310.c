//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_ENTRIES];
    int count;
    float total;
} FinancePlanner;

void addExpense(FinancePlanner *planner);
void viewExpenses(FinancePlanner *planner);
void calculateTotal(FinancePlanner *planner);
void displayMenu();

int main() {
    FinancePlanner planner = { .count = 0, .total = 0.0 };
    int choice;

    printf("Welcome to the Personal Finance Planner! 🎉\n");

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(&planner);
                break;
            case 2:
                viewExpenses(&planner);
                break;
            case 3:
                calculateTotal(&planner);
                break;
            case 4:
                printf("Exiting the planner. Have a great day! 😊\n");
                return 0;
            default:
                printf("Oops! That's not a valid choice. Please try again! ❌\n");
        }
    }
}

void displayMenu() {
    printf("\n--- Main Menu ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void addExpense(FinancePlanner *planner) {
    if (planner->count >= MAX_ENTRIES) {
        printf("Whoa! You've reached the maximum number of entries! 🚫\n");
        return;
    }

    Expense newExpense;
    printf("Enter the name of the expense: ");
    scanf("%s", newExpense.name);
    printf("Enter the amount spent: ");
    scanf("%f", &newExpense.amount);

    planner->expenses[planner->count++] = newExpense;
    printf("Expense added! 💵\n");
}

void viewExpenses(FinancePlanner *planner) {
    if (planner->count == 0) {
        printf("Hey, it seems you haven't added any expenses yet! 🧐\n");
        return;
    }

    printf("\n--- Your Expenses ---\n");
    for (int i = 0; i < planner->count; i++) {
        printf("%d. %s: $%.2f\n", i + 1, planner->expenses[i].name, planner->expenses[i].amount);
    }
}

void calculateTotal(FinancePlanner *planner) {
    if (planner->count == 0) {
        printf("You have no expenses to calculate! 📉\n");
        return;
    }

    planner->total = 0.0;
    for (int i = 0; i < planner->count; i++) {
        planner->total += planner->expenses[i].amount;
    }

    printf("Your total expenses amount to: $%.2f 💰\n", planner->total);
}