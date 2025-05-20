//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: genious
/* Warehouse Management System */

#include <stdio.h>
#include <stdlib.h>

struct Item {
  int code;
  char name[20];
  int quantity;
  float price;
};
typedef struct Item Item;

Item items[100]; // Array to hold items
int itemCount = 0; // Number of items in the warehouse

void addItem() {
    Item newItem;
    printf("Enter the code of the item: ");
    scanf("%d", &newItem.code);
    printf("Enter the name of the item: ");
    scanf("%s", &newItem.name);
    printf("Enter the quantity of the item: ");
    scanf("%d", &newItem.quantity);
    printf("Enter the price of the item: ");
    scanf("%f", &newItem.price);
    items[itemCount++] = newItem;
    printf("Item added successfully.");
}

void removeItem() {
    int code, i;
    printf("\nEnter the code of the item to be removed: ");
    scanf("%d", &code);
    for (i = 0; i < itemCount; i++) {
        if (items[i].code == code) {
            items[i] = items[--itemCount];
            printf("Item removed successfully.");
            return;
        }
    }
    printf("Item not found.");
}

void viewInventory() {
    int i;
    if (itemCount == 0) {
        printf("\nThere are no items in the warehouse.");
        return;
    }
    printf("\nWarehouse Inventory:\n");
    printf("Code  Name               Quantity  Price\n");
    for (i = 0; i < itemCount; i++) {
        printf("%-5d %-18s %-9d $%.2f\n", items[i].code, items[i].name, items[i].quantity, items[i].price);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nWarehouse Management System\n");
        printf("---------------------------\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. View inventory\n");
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
                viewInventory();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.");
        }
    }
    return 0;
}