//FormAI DATASET v1.0 Category: Expense Tracker ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold expense details
typedef struct Expense {
    char name[50];
    float cost;
} Expense;

int main() {
    printf("Welcome to the Expense Tracker 9000!\n\n"); // Intro message
    printf("What's your name?: ");
    char username[50];
    scanf("%s", username);
    printf("\nHi %s! Let's start tracking your expenses!\n", username);

    int numExpenses; // Number of expenses user wants to track
    printf("\nHow many expenses do you want to track?: ");
    scanf("%d", &numExpenses);

    Expense expenses[numExpenses]; // Array to hold the expenses

    // Loop through and prompt user to input expense details
    for(int i=0; i<numExpenses; i++) {
        printf("\nEnter name of expense #%d: ", i+1);
        scanf("%s", expenses[i].name);
        printf("Enter cost of expense #%d: ", i+1);
        scanf("%f", &expenses[i].cost);
    }

    printf("\nGreat! Here are your expenses:\n");

    // Loop through and print out all expenses
    for(int i=0; i<numExpenses; i++) {
        printf("%d. %s: $%.2f\n",i+1, expenses[i].name, expenses[i].cost);
    }

    float totalCost = 0; // Total cost variable

    // Loop through and add up all expenses
    for(int i=0; i<numExpenses; i++) {
        totalCost += expenses[i].cost;
    }

    printf("\nYour total expenses come out to be $%.2f\n", totalCost);

    char decision[10]; // Variable to hold user's decision

    // Prompt user to see if they want to continue with the program
    printf("\nDo you want to continue tracking expenses? (y/n): ");
    scanf("%s", decision);

    while(strcmp(decision, "y")==0) { // While user decides to continue

        printf("\nAlright, let's track another expense!\n");

        // Increase size of array by 1 to hold new expense
        numExpenses++;
        Expense newExpense[numExpenses];
        
        // Transfer old expenses into new array
        for(int i=0; i<numExpenses-1; i++) {
            strcpy(newExpense[i].name, expenses[i].name);
            newExpense[i].cost = expenses[i].cost;
        }

        // Prompt user to input new expense details
        printf("\nEnter name of new expense: ");
        scanf("%s", newExpense[numExpenses-1].name);
        printf("Enter cost of new expense: ");
        scanf("%f", &newExpense[numExpenses-1].cost);

        printf("\nHere are all your expenses:\n");

        // Loop through and print out all expenses
        for(int i=0; i<numExpenses; i++) {
            printf("%d. %s: $%.2f\n",i+1, newExpense[i].name, newExpense[i].cost);
        }

        totalCost = 0; // Reset total cost variable

        // Loop through and add up all expenses
        for(int i=0; i<numExpenses; i++) {
            totalCost += newExpense[i].cost;
        }

        printf("\nYour total expenses come out to be $%.2f\n", totalCost);

        // Prompt user to see if they want to continue with the program
        printf("\nDo you want to continue tracking expenses? (y/n): ");
        scanf("%s", decision);

        // If user decided to quit, transfer new expenses into old array
        if(strcmp(decision, "n")==0) {
            numExpenses--;
            for(int i=0; i<numExpenses; i++) {
                strcpy(expenses[i].name, newExpense[i].name);
                expenses[i].cost = newExpense[i].cost;
            }
        }
    }

    printf("\nThank you for using the Expense Tracker 9000! Have an expense-free day!\n");

    return 0; // End of program
}