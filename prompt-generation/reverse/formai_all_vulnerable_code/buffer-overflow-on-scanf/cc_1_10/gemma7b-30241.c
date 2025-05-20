//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[50];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS];

void displayItems() {
    printf("Here are the available items:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0] != '\0') {
            printf("%s - %d - %.2f\n", items[i].name, items[i].quantity, items[i].price);
        }
    }
}

void addItem() {
    printf("Enter item name: ");
    scanf("%s", items[MAX_ITEMS - 1].name);
    printf("Enter item quantity: ");
    scanf("%d", &items[MAX_ITEMS - 1].quantity);
    printf("Enter item price: ");
    scanf("%f", &items[MAX_ITEMS - 1].price);
    items[MAX_ITEMS - 1].name[0] = '\0';
}

void calculateTotal() {
    float total = 0;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0] != '\0') {
            total += items[i].quantity * items[i].price;
        }
    }
    printf("Total amount: %.2f\n", total);
}

int main() {
    int choice;

    displayItems();

    printf("Enter 1 to add an item, 2 to calculate total, or 3 to exit: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addItem();
            break;
        case 2:
            calculateTotal();
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Invalid input.\n");
            break;
    }

    return 0;
}