//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

void createItem(Item *item) {
    printf("Enter item name: ");
    scanf("%s", item->name);
    printf("Enter item quantity: ");
    scanf("%d", &item->quantity);
    printf("Enter item price: ");
    scanf("%f", &item->price);
}

void displayItems(Item *items, int numItems) {
    for (int i = 0; i < numItems; i++) {
        printf("%s: %d, Price: %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

int calculateTotal(Item *items, int numItems) {
    int total = 0;
    for (int i = 0; i < numItems; i++) {
        total += items[i].quantity * items[i].price;
    }
    return total;
}

int main() {
    Item items[10];
    int numItems = 0;

    // Create items
    printf("Enter 'c' to create an item: ");
    char command;
    scanf("%c", &command);

    while (command == 'c') {
        createItem(&items[numItems]);
        numItems++;
        printf("Enter 'c' to create an item (or any other letter to finish): ");
        scanf("%c", &command);
    }

    // Display items
    displayItems(items, numItems);

    // Calculate total
    int total = calculateTotal(items, numItems);

    // Print total
    printf("Total: $%d\n", total);

    return 0;
}