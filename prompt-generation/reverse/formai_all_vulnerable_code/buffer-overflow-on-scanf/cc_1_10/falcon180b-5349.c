//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_NAME_SIZE 50
#define MAX_QUANTITY_SIZE 10
#define MAX_PRICE_SIZE 10

typedef struct {
    char name[MAX_NAME_SIZE];
    int quantity;
    float price;
} Item;

Item inventory[MAX_ITEMS];
int num_items = 0;

void addItem() {
    if (num_items >= MAX_ITEMS) {
        printf("Inventory is full.\n");
        return;
    }
    printf("Enter item name: ");
    scanf("%s", inventory[num_items].name);
    printf("Enter item quantity: ");
    scanf("%d", &inventory[num_items].quantity);
    printf("Enter item price: ");
    scanf("%f", &inventory[num_items].price);
    num_items++;
    printf("Item added successfully.\n");
}

void removeItem() {
    if (num_items == 0) {
        printf("Inventory is empty.\n");
        return;
    }
    int index;
    printf("Enter item index to remove: ");
    scanf("%d", &index);
    if (index >= 0 && index < num_items) {
        num_items--;
        for (int i = index; i < num_items; i++) {
            inventory[i] = inventory[i+1];
        }
        printf("Item removed successfully.\n");
    } else {
        printf("Invalid item index.\n");
    }
}

void displayItems() {
    if (num_items == 0) {
        printf("Inventory is empty.\n");
        return;
    }
    printf("Item Name\tQuantity\tPrice\n");
    for (int i = 0; i < num_items; i++) {
        printf("%-20s\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    int choice;
    do {
        printf("Product Inventory System\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Display items\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                removeItem();
                break;
            case 3:
                displayItems();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);
    return 0;
}