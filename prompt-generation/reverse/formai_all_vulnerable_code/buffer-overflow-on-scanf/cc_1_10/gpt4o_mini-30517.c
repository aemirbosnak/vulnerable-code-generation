//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold expense details
typedef struct {
    char category[30];
    char description[100];
    float amount;
} Expense;

// Function to add an expense
void addExpense(Expense *expenses, int *count) {
    printf("\nEnter expense category: ");
    scanf("%s", expenses[*count].category);
    
    printf("Enter expense description: ");
    scanf(" %[^\n]s", expenses[*count].description); // Read string with spaces
    
    printf("Enter expense amount: ");
    scanf("%f", &expenses[*count].amount);
    
    (*count)++;
    printf("Expense added successfully!\n");
}

// Function to view all expenses
void viewExpenses(Expense *expenses, int count) {
    printf("\nYour Expenses:\n");
    for (int i = 0; i < count; i++) {
        printf("Category: %s | Description: %s | Amount: %.2f\n", 
                expenses[i].category, expenses[i].description, expenses[i].amount);
    }
    if (count == 0) {
        printf("No expenses recorded yet.\n");
    }
}

// Function to delete an expense
void deleteExpense(Expense *expenses, int *count) {
    if (*count == 0) {
        printf("\nNo expenses to delete.\n");
        return;
    }

    int index;
    printf("\nEnter the expense index to delete (0 to %d): ", *count - 1);
    scanf("%d", &index);
    
    if (index < 0 || index >= *count) {
        printf("Invalid index!\n");
        return;
    }

    // Shift expenses to fill the gap left by the deleted expense
    for (int i = index; i < *count - 1; i++) {
        expenses[i] = expenses[i + 1];
    }
    (*count)--; // Decrease the count of expenses
    printf("Expense deleted successfully!\n");
}

// Main function
int main() {
    Expense expenses[100]; // Array to hold up to 100 expenses
    int count = 0; // Current expense count
    int choice;

    do {
        printf("\nExpense Tracker Menu:\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Delete Expense\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                viewExpenses(expenses, count);
                break;
            case 3:
                deleteExpense(expenses, &count);
                break;
            case 4:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}