//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char amount[MAX_AMOUNT_LENGTH];
} ExpenseItem;

void addExpense(ExpenseItem items[], int numItems, char* name, char* amount) {
    if (numItems >= MAX_ITEMS) {
        printf("Error: Maximum number of items reached.\n");
        return;
    }

    int i;
    for (i = 0; i < numItems; i++) {
        if (strcmp(items[i].name, name) == 0) {
            printf("Error: Duplicate item name.\n");
            return;
        }
    }

    strcpy(items[numItems].name, name);
    strcpy(items[numItems].amount, amount);
    numItems++;
}

void displayExpenses(ExpenseItem items[], int numItems) {
    if (numItems == 0) {
        printf("No expenses entered.\n");
        return;
    }

    printf("Expenses:\n");
    printf("Name\tAmount\n");

    int i;
    for (i = 0; i < numItems; i++) {
        printf("%s\t%s\n", items[i].name, items[i].amount);
    }
}

int main() {
    ExpenseItem items[MAX_ITEMS];
    int numItems = 0;

    char choice;
    do {
        printf("Expense Tracker\n");
        printf("A - Add expense\n");
        printf("D - Display expenses\n");
        printf("Q - Quit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case 'A':
            printf("Enter expense name: ");
            scanf("%s", items[numItems].name);
            printf("Enter expense amount: ");
            scanf("%s", items[numItems].amount);
            numItems++;
            break;

        case 'D':
            displayExpenses(items, numItems);
            break;

        case 'Q':
            printf("Goodbye!\n");
            break;

        default:
            printf("Invalid choice.\n");
            break;
        }
    } while (choice!= 'Q');

    return 0;
}