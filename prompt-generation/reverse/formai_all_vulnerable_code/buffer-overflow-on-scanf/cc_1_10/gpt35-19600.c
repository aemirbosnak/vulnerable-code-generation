//FormAI DATASET v1.0 Category: Expense Tracker ; Style: systematic
#include <stdio.h> // To use standard input/output functions
#include <stdlib.h> // To use malloc() and free() functions

// Define a structure to store individual expense details
struct Expense {
    int id;
    char description[50];
    float amount;
    char category[20];
};

// Declare necessary functions
void createExpense();
void viewExpense();
void editExpense();
void deleteExpense();
void searchExpense();

// Define a global variable to store total number of expenses
int numExpenses = 0;
// Define a global array of Expenses to store all expenses
struct Expense* expenses;

int main() {
    int choice;
    do { // Display menu and repeat until user chooses to exit
        printf("\n\nExpense Tracker Menu");
        printf("\n1. Create a new expense");
        printf("\n2. View all expenses");
        printf("\n3. Edit an existing expense");
        printf("\n4. Delete an existing expense");
        printf("\n5. Search for an expense");
        printf("\n6. Exit");
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: // If user chooses to create a new expense
                createExpense();
                break;
            case 2: // If user chooses to view all expenses
                viewExpense();
                break;
            case 3: // If user chooses to edit an existing expense
                editExpense();
                break;
            case 4: // If user chooses to delete an existing expense
                deleteExpense();
                break;
            case 5: // If user chooses to search for an expense
                searchExpense();
                break;
            case 6: // If user chooses to exit
                printf("\nThank you for using Expense Tracker!");
                break;
            default: // If user enters an invalid choice
                printf("\nInvalid choice! Please try again.");
        }
    } while(choice != 6);
    // Free the dynamically allocated memory before exiting the program
    free(expenses);
    return 0;
}

void createExpense() {
    // Increment the counter for total number of expenses
    numExpenses++;
    // Allocate memory for a new Expense structure and store its address in pointer newExpense
    struct Expense* newExpense = (struct Expense*) malloc(sizeof(struct Expense));
    // Assign a unique id to the new expense
    newExpense->id = numExpenses;
    getchar(); // To consume the newline character left after last scanf() call
    printf("\nEnter a brief description of the expense: ");
    fgets(newExpense->description, 50, stdin);
    printf("Enter the amount of the expense: ");
    scanf("%f", &newExpense->amount);
    getchar();
    printf("Enter the category of the expense: ");
    fgets(newExpense->category, 20, stdin);
    // If this is the first expense, allocate memory to the global array of expenses
    if(numExpenses == 1) {
        expenses = (struct Expense*) malloc(sizeof(struct Expense));
    }
    // If not, reallocate memory to expand the global array of expenses
    else {
        expenses = (struct Expense*) realloc(expenses, numExpenses * sizeof(struct Expense));
    }
    // Add the new expense to the global array
    expenses[numExpenses-1] = *newExpense;
    // Free the memory allocated to the new expense
    free(newExpense);
    printf("\nExpense created successfully!");
}

void viewExpense() {
    // If there are no expenses, display appropriate message
    if(numExpenses == 0) {
        printf("\nNo expenses to display!");
    }
    // If there are expenses, display all expenses
    else {
        printf("\nAll Expenses:");
        for(int i=0; i<numExpenses; i++) {
            printf("\nExpense id: %d\nDescription: %sAmount: %.2f\nCategory: %s", expenses[i].id, expenses[i].description, expenses[i].amount, expenses[i].category);
        }
    }
}

void editExpense() {
    int idToEdit, choice;
    printf("\nEnter the id of the expense to edit: ");
    scanf("%d", &idToEdit);
    // Search for the expense with the given id
    int indexToEdit = -1;
    for(int i=0; i<numExpenses; i++) {
        if(expenses[i].id == idToEdit) {
            indexToEdit = i;
            break;
        }
    }
    // If the expense with the given id is not found, display appropriate message
    if(indexToEdit == -1) {
        printf("\nExpense with id %d not found!", idToEdit);
    }
    // If the expense with the given id is found, display its details and offer options to edit
    else {
        printf("\nExpense details:\n");
        printf("Description: %sAmount: %.2f\nCategory: %s", expenses[indexToEdit].description, expenses[indexToEdit].amount, expenses[indexToEdit].category);
        printf("\n\nSelect an option to edit:");
        printf("\n1. Description");
        printf("\n2. Amount");
        printf("\n3. Category");
        printf("\n4. Cancel");
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character left after last scanf() call
        switch(choice) {
            case 1: // If user wants to edit description
                printf("\nEnter a new brief description of the expense: ");
                fgets(expenses[indexToEdit].description, 50, stdin);
                printf("Expense description updated successfully!");
                break;
            case 2: // If user wants to edit amount
                printf("\nEnter a new amount of the expense: ");
                scanf("%f", &expenses[indexToEdit].amount);
                getchar(); // To consume the newline character left after last scanf() call
                printf("Expense amount updated successfully!");
                break;
            case 3: // If user wants to edit category
                printf("\nEnter a new category of the expense: ");
                fgets(expenses[indexToEdit].category, 20, stdin);
                printf("Expense category updated successfully!");
                break;
            case 4: // If user wants to cancel
                break;
            default: // If user enters an invalid choice
                printf("\nInvalid choice! Please try again.");
        }
    }
}

void deleteExpense() {
    int idToDelete;
    printf("\nEnter the id of the expense to delete: ");
    scanf("%d", &idToDelete);
    // Search for the expense with the given id
    int indexToDelete = -1;
    for(int i=0; i<numExpenses; i++) {
        if(expenses[i].id == idToDelete) {
            indexToDelete = i;
            break;
        }
    }
    // If the expense with the given id is not found, display appropriate message
    if(indexToDelete == -1) {
        printf("\nExpense with id %d not found!", idToDelete);
    }
    // If the expense with the given id is found, delete it
    else {
        // If there is only one expense, simply initialize the count to zero
        if(numExpenses == 1) {
            numExpenses = 0;
        }
        // If there are multiple expenses, overwrite the expense to delete with the last expense and decrement the count
        else {
            expenses[indexToDelete] = expenses[numExpenses-1];
            numExpenses--;
            // Reallocate memory to reduce the size of global array of expenses
            expenses = (struct Expense*) realloc(expenses, numExpenses * sizeof(struct Expense));
        }
        printf("\nExpense with id %d deleted successfully!", idToDelete);
    }
}

void searchExpense() {
    char searchString[50];
    printf("\nEnter a keyword to search: ");
    getchar(); // To consume the newline character left after last scanf() call
    fgets(searchString, 50, stdin);
    int countResults = 0;
    printf("\nSearch Results:");
    for(int i=0; i<numExpenses; i++) {
        if(strstr(expenses[i].description, searchString) != NULL || strstr(expenses[i].category, searchString) != NULL) {
            printf("\nExpense id: %d\nDescription: %sAmount: %.2f\nCategory: %s", expenses[i].id, expenses[i].description, expenses[i].amount, expenses[i].category);
            countResults++;
        }
    }
    if(countResults == 0) {
        printf("\nNo matching expenses found!");
    }
}