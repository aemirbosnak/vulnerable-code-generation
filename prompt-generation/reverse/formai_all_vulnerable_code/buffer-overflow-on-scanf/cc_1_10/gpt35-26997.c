//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 100

struct Expense {
    int id;
    char category[20];
    float amount;
};

struct Expense expenses[MAX_EXPENSES];
int numExpenses = 0;

float getTotalExpenses() {
    float total = 0.0;
    for(int i=0;i<numExpenses;i++) {
        total += expenses[i].amount;
    }
    return total;
}

void printExpenses() {
    printf("Expense List:\n");
    printf("-----------------------------------------------------\n");
    printf("ID    | CATEGORY      | AMOUNT\n");
    printf("-----------------------------------------------------\n");
    for(int i=0;i<numExpenses;i++) {
        printf("%-5d | %-13s | $%.2f\n", expenses[i].id, expenses[i].category, expenses[i].amount);
    }
}

void addExpense(int id, char category[], float amount) {
    if(numExpenses == MAX_EXPENSES) {
        printf("\nUnable to Add Expense. Expense List is Full.\n");
        return;
    }
    
    struct Expense expense;
    expense.id = id;
    strcpy(expense.category, category);
    expense.amount = amount;
    
    expenses[numExpenses] = expense;
    numExpenses++;
    
    printf("\nExpense Added Successfully.\n");
}

void deleteExpense(int id) {
    int index = 0;
    for(int i=0;i<numExpenses;i++) {
        if(expenses[i].id == id) {
            index = i;
            break;
        }
    }
    for(int j=index;j<numExpenses-1;j++) {
        expenses[j] = expenses[j+1];
    }
    numExpenses--;
    printf("\nExpense Deleted Successfully.\n");
}

int main() {
    int choice, expenseId;
    char expenseCategory[20];
    float expenseAmount;
    
    while(1) {
        printf("\n-------------- Expense Tracker ---------------\n");
        printf("1. Add Expense\n");
        printf("2. Delete Expense\n");
        printf("3. Print Expenses\n");
        printf("4. Get Total Expenses\n");
        printf("5. Exit\n");
        printf("-----------------------------------------------\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nEnter Expense ID: ");
                scanf("%d", &expenseId);
                printf("Enter Expense Category: ");
                scanf("%s", expenseCategory);
                printf("Enter Expense Amount: ");
                scanf("%f", &expenseAmount);
                addExpense(expenseId, expenseCategory, expenseAmount);
                break;
            case 2:
                printf("\nEnter Expense ID to Delete: ");
                scanf("%d", &expenseId);
                deleteExpense(expenseId);
                break;
            case 3:
                printExpenses();
                break;
            case 4:
                printf("\nTotal Expenses: $%.2f\n", getTotalExpenses());
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("\nInvalid Choice. Please try again.\n");
        }
    }
    return 0;
}