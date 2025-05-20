//FormAI DATASET v1.0 Category: Expense Tracker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 10 // max number of expenses that can be tracked
#define MAX_NAME_SIZE 100 // max size of name of expense category
#define MAX_TRANSACTION_DESCRIPTION 200 // max size of transaction description
#define MAX_TRANSACTIONS 50 // max number of transactions that can be tracked per expense category

// structure to store information on each expense transaction
struct Transaction {
    float amount;
    char description[MAX_TRANSACTION_DESCRIPTION];
};

// structure to store information on each expense category
struct Expense {
    char name[MAX_NAME_SIZE];
    float budget;
    float totalExpenses;
    int numTransactions;
    struct Transaction transactions[MAX_TRANSACTIONS];
};

// function declarations
void addExpense(struct Expense expenses[], int* numExpenses);
void addTransaction(struct Expense expenses[], int numExpenses);
void displayExpenses(struct Expense expenses[], int numExpenses);
void displayTransactions(struct Expense expenses[], int numExpenses);

int main() {
    int numExpenses = 0;
    struct Expense expenses[MAX_EXPENSES];
    char choice;

    while(1) {
        printf("Welcome to the Expense Tracker program!\n");
        printf("What would you like to do today?\n");
        printf("1) Add a new expense category\n");
        printf("2) Add a transaction to an existing expense category\n");
        printf("3) Display all expenses and their details\n");
        printf("4) Display details of all transactions in a particular expense category\n");
        printf("5) Exit the program\n");
        printf("\nEnter your choice: ");
        scanf(" %c", &choice);
        printf("\n");

        switch(choice) {
            case '1':
                addExpense(expenses, &numExpenses);
                break;
            case '2':
                addTransaction(expenses, numExpenses);
                break;
            case '3':
                displayExpenses(expenses, numExpenses);
                break;
            case '4':
                displayTransactions(expenses, numExpenses);
                break;
            case '5':
                printf("Thank you for using the Expense Tracker program!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }

        printf("\n");
    }
}

// function to add a new expense category
void addExpense(struct Expense expenses[], int* numExpenses) {
    if(*numExpenses >= MAX_EXPENSES) {
        printf("Sorry, you have reached the maximum number of expenses that can be tracked.\n");
        return;
    }

    struct Expense newExpense;
    printf("Enter the name of the new expense: ");
    scanf(" %[^\n]", newExpense.name);
    printf("Enter the budget for this expense category: $");
    scanf("%f", &newExpense.budget);
    newExpense.totalExpenses = 0.0;
    newExpense.numTransactions = 0;

    expenses[*numExpenses] = newExpense;
    (*numExpenses)++;

    printf("New expense category added successfully!\n");
}

// function to add a transaction to an existing expense category
void addTransaction(struct Expense expenses[], int numExpenses) {
    if(numExpenses == 0) {
        printf("There are currently no expense categories to add transactions to. Please add an expense category first.\n");
        return;
    }

    char expenseName[MAX_NAME_SIZE];
    printf("Enter the name of the expense you want to add a transaction to: ");
    scanf(" %[^\n]", expenseName);

    int i;
    for(i = 0; i < numExpenses; i++) {
        if(strcmp(expenses[i].name, expenseName) == 0) {
            struct Transaction newTransaction;
            printf("Enter the amount of the transaction: $");
            scanf("%f", &newTransaction.amount);
            printf("Enter a description of the transaction: ");
            scanf(" %[^\n]", newTransaction.description);

            expenses[i].totalExpenses += newTransaction.amount;
            expenses[i].transactions[expenses[i].numTransactions] = newTransaction;
            expenses[i].numTransactions++;

            printf("Transaction added successfully to expense category: %s\n", expenses[i].name);
            return;
        }
    }

    printf("Sorry, expense category not found. Please try again.\n");
}

// function to display all expenses and their details
void displayExpenses(struct Expense expenses[], int numExpenses) {
    if(numExpenses == 0) {
        printf("There are currently no expense categories to display.\n");
        return;
    }

    int i;
    for(i = 0; i < numExpenses; i++) {
        struct Expense currentExpense = expenses[i];
        printf("\nExpense Category: %s\n", currentExpense.name);
        printf("Budget: $%.2f\n", currentExpense.budget);
        printf("Total Expenses: $%.2f\n\n", currentExpense.totalExpenses);
    }
}

// function to display details of all transactions in a particular expense category
void displayTransactions(struct Expense expenses[], int numExpenses) {
    if(numExpenses == 0) {
        printf("There are currently no expense categories to display transactions for.\n");
        return;
    }

    char expenseName[MAX_NAME_SIZE];
    printf("Enter the name of the expense you want to display transactions for: ");
    scanf(" %[^\n]", expenseName);

    int i;
    for(i = 0; i < numExpenses; i++) {
        if(strcmp(expenses[i].name, expenseName) == 0) {
            struct Expense currentExpense = expenses[i];
            printf("\nTransactions for Expense Category: %s\n", currentExpense.name);
            if(currentExpense.numTransactions == 0) {
                printf("There are currently no transactions for this expense category.\n\n");
                return;
            }

            int j;
            for(j = 0; j < currentExpense.numTransactions; j++) {
                struct Transaction currentTransaction = currentExpense.transactions[j];
                printf("Transaction #%d: $%.2f - %s\n", j+1, currentTransaction.amount, currentTransaction.description);
            }

            printf("\n");
            return;
        }
    }

    printf("Sorry, expense category not found. Please try again.\n");
}