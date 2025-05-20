//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORIES 10
#define MAX_NAME_LENGTH 50
#define MAX_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORIES][MAX_NAME_LENGTH];
    float amount;
    int count;
} Expense;

void addExpense(Expense* expenses, int numExpenses, char* name, char* category, float amount) {
    int i;
    for (i = 0; i < numExpenses; i++) {
        if (strcmp(expenses[i].name, name) == 0) {
            strcpy(expenses[i].category[expenses[i].count], category);
            expenses[i].amount += amount;
            expenses[i].count++;
            return;
        }
    }
    strcpy(expenses[numExpenses].name, name);
    strcpy(expenses[numExpenses].category[0], category);
    expenses[numExpenses].amount = amount;
    expenses[numExpenses].count = 1;
    numExpenses++;
}

void displayExpenses(Expense* expenses, int numExpenses) {
    int i, j;
    for (i = 0; i < numExpenses; i++) {
        printf("Name: %s\n", expenses[i].name);
        printf("Category: ");
        for (j = 0; j < expenses[i].count; j++) {
            printf("%s ", expenses[i].category[j]);
        }
        printf("\nAmount: $%.2f\n", expenses[i].amount);
        printf("Count: %d\n\n", expenses[i].count);
    }
}

int main() {
    int numExpenses = 0;
    Expense expenses[MAX_EXPENSES];
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORIES][MAX_NAME_LENGTH];
    float amount;
    int i, j, choice;

    do {
        system("clear");
        printf("Expense Tracker\n");
        printf("1. Add expense\n");
        printf("2. Display expenses\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter expense name: ");
            scanf("%s", name);
            printf("Enter expense category: ");
            scanf("%s", category[0]);
            printf("Enter expense amount: $");
            scanf("%f", &amount);
            addExpense(expenses, numExpenses, name, category[0], amount);
            numExpenses++;
            break;
        case 2:
            displayExpenses(expenses, numExpenses);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}