//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for storing expenses
struct Expense {
    char title[50];
    float amount;
};

// Define a function for adding expenses
void addExpense(struct Expense expenses[], int *count) {
    // Get the title of the expense
    printf("Enter the title of the expense: ");
    char title[50];
    scanf("%s", title);
    
    // Get the amount of the expense
    printf("Enter the amount of the expense: ");
    float amount;
    scanf("%f", &amount);
    
    // Create a new expense and add it to the expenses array
    struct Expense newExpense;
    strcpy(newExpense.title, title);
    newExpense.amount = amount;
    expenses[*count] = newExpense;
    *count += 1;
    
    printf("Expense added successfully.\n");
}

// Define a function for printing expenses
void printExpenses(struct Expense expenses[], int count) {
    // Check if there are any expenses to print
    if (count == 0) {
        printf("There are no expenses to print.\n");
        return;
    }
    
    printf("Expenses:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %.2f\n", i+1, expenses[i].title, expenses[i].amount);
    }
}

int main() {
    // Define an array to store expenses
    struct Expense expenses[100];
    int count = 0;
    
    // Show the menu and get user input
    while (1) {
        printf("Expense Tracker\n");
        printf("1. Add expense\n");
        printf("2. Print expenses\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                printExpenses(expenses, count);
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}