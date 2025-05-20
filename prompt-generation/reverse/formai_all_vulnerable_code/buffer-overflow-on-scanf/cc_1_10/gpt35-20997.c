//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EXPENSES 100
#define MAX_CHARACTERS 20

struct Expense {
    char name[MAX_CHARACTERS];
    int cost;
    char date[MAX_CHARACTERS];
};

void addExpense(struct Expense expenses[], int *totalExpenses) {
    if (*totalExpenses >= MAX_EXPENSES) {
        printf("You have exceeded your expense limit. Please delete some expenses before adding more.\n");
        return;
    }
    
    struct Expense newExpense;
    printf("Enter name of expense: ");
    scanf("%s", newExpense.name);
    printf("Enter cost of expense: ");
    scanf("%d", &newExpense.cost);
    printf("Enter date of expense (DD/MM/YYYY): ");
    scanf("%s", newExpense.date);
    
    expenses[*totalExpenses] = newExpense;
    (*totalExpenses)++;
    
    printf("Expense added successfully.\n");
}

void deleteExpense(struct Expense expenses[], int *totalExpenses) {
    if (*totalExpenses <= 0) {
        printf("You have no expenses to delete.\n");
        return;
    }
    
    int indexToDelete;
    printf("Enter index of expense to delete (starting from 1): ");
    scanf("%d", &indexToDelete);
    
    if (indexToDelete < 1 || indexToDelete > *totalExpenses) {
        printf("Invalid index. Please enter a number between 1 and %d.\n", *totalExpenses);
        return;
    }
    
    for (int i = indexToDelete - 1; i < *totalExpenses - 1; i++) {
        expenses[i] = expenses[i+1];
    }
    (*totalExpenses)--;
    
    printf("Expense deleted successfully.\n");
}

void printExpenses(struct Expense expenses[], int totalExpenses) {
    printf("      Expense      |    Cost (Credits)   |      Date Bought     \n");
    printf("-------------------|---------------------|-----------------------\n");
    for (int i = 0; i < totalExpenses; i++) {
        printf("%-19s|%21d|%s\n", expenses[i].name, expenses[i].cost, expenses[i].date);
    }
    printf("-------------------|---------------------|-----------------------\n");
}

int main() {
    struct Expense expenses[MAX_EXPENSES];
    int totalExpenses = 0;
    int choice;
    
    printf("Welcome to the Cyber Expense Tracker!\n");
    printf("------------------------------------\n");
    
    while (1) {
        printf("\nPlease select an option:\n");
        printf("1. Add an expense\n");
        printf("2. Delete an expense\n");
        printf("3. View all expenses\n");
        printf("4. Exit\n");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addExpense(expenses, &totalExpenses);
                break;
            case 2:
                deleteExpense(expenses, &totalExpenses);
                break;
            case 3:
                printExpenses(expenses, totalExpenses);
                break;
            case 4:
                printf("Thank you for using the Cyber Expense Tracker!\n");
                return 0;
            default:
                printf("Invalid option. Please choose a number between 1 and 4.\n");
                break;
        }
    }
    
    return 0;
}