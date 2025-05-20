//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store expense details
struct expense {
    char category[20];
    float amount;
    char description[100];
};

int main() {
    int n = 0; // Number of expenses
    float total_expense = 0; // Total expense
    struct expense expenses[100]; // Maximum 100 expenses can be entered
    
    // Loop to get user input for expenses
    while (1) {
        printf("Enter expense details (or type 'quit' to exit):\n");
        
        // Get category input
        printf("Category: ");
        scanf("%s", expenses[n].category);
        
        // Check if user wants to quit
        if (strcmp(expenses[n].category, "quit") == 0) {
            break; // Exit the loop
        }
        
        // Get amount input
        printf("Amount: ");
        scanf("%f", &expenses[n].amount);
        
        // Get description input
        printf("Description: ");
        scanf(" %[^\n]", expenses[n].description); // Use %[^\n] to allow spaces in input
        
        // Increase total expense
        total_expense += expenses[n].amount;
        
        // Increase number of expenses entered
        n++;
    }
    
    // Display expense details
    printf("\nExpenses:\n");
    for (int i = 0; i < n; i++) {
        printf("Category: %s, Amount: %.2f, Description: %s\n", expenses[i].category, expenses[i].amount, expenses[i].description);
    }
    
    // Display total expense
    printf("\nTotal expense: %.2f\n", total_expense);
    
    return 0;
}