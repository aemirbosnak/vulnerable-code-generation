//FormAI DATASET v1.0 Category: Expense Tracker ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// struct to store expense details
struct Expense {
    char category[50];
    float amount;
};

// function to add an expense
void addExpense(struct Expense expenses[], int* num_expenses) {
    char category[50];
    float amount;
    printf("Enter expense category: ");
    scanf("%s", category);
    printf("Enter expense amount: ");
    scanf("%f", &amount);

    strcpy(expenses[*num_expenses].category, category);
    expenses[*num_expenses].amount = amount;
    (*num_expenses)++;
    printf("Expense added successfully!\n");
}

// function to display all expenses
void displayExpenses(struct Expense expenses[], int num_expenses) {
    if(num_expenses == 0) {
        printf("No expenses to display!\n");
        return;
    }
    printf("%-20s%-10s\n", "Category", "Amount");
    for(int i=0; i<num_expenses; i++) {
        printf("%-20s$%-9.2f\n", expenses[i].category, expenses[i].amount);
    }
}

// function to display expenses by category
void displayExpensesByCategory(struct Expense expenses[], int num_expenses) {
    if(num_expenses == 0) {
        printf("No expenses to display!\n");
        return;
    }

    int count = 0;
    char category[50];
    printf("Enter category to display: ");
    scanf("%s", category);

    printf("%-20s%-10s\n", "Category", "Amount");
    for(int i=0; i<num_expenses; i++) {
        if(strcmp(expenses[i].category, category) == 0) {
            printf("%-20s$%-9.2f\n", expenses[i].category, expenses[i].amount);
            count++;
        }
    }
    if(count == 0) {
        printf("No expenses found under the given category!\n");
    }
}

int main() {
    struct Expense expenses[100];
    int num_expenses = 0;
    int choice;

    printf("Welcome to the Expense Tracker!\n");
    printf("------------------------------\n");

    while(1) {
        printf("\n1. Add an expense\n");
        printf("2. Display all expenses\n");
        printf("3. Display expenses by category\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addExpense(expenses, &num_expenses);
                break;
            case 2:
                displayExpenses(expenses, num_expenses);
                break;
            case 3:
                displayExpensesByCategory(expenses, num_expenses);
                break;
            case 4:
                printf("\nThank you for using Expense Tracker!\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}