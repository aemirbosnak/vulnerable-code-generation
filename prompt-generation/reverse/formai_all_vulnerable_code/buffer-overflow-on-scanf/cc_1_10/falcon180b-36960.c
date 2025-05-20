//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    char description[100];
    int quantity;
    float price;
} Item;

void addItem(Item items[], int numItems) {
    printf("Enter item name: ");
    scanf("%s", items[numItems].name);

    printf("Enter item description: ");
    scanf("%s", items[numItems].description);

    printf("Enter item quantity: ");
    scanf("%d", &items[numItems].quantity);

    printf("Enter item price: ");
    scanf("%f", &items[numItems].price);

    numItems++;
}

void displayItems(Item items[], int numItems) {
    printf("Item Name\tItem Description\tQuantity\tPrice\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s\t\t%s\t\t%d\t\t$%.2f\n", items[i].name, items[i].description, items[i].quantity, items[i].price);
    }
}

int main() {
    Item items[MAX_ITEMS];
    int numItems = 0;

    while (numItems < MAX_ITEMS) {
        printf("Enter 1 to add item, 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            addItem(items, numItems);
        } else if (choice == 0) {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    printf("Displaying items:\n");
    displayItems(items, numItems);

    return 0;
}