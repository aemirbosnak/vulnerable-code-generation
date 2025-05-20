//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Linus Torvalds
/**
 * Linux-inspired expense tracker in C
 *
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

/* Define a structure to hold individual expense entries */
struct ExpenseEntry {
    char category[20];
    float amount;
};

/* Initialize an array to hold all of the expense entries */
struct ExpenseEntry expenseEntries[MAX_ENTRIES];
int numEntries = 0;

/* Define functions to handle adding, removing, and listing expense entries */
void addExpense(char *category, float amount) {
    if (numEntries < MAX_ENTRIES) {
        struct ExpenseEntry newEntry;
        strcpy(newEntry.category, category);
        newEntry.amount = amount;
        expenseEntries[numEntries++] = newEntry;
        printf("Expense added successfully!\n");
    } else {
        printf("Error: maximum number of entries reached.\n");
    }
}

void removeExpense(int index) {
    if (index >= 0 && index < numEntries) {
        for (int i = index; i < numEntries - 1; i++) {
            expenseEntries[i] = expenseEntries[i + 1];
        }
        numEntries--;
        printf("Expense removed successfully!\n");
    } else {
        printf("Error: invalid index.\n");
    }
}

void listExpenses() {
    if (numEntries == 0) {
        printf("No expenses to show.\n");
    } else {
        printf("Category\tAmount\n");
        printf("==============================\n");
        for (int i = 0; i < numEntries; i++) {
            printf("%-20s\t%.2f\n", expenseEntries[i].category, expenseEntries[i].amount);
        }
    }
}

/* Define a function to display a command prompt and receive user input */
void displayPrompt() {
    char command[10], category[20];
    float amount;
    int index;
    printf("> ");
    scanf("%s", command);
    switch (command[0]) {
        case 'a':
            scanf("%s %f", category, &amount);
            addExpense(category, amount);
            break;
        case 'r':
            scanf("%d", &index);
            removeExpense(index);
            break;
        case 'l':
            listExpenses();
            break;
        case 'q':
            printf("Exiting expense tracker...\n");
            exit(0);
        default:
            printf("Error: invalid command.\n");
            break;
    }
}

/* Define the main function to repeatedly display the command prompt */
int main() {
    printf("Welcome to the Linux-inspired Expense Tracker!\n");
    while (1) {
        displayPrompt();
    }
    return 0;
}