//FormAI DATASET v1.0 Category: Expense Tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EXPENSES 100
#define MAX_DESCRIPTION_LENGTH 50

/* Define expense data structure */
typedef struct {
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
} Expense;

/* Function prototypes */
int getMenuOption();
void addExpense(Expense expenses[MAX_EXPENSES], int *numExpenses);
void displayExpenses(Expense expenses[MAX_EXPENSES], int numExpenses);
void saveExpenses(Expense expenses[MAX_EXPENSES], int numExpenses);

int main() {
    /* Declare variables */
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    int menuOption;

    /* Main program loop */
    do {
        /* Display menu */
        menuOption = getMenuOption();
        switch (menuOption) {
            case 1:
                addExpense(expenses, &numExpenses);
                break;
            case 2:
                displayExpenses(expenses, numExpenses);
                break;
            case 3:
                saveExpenses(expenses, numExpenses);
                break;
            case 4:
                /* Do nothing, will exit below */
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (menuOption != 4);

    return 0;
}

int getMenuOption() {
    /* Declare variables */
    int option;

    /* Display menu options */
    printf("\nExpense Tracker\n");
    printf("----------------\n");
    printf("1. Add Expense\n");
    printf("2. Display Expenses\n");
    printf("3. Save Expenses\n");
    printf("4. Exit\n");
    printf("Enter option: ");

    /* Get user input */
    scanf("%d", &option);
    return option;
}

void addExpense(Expense expenses[MAX_EXPENSES], int *numExpenses) {
    /* Declare variables */
    Expense expense;

    /* Get user input */
    printf("\nEnter expense description: ");
    scanf("%s", expense.description); /* Note: no spaces allowed in description */
    printf("Enter expense amount: $");
    scanf("%f", &expense.amount);

    /* Add expense to array */
    expenses[*numExpenses] = expense;
    (*numExpenses)++;

    printf("\nExpense added.\n");
}

void displayExpenses(Expense expenses[MAX_EXPENSES], int numExpenses) {
    /* Declare variables */
    int i;

    /* Display expenses */
    printf("\nExpenses\n");
    printf("--------\n");
    for (i = 0; i < numExpenses; i++) {
        printf("%s: $%.2f\n", expenses[i].description, expenses[i].amount);
    }
}

void saveExpenses(Expense expenses[MAX_EXPENSES], int numExpenses) {
    /* Declare variables */
    FILE *fp;
    int i;

    /* Get file name from user */
    char fileName[MAX_DESCRIPTION_LENGTH];
    printf("\nEnter file name to save expenses: ");
    scanf("%s", fileName);

    /* Open file for writing */
    fp = fopen(fileName, "w");

    /* Write expenses to file */
    for (i = 0; i < numExpenses; i++) {
        fprintf(fp, "%s,%.2f\n", expenses[i].description, expenses[i].amount);
    }

    /* Close file */
    fclose(fp);

    printf("\nExpenses saved to file: %s.\n", fileName);
}