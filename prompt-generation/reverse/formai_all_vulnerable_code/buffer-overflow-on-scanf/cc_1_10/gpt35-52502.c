//FormAI DATASET v1.0 Category: Expense Tracker ; Style: visionary
// Welcome to the Expense Tracker program
// This program helps to manage your personal expenses

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define the structure for expense details
struct expense {
    char category[20];
    float amount;
    char notes[50];
};

// Function to add new expense
void addExpense(struct expense *expenseList, int *count) {
    // Get details for new expense
    printf("Enter the category: ");
    scanf("%s", expenseList[*count].category);
    printf("Enter the amount: ");
    scanf("%f", &expenseList[*count].amount);
    printf("Enter any notes (optional): ");
    fflush(stdin);
    fgets(expenseList[*count].notes, 50, stdin);

    // Increment the count of expenses
    (*count)++;
}

// Function to print all expenses in table format
void printExpenses(struct expense *expenseList, int count) {
    printf("Category\tAmount\tNotes\n");
    for(int i=0; i<count; i++) {
        printf("%s\t\t%.2f\t%s\n", expenseList[i].category, expenseList[i].amount, expenseList[i].notes);
    }
}

// Function to calculate total expenses
float getTotalExpenses(struct expense *expenseList, int count) {
    float total = 0;
    for(int i=0; i<count; i++) {
        total += expenseList[i].amount;
    }
    return total;
}

int main() {
    struct expense expenses[100];
    int expenseCount = 0;

    int option = 0;
    while(option != 4) {
        // Print menu options
        printf("\nExpense Tracker\n");
        printf("1. Add new expense\n");
        printf("2. View all expenses\n");
        printf("3. View total expenses\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        // Process user input based on option
        switch(option) {
            case 1:
                addExpense(expenses, &expenseCount);
                break;
            case 2:
                printExpenses(expenses, expenseCount);
                break;
            case 3:
                printf("Total expenses: $%.2f\n", getTotalExpenses(expenses, expenseCount));
                break;
            case 4:
                printf("Thank you for using Expense Tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid option selected. Please try again.\n");
                break;
        }
    }

    return 0;
}