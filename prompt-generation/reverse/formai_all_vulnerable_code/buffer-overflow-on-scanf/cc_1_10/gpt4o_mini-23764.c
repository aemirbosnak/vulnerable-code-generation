//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char description[100];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int expenseCount = 0;

void addExpense() {
    if (expenseCount >= MAX_EXPENSES) {
        printf("Expense list is full!\n");
        return;
    }
    
    printf("Enter expense description: ");
    scanf(" %[^\n]", expenses[expenseCount].description);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[expenseCount].amount);
    expenseCount++;

    char choice;
    printf("Do you want to add another expense? (y/n): ");
    getchar(); // To consume the newline character
    choice = getchar();
    
    if (choice == 'y' || choice == 'Y') {
        addExpense();  // Recursive call to add another expense
    }
}

void listExpenses(int index) {
    if (index >= expenseCount) {
        return; // Base case
    }
    
    printf("Expense %d: %s - $%.2f\n", index + 1, expenses[index].description, expenses[index].amount);
    listExpenses(index + 1); // Recursive call for the next expense
}

float calculateTotalExpenses(int index, float total) {
    if (index >= expenseCount) {
        return total; // Base case, return total
    }
    
    total += expenses[index].amount;
    return calculateTotalExpenses(index + 1, total); // Recursive call to calculate total
}

void displayMenu() {
    printf("\nPersonal Finance Planner\n");
    printf("1. Add Expense\n");
    printf("2. List Expenses\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                printf("Listing all expenses:\n");
                listExpenses(0); // Start listing from the first expense
                break;
            case 3:
                {
                    float total = calculateTotalExpenses(0, 0.0);
                    printf("Total Expenses: $%.2f\n", total);
                }
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}