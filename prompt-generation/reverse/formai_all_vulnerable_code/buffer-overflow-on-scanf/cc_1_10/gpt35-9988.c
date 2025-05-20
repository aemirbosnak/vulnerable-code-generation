//FormAI DATASET v1.0 Category: Expense Tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

// Define the expense struct
typedef struct Expense {
    char date[20];
    char category[50];
    float amount;
} Expense;

// Define the expenses array
Expense expenses[MAX_EXPENSES];

// Define the number of expenses
int num_expenses = 0;

// Function to add a new expense
void addExpense(char date[], char category[], float amount) {
    if (num_expenses < MAX_EXPENSES) {
        strcpy(expenses[num_expenses].date, date);
        strcpy(expenses[num_expenses].category, category);
        expenses[num_expenses].amount = amount;
        num_expenses++;
        printf("Expense added successfully!\n");
    } else {
        printf("Could not add expense. Maximum number of expenses reached.\n");
    }
}

// Function to display all expenses
void displayExpenses() {
    if (num_expenses == 0) {
        printf("No expenses found!\n");
        return;
    }
    printf("%-10s %-20s %s\n", "Date", "Category", "Amount");
    for (int i = 0; i < num_expenses; i++) {
        printf("%-10s %-20s $%.2f\n", expenses[i].date, expenses[i].category, expenses[i].amount);
    }
}

// Function to calculate total expenses
float getTotalExpenses() {
    float total = 0;
    for (int i = 0; i < num_expenses; i++) {
        total += expenses[i].amount;
    }
    return total;
}

// Main function
int main() {
    int choice;
    char date[20], category[50];
    float amount;

    while (1) {
        printf("Expense Tracker Menu\n");
        printf("--------------------\n");
        printf("1. Add expense\n");
        printf("2. Display all expenses\n");
        printf("3. Get total expenses\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter date (MM/DD/YYYY): ");
                scanf("%s", date);
                printf("Enter category: ");
                scanf("%s", category);
                printf("Enter amount: $");
                scanf("%f", &amount);
                addExpense(date, category, amount);
                break;
            case 2:
                displayExpenses();
                break;
            case 3:
                printf("Total expenses: $%.2f\n", getTotalExpenses());
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}