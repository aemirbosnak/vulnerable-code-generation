//FormAI DATASET v1.0 Category: Expense Tracker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#define MAX_EXPENSES 1000

/* Define the structure of an expense */
typedef struct {
    char date[11];
    char category[31];
    float amount;
} Expense;

/* Function prototypes */
void recordExpense(Expense expenses[], int *numExpenses);
void printExpenses(Expense expenses[], int numExpenses);

int main() {
    /* Initialize variables */
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    
    /* User Interface */
    printf("Welcome to the Expense Tracker\n\n");
    printf("Please select an option:\n");
    printf("1. Record an expense\n");
    printf("2. Print all recorded expenses\n");
    printf("3. Exit\n\n");
    
    /* Loop until user exits */
    int option;
    do {
        printf("Option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                recordExpense(expenses, &numExpenses);
                break;
            case 2:
                printExpenses(expenses, numExpenses);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    } while (option != 3);
    
    return 0;
}

/* Function to record an expense */
void recordExpense(Expense expenses[], int *numExpenses) {
    /* Check if limit has been reached */
    if (*numExpenses >= MAX_EXPENSES) {
        printf("Maximum number of expenses (%d) reached.\n", MAX_EXPENSES);
        return;
    }
    
    /* Prompt user for input */
    printf("Date (DD/MM/YYYY): ");
    scanf("%s", expenses[*numExpenses].date);
    printf("Category: ");
    scanf("%s", expenses[*numExpenses].category);
    printf("Amount: ");
    scanf("%f", &expenses[*numExpenses].amount);
    
    /* Increment number of expenses */
    (*numExpenses)++;
    
    /* Confirmation message */
    printf("Expense recorded successfully!\n\n");
}

/* Function to print all recorded expenses */
void printExpenses(Expense expenses[], int numExpenses) {
    /* Check if there are any expenses recorded */
    if (numExpenses == 0) {
        printf("No expenses recorded.\n\n");
        return;
    }
    
    /* Print headers */
    printf("Date\t\tCategory\tAmount\n");
    
    /* Loop through expenses and print each one */
    for (int i = 0; i < numExpenses; i++) {
        printf("%s\t%s\t$%.2f\n", expenses[i].date, expenses[i].category, expenses[i].amount);
    }
    
    printf("\n");
}