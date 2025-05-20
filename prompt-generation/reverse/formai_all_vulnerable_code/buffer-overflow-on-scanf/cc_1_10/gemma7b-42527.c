//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS];

void displayItems() {
    int i = 0;
    for (i = 0; i < MAX_ITEMS && items[i].name[0] != '\0'; i++) {
        printf("%s - %d - %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

void addItem() {
    int i = 0;
    for (i = 0; items[i].name[0] != '\0'; i++) {}

    printf("Enter item name: ");
    scanf("%s", items[i].name);

    printf("Enter item quantity: ");
    scanf("%d", &items[i].quantity);

    printf("Enter item price: ");
    scanf("%f", &items[i].price);

    printf("Item added.\n");
}

void calculateTotal() {
    int i = 0;
    float total = 0;
    for (i = 0; items[i].name[0] != '\0'; i++) {
        total += items[i].quantity * items[i].price;
    }

    printf("Total: %.2f\n", total);
}

int main() {
    int choice = 0;

    displayItems();

    printf("Enter 1 to add item, 2 to calculate total: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addItem();
            break;
        case 2:
            calculateTotal();
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}