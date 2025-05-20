//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    char name[50];
    char category[50];
    int amount;
    int date;
} Expense;

void addExpense(Expense *expenses, int numExpenses, char *name, char *category, int amount) {
    if (numExpenses == 100) {
        printf("Cannot add more than 100 expenses.\n");
        return;
    }
    strcpy(expenses[numExpenses].name, name);
    strcpy(expenses[numExpenses].category, category);
    expenses[numExpenses].amount = amount;
    time_t now = time(NULL);
    expenses[numExpenses].date = now;
    numExpenses++;
}

void printExpenses(Expense *expenses, int numExpenses) {
    printf("\nExpenses:\n");
    printf("------------------\n");
    printf("Name | Category | Amount | Date\n");
    printf("------------------\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%-20s | %-20s | %10d | %s\n", expenses[i].name, expenses[i].category, expenses[i].amount, ctime(&expenses[i].date));
    }
}

void main() {
    Expense expenses[100];
    int numExpenses = 0;
    char name[50];
    char category[50];
    int amount;
    char choice;
    do {
        printf("\nEnter 1 to add an expense or any other key to exit:\n");
        scanf("%c", &choice);
        if (choice == '1') {
            printf("Enter expense name:\n");
            scanf("%s", name);
            printf("Enter expense category:\n");
            scanf("%s", category);
            printf("Enter expense amount:\n");
            scanf("%d", &amount);
            addExpense(expenses, numExpenses, name, category, amount);
        } else if (choice!= '\n') {
            printf("Invalid input. Please try again.\n");
        }
    } while (choice!= '\n');
    printExpenses(expenses, numExpenses);
}