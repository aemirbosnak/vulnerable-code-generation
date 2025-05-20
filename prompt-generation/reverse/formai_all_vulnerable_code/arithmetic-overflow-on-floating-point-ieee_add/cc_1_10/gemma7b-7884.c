//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEM_NUM 10

typedef struct Item {
    char name[20];
    float price;
    int quantity;
} Item;

Item items[MAX_ITEM_NUM];

void displayMenu() {
    int i = 0;
    printf("Here is the menu:\n");
    for (i = 0; i < MAX_ITEM_NUM; i++) {
        if (items[i].name[0] != '\0') {
            printf("%s - $%.2f,  Quantity: %d\n", items[i].name, items[i].price, items[i].quantity);
        }
    }
}

void addItem() {
    int i = 0;
    for (i = 0; i < MAX_ITEM_NUM; i++) {
        if (items[i].name[0] == '\0') {
            printf("Enter item name: ");
            scanf("%s", items[i].name);
            printf("Enter item price: $");
            scanf("%f", &items[i].price);
            printf("Enter item quantity: ");
            scanf("%d", &items[i].quantity);
            return;
        }
    }
    printf("Error: Item list is full!\n");
}

void calculateTotal() {
    int i = 0;
    float total = 0.0f;
    for (i = 0; i < MAX_ITEM_NUM; i++) {
        if (items[i].name[0] != '\0') {
            total += items[i].price * items[i].quantity;
        }
    }
    printf("Total: $%.2f\n", total);
}

int main() {
    displayMenu();
    addItem();
    displayMenu();
    calculateTotal();
    return 0;
}