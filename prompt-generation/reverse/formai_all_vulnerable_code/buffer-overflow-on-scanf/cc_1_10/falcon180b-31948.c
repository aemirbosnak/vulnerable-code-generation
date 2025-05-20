//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    double price;
    int quantity;
} Item;

void addItem(Item items[], int numItems) {
    char name[MAX_NAME_LENGTH];
    double price;
    int quantity;

    printf("Enter item name: ");
    scanf("%s", name);

    printf("Enter item price: ");
    scanf("%lf", &price);

    printf("Enter item quantity: ");
    scanf("%d", &quantity);

    strcpy(items[numItems].name, name);
    items[numItems].price = price;
    items[numItems].quantity = quantity;

    numItems++;
}

void displayItems(Item items[], int numItems) {
    printf("\nItem Name\t\tPrice\t\tQuantity\n");

    for (int i = 0; i < numItems; i++) {
        printf("%s\t\t%.2lf\t\t%d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

void calculateTotal(Item items[], int numItems) {
    double total = 0.0;

    for (int i = 0; i < numItems; i++) {
        total += items[i].price * items[i].quantity;
    }

    printf("\nTotal Expense: $%.2lf\n", total);
}

int main() {
    Item items[MAX_ITEMS];
    int numItems = 0;

    printf("Expense Tracker\n");

    while (numItems < MAX_ITEMS) {
        printf("\nDo you want to add an item? (y/n): ");
        char choice;
        scanf("%c", &choice);

        if (choice == 'y' || choice == 'Y') {
            addItem(items, numItems);
        } else if (choice == 'n' || choice == 'N') {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    displayItems(items, numItems);
    calculateTotal(items, numItems);

    return 0;
}