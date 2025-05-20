//FormAI DATASET v1.0 Category: Expense Tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Expense
struct Expense {
    char name[100];
    float amount;
    char category[50];
};

// Function to add expense
void addExpense(struct Expense expense[], int *count) {
    printf("Enter the name of the expense: ");
    scanf("%s", expense[*count].name);
    printf("Enter the amount of the expense: ");
    scanf("%f", &expense[*count].amount);
    printf("Enter the category of the expense: ");
    scanf("%s", expense[*count].category);
    (*count)++;
    printf("\nExpense added successfully!\n");
}

// Function to display expenses
void displayExpenses(struct Expense expense[], int count) {
    printf("\n%-20s%-20s%s\n", "Expense Name", "Expense Amount", "Expense Category");
    for(int i=0; i<count; i++) {
        printf("%-20s%-20.2f%s\n", expense[i].name, expense[i].amount, expense[i].category);
    }
}

// Function to calculate expense stats
void calculateStats(struct Expense expense[], int count) {
    float totalAmount = 0, maxAmount = 0;
    char maxCategory[50];

    for(int i=0; i<count; i++) {
        totalAmount += expense[i].amount;
        if(expense[i].amount > maxAmount) {
            maxAmount = expense[i].amount;
            strcpy(maxCategory, expense[i].category);
        }
    }

    printf("\nTotal Expense Amount: %.2f\n", totalAmount);
    printf("Maximum Expense: %.2f in category %s\n", maxAmount, maxCategory);
}

int main() {
    int choice, count = 0;
    struct Expense expense[100];

    printf("------ Expense Tracker ------\n");
    while(1) {
        printf("\nEnter your choice:\n1. Add Expense\n2. Display Expenses\n3. Calculate Expense Stats\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addExpense(expense, &count); break;
            case 2: displayExpenses(expense, count); break;
            case 3: calculateStats(expense, count); break;
            case 4: printf("\nThank you for using Expense Tracker!\n"); exit(1);
        }
    }
    return 0;
}