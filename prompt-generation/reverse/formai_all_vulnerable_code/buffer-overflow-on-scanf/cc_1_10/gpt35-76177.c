//FormAI DATASET v1.0 Category: Expense Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_DATE 11

typedef struct {
    char date[MAX_DATE];
    float amount;
    char description[50];
} expenseEntry;

int numEntries = 0;
expenseEntry expenseTracker[MAX_ENTRIES];

void printMenu() {
    printf("\n");
    printf("Expense Tracker\n");
    printf("----------------------\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Delete Expense\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int addExpense() {
    if (numEntries == MAX_ENTRIES) {
        printf("Expense tracker is full! Cannot add more expenses.\n");
        return 0;
    }
    
    expenseEntry expense;
    printf("Enter the date (format: MM/DD/YYYY): ");
    scanf("%s", expense.date);
    printf("Enter the amount: ");
    scanf("%f", &expense.amount);
    printf("Enter the description: ");
    scanf("%s", expense.description);
    
    expenseTracker[numEntries] = expense;
    numEntries++;
    
    printf("Expense added successfully!\n");
    return 1;
}

void viewExpenses() {
    if (numEntries == 0) {
        printf("No expenses to show.\n");
        return;
    }
    
    printf("Date\t\tAmount\tDescription\n");
    printf("--------------------------------------\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s\t$%.2f\t%s\n", expenseTracker[i].date, expenseTracker[i].amount, expenseTracker[i].description);
    }
}

int deleteExpense() {
    if (numEntries == 0) {
        printf("No expenses to delete.\n");
        return 0;
    }
    
    char dateToDelete[MAX_DATE];
    printf("Enter the date of the expense to delete (format: MM/DD/YYYY): ");
    scanf("%s", dateToDelete);
    
    int deleteIndex = -1; // Set to -1 so we can check if a match was found
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(expenseTracker[i].date, dateToDelete) == 0) {
            deleteIndex = i;
            break;
        }
    }
    
    if (deleteIndex == -1) {
        printf("No expense with that date found.\n");
        return 0;
    }
    
    for (int i = deleteIndex; i < numEntries - 1; i++) {
        expenseTracker[i] = expenseTracker[i+1];
    }
    numEntries--;
    
    printf("Expense deleted successfully!\n");
    return 1;
}

int main() {
    int choice;
    do {
        printMenu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                deleteExpense();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        
    } while (choice != 4);
    
    return 0;
}