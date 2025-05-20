//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
} Item;

void addItem(Item* items, int* numItems) {
    printf("Enter item name: ");
    scanf("%s", (*numItems >= MAX_ITEMS? "" : items[*numItems].name));
    printf("Enter item price: ");
    scanf("%f", &items[*numItems].price);
    (*numItems)++;
}

void displayItems(Item* items, int numItems) {
    printf("\nItem List:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - $%.2f\n", i+1, items[i].name, items[i].price);
    }
}

void calculateTotalExpenses(Item* items, int numItems) {
    float totalExpenses = 0.0;
    for (int i = 0; i < numItems; i++) {
        totalExpenses += items[i].price;
    }
    printf("\nTotal Expenses: $%.2f\n", totalExpenses);
}

int main() {
    Item items[MAX_ITEMS];
    int numItems = 0;
    char choice;

    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add Item\n2. Display Items\n3. Calculate Total Expenses\n4. Quit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                addItem(items, &numItems);
                break;
            case '2':
                displayItems(items, numItems);
                break;
            case '3':
                calculateTotalExpenses(items, numItems);
                break;
            case '4':
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}