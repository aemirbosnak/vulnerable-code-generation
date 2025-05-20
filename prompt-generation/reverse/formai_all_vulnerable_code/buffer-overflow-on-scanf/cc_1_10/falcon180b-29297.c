//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    double amount;
    int category;
} item;

void addItem(item *items, int *numItems) {
    printf("Enter item name: ");
    scanf("%s", items[*numItems].name);
    printf("Enter item amount: ");
    scanf("%lf", &items[*numItems].amount);
    printf("Enter item category (0 for expense, 1 for income): ");
    scanf("%d", &items[*numItems].category);
    (*numItems)++;
}

void displayItems(item *items, int numItems) {
    printf("\nItem Name\t\tAmount\tCategory\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s\t\t%.2lf\t\t%d\n", items[i].name, items[i].amount, items[i].category);
    }
}

void calculateTotal(item *items, int numItems, double *totalExpenses, double *totalIncome) {
    for (int i = 0; i < numItems; i++) {
        if (items[i].category == 0) {
            *totalExpenses += items[i].amount;
        } else {
            *totalIncome += items[i].amount;
        }
    }
}

int main() {
    item items[MAX_ITEMS];
    int numItems = 0;
    double totalExpenses = 0.0, totalIncome = 0.0;

    printf("Welcome to the Personal Finance Planner!\n");
    printf("Please enter your items below.\n");

    while (numItems < MAX_ITEMS && numItems >= 0) {
        addItem(items, &numItems);
        printf("\nDo you want to add another item? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice!= 'y') {
            break;
        }
    }

    displayItems(items, numItems);

    calculateTotal(items, numItems, &totalExpenses, &totalIncome);

    printf("\nTotal Expenses: $%.2lf\n", totalExpenses);
    printf("Total Income: $%.2lf\n", totalIncome);

    return 0;
}