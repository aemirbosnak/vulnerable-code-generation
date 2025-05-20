//FormAI DATASET v1.0 Category: Expense Tracker ; Style: scientific
/*
 * C Expense Tracker Example Program
 * By [Your Name]
 * [Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define structure for expenses
typedef struct {
    char category[50];
    float amount;
} Expense;

// function to add expense
void addExpense(Expense *expenses, int *size) {
    char category[50];
    float amount;
    
    printf("Enter category: ");
    scanf("%s", category);
    printf("Enter amount: ");
    scanf("%f", &amount);
    
    // increase size of expenses array
    *size += 1;
    expenses = (Expense*) realloc(expenses, (*size) * sizeof(Expense));
    
    // add new expense to array
    strcpy(expenses[*size - 1].category, category);
    expenses[*size - 1].amount = amount;
    
    printf("Expense added successfully.\n");
}

// function to delete expense
void deleteExpense(Expense *expenses, int *size) {
    int index;
    
    printf("Enter index of expense to delete: ");
    scanf("%d", &index);
    
    // remove expense from array
    for (int i = index - 1; i < (*size) - 1; i++) {
        expenses[i] = expenses[i + 1];
    }
    
    // decrease size of expenses array
    *size -= 1;
    expenses = (Expense*) realloc(expenses, (*size) * sizeof(Expense));
    
    printf("Expense deleted successfully.\n");
}

// function to view all expenses
void viewAllExpenses(Expense *expenses, int size) {
    if (size == 0) {
        printf("No expenses found.\n");
    } else {
        printf("\nExpenses:\n");
        printf("%-20s %-10s\n", "Category", "Amount");
        printf("-------------------- ---------------------\n");
        for (int i = 0; i < size; i++) {
            printf("%-20s %-10.2f\n", expenses[i].category, expenses[i].amount);
        }
    }
}

// main function
int main() {
    Expense *expenses = NULL;
    int size = 0;
    int choice;
    
    do {
        printf("\nExpense Tracker Menu:\n");
        printf("---------------------\n");
        printf("1. Add Expense\n");
        printf("2. Delete Expense\n");
        printf("3. View All Expenses\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addExpense(expenses, &size);
                break;
            case 2:
                deleteExpense(expenses, &size);
                break;
            case 3:
                viewAllExpenses(expenses, size);
                break;
            case 4:
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);
    
    // free memory
    free(expenses);
    
    return 0;
}