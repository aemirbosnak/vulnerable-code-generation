//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a structure for an expense
typedef struct {
    char name[50];
    int amount;
    char category[50];
} Expense;

// Function to add an expense
void addExpense(Expense* expenses, int size, Expense newExpense) {
    if (size == 0) {
        expenses[0] = newExpense;
        return;
    }
    
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(newExpense.name, expenses[i].name) == 0 && 
            newExpense.amount == expenses[i].amount &&
            strcmp(newExpense.category, expenses[i].category) == 0) {
            printf("Expense already exists\n");
            return;
        }
    }
    
    expenses[size] = newExpense;
    size++;
}

// Function to print expenses
void printExpenses(Expense* expenses, int size) {
    int i;
    printf("Expenses:\n");
    for (i = 0; i < size; i++) {
        printf("Name: %s\nAmount: %d\nCategory: %s\n\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

// Function to calculate total expenses
int calculateTotal(Expense* expenses, int size) {
    int total = 0;
    int i;
    for (i = 0; i < size; i++) {
        total += expenses[i].amount;
    }
    return total;
}

// Function to search for an expense
int searchExpense(Expense* expenses, int size, char* name, int* amount, char* category) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(expenses[i].name, name) == 0 &&
            expenses[i].amount == *amount &&
            strcmp(expenses[i].category, category) == 0) {
            *amount = expenses[i].amount;
            return 1;
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));
    
    // Initialize an array of expenses
    Expense expenses[10];
    int size = 0;
    
    // Prompt user to enter a new expense
    char name[50];
    int amount;
    char category[50];
    printf("Enter the name of the expense: ");
    scanf("%s", name);
    printf("Enter the amount: ");
    scanf("%d", &amount);
    printf("Enter the category: ");
    scanf("%s", category);
    Expense newExpense = {name, amount, category};
    
    // Add the expense to the array
    addExpense(expenses, size, newExpense);
    
    // Print all expenses
    printExpenses(expenses, size);
    
    // Calculate the total expenses
    int total = calculateTotal(expenses, size);
    printf("Total expenses: %d\n", total);
    
    // Search for an expense
    char searchName[50];
    int searchAmount;
    char searchCategory[50];
    printf("Enter the name of the expense to search: ");
    scanf("%s", searchName);
    printf("Enter the amount of the expense to search: ");
    scanf("%d", &searchAmount);
    printf("Enter the category of the expense to search: ");
    scanf("%s", searchCategory);
    int searchResult = searchExpense(expenses, size, searchName, &searchAmount, searchCategory);
    if (searchResult) {
        printf("Expense found!\n");
    } else {
        printf("Expense not found\n");
    }
    
    // Free memory
    free(expenses);
    
    return 0;
}