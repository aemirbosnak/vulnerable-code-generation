//FormAI DATASET v1.0 Category: Expense Tracker ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of expenses that can be tracked
#define MAX_EXPENSES 100

// Define a structure to hold information about each expense
struct Expense {
    char name[50];
    double amount;
    char category[20];
};

// Function to add a new expense to the tracker
void addExpense(struct Expense tracker[], int *numExpenses) {
    // Check if the tracker is full
    if (*numExpenses >= MAX_EXPENSES) {
        printf("Tracker is full, can't add more expenses.\n");
        return;
    }
    
    // Prompt the user for the expense details
    struct Expense newExpense;
    printf("Enter expense name: ");
    fgets(newExpense.name, 50, stdin);
    printf("Enter expense amount: ");
    scanf("%lf", &newExpense.amount);
    printf("Enter expense category: ");
    fgets(newExpense.category, 20, stdin);
    
    // Add the new expense to the tracker
    tracker[*numExpenses] = newExpense;
    (*numExpenses)++;
    
    printf("Expense added.\n");
}

// Function to display the expenses in the tracker
void displayExpenses(struct Expense tracker[], int numExpenses) {
    // Check if there are any expenses to display
    if (numExpenses == 0) {
        printf("No expenses in tracker.\n");
        return;
    }
    
    // Print header row
    printf("%-25s %10s %15s\n", "Name", "Amount", "Category");
    printf("------------------------------------------------\n");
    
    // Print each expense in the tracker
    for (int i = 0; i < numExpenses; i++) {
        printf("%-25s %10.2lf %15s\n", tracker[i].name, tracker[i].amount, tracker[i].category);
    }
}

// Function to calculate the total amount of expenses in the tracker
double calculateTotal(struct Expense tracker[], int numExpenses) {
    double total = 0.0;
    
    // Sum up the amount of each expense
    for (int i = 0; i < numExpenses; i++) {
        total += tracker[i].amount;
    }
    
    return total;
}

int main() {
    // Create an array to hold the expenses
    struct Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    
    // Main loop
    char command[10];
    while (1) {
        // Prompt the user for a command
        printf("Enter command (add/display/total/quit): ");
        fgets(command, 10, stdin);
        
        // Remove the newline character from the end of the command
        int len = strlen(command);
        if (command[len-1] == '\n') {
            command[len-1] = '\0';
        }
        
        // Execute the command
        if (strcmp(command, "add") == 0) {
            addExpense(expenses, &numExpenses);
        } else if (strcmp(command, "display") == 0) {
            displayExpenses(expenses, numExpenses);
        } else if (strcmp(command, "total") == 0) {
            double total = calculateTotal(expenses, numExpenses);
            printf("Total expenses: %.2lf\n", total);
        } else if (strcmp(command, "quit") == 0) {
            printf("Quitting program.\n");
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
    
    return 0;
}