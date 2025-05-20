//FormAI DATASET v1.0 Category: Expense Tracker ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>

// define max size of the array
#define MAX_SIZE 100

// function prototypes
void displayMenu();
int getChoice();
float getExpense();
void addExpense(float*, int*);
void viewExpenses(float*, int);
float calculateTotalExpenses(float*, int);

// main function
int main() {

    // array to store expenses, initialized to zero
    float expenses[MAX_SIZE] = {0};

    // number of entries in expenses array
    int numExpenses = 0;

    // display menu to user
    displayMenu();

    // get user's choice
    int choice = getChoice();

    // loop until user chooses to exit the program
    while(choice != 4) {

        // invoke corresponding function based on user's choice
        switch(choice) {
            case 1:
                addExpense(expenses, &numExpenses);
                break;
            case 2:
                viewExpenses(expenses, numExpenses);
                break;
            case 3:
                printf("Total expenses so far: $%.2f\n", calculateTotalExpenses(expenses, numExpenses));
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        // display menu and get user's choice again
        displayMenu();
        choice = getChoice();
    }

    return 0;
}

// function to display menu to user
void displayMenu() {
    printf("Expense tracker\n");
    printf("1. Add an expense\n");
    printf("2. View all expenses\n");
    printf("3. Calculate total expenses\n");
    printf("4. Exit\n");
}

// function to get user's choice
int getChoice() {
    int choice = 0;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// function to add an expense to the expenses array
void addExpense(float* expenses, int* numExpenses) {
    float expense = getExpense();
    expenses[*numExpenses] = expense;
    (*numExpenses)++;
    printf("Expense added successfully.\n");
}

// function to get expense amount from user
float getExpense() {
    float expense = 0;
    printf("Enter expense amount: $");
    scanf("%f", &expense);
    return expense;
}

// function to view all expenses in the expenses array
void viewExpenses(float* expenses, int numExpenses) {
    if(numExpenses == 0) {
        printf("No expenses added yet.\n");
        return;
    }
    printf("Expenses:\n");
    for(int i=0; i<numExpenses; i++) {
        printf("$%.2f\n", expenses[i]);
    }
}

// function to calculate total expenses in the expenses array
float calculateTotalExpenses(float* expenses, int numExpenses) {
    float total = 0;
    for(int i=0; i<numExpenses; i++) {
        total += expenses[i];
    }
    return total;
}