//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    char category[50];
    float amount;
} Expense;

int main() {
    FILE *fp;
    char fileName[50];
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    float totalExpenses = 0.0;
    int i;

    // Get filename from user
    printf("Enter filename: ");
    scanf("%s", fileName);

    // Open file
    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Read expenses from file
    while (fscanf(fp, "%s %s %f", expenses[numExpenses].name, expenses[numExpenses].category, &expenses[numExpenses].amount)!= EOF) {
        numExpenses++;
        if (numExpenses == MAX_EXPENSES) {
            printf("Error: Maximum number of expenses (%d) reached.\n", MAX_EXPENSES);
            fclose(fp);
            return 1;
        }
    }

    // Calculate total expenses
    for (i = 0; i < numExpenses; i++) {
        totalExpenses += expenses[i].amount;
    }

    // Print expenses and total
    printf("\nExpenses:\n");
    for (i = 0; i < numExpenses; i++) {
        printf("%s - %s - $%.2f\n", expenses[i].name, expenses[i].category, expenses[i].amount);
    }
    printf("\nTotal expenses: $%.2f\n", totalExpenses);

    // Close file
    fclose(fp);

    return 0;
}