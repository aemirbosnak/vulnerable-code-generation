//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Function to print the menu
void printMenu() {
    printf("\n");
    printf("Personal Finance Planner\n");
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. View Income\n");
    printf("4. View Expenses\n");
    printf("5. View Balance\n");
    printf("6. Exit\n");
}

// Function to add income
void addIncome() {
    float amount;
    printf("\nEnter the amount of income: ");
    scanf("%f", &amount);
    printf("\nIncome added successfully!\n");
    return;
}

// Function to add expense
void addExpense() {
    float amount;
    printf("\nEnter the amount of expense: ");
    scanf("%f", &amount);
    printf("\nExpense added successfully!\n");
    return;
}

// Function to view income
void viewIncome() {
    float totalIncome = 0;
    printf("\nTotal Income: $%.2f\n", totalIncome);
    return;
}

// Function to view expenses
void viewExpenses() {
    float totalExpenses = 0;
    printf("\nTotal Expenses: $%.2f\n", totalExpenses);
    return;
}

// Function to view balance
void viewBalance() {
    float totalIncome = 0, totalExpenses = 0, balance = 0;
    printf("\nTotal Income: $%.2f\n", totalIncome);
    printf("\nTotal Expenses: $%.2f\n", totalExpenses);
    balance = totalIncome - totalExpenses;
    printf("\nBalance: $%.2f\n", balance);
    return;
}

// Main function
int main() {
    int choice;
    float totalIncome = 0, totalExpenses = 0;
    do {
        printMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addIncome();
                totalIncome += 1;
                break;
            case 2:
                addExpense();
                totalExpenses += 1;
                break;
            case 3:
                viewIncome();
                break;
            case 4:
                viewExpenses();
                break;
            case 5:
                viewBalance();
                break;
            case 6:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while(choice!= 6);
    return 0;
}