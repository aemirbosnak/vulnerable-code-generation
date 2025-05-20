//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the income details
typedef struct {
    char source[50];
    double amount;
} Income;

// Structure to store the expense details
typedef struct {
    char category[50];
    double amount;
} Expense;

// Function to add a new income
void addIncome(Income *incomes, int *numIncomes) {
    printf("Enter the source of income: ");
    scanf("%s", incomes[*numIncomes].source);
    printf("Enter the amount of income: ");
    scanf("%lf", &incomes[*numIncomes].amount);
    (*numIncomes)++;
}

// Function to add a new expense
void addExpense(Expense *expenses, int *numExpenses) {
    printf("Enter the category of expense: ");
    scanf("%s", expenses[*numExpenses].category);
    printf("Enter the amount of expense: ");
    scanf("%lf", &expenses[*numExpenses].amount);
    (*numExpenses)++;
}

// Function to print the income details
void printIncome(Income *incomes, int numIncomes) {
    printf("\nIncome Details:\n");
    for (int i = 0; i < numIncomes; i++) {
        printf("%s: $%.2lf\n", incomes[i].source, incomes[i].amount);
    }
}

// Function to print the expense details
void printExpense(Expense *expenses, int numExpenses) {
    printf("\nExpense Details:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s: $%.2lf\n", expenses[i].category, expenses[i].amount);
    }
}

// Function to calculate the net income
double calculateNetIncome(Income *incomes, int numIncomes, Expense *expenses, int numExpenses) {
    double totalIncome = 0;
    for (int i = 0; i < numIncomes; i++) {
        totalIncome += incomes[i].amount;
    }

    double totalExpense = 0;
    for (int i = 0; i < numExpenses; i++) {
        totalExpense += expenses[i].amount;
    }

    return totalIncome - totalExpense;
}

// Main function
int main() {
    // Declare the arrays to store the income and expense details
    Income incomes[10];
    Expense expenses[10];

    // Initialize the number of incomes and expenses to 0
    int numIncomes = 0;
    int numExpenses = 0;

    // Get the user input
    int choice;
    do {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. Print Income Details\n");
        printf("4. Print Expense Details\n");
        printf("5. Calculate Net Income\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addIncome(incomes, &numIncomes);
                break;
            case 2:
                addExpense(expenses, &numExpenses);
                break;
            case 3:
                printIncome(incomes, numIncomes);
                break;
            case 4:
                printExpense(expenses, numExpenses);
                break;
            case 5:
                printf("\nNet Income: $%.2lf\n", calculateNetIncome(incomes, numIncomes, expenses, numExpenses));
                break;
            case 6:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}