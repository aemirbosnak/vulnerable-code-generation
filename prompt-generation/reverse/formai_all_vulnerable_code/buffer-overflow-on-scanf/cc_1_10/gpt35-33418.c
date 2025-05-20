//FormAI DATASET v1.0 Category: Expense Tracker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 100

// Structure to hold an expense
typedef struct {
    char name[30];
    float amount;
} Expense;

// Function prototypes
void addExpense(Expense expenses[], int *numExpenses);
void printExpenses(Expense expenses[], int numExpenses);
float calculateTotalExpenses(Expense expenses[], int numExpenses);
float calculateAverageExpense(Expense expenses[], int numExpenses);
int countExpensesAboveThreshold(Expense expenses[], int numExpenses, float threshold);

int main() {
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    int choice;
    float threshold;
    
    do {
        printf("\n\n");
        printf("1. Add expense\n");
        printf("2. Print expenses\n");
        printf("3. Calculate total expenses\n");
        printf("4. Calculate average expense\n");
        printf("5. Count expenses above a certain threshold\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addExpense(expenses, &numExpenses);
                break;
            case 2:
                printExpenses(expenses, numExpenses);
                break;
            case 3:
                printf("Total expenses: $%.2f\n", calculateTotalExpenses(expenses, numExpenses));
                break;
            case 4:
                printf("Average expense: $%.2f\n", calculateAverageExpense(expenses, numExpenses));
                break;
            case 5:
                printf("Enter threshold amount: ");
                scanf("%f", &threshold);
                printf("Number of expenses above %.2f: %d\n", threshold, countExpensesAboveThreshold(expenses, numExpenses, threshold));
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 6);
    
    return 0;
}

// Function to add a new expense to the list
void addExpense(Expense expenses[], int *numExpenses) {
    if(*numExpenses == MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }
    
    Expense newExpense;
    printf("Enter name of expense: ");
    scanf("%s", newExpense.name);
    printf("Enter amount of expense: ");
    scanf("%f", &newExpense.amount);
    
    expenses[*numExpenses] = newExpense;
    *numExpenses += 1;
}

// Function to print all expenses in the list
void printExpenses(Expense expenses[], int numExpenses) {
    if(numExpenses == 0) {
        printf("No expenses to print.\n");
        return;
    }
    
    printf("%-30s %s\n", "Name", "Amount ($)");
    printf("------------------------------\n");
    for(int i = 0; i < numExpenses; i++) {
        printf("%-30s %.2f\n", expenses[i].name, expenses[i].amount);
    }
}

// Function to calculate the total expenses in the list
float calculateTotalExpenses(Expense expenses[], int numExpenses) {
    float total = 0.0;
    for(int i = 0; i < numExpenses; i++) {
        total += expenses[i].amount;
    }
    return total;
}

// Function to calculate the average expense in the list
float calculateAverageExpense(Expense expenses[], int numExpenses) {
    return calculateTotalExpenses(expenses, numExpenses) / numExpenses;
}

// Function to count the number of expenses above a certain threshold
int countExpensesAboveThreshold(Expense expenses[], int numExpenses, float threshold) {
    int count = 0;
    for(int i = 0; i < numExpenses; i++) {
        if(expenses[i].amount > threshold) {
            count++;
        }
    }
    return count;
}