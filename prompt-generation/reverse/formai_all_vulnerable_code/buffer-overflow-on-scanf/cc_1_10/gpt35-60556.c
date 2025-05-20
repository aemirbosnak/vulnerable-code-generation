//FormAI DATASET v1.0 Category: Expense Tracker ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// declaring the function prototypes
void addExpense();
void displayExpenses();
void searchExpense();

// defining the structure to hold expenses
struct Expense {
    char category[20];
    float cost;
};

// declaring global variables
int count = 0;
struct Expense expenses[100];

int main() {
    int choice;

    while(1) {
        printf("\nWelcome to Expense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Search Expense\n");
        printf("4. Exit\n");

        printf("\nPlease enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);

        switch(choice) {
            case 1: addExpense();
                    break;
            case 2: displayExpenses();
                    break;
            case 3: searchExpense();
                    break;
            case 4: printf("\nThank You for using Expense Tracker!\n");
                    exit(0);
            default: printf("\nInvalid choice! Please enter again.\n");
                     break;
        }
    }

    return 0;
}

// function to add a new expense
void addExpense() {
    printf("\nEnter Category of Expense: ");
    fgets(expenses[count].category, 20, stdin);

    printf("\nEnter Cost of Expense: ");
    scanf("%f", &expenses[count].cost);
    fflush(stdin);

    printf("\nExpense Added Successfully!\n");

    count++;
}

// function to display all the expenses
void displayExpenses() {
    if(count == 0) {
        printf("\nNo expenses added yet!\n");
        return;
    }

    float total = 0;
    printf("\nCategory\tCost\n");
    printf("--------------------------------\n");
    for(int i=0; i<count; i++) {
        printf("%s\t%.2f\n", expenses[i].category, expenses[i].cost);
        total += expenses[i].cost;
    }
    printf("\nTotal Expenses: %.2f\n", total);
}

// function to search for a specific expense
void searchExpense() {
    if(count == 0) {
        printf("\nNo expenses added yet!\n");
        return;
    }

    char query[20];
    printf("\nEnter the Category to Search: ");
    fgets(query, 20, stdin);

    int found = 0;
    printf("\nSearch Results:\n");
    printf("\nCategory\tCost\n");
    printf("--------------------------------\n");
    for(int i=0; i<count; i++) {
        if(strstr(expenses[i].category, query) != NULL) {
            printf("%s\t%.2f\n", expenses[i].category, expenses[i].cost);
            found = 1;
        }
    }

    if(found == 0) {
        printf("\nNo expense found with the given category!\n");
    }
}