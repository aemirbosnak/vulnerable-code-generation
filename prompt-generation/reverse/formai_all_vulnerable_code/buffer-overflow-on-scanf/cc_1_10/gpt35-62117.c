//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char category[20];
    float amount;
};

void addExpense(struct expense expenses[], int *numExpenses);
void viewExpenses(struct expense expenses[], int numExpenses);
void saveExpenses(struct expense expenses[], int numExpenses);

int main() {
    struct expense expenses[100];
    int numExpenses = 0;
    char input[20];

    printf("===================================\n");
    printf("CYBERPUNK EXPENSE TRACKER\n");
    printf("===================================\n");

    // Load saved expenses
    FILE *fptr;
    if ((fptr = fopen("expenses.txt", "r")) != NULL) {
        while (fscanf(fptr, "%s %f", expenses[numExpenses].category, &expenses[numExpenses].amount) == 2) {
            numExpenses++;
        }
        fclose(fptr);
        printf("%d expenses loaded from file.\n", numExpenses);
    }

    // Main program loop
    while (1) {
        printf("\nEnter a command (add, view, save, exit): ");
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            addExpense(expenses, &numExpenses);
        } else if (strcmp(input, "view") == 0) {
            viewExpenses(expenses, numExpenses);
        } else if (strcmp(input, "save") == 0) {
            saveExpenses(expenses, numExpenses);
        } else if (strcmp(input, "exit") == 0) {
            printf("Exiting program.\n");
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}

void addExpense(struct expense expenses[], int *numExpenses) {
    // Get user input for a new expense
    printf("\nEnter category (max 20 chars): ");
    scanf("%s", expenses[*numExpenses].category);
    printf("Enter amount: ");
    scanf("%f", &expenses[*numExpenses].amount);

    (*numExpenses)++;
    printf("Expense added successfully.\n");
}

void viewExpenses(struct expense expenses[], int numExpenses) {
    // Print a table of all expenses
    printf("\n===================================\n");
    printf("           EXPENSES TABLE           \n");
    printf("===================================\n");
    printf("  CATEGORY     |    AMOUNT (BTC)    \n");
    printf("-----------------------------------\n");
    for (int i=0; i<numExpenses; i++) {
        printf("  %-13s|      %8.2f       \n", expenses[i].category, expenses[i].amount);
    }
    printf("===================================\n");
}

void saveExpenses(struct expense expenses[], int numExpenses) {
    // Save expenses to file
    FILE *fptr;
    if ((fptr = fopen("expenses.txt", "w")) == NULL) {
        printf("Failed to save expenses to file.\n");
        return;
    }

    for (int i=0; i<numExpenses; i++) {
        fprintf(fptr, "%s %.2f\n", expenses[i].category, expenses[i].amount);
    }

    fclose(fptr);
    printf("Expenses saved successfully.\n");
}