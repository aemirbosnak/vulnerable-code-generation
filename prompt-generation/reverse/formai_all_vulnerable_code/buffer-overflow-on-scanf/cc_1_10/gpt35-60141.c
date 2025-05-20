//FormAI DATASET v1.0 Category: Expense Tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESC_LENGTH 50

// Structure for each expense
struct Expense {
    char desc[MAX_DESC_LENGTH];
    float amount;
};

// Initialize the expenses array
struct Expense expenses[MAX_EXPENSES];
int numExpenses = 0;

// Function to get user's choice
int getChoice() {
    int choice = 0;
    printf("\n1 - Add expense\n2 - View expenses\n3 - Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to add a new expense
void addExpense() {
    if(numExpenses >= MAX_EXPENSES) {
        printf("Maximum number of expenses reached.\n");
        return;
    }

    struct Expense newExpense;
    printf("Enter expense description (max %d characters): ", MAX_DESC_LENGTH);
    scanf("%s", newExpense.desc);
    printf("Enter expense amount: ");
    scanf("%f", &newExpense.amount);

    expenses[numExpenses] = newExpense;
    numExpenses++;

    printf("Expense added successfully.\n");
}

// Function to view all expenses
void viewExpenses() {
    if(numExpenses == 0) {
        printf("No expenses added.\n");
        return;
    }

    printf("Expenses:\n");
    for(int i=0; i<numExpenses; i++) {
        printf("%d. %s: $%.2f\n", i+1, expenses[i].desc, expenses[i].amount);
    }
}

int main() {
    int choice = 0;
    while(choice != 3) {
        choice = getChoice();

        switch(choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}