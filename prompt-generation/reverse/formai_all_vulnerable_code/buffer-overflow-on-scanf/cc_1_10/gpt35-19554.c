//FormAI DATASET v1.0 Category: Expense Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHARACTERS 1000

struct expense {
    char category[MAX_CHARACTERS];
    float amount;
    char date[MAX_CHARACTERS];
};

void addExpense(struct expense expenses[], int *numExpenses);
void printExpenses(struct expense expenses[], int numExpenses);
void filterByCategory(struct expense expenses[], int numExpenses);
void filterByDate(struct expense expenses[], int numExpenses);

int main() {
    struct expense expenses[MAX_CHARACTERS];
    int numExpenses = 0;
    char choice[MAX_CHARACTERS];
    do {
        printf("Please choose an option:\n");
        printf("1. Add expense\n");
        printf("2. Print all expenses\n");
        printf("3. Filter by category\n");
        printf("4. Filter by date\n");
        printf("5. Exit\n");
        scanf("%s", choice);
        if(strcmp(choice, "1") == 0) {
            addExpense(expenses, &numExpenses);
        } else if(strcmp(choice, "2") == 0) {
            printExpenses(expenses, numExpenses);
        } else if(strcmp(choice, "3") == 0) {
            filterByCategory(expenses, numExpenses);
        } else if(strcmp(choice, "4") == 0) {
            filterByDate(expenses, numExpenses);
        }
    } while(strcmp(choice, "5") != 0);
    return 0;
}

void addExpense(struct expense expenses[], int *numExpenses) {
    printf("Please enter the expense category: ");
    scanf("%s", expenses[*numExpenses].category);
    printf("Please enter the expense amount: ");
    scanf("%f", &expenses[*numExpenses].amount);
    printf("Please enter the expense date: ");
    scanf("%s", expenses[*numExpenses].date);
    (*numExpenses)++;
}

void printExpenses(struct expense expenses[], int numExpenses) {
    for(int i = 0; i < numExpenses; i++) {
        printf("Category: %s\n", expenses[i].category);
        printf("Amount: %.2f\n", expenses[i].amount);
        printf("Date: %s\n", expenses[i].date);
    }
}

void filterByCategory(struct expense expenses[], int numExpenses) {
    char categoryFilter[MAX_CHARACTERS];
    printf("Please enter the category to filter by: ");
    scanf("%s", categoryFilter);
    for(int i = 0; i < numExpenses; i++) {
        if(strcmp(expenses[i].category, categoryFilter) == 0) {
            printf("Category: %s\n", expenses[i].category);
            printf("Amount: %.2f\n", expenses[i].amount);
            printf("Date: %s\n", expenses[i].date);
        }
    }
}

void filterByDate(struct expense expenses[], int numExpenses) {
    char dateFilter[MAX_CHARACTERS];
    printf("Please enter the date to filter by: ");
    scanf("%s", dateFilter);
    for(int i = 0; i < numExpenses; i++) {
        if(strcmp(expenses[i].date, dateFilter) == 0) {
            printf("Category: %s\n", expenses[i].category);
            printf("Amount: %.2f\n", expenses[i].amount);
            printf("Date: %s\n", expenses[i].date);
        }
    }
}