//FormAI DATASET v1.0 Category: Product Inventory System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for product
typedef struct {
    char name[20];
    int id;
    float price;
    int quantity;
} Product;

// Define function to add product to inventory
void addProduct(Product *inventory, int *size) {
    Product newProduct;
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product ID: ");
    scanf("%d", &newProduct.id);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    inventory[*size] = newProduct;
    (*size)++;
    printf("Product added to inventory!\n");
}

// Define function to remove product from inventory
void removeProduct(Product *inventory, int *size, int id) {
    int index = -1;
    for (int i=0 ; i<*size ; i++) {
        if (inventory[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Product not found!\n");
        return;
    }
    for (int i=index ; i<*size-1 ; i++) {
        inventory[i] = inventory[i+1];
    }
    (*size)--;
    printf("Product removed from inventory!\n");
}

// Define function to display all products in inventory
void displayProducts(Product *inventory, int size) {
    printf("\nProduct ID\tProduct Name\tProduct Price\tProduct Quantity\n");
    for (int i=0 ; i<size ; i++) {
        printf("%d\t\t%s\t\t%.2f\t\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

// Define main function
int main() {
    Product inventory[100];
    int size = 0;
    int choice = -1;
    printf("Welcome to the Product Inventory System!\n");
    while (choice != 0) {
        printf("\nPlease choose an option:\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display all products\n");
        printf("0. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addProduct(inventory, &size);
                break;
            case 2:
                printf("Enter product ID to remove: ");
                int id;
                scanf("%d", &id);
                removeProduct(inventory, &size, id);
                break;
            case 3:
                displayProducts(inventory, size);
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}