//FormAI DATASET v1.0 Category: Expense Tracker ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_EXPENSES 50
#define MAX_DESCRIPTION_LENGTH 100

struct Expense{
    int id;
    char description[MAX_DESCRIPTION_LENGTH + 1];
    float amount;
    char category[MAX_DESCRIPTION_LENGTH + 1];
};

struct Expense expenses[MAX_EXPENSES];
int numExpenses = 0;

void printMenu() {
    printf("\n\n****EXPENSE TRACKER****");
    printf("\n1. Add Expense");
    printf("\n2. View All Expenses");
    printf("\n3. View Expenses by Category");
    printf("\n4. Exit");
}

void addExpense() {
    if(numExpenses >= MAX_EXPENSES){
        printf("\nUnable to add expense. Maximum number of expenses reached.");
        return;
    }

    printf("\nEnter expense details:");

    int id = numExpenses + 1;
    char description[MAX_DESCRIPTION_LENGTH + 1];
    float amount;
    char category[MAX_DESCRIPTION_LENGTH];

    printf("\nDescription (max %d characters): ", MAX_DESCRIPTION_LENGTH);
    getchar();
    fgets(description, MAX_DESCRIPTION_LENGTH, stdin);
    description[strcspn(description, "\n")] = '\0'; // remove newline character

    printf("\nAmount: ");
    scanf("%f", &amount);

    printf("\nCategory (max %d characters): ", MAX_DESCRIPTION_LENGTH);
    getchar();
    fgets(category, MAX_DESCRIPTION_LENGTH, stdin);
    category[strcspn(category, "\n")] = '\0'; // remove newline character

    struct Expense expense = {id, description, amount, category};
    expenses[numExpenses] = expense;

    numExpenses++;

    printf("\nExpense added successfully.");
}

void viewAllExpenses() {
    printf("\n\nAll Expenses:");

    if(numExpenses == 0) {
        printf("\nNo expenses to show.");
    }

    for(int i=0; i<numExpenses; i++) {
        printf("\n%d. %s ($%.2f) - %s", expenses[i].id, expenses[i].description, expenses[i].amount, expenses[i].category);
    }
}

void viewExpensesByCategory() {
    char category[MAX_DESCRIPTION_LENGTH + 1];

    printf("\nEnter category to view expenses: ");
    getchar();
    fgets(category, MAX_DESCRIPTION_LENGTH, stdin);
    category[strcspn(category, "\n")] = '\0'; // remove newline character
    
    printf("\nExpenses for category: %s", category);

    int foundExpenses = 0;

    for(int i=0; i<numExpenses; i++) {
        if(strcmp(expenses[i].category, category) == 0) {
            foundExpenses++;
            printf("\n%d. %s ($%.2f)", expenses[i].id, expenses[i].description, expenses[i].amount);
        }
    }

    if(foundExpenses == 0) {
        printf("\nNo expenses found for category: %s", category);
    }
}

int main() {
    int choice = 0;

    while(choice != 4) {
        printMenu();
        printf("\n\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewAllExpenses();
                break;
            case 3:
                viewExpensesByCategory();
                break;
            case 4:
                printf("\nExiting Expense Tracker. Goodbye!\n\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}