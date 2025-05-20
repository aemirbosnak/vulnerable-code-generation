//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float price;
} Expense;

int main() {
    Expense expenses[10];
    int numExpenses = 0;
    char line[100];
    int expenseCount = 0;
    int totalExpense = 0.0;

    // Input expenses
    printf("Enter expenses (Enter 0 to stop): ");
    while (fgets(line, sizeof(line), stdin)!= NULL) {
        if (line[0] == '0')
            break;

        // Split the input line into name and price
        char *name = strtok(line, " ");
        char *price = strtok(NULL, " ");

        // Check if the name and price are valid
        if (name == NULL || price == NULL) {
            printf("Invalid input format. Please enter name and price separated by a space.\n");
            continue;
        }

        // Check if the expense already exists
        for (int i = 0; i < numExpenses; i++) {
            if (strcmp(expenses[i].name, name) == 0) {
                printf("Expense already exists.\n");
                continue;
            }
        }

        // Add the expense to the list
        strcpy(expenses[numExpenses].name, name);
        expenses[numExpenses].price = atof(price);
        numExpenses++;

        // Calculate total expense
        totalExpense += expenses[numExpenses].price;
    }

    // Display the expenses and total expense
    printf("Expenses: ");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s - $%.2f\n", expenses[i].name, expenses[i].price);
    }
    printf("Total expense: $%.2f\n", totalExpense);

    return 0;
}