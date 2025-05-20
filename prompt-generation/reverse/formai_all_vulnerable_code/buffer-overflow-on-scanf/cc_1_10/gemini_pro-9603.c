//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Structure to store expenses
typedef struct {
    char name[50];
    float amount;
} Expense;

// Structure to store income
typedef struct {
    char name[50];
    float amount;
} Income;

// Function to add an expense
void addExpense(Expense *expenses, int *numExpenses) {
    // Get the expense details from the user
    printf("Enter expense name: ");
    scanf("%s", expenses[*numExpenses].name);

    printf("Enter expense amount: ");
    scanf("%f", &expenses[*numExpenses].amount);

    // Increment the number of expenses
    (*numExpenses)++;
}

// Function to add an income
void addIncome(Income *incomes, int *numIncomes) {
    // Get the income details from the user
    printf("Enter income name: ");
    scanf("%s", incomes[*numIncomes].name);

    printf("Enter income amount: ");
    scanf("%f", &incomes[*numIncomes].amount);

    // Increment the number of incomes
    (*numIncomes)++;
}

// Function to print the expenses
void printExpenses(Expense *expenses, int numExpenses) {
    printf("\nExpenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf(" - %s: $%.2f\n", expenses[i].name, expenses[i].amount);
    }
}

// Function to print the incomes
void printIncomes(Income *incomes, int numIncomes) {
    printf("\nIncomes:\n");
    for (int i = 0; i < numIncomes; i++) {
        printf(" - %s: $%.2f\n", incomes[i].name, incomes[i].amount);
    }
}

// Function to calculate the total expenses
float calculateTotalExpenses(Expense *expenses, int numExpenses) {
    float total = 0;
    for (int i = 0; i < numExpenses; i++) {
        total += expenses[i].amount;
    }
    return total;
}

// Function to calculate the total incomes
float calculateTotalIncomes(Income *incomes, int numIncomes) {
    float total = 0;
    for (int i = 0; i < numIncomes; i++) {
        total += incomes[i].amount;
    }
    return total;
}

// Function to print the financial summary
void printFinancialSummary(float totalExpenses, float totalIncomes) {
    printf("\nFinancial Summary:\n");
    printf(" - Total expenses: $%.2f\n", totalExpenses);
    printf(" - Total incomes: $%.2f\n", totalIncomes);
    printf(" - Net income: $%.2f\n", totalIncomes - totalExpenses);
}

// Main function
int main() {
    // Initialize the arrays to store expenses and incomes
    Expense expenses[100];
    Income incomes[100];

    // Initialize the number of expenses and incomes to 0
    int numExpenses = 0;
    int numIncomes = 0;

    // Get the user's choice
    int choice;
    do {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add expense\n");
        printf("2. Add income\n");
        printf("3. Print expenses\n");
        printf("4. Print incomes\n");
        printf("5. Print financial summary\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the selected operation
        switch (choice) {
            case 1:
                addExpense(expenses, &numExpenses);
                break;
            case 2:
                addIncome(incomes, &numIncomes);
                break;
            case 3:
                printExpenses(expenses, numExpenses);
                break;
            case 4:
                printIncomes(incomes, numIncomes);
                break;
            case 5:
                printFinancialSummary(calculateTotalExpenses(expenses, numExpenses), calculateTotalIncomes(incomes, numIncomes));
                break;
            case 6:
                printf("Thank you for using Personal Finance Planner!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}