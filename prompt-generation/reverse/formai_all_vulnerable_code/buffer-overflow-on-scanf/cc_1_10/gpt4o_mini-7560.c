//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void displayMenu() {
    printf("\n--- Product Inventory System ---\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Search Product\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }
    Product newProduct;
    newProduct.id = productCount + 1;

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

void viewProducts() {
    if (productCount == 0) {
        printf("No products in inventory.\n");
        return;
    }
 
    printf("\n--- Product List ---\n");
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
               inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void updateProduct() {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    
    if (id < 1 || id > productCount) {
        printf("Invalid product ID!\n");
        return;
    }

    Product *p = &inventory[id - 1];
    printf("Updating product: %s\n", p->name);

    printf("Enter new product name (current: %s): ", p->name);
    scanf(" %[^\n]", p->name);
    printf("Enter new product quantity (current: %d): ", p->quantity);
    scanf("%d", &p->quantity);
    printf("Enter new product price (current: %.2f): ", p->price);
    scanf("%f", &p->price);
    
    printf("Product updated successfully!\n");
}

void deleteProduct() {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    
    if (id < 1 || id > productCount) {
        printf("Invalid product ID!\n");
        return;
    }
    
    for (int i = id - 1; i < productCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    productCount--;
    printf("Product deleted successfully!\n");
}

void searchProduct() {
    char name[50];
    printf("Enter product name to search: ");
    scanf(" %[^\n]", name);
    
    int found = 0;
    printf("\n--- Search Results ---\n");
    for (int i = 0; i < productCount; i++) {
        if (strstr(inventory[i].name, name) != NULL) {
            printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
                   inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            found = 1;
        }
    }
    if (!found) {
        printf("No products found with that name.\n");
    }
}

int main() {
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: addProduct(); break;
            case 2: viewProducts(); break;
            case 3: updateProduct(); break;
            case 4: deleteProduct(); break;
            case 5: searchProduct(); break;
            case 6: printf("Exiting the program. Goodbye!\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}