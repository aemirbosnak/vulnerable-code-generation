//FormAI DATASET v1.0 Category: Expense Tracker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESCRIPTION_LENGTH 50

typedef struct {
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
} Expense;

void addExpense(Expense expenses[], int* numExpenses);
void printExpenses(Expense expenses[], int numExpenses);
float getTotalExpenses(Expense expenses[], int numExpenses);

int main() {
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    char choice;

    do {
        printf("\nWelcome to the Expense Tracker!\n");
        printf("1. Add an expense\n");
        printf("2. Print all expenses\n");
        printf("3. Print total expenses\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                addExpense(expenses, &numExpenses);
                break;
            case '2':
                printExpenses(expenses, numExpenses);
                break;
            case '3':
                printf("\nTotal expenses: $%.2f\n", getTotalExpenses(expenses, numExpenses));
                break;
            case '4':
                printf("\nGoodbye!\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while(1);

    return 0;
}

void addExpense(Expense expenses[], int* numExpenses) {
    if(*numExpenses >= MAX_EXPENSES) {
        printf("\nCannot add any more expenses. Maximum number of expenses reached.\n");
        return;
    }

    printf("\nEnter the description of the expense (up to %d characters): ", MAX_DESCRIPTION_LENGTH);
    scanf(" %[^\n]s", expenses[*numExpenses].description);

    printf("Enter the amount of the expense: $");
    scanf(" %f", &expenses[*numExpenses].amount);

    (*numExpenses)++;

    printf("\nExpense added successfully.\n");
}

void printExpenses(Expense expenses[], int numExpenses) {
    if(numExpenses == 0) {
        printf("\nNo expenses added yet.\n");
        return;
    }

    printf("\nList of expenses:\n\n");

    for(int i = 0; i < numExpenses; i++) {
        printf("%d. %-50s $%.2f\n", i+1, expenses[i].description, expenses[i].amount);
    }
}

float getTotalExpenses(Expense expenses[], int numExpenses) {
    float total = 0;

    for(int i = 0; i < numExpenses; i++) {
        total += expenses[i].amount;
    }

    return total;
}