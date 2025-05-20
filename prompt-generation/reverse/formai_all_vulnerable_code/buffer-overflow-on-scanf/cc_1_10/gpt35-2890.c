//FormAI DATASET v1.0 Category: Expense Tracker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expenses {
    int id;
    char description[50];
    float amount;
    char category[20];
};

void displayMenu() {
    printf("\nExpense Tracker\n");
    printf("==========================\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Exit\n");
    printf("==========================\n\n");
}

void addExpense(struct Expenses *expenses, int *count) {
    printf("Enter Expense Details\n");
    printf("==========================\n");
    
    int id = ++(*count);
    printf("ID: %d\n", id);
    
    printf("Description: ");
    scanf(" %[^\n]%*c", expenses[id-1].description);
    
    printf("Amount: ");
    scanf("%f", &expenses[id-1].amount);
    
    printf("Category: ");
    scanf(" %[^\n]%*c", expenses[id-1].category);
    
    printf("\nExpense added successfully!\n");
}

void viewExpenses(struct Expenses *expenses, int count) {
    if(count == 0) {
        printf("\nNo expenses to display.\n");
        return;
    }
    
    printf("%-10s %-20s %-10s\n", "ID", "Description", "Amount");
    printf("=====================================================\n");
    for(int i=0; i<count; i++) {
        printf("%-10d %-20s %-.2f\n", expenses[i].id, expenses[i].description, expenses[i].amount);
    }
}

int main() {
    struct Expenses expenses[100];
    int count = 0;
    
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: 
                addExpense(expenses, &count);
                break;
            case 2:
                viewExpenses(expenses, count);
                break;
            case 3:
                printf("\nThank you for using Expense Tracker!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while(choice != 3);
    
    return 0;
}