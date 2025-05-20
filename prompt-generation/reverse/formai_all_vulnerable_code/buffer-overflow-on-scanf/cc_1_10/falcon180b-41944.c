//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_ITEM_NAME 50
#define MAX_ITEM_PRICE 10
#define MAX_ITEM_QUANTITY 10

typedef struct {
    char name[MAX_ITEM_NAME];
    float price;
    int quantity;
} Item;

Item items[MAX_ITEMS];
int numItems = 0;

void addItem() {
    printf("Enter item name: ");
    scanf("%s", &items[numItems].name);
    printf("Enter item price: ");
    scanf("%f", &items[numItems].price);
    printf("Enter item quantity: ");
    scanf("%d", &items[numItems].quantity);
    numItems++;
}

void displayItems() {
    printf("Item Name\tPrice\tQuantity\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s\t%.2f\t%d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

int main() {
    int choice;
    while (1) {
        printf("Welcome to Medical Store Management System\n");
        printf("1. Add Item\n2. Display Items\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                displayItems();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}