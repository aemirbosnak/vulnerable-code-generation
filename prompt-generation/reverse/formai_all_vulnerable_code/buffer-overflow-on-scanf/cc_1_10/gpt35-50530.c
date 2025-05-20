//FormAI DATASET v1.0 Category: Product Inventory System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct Product {
    char name[100];
    int id;
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int numProducts = 0;

void addProduct() {
    if (numProducts >= MAX_PRODUCTS) {
        printf("Inventory is full\n");
        return;
    }
    Product p;
    printf("Enter product name: ");
    fgets(p.name, 100, stdin);
    p.name[strcspn(p.name, "\n")] = 0;
    printf("Enter product ID: ");
    scanf("%d", &p.id);
    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter product price: ");
    scanf("%f", &p.price);
    getchar();
    inventory[numProducts++] = p;
    printf("Product added to inventory\n");
}

void removeProduct() {
    printf("Enter ID of product to remove: ");
    int idToRemove;
    scanf("%d", &idToRemove);
    for (int i = 0; i < numProducts; i++) {
        if (inventory[i].id == idToRemove) {
            for (int j = i; j < numProducts - 1; j++) {
                inventory[j] = inventory[j+1];
            }
            numProducts--;
            printf("Product removed from inventory\n");
            return;
        }
    }
    printf("Product with ID %d not found\n", idToRemove);
}

void listProducts() {
    if (numProducts == 0) {
        printf("Inventory is empty\n");
        return;
    }
    printf("Name\tID\tQuantity\tPrice\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%s\t%d\t%d\t$%.2f\n", inventory[i].name, inventory[i].id, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    printf("Product Inventory System\n");
    while (1) {
        printf("1. Add product\n2. Remove product\n3. List products\n4. Exit\n");
        int choice;
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                removeProduct();
                break;
            case 3:
                listProducts();
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}