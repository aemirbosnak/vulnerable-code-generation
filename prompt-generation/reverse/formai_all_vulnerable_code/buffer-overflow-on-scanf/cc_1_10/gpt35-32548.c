//FormAI DATASET v1.0 Category: Product Inventory System ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STRLEN 30
#define MAX 50

struct Product {
    char name[STRLEN];
    int id;
    float price;
    int quantity;
};

struct Inventory {
    struct Product products[MAX];
    int itemCount;
};

void addProduct(struct Inventory *inv, struct Product p) {
    if (inv->itemCount < MAX) {
        inv->products[inv->itemCount] = p;
        inv->itemCount++;
        printf("Product added to inventory.\n");
    } else {
        printf("Inventory is full. Cannot add more products.\n");
    }
}

void removeProduct(struct Inventory *inv, int id) {
    int found = 0;
    int i;
    for (i = 0; i < inv->itemCount; i++) {
        if (inv->products[i].id == id) {
            found = 1;
            break;
        }
    }

    if (found) {
        for (; i < inv->itemCount - 1; i++) {
            inv->products[i] = inv->products[i+1];
        }
        inv->itemCount--;
        printf("Product removed from inventory.\n");
    } else {
        printf("Product not found in inventory.\n");
    }
}

void displayInventory(struct Inventory inv) {
    printf("==========================\n");
    printf("Inventory Details\n");
    printf("==========================\n");
    printf("%-10s%-20s%-10s%-10s\n", "ID", "Name", "Price", "Quantity");
    printf("--------------------------\n");
    int i;
    for (i = 0; i < inv.itemCount; i++) {
        printf("%-10d%-20s%-10.2f%-10d\n", inv.products[i].id, inv.products[i].name, inv.products[i].price, inv.products[i].quantity);
    }
}

int main() {
    struct Inventory inventory;
    inventory.itemCount = 0;

    int choice = 0;
    while (choice != 4) {
        printf("\nSelect operation:\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display inventory\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
            {
                struct Product p;
                printf("Enter product name: ");
                scanf("%s", &p.name);
                printf("Enter product price: ");
                scanf("%f", &p.price);
                printf("Enter product quantity: ");
                scanf("%d", &p.quantity);
                printf("Enter product ID: ");
                scanf("%d", &p.id);
                addProduct(&inventory, p);
                break;
            }
            case 2:
            {
                int id;
                printf("Enter product ID to remove: ");
                scanf("%d", &id);
                removeProduct(&inventory, id);
                break;
            }
            case 3:
            {
                displayInventory(inventory);
                break;
            }
            case 4:
            {
                printf("Exiting program. Bye!\n");
                break;
            }
            default:
            {
                printf("Invalid choice. Please select again.\n");
                break;
            }
        }
    }

    return 0;
}