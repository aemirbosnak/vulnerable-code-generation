//FormAI DATASET v1.0 Category: Product Inventory System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[20];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int numProducts = 0;

void addProduct(char *name, int quantity, float price) {
    if (numProducts < MAX_PRODUCTS) {
        Product p;
        strcpy(p.name, name);
        p.quantity = quantity;
        p.price = price;
        inventory[numProducts++] = p;
        printf("%s added to inventory.\n", name);
    } else {
        printf("Inventory is full.\n");
    }
}

void removeProduct(char *name) {
    int index = -1;
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < numProducts-1; i++) {
            inventory[i] = inventory[i+1];
        }
        numProducts--;
        printf("%s removed from inventory.\n", name);
    } else {
        printf("%s not found in inventory.\n", name);
    }
}

void listInventory() {
    printf("%-20s%-10s%-10s\n", "Name", "Quantity", "Price");
    for (int i = 0; i < numProducts; i++) {
        printf("%-20s%-10d%-10.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    for (;;) {
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. List inventory\n");
        printf("4. Exit\n");

        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[20];
                int quantity;
                float price;
                printf("Enter product name:");
                scanf("%s", name);
                printf("Enter quantity:");
                scanf("%d", &quantity);
                printf("Enter price:");
                scanf("%f", &price);
                addProduct(name, quantity, price);
                break;
            }
            case 2: {
                char name[20];
                printf("Enter product name:");
                scanf("%s", name);
                removeProduct(name);
                break;
            }
            case 3: {
                listInventory();
                break;
            }
            case 4: {
                printf("Exiting...\n");
                exit(0);
            }
            default: {
                printf("Invalid choice.\n");
                break;
            }
        }
        printf("\n");
    }
    return 0;
}