//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    char date[11]; // Format: YYYY-MM-DD
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("Oh, what light through yonder window breaks! The expense list is full!\n");
        return;
    }
    
    Expense newExpense;
    printf("Enter the name of the expense, dear Juliet: ");
    scanf("%s", newExpense.name);
    
    printf("How much dost thou spend, brave Romeo? ");
    scanf("%f", &newExpense.amount);
    
    printf("On what day didst thou part with thy coins? (YYYY-MM-DD): ");
    scanf("%s", newExpense.date);
    
    tracker->expenses[tracker->count] = newExpense;
    tracker->count++;
    printf("Thou hast added an expense for \"%s\" costing %.2f ducats on the fateful day of %s.\n", 
            newExpense.name, newExpense.amount, newExpense.date);
}

void viewExpenses(const ExpenseTracker *tracker) {
    printf("A pox upon me for counting these expenses, yet I shall list them for thee:\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Expense %d: %s - %.2f ducats on %s\n", 
                i + 1, tracker->expenses[i].name, tracker->expenses[i].amount, tracker->expenses[i].date);
    }
}

float calculateTotalExpenses(const ExpenseTracker *tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    return total;
}

void displayMenu() {
    printf("\nWhat light doth break upon our eyes? Choose yon option:\n");
    printf("1. Add an expense\n");
    printf("2. View all expenses\n");
    printf("3. Calculate total expenses\n");
    printf("4. Exit this tragic tale\n");
}

int main() {
    ExpenseTracker tracker = { .count = 0 };
    int choice;
    
    while (1) {
        displayMenu();
        printf("Thou must declare thy choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                viewExpenses(&tracker);
                break;
            case 3:
                printf("The sum of all expenses is %.2f ducats, my dear sense of frugality.\n", 
                       calculateTotalExpenses(&tracker));
                break;
            case 4:
                printf("Farewell, sweet memories of the expenses past!\n");
                exit(0);
            default:
                printf("Alas! Thy choice is not known in fair Verona.\n");
                break;
        }
    }
    
    return 0;
}