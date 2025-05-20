//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int quantity;
    double price;
} Item;

Item items[MAX_ITEMS];

int main() {
    int numItems = 0;
    double totalAmount = 0.0;

    // Create a loop to add items to the menu
    while (1) {
        char itemName[20];
        int itemQuantity;
        double itemPrice;

        printf("Enter item name: ");
        scanf("%s", itemName);

        printf("Enter item quantity: ");
        scanf("%d", &itemQuantity);

        printf("Enter item price: ");
        scanf("%lf", &itemPrice);

        // Add the item to the menu
        Item item;
        strcpy(item.name, itemName);
        item.quantity = itemQuantity;
        item.price = itemPrice;
        items[numItems++] = item;

        // Check if the user wants to add more items
        char answer;
        printf("Do you want to add more items? (Y/N): ");
        scanf(" %c", &answer);

        if (answer == 'N') {
            break;
        }
    }

    // Calculate the total amount
    for (int i = 0; i < numItems; i++) {
        double itemTotalAmount = items[i].quantity * items[i].price;
        totalAmount += itemTotalAmount;
    }

    // Print the bill
    printf("------------------------------------------------------------------------\n");
    printf("Item Name\t\tQuantity\t\tPrice\t\tTotal Amount\n");
    printf("------------------------------------------------------------------------\n");

    for (int i = 0; i < numItems; i++) {
        printf("%s\t\t%d\t\t%.2lf\t\t%.2lf\n", items[i].name, items[i].quantity, items[i].price, items[i].quantity * items[i].price);
    }

    printf("------------------------------------------------------------------------\n");
    printf("Total Amount: %.2lf\n", totalAmount);
    printf("------------------------------------------------------------------------\n");

    return 0;
}