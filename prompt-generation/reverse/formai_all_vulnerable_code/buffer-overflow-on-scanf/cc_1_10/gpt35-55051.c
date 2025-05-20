//FormAI DATASET v1.0 Category: Expense Tracker ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char category[20];
    float amount;
    char date[11];
} Expense;

int numExpenses = 0;
Expense expenses[MAX_EXPENSES];

void printMainMenu() {
    printf("1. Enter expense\n"
           "2. View expenses\n"
           "3. Exit\n");
}

void enterExpense() {
    if (numExpenses == MAX_EXPENSES) {
        printf("\nMaximum number of expenses reached!\n\n");
        return;
    }
    
    Expense expense;
    printf("\nEnter category: ");
    scanf("%s", expense.category);
    printf("Enter amount: ");
    scanf("%f", &expense.amount);
    printf("Enter date (format: yyyy/mm/dd): ");
    scanf("%s", expense.date);
    
    expenses[numExpenses++] = expense;
    
    printf("\nExpense added successfully!\n\n");
}

void viewExpenses() {
    if (numExpenses == 0) {
        printf("\nNo expenses added yet.\n\n");
        return;
    }
    
    printf("\n*****************************************\n");
    printf("* %-15s %-10s %-10s *\n", "Category", "Amount", "Date");
    printf("*****************************************\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("* %-15s $%-9.2f %-10s*\n", expenses[i].category, expenses[i].amount, expenses[i].date);
    }
    printf("*****************************************\n\n");
}

int main() {
    int choice;
    
    do {
        printMainMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                enterExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice, try again.\n\n");
        }
    } while (choice != 3);
    
    return 0;
}