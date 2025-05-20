//FormAI DATASET v1.0 Category: Expense Tracker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//define constants
#define MAX_EXPENSES 100
#define MAX_DESCRIPTION_LENGTH 50

//define struct to hold expense data
struct Expense {
    float amount;
    char description[MAX_DESCRIPTION_LENGTH];
    int day;
    int month;
    int year;
};

//declare global array of expenses and variable to track number of expenses
struct Expense expenses[MAX_EXPENSES];
int numOfExpenses = 0;

//function to display menu and get user input
char getMenuInput() {
    char input;
    printf("\n\nExpense Tracker Menu\n");
    printf("--------------------\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Search Expenses\n");
    printf("4. Exit\n\n");
    printf("Enter choice: ");
    scanf(" %c", &input);
    input = toupper(input);
    return input;
}

//function to add expense
void addExpense() {
    //check if max number of expenses has been reached
    if (numOfExpenses >= MAX_EXPENSES) {
        printf("\nError: Max number of expenses reached.\n");
        return;
    }
    
    //get user input for new expense and add to expenses array
    struct Expense newExpense;
    printf("\nEnter expense amount: ");
    scanf("%f", &newExpense.amount);
    printf("Enter expense description (max %d characters): ", MAX_DESCRIPTION_LENGTH);
    scanf(" %[^\n]", newExpense.description);
    printf("Enter expense day: ");
    scanf("%d", &newExpense.day);
    printf("Enter expense month: ");
    scanf("%d", &newExpense.month);
    printf("Enter expense year: ");
    scanf("%d", &newExpense.year);
    expenses[numOfExpenses] = newExpense;
    numOfExpenses++;
    printf("\nExpense added successfully!\n");
}

//function to view expenses
void viewExpenses() {
    //check if expenses have been added
    if (numOfExpenses == 0) {
        printf("\nNo expenses found.\n");
        return;
    }
    
    //print out all expenses
    printf("\nExpenses:\n");
    printf("---------\n");
    for (int i = 0; i < numOfExpenses; i++) {
        printf("Amount: $%.2f\n", expenses[i].amount);
        printf("Description: %s\n", expenses[i].description);
        printf("Date: %d/%d/%d\n\n", expenses[i].day, expenses[i].month, expenses[i].year);
    }
}

//function to search expenses
void searchExpenses() {
    //check if expenses have been added
    if (numOfExpenses == 0) {
        printf("\nNo expenses found.\n");
        return;
    }
    
    //get user input for search term
    char searchTerm[MAX_DESCRIPTION_LENGTH];
    printf("\nEnter search term: ");
    scanf(" %[^\n]", searchTerm);
    
    //search for expenses containing search term and print out matching expenses
    printf("\nMatching Expenses:\n");
    printf("--------------------\n");
    int numMatches = 0;
    for (int i = 0; i < numOfExpenses; i++) {
        if (strstr(expenses[i].description, searchTerm) != NULL) {
            numMatches++;
            printf("Amount: $%.2f\n", expenses[i].amount);
            printf("Description: %s\n", expenses[i].description);
            printf("Date: %d/%d/%d\n\n", expenses[i].day, expenses[i].month, expenses[i].year);
        }
    }
    if (numMatches == 0) {
        printf("\nNo matching expenses found.\n");
    }
}

//main function to run expense tracker program
int main() {
    printf("Welcome to the Expense Tracker!\n\n");
    
    char input;
    do {
        input = getMenuInput();
        switch (input) {
            case '1':
                addExpense();
                break;
            case '2':
                viewExpenses();
                break;
            case '3':
                searchExpenses();
                break;
            case '4':
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nError: Invalid input.\n");
                break;
        }
    } while (input != '4');
    
    return 0;
}