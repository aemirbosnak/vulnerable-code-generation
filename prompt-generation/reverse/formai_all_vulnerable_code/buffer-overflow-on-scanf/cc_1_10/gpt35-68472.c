//FormAI DATASET v1.0 Category: Product Inventory System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    double price;
} Product;

typedef struct {
    Product products[100];
    int count;
} Inventory;

void addProduct(Inventory *inv, char *name, int quantity, double price) {
    Product p;
    strcpy(p.name, name);
    p.quantity = quantity;
    p.price = price;
    inv->products[inv->count] = p;
    inv->count++;
}

void removeProduct(Inventory *inv, int index) {
    if (index >= 0 && index < inv->count) {
        for (int i = index; i < inv->count - 1; i++) {
            inv->products[i] = inv->products[i+1];
        }
        inv->count--;
    }
}

void printInventory(Inventory *inv) {
    printf("Inventory:\n");
    for (int i = 0; i < inv->count; i++) {
        printf("%d. %s - Quantity: %d - Price: %.2f\n", i+1, inv->products[i].name, inv->products[i].quantity, inv->products[i].price);
    }
}

int main() {
    Inventory inv = {.count = 0};
    int choice = 1;
    char name[50];
    int quantity;
    double price;
    int index;
    
    printf("Welcome to the shape-shifting C Product Inventory System!\n");
    while (choice != 0) {
        printf("Choose an option:\n");
        printf("1. Add a product\n");
        printf("2. Remove a product\n");
        printf("3. Print inventory\n");
        printf("0. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("Enter price: ");
                scanf("%lf", &price);
                addProduct(&inv, name, quantity, price);
                printf("Product added!\n");
                break;
            case 2:
                printf("Enter index of product to remove: ");
                scanf("%d", &index);
                removeProduct(&inv, index-1);
                printf("Product removed!\n");
                break;
            case 3:
                printInventory(&inv);
                break;
            case 0:
                printf("Thanks for using the shape-shifting C Product Inventory System!\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}