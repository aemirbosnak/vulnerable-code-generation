//FormAI DATASET v1.0 Category: Expense Tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

// Structure to store expense information
struct Expense {
    char category[50];
    float amount;
    char date[20];
    char description[100];
};

// Function to add expense
void addExpense(struct Expense expenses[], int *numExpenses) {
    char category[50], date[20], description[100], amountStr[20];
    float amount;

    printf("\nEnter category: ");
    scanf(" %[^\n]", category);
    printf("Enter date (DD/MM/YYYY): ");
    scanf(" %[^\n]", date);
    printf("Enter description: ");
    scanf(" %[^\n]", description);
    printf("Enter amount: ");
    scanf(" %[^\n]", amountStr);

    amount = atof(amountStr);

    // Add new expense to array
    strcpy(expenses[*numExpenses].category, category);
    expenses[*numExpenses].amount = amount;
    strcpy(expenses[*numExpenses].date, date);
    strcpy(expenses[*numExpenses].description, description);

    (*numExpenses)++;
}

// Function to print expense list
void printExpenses(struct Expense expenses[], int numExpenses) {
    if(numExpenses == 0) {
        printf("\nNo expenses added yet.\n");
        return;
    }

    printf("\nExpense List:\n");
    printf("%5s  %-15s  %-10s  %-25s  %s\n", "ID", "Category", "Amount", "Description", "Date");
    for(int i = 0; i < numExpenses; i++) {
        printf("%2d.  %-15s  $%-10.2f  %-25s  %s\n", i+1, expenses[i].category, expenses[i].amount, expenses[i].description, expenses[i].date);
    }
}

// Main function
int main() {
    struct Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    char choice;

    while(1) {
        printf("\nExpense Tracker Menu:\n");
        printf("1. Add Expense\n");
        printf("2. Print Expenses\n");
        printf("3. Exit\n");

        printf("\nEnter your choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                addExpense(expenses, &numExpenses);
                break;

            case '2':
                printExpenses(expenses, numExpenses);
                break;

            case '3':
                printf("\nGoodbye!\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}