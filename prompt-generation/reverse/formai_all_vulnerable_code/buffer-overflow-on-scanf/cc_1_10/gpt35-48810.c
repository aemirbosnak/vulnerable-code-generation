//FormAI DATASET v1.0 Category: Expense Tracker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EXPENSES 50

struct Expense {
    char type[30];
    float amount;
    char date[20];
};

int main() {
    struct Expense expenses[MAX_EXPENSES]; // array of expense structs
    int numExpenses = 0; // current number of expenses in array
    
    while(1) { // continuously loop until user exits
        printf("\nWhat would you like to do?\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Exit\n");
        int option;
        scanf("%d", &option);
        
        if(option == 1) { // add new expense
            printf("\nEnter Expense Type: ");
            scanf("%s", expenses[numExpenses].type);
            printf("Enter Expense Amount: ");
            scanf("%f", &expenses[numExpenses].amount);
            printf("Enter Expense Date (dd/mm/yyyy): ");
            scanf("%s", expenses[numExpenses].date);
            numExpenses++; // increment numExpenses after adding expense
        }
        else if(option == 2) { // display all expenses
            printf("\nEXPENSES:\n\n");
            float totalExpense = 0;
            for(int i = 0; i < numExpenses; i++) {
                printf("%d) Type: %s | Amount: %.2f | Date: %s\n", 
                       i+1, expenses[i].type, expenses[i].amount, expenses[i].date);
                totalExpense += expenses[i].amount; // keep track of total expenses
            }
            printf("\nTotal Expenses: %.2f\n", totalExpense);
        }
        else if(option == 3) { // exit program
            printf("\nExiting Expense Tracker.\n");
            break;
        }
        else { // invalid input
            printf("\nInvalid Option.\n");
        }
    }
    return 0;
}