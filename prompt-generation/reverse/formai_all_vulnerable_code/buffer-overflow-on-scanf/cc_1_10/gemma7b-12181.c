//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: funny
#include <stdio.h>
#include <string.h>

// Define the expense structure
typedef struct Expense {
    char name[50];
    int amount;
    char category[50];
} Expense;

// Define the expense list
Expense expenses[100];

// Function to add an expense
void addExpense() {
    // Get the expense name, amount, and category
    printf("Enter the expense name: ");
    scanf("%s", expenses[0].name);

    printf("Enter the expense amount: ");
    scanf("%d", &expenses[0].amount);

    printf("Enter the expense category: ");
    scanf("%s", expenses[0].category);

    // Increment the expense index
    int i = 0;
    while (expenses[i].name[0] != '\0') {
        i++;
    }
    expenses[i] = expenses[0];
}

// Function to print the expenses
void printExpenses() {
    // Print the expenses
    printf("Here are your expenses:\n");
    for (int i = 0; expenses[i].name[0] != '\0'; i++) {
        printf("%s - %d - %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

int main() {
    // Add some expenses
    addExpense();
    addExpense();
    addExpense();

    // Print the expenses
    printExpenses();

    return 0;
}