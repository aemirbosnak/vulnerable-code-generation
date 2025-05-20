//FormAI DATASET v1.0 Category: Expense Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Expense
struct expense {
    char category[20];
    float amount;
    char date[11];
};

// Function to get user input for expense
struct expense getExpense() {
    struct expense e;
    printf("Enter Category: ");
    scanf("%s", e.category);
    printf("Enter Amount: ");
    scanf("%f", &e.amount);
    printf("Enter Date (dd-mm-yyyy): ");
    scanf("%s", e.date);
    return e;
}

// Function to display an expense
void displayExpense(struct expense e) {
    printf("%-20s%-10.2f%-12s\n", e.category, e.amount, e.date);
}

// Function to display all expenses
void displayAllExpenses(struct expense expenses[], int count) {
    printf("%-20s%-10s%-12s\n", "Category", "Amount", "Date");
    for (int i = 0; i < count; i++) {
        displayExpense(expenses[i]);
    }
}

// Function to calculate total expenses
float calculateTotalExpenses(struct expense expenses[], int count) {
    float total = 0;
    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }
    return total;
}

int main() {
    struct expense expenses[100];
    int count = 0;
    int choice;
    do {
        printf("\nExpense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. Display All Expenses\n");
        printf("3. Calculate Total Expenses\n");
        printf("4. Exit\n");
        printf("Enter Choice (1-4): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                struct expense e = getExpense();
                expenses[count++] = e;
                printf("Expense added successfully!\n");
                break;
            }
            case 2: {
                if (count == 0) {
                    printf("No expenses to display\n");
                } else {
                    displayAllExpenses(expenses, count);
                }
                break;
            }
            case 3: {
                if (count == 0) {
                    printf("No expenses to calculate\n");
                } else {
                    float total = calculateTotalExpenses(expenses, count);
                    printf("Total Expenses: %.2f\n", total);
                }
                break;
            }
            case 4: {
                printf("Goodbye!\n");
                break;
            }
            default: {
                printf("Invalid Choice!\n");
            }
        }
    } while (choice != 4);

    return 0;
}