//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define CATEGORY_LEN 30
#define DESC_LEN 50

typedef struct {
    char category[CATEGORY_LEN];
    char description[DESC_LEN];
    float amount;
} Expense;

void addExpense(Expense expenses[], int *count);
void viewExpenses(Expense expenses[], int count);
float totalExpenses(Expense expenses[], int count);
void menu();

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;
    int choice;
    
    while (1) {
        menu();
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
                printf("Total Expenses: $%.2f\n", totalExpenses(expenses, count));
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}

void menu() {
    printf("\n=== Expense Tracker ===\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. View Total Expenses\n");
    printf("4. Exit\n");
}

void addExpense(Expense expenses[], int *count) {
    if (*count >= MAX_EXPENSES) {
        printf("Cannot add more expenses. Maximum limit reached.\n");
        return;
    }
    
    printf("Enter category: ");
    scanf("%s", expenses[*count].category);
    printf("Enter description: ");
    scanf(" %[^\n]s", expenses[*count].description);
    printf("Enter amount: ");
    scanf("%f", &expenses[*count].amount);
    
    (*count)++;
    printf("Expense added successfully!\n");
}

void viewExpenses(Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses to display.\n");
        return;
    }
    
    printf("\n=== List of Expenses ===\n");
    for (int i = 0; i < count; i++) {
        printf("Category: %s | Description: %s | Amount: $%.2f\n",
               expenses[i].category, expenses[i].description, expenses[i].amount);
    }
}

float totalExpenses(Expense expenses[], int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }
    return total;
}