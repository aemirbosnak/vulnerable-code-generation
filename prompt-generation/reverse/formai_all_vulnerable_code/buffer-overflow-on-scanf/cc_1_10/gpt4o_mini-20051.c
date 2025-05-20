//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct Product {
    char name[30];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Alas! The inventory cannot hold more products!\n");
        return;
    }
    Product newProduct;
    printf("Enter the name of the product: ");
    scanf("%s", newProduct.name);
    printf("Enter the quantity of the product: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter the price of the product: ");
    scanf("%f", &newProduct.price);
    inventory[productCount++] = newProduct;
    printf("Oh joyous day! The product has been added to the inventory!\n");
}

void viewProducts() {
    if (productCount == 0) {
        printf("Woe betide us! The inventory is empty!\n");
        return;
    }
    printf("Alas! Here lies the inventory of products:\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d. %s - Quantity: %d, Price: %.2f\n", i + 1, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void updateProduct() {
    int index;
    printf("Enter the product number to update: ");
    scanf("%d", &index);
    if (index <= 0 || index > productCount) {
        printf("Alack! The product number does not exist in our humble inventory!\n");
        return;
    }
    index--; // Adjust for zero-based index
    printf("Enter the new quantity for %s: ", inventory[index].name);
    scanf("%d", &inventory[index].quantity);
    printf("Enter the new price for %s: ", inventory[index].name);
    scanf("%f", &inventory[index].price);
    printf("The product hath been updated with grace and poise.\n");
}

void deleteProduct() {
    int index;
    printf("Enter the product number to remove: ");
    scanf("%d", &index);
    if (index <= 0 || index > productCount) {
        printf("Oh no! The product number doth not exist!\n");
        return;
    }
    index--; // Adjust for zero-based index
    for (int i = index; i < productCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    productCount--;
    printf("Thy product hath been banished from the inventory.\n");
}

void menu() {
    int choice;
    while (1) {
        printf("\n----------------------------\n");
        printf("Welcome to the Product Inventory System!\n");
        printf("1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Exit\n");
        printf("Choose thy fate: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addProduct(); break;
            case 2: viewProducts(); break;
            case 3: updateProduct(); break;
            case 4: deleteProduct(); break;
            case 5: printf("Fare thee well!\n"); exit(0);
            default: printf("Methinks thou hast made an error in thy choice.\n"); break;
        }
    }
}

int main() {
    menu();
    return 0;
}