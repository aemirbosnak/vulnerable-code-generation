//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 100
#define MAX_PRICE 1000.00

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
    double price;
} Item;

void addItem(Item items[], int numItems) {
    printf("Enter item name: ");
    scanf("%s", items[numItems].name);
    printf("Enter item quantity: ");
    scanf("%d", &items[numItems].quantity);
    printf("Enter item price: ");
    scanf("%lf", &items[numItems].price);
    numItems++;
}

void displayItems(Item items[], int numItems) {
    printf("\nItem Name\t\tQuantity\t\tPrice\n");
    for (int i = 0; i < numItems; i++) {
        printf("%-20s\t%-10d\t\t$%.2lf\n", items[i].name, items[i].quantity, items[i].price);
    }
}

void calculateTotal(Item items[], int numItems) {
    double total = 0.00;
    for (int i = 0; i < numItems; i++) {
        total += items[i].quantity * items[i].price;
    }
    printf("\nTotal: $%.2lf\n", total);
}

void main() {
    Item items[MAX_ITEMS];
    int numItems = 0;

    printf("Welcome to the Cafe Billing System!\n");

    while (numItems < MAX_ITEMS) {
        printf("\nEnter 'a' to add an item, 'd' to display items, 'c' to calculate total, or 'q' to quit: ");
        char choice;
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                addItem(items, numItems);
                break;
            case 'd':
                displayItems(items, numItems);
                break;
            case 'c':
                calculateTotal(items, numItems);
                break;
            case 'q':
                printf("\nThank you for using the Cafe Billing System!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}