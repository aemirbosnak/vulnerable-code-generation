//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory is full!\n");
        return;
    }
    
    Product newProduct;
    
    printf("Enter product ID: ");
    scanf("%d", &newProduct.id);
    
    printf("Enter product name: ");
    scanf(" %[^\n]", newProduct.name);
    
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    
    inventory[productCount] = newProduct;
    productCount++;
    printf("Product added successfully!\n");
}

void displayProducts(int index) {
    if (index >= productCount) {
        return;
    }
    
    printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
           inventory[index].id,
           inventory[index].name,
           inventory[index].quantity,
           inventory[index].price);
    
    displayProducts(index + 1);
}

void searchProduct(int id, int index) {
    if (index >= productCount) {
        printf("Product with ID %d not found!\n", id);
        return;
    }

    if (inventory[index].id == id) {
        printf("Product found! ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
               inventory[index].id,
               inventory[index].name,
               inventory[index].quantity,
               inventory[index].price);
        return;
    }

    searchProduct(id, index + 1);
}

void menu() {
    printf("Menu:\n");
    printf("1. Add Product\n");
    printf("2. Display Products\n");
    printf("3. Search Product by ID\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    
    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                printf("Products in inventory:\n");
                displayProducts(0);
                break;
            case 3: {
                int id;
                printf("Enter product ID to search: ");
                scanf("%d", &id);
                searchProduct(id, 0);
                break;
            }
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}