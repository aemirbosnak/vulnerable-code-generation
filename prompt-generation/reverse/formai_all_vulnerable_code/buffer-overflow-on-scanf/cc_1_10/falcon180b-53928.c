//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float price;
    int quantity;
} Item;

void addItem(Item *items, int numItems) {
    printf("Enter item name: ");
    scanf("%s", &items[numItems].name);
    printf("Enter item price: ");
    scanf("%f", &items[numItems].price);
    printf("Enter item quantity: ");
    scanf("%d", &items[numItems].quantity);
}

void displayItems(Item *items, int numItems) {
    printf("Item Name\tPrice\tQuantity\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s\t%.2f\t%d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

int main() {
    Item items[MAX_ITEMS];
    int numItems = 0;

    printf("Welcome to the Expense Tracker!\n");

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add item\n");
        printf("2. Display items\n");
        printf("3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (numItems >= MAX_ITEMS) {
                printf("Max items reached!\n");
            } else {
                addItem(items, numItems);
                numItems++;
            }
            break;
        case 2:
            displayItems(items, numItems);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}