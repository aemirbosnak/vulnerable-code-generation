//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// Declare the structure for an expense item
typedef struct {
    char item_name[30];
    float cost;
} Expense;

// Declare the function to add an expense item to the tracker
void addExpense(Expense tracker[], int *numExpenses);

// Declare the function to print all expense items in the tracker
void printExpenses(Expense tracker[], int numExpenses);

int main() {
    int numExpenses = 0;
    Expense tracker[50];
    char menuOption;

    do {
        // Print the menu options
        printf("\nC Expense Tracker\n");
        printf("1. Add an expense\n");
        printf("2. Print all expenses\n");
        printf("3. Quit\n");
        printf("Choose an option: ");
        
        // Get the user's menu choice
        scanf(" %c", &menuOption);
        
        switch(menuOption) {
            case '1':
                // Add an expense item
                addExpense(tracker, &numExpenses);
                break;
            case '2':
                // Print all expense items
                printExpenses(tracker, numExpenses);
                break;
            case '3':
                // Quit the program
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid menu option. Please choose again.\n");
                break;
        }
    } while(menuOption != '3');

    return 0;
}

void addExpense(Expense tracker[], int *numExpenses) {
    // Get the item name and cost from the user
    printf("\nEnter the expense item name: ");
    scanf("%s", tracker[*numExpenses].item_name);
    printf("Enter the expense cost: ");
    scanf("%f", &tracker[*numExpenses].cost);
    
    // Increment the number of expense items in the tracker
    *numExpenses += 1;
    
    printf("Expense added successfully.\n");
}

void printExpenses(Expense tracker[], int numExpenses) {
    // Check if any expenses have been added
    if(numExpenses == 0) {
        printf("No expenses have been added yet.\n");
        return;
    }
    
    // Print the header row
    printf("\n%-30s%10s\n", "Item", "Cost");
    
    // Print each expense item
    for(int i = 0; i < numExpenses; i++) {
        printf("%-30s%10.2f\n", tracker[i].item_name, tracker[i].cost);
    }
}