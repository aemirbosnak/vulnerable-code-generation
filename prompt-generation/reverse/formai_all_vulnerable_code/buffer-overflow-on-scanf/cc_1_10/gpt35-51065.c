//FormAI DATASET v1.0 Category: Expense Tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char date[11];
    char category[20];
    float amount;
};

void addExpense(int *numExpenses, struct Expense **expenses) {
    char date[11];
    char category[20];
    float amount;
    
    printf("\nEnter date (dd/mm/yyyy): ");
    scanf("%s", date);
    
    printf("\nEnter category: ");
    scanf("%s", category);
    
    printf("\nEnter amount: ");
    scanf("%f", &amount);
    
    // Incrementing number of expenses
    (*numExpenses)++;
    
    // Reallocating memory for expenses
    *expenses = (struct Expense*)realloc(*expenses, (*numExpenses)*sizeof(struct Expense));
    
    // Adding new expense
    strcpy((*expenses)[*numExpenses-1].date, date);
    strcpy((*expenses)[*numExpenses-1].category, category);
    (*expenses)[*numExpenses-1].amount = amount;
    
    printf("\nExpense added successfully.\n");
}

void displayExpenses(int numExpenses, struct Expense *expenses) {
    printf("\n------------------------------\n");
    printf("   Date    |  Category  |  Amount\n");
    printf("------------------------------\n");
    
    for(int i=0; i<numExpenses; i++) {
        printf("%10s | %10s | %7.2f\n", expenses[i].date, expenses[i].category, expenses[i].amount);
    }
    printf("------------------------------\n");
}

void displayTotal(int numExpenses, struct Expense *expenses) {
    float total = 0;
    for(int i=0; i<numExpenses; i++) {
        total += expenses[i].amount;    
    }
    printf("\nTotal expenses: %.2f\n", total);
}

int main() {
    int choice;
    int numExpenses = 0;
    struct Expense *expenses = NULL;
    
    do {
        printf("\nEXPENSE TRACKER MENU\n");
        printf("1. Add Expense\n");
        printf("2. Display All Expenses\n");
        printf("3. Display Total Expenses\n");
        printf("4. Exit\n");
        
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addExpense(&numExpenses, &expenses);
                break;
            case 2:
                if(numExpenses == 0) {
                    printf("\nNo expenses found.\n");
                } else {
                    displayExpenses(numExpenses, expenses);
                }
                break;
            case 3:
                if(numExpenses == 0) {
                    printf("\nNo expenses found.\n");
                } else {
                    displayTotal(numExpenses, expenses);
                }
                break;
            case 4:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
        
    } while(choice != 4);
    
    return 0;
}