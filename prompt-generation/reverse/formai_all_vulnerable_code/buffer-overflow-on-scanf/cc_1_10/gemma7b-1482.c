//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[50];
    float price;
    int quantity;
} Item;

Item items[MAX_ITEMS];

void displayMenu() {
    printf("---------------------------------------------------\n");
    printf("           Welcome to Caffeinated Dreams!           \n");
    printf("---------------------------------------------------\n");
    printf("Items:\n");

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0] != '\0') {
            printf("%s - %.2f (Qty: %d)\n", items[i].name, items[i].price, items[i].quantity);
        }
    }

    printf("\n");
}

void addItem() {
    printf("Enter item name: ");
    scanf("%s", items[MAX_ITEMS - 1].name);

    printf("Enter item price: ");
    scanf("%f", &items[MAX_ITEMS - 1].price);

    printf("Enter item quantity: ");
    scanf("%d", &items[MAX_ITEMS - 1].quantity);

    items[MAX_ITEMS - 1].quantity++;
}

void calculateTotal() {
    float total = 0.0f;

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0] != '\0') {
            total += items[i].price * items[i].quantity;
        }
    }

    printf("Total: $%.2f\n", total);
}

int main() {
    displayMenu();

    char choice;

    printf("Enter 'a' to add an item, 'c' to calculate total: ");
    scanf(" %c", &choice);

    switch (choice) {
        case 'a':
            addItem();
            displayMenu();
            break;
        case 'c':
            calculateTotal();
            break;
        default:
            printf("Invalid input.\n");
    }

    return 0;
}