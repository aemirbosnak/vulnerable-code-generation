//FormAI DATASET v1.0 Category: Expense Tracker ; Style: careful
#include <stdio.h> // Include standard input/output header file
#include <stdlib.h> // Include standard library header file
#include <string.h> // Include string header file

#define MAX_EXPENSES 100 // Define maximum number of expenses

typedef struct Expense { // Define Expense structure
    char name[50];
    float amount;
    char category[20];
    char date[11]; // Format: dd-mm-yyyy
} Expense;

int total_expenses = 0; // Initialize total expenses to 0
Expense expenses[MAX_EXPENSES]; // Declare an array of expenses

void addExpense(); // Function prototype to add a new expense
void viewExpenses(); // Function prototype to view all expenses
void viewExpensesByCategory(); // Function prototype to view expenses by category
void viewTotalExpense(); // Function prototype to view total expense
void deleteExpense(); // Function prototype to delete an expense

int main() {
    int choice;

    // Display main menu and get user choice
    do {
        printf("\n\n=======================");
        printf("\nExpense Tracker Program");
        printf("\n=======================\n");
        printf("1. Add new expense\n");
        printf("2. View all expenses\n");
        printf("3. View expenses by category\n");
        printf("4. View total expense\n");
        printf("5. Delete an expense\n");
        printf("6. Exit program\n");
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                viewExpensesByCategory();
                break;
            case 4:
                viewTotalExpense();
                break;
            case 5:
                deleteExpense();
                break;
            case 6:
                printf("\nExiting program...");
                break;
            default:
                printf("\nInvalid choice! Please enter a valid choice (1-6).");
                break;
        }
    } while(choice != 6);

    return 0;
}

void addExpense() {
    if(total_expenses == MAX_EXPENSES) { // Check if maximum number of expenses is reached
        printf("\nSorry, you can't add any more expenses as maximum limit has been reached!");
        return;
    }

    // Get expense details from user
    printf("\nEnter expense name: ");
    scanf("%s", expenses[total_expenses].name);
    printf("Enter amount: ");
    scanf("%f", &expenses[total_expenses].amount);
    printf("Enter category: ");
    scanf("%s", expenses[total_expenses].category);
    printf("Enter date (dd-mm-yyyy): ");
    scanf("%s", expenses[total_expenses].date);

    total_expenses++; // Increment total expenses
    printf("\nExpense added successfully!");
}

void viewExpenses() {
    if(total_expenses == 0) { // Check if there are no expenses
        printf("\nNo expenses found!");
        return;
    }

    printf("\nAll expenses:\n");
    
    //Display table header
    printf("%-20s %-10s %-15s %-10s", "Expense Name", "Amount", "Category", "Date");

    //Display all the expenses
    for(int i = 0; i < total_expenses; i++) {
        printf("\n%-20s %-10.2f %-15s %-10s", expenses[i].name, expenses[i].amount, expenses[i].category, expenses[i].date);
    }
}

void viewExpensesByCategory() {
    if(total_expenses == 0) { // Check if there are no expenses
        printf("\nNo expenses found!");
        return;
    }

    char category[20];
    int count = 0;

    // Get category input from user
    printf("\nEnter category: ");
    scanf("%s", category);

    printf("\nExpenses in category '%s':\n", category);

    // Display table header
    printf("%-20s %-10s %-10s", "Expense Name", "Amount", "Date");

    // Display expenses in the given category
    for(int i = 0; i < total_expenses; i++) {
        if(strcmp(expenses[i].category, category) == 0) {
            printf("\n%-20s %-10.2f %-10s", expenses[i].name, expenses[i].amount, expenses[i].date);
            count++;
        }
    }

    if(count == 0) { // Check if there are no expenses in the given category
        printf("\nNo expenses found in category '%s'!", category);
    }
}

void viewTotalExpense() {
    if(total_expenses == 0) { // Check if there are no expenses
        printf("\nNo expenses found!");
        return;
    }

    float total = 0;

    // Calculate total expense
    for(int i = 0; i < total_expenses; i++) {
        total += expenses[i].amount;
    }

    printf("\nTotal expense: %.2f", total);
}

void deleteExpense() {
    if(total_expenses == 0) { // Check if there are no expenses
        printf("\nNo expenses found!");
        return;
    }

    char name[50];
    int index = -1;

    // Get expense name to be deleted from user
    printf("\nEnter expense name to be deleted: ");
    scanf("%s", name);

    // Find expense index from name
    for(int i = 0; i < total_expenses; i++) {
        if(strcmp(expenses[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if(index == -1) { // Check if expense not found
        printf("\nExpense '%s' not found!", name);
        return;
    }

    // Shift remaining expenses one index left
    for(int i = index; i < total_expenses - 1; i++) {
        expenses[i] = expenses[i+1];
    }

    total_expenses--; // Decrement total expenses
    printf("\nExpense '%s' deleted successfully!", name);
}