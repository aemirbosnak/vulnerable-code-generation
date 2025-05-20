//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: automated
#include <stdio.h>

// Declare functions
void printMenu();
void addExpense();
void addIncome();
void viewAllExpenses();
void viewAllIncomes();
void viewTotalExpenses();
void viewTotalIncomes();

// Declare variables
int choice;
float expense = 0;
float income = 0;
float totalExpenses = 0;
float totalIncomes = 0;
int countExpenses = 0;
int countIncomes = 0;

// Main function
int main() {

    do {
        printf("\n\n");
        printMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addExpense();
                break;
            case 2:
                addIncome();
                break;
            case 3:
                viewAllExpenses();
                break;
            case 4:
                viewAllIncomes();
                break;
            case 5:
                viewTotalExpenses();
                break;
            case 6:
                viewTotalIncomes();
                break;
            case 7:
                printf("\nThank you for using the Personal Finance Planner.\n\n");
                break;
            default:
                printf("\nInvalid Choice. Please enter a valid choice.\n");
        }
    } while(choice != 7);

    return 0;
}

// Function to print menu
void printMenu() {
    printf("===================================\n");
    printf("|        Personal Finance         |\n");
    printf("|              Planner            |\n");
    printf("===================================\n");
    printf("| Options:                        |\n");
    printf("|         1. Add Expense          |\n");
    printf("|         2. Add Income           |\n");
    printf("|         3. View All Expenses    |\n");
    printf("|         4. View All Incomes     |\n");
    printf("|         5. View Total Expenses  |\n");
    printf("|         6. View Total Incomes   |\n");
    printf("|         7. Exit                 |\n");
    printf("===================================\n");
}

// Function to add expense
void addExpense() {
    float amt;
    printf("\nEnter the amount for the expense: ");
    scanf("%f", &amt);
    expense = amt;
    totalExpenses += amt;
    countExpenses++;
    printf("\nExpense added successfully.\n");
}

// Function to add income
void addIncome() {
    float amt;
    printf("\nEnter the amount for the income: ");
    scanf("%f", &amt);
    income = amt;
    totalIncomes += amt;
    countIncomes++;
    printf("\nIncome added successfully.\n");
}

// Function to view all expenses
void viewAllExpenses() {
    if(countExpenses == 0) {
        printf("\nNo expenses to show.\n");
        return;
    }
    printf("\nAll Expenses: \n");
    for(int i=1; i<=countExpenses; i++) {
        printf("%d. $%.2f\n", i, expense);
    }
}

// Function to view all incomes
void viewAllIncomes() {
    if(countIncomes == 0) {
        printf("\nNo incomes to show.\n");
        return;
    }
    printf("\nAll Incomes: \n");
    for(int i=1; i<=countIncomes; i++) {
        printf("%d. $%.2f\n", i, income);
    }
}

// Function to view total expenses
void viewTotalExpenses() {
    printf("\nTotal Expenses: $%.2f\n", totalExpenses);
}

// Function to view total incomes
void viewTotalIncomes() {
    printf("\nTotal Incomes: $%.2f\n", totalIncomes);
}