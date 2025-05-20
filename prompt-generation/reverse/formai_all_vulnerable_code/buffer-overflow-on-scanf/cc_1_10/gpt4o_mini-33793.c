//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define CATEGORY_LEN 20
#define DESC_LEN 50

typedef struct {
    char category[CATEGORY_LEN];
    char description[DESC_LEN];
    float amount;
} Expense;

int expenseCount = 0; // Total number of expenses
Expense expenses[MAX_EXPENSES]; // Array to hold expenses

void addExpense(); // Function to add a new expense
void displayExpenses(); // Function to show all expenses
void displayTotal(); // Function to display total expenses
void clearScreen(); // Function to clear the screen

int main() {
    int choice;

    do {
        clearScreen();
        printf("=== Expense Tracker ===\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Display Total Expenses\n");
        printf("4. Exit\n");
        printf("========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                displayExpenses();
                break;
            case 3:
                displayTotal();
                break;
            case 4:
                printf("Exiting... Have a great day!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        printf("Press Enter to continue...");
        while(getchar() != '\n'); // Clearing buffer
        getchar();
    } while (1);
    return 0;
}

void addExpense() {
    if (expenseCount >= MAX_EXPENSES) {
        printf("Expense limit reached. Cannot add more expenses.\n");
        return;
    }
    
    printf("Enter category: ");
    scanf("%s", expenses[expenseCount].category);
    
    printf("Enter description: ");
    getchar(); // clear newline from buffer
    fgets(expenses[expenseCount].description, DESC_LEN, stdin);
    expenses[expenseCount].description[strcspn(expenses[expenseCount].description, "\n")] = 0; // Remove newline
    
    printf("Enter amount: ");
    scanf("%f", &expenses[expenseCount].amount);
    
    expenseCount++;
    printf("Expense added successfully!\n");
}

void displayExpenses() {
    if (expenseCount == 0) {
        printf("No expenses recorded yet.\n");
        return;
    }
    
    printf("=== Recorded Expenses ===\n");
    for (int i = 0; i < expenseCount; i++) {
        printf("%d. Category: %s, Description: %s, Amount: $%.2f\n",
               i + 1, expenses[i].category, expenses[i].description, expenses[i].amount);
    }
}

void displayTotal() {
    float total = 0.0;
    for (int i = 0; i < expenseCount; i++) {
        total += expenses[i].amount;
    }
    printf("Total Expenses: $%.2f\n", total);
}

void clearScreen() {
#ifdef __linux__
    system("clear");
#else
    system("cls");
#endif
}