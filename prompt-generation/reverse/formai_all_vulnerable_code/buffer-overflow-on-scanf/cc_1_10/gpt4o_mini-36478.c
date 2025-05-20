//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_STR_LEN 50

// Structure to hold Expense data
typedef struct {
    int id;
    char name[MAX_STR_LEN];
    float amount;
} Expense;

// Function prototypes
void addExpense(Expense expenses[], int *count);
void viewExpenses(Expense expenses[], int count);
void deleteExpense(Expense expenses[], int *count);
void viewTotalExpenses(Expense expenses[], int count);
void showMenu();

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;
    int choice;
    
    while (1) {
        showMenu();
        printf("Enter your choice: ");
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
                viewTotalExpenses(expenses, count);
                break;
            case 5:
                printf("Exiting... Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}

void showMenu() {
    printf("\n--- Expense Tracker ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Delete Expense\n");
    printf("4. View Total Expenses\n");
    printf("5. Exit\n");
}

void addExpense(Expense expenses[], int *count) {
    if (*count >= MAX_EXPENSES) {
        printf("Cannot add more expenses, limit reached.\n");
        return;
    }

    Expense newExpense;
    newExpense.id = *count + 1;
    
    printf("Enter expense name: ");
    scanf("%s", newExpense.name);
    
    printf("Enter amount: ");
    scanf("%f", &newExpense.amount);

    expenses[*count] = newExpense;
    (*count)++;
    printf("Expense added successfully!\n");
}

void viewExpenses(Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses recorded.\n");
        return;
    }
    
    printf("\n--- Expenses List ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Amount: %.2f\n", 
                expenses[i].id, expenses[i].name, expenses[i].amount);
    }
}

void deleteExpense(Expense expenses[], int *count) {
    if (*count == 0) {
        printf("No expenses to delete.\n");
        return;
    }
    
    int id;
    printf("Enter the ID of the expense to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {
        if (expenses[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                expenses[j] = expenses[j + 1];
            }
            (*count)--;
            printf("Expense deleted successfully!\n");
            return;
        }
    }
    printf("Expense with ID %d not found.\n", id);
}

void viewTotalExpenses(Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses recorded. Total amount is 0.00\n");
        return;
    }
    
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }
    printf("Total Expenses: %.2f\n", total);
}