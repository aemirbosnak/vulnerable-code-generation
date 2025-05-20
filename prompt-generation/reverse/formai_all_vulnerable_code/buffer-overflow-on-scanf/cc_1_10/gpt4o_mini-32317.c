//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESC_LENGTH 50

typedef struct {
    char description[MAX_DESC_LENGTH];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int expenseCount = 0;

void addExpense();
void viewExpenses(int index);
void calculateTotal(float total);
void menu();
int isValidChoice(int choice);

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;

    printf("Welcome to the Expense Tracker!\n");
    do {
        printf("\nMenu:\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Calculate Total Expense\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        if (!isValidChoice(choice)) {
            printf("Invalid choice, please try again.\n");
            continue;
        }

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses(0);
                break;
            case 3:
                calculateTotal(0);
                break;
            case 4:
                printf("Exiting Expense Tracker. Goodbye!\n");
                break;
            default:
                break;
        }
    } while (choice != 4);
}

int isValidChoice(int choice) {
    return choice >= 1 && choice <= 4;
}

void addExpense() {
    if (expenseCount >= MAX_EXPENSES) {
        printf("Expense limit reached. Cannot add more expenses.\n");
        return;
    }

    printf("Enter description of the expense: ");
    scanf(" %[^\n]s", expenses[expenseCount].description);
    printf("Enter amount of the expense: ");
    scanf("%f", &expenses[expenseCount].amount);
    
    expenseCount++;
    printf("Expense added successfully!\n");
}

void viewExpenses(int index) {
    if (index >= expenseCount) {
        printf("All expenses have been displayed.\n");
        return;
    }

    printf("Expense %d:\n", index + 1);
    printf("Description: %s\n", expenses[index].description);
    printf("Amount: %.2f\n\n", expenses[index].amount);
    
    viewExpenses(index + 1);
}

void calculateTotal(float total) {
    if (total >= expenseCount)
        return;

    total += expenses[(int)total].amount;
    calculateTotal(total + 1);
    
    if (total == 0) // only want to print total once
        printf("Total Expenses: %.2f\n", total);
}