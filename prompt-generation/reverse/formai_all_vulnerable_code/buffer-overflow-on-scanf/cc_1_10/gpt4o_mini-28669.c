//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory is full. Cannot add more products.\n");
        return;
    }
    
    Product p;
    p.id = productCount + 1; // Simple ID assignment
    
    printf("Enter product name: ");
    scanf("%s", p.name);
    
    printf("Enter product price: ");
    scanf("%f", &p.price);
    
    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);
    
    inventory[productCount++] = p;
    printf("Product added successfully!\n");
}

void displayProducts() {
    if (productCount == 0) {
        printf("No products available in the inventory.\n");
        return;
    }
    
    printf("\nProduct Inventory:\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    printf("---------------------------------------\n");
    
    for (int i = 0; i < productCount; i++) {
        printf("%d\t%-15s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

void updateProduct() {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    
    if (id < 1 || id > productCount) {
        printf("Invalid product ID.\n");
        return;
    }
    
    Product *p = &inventory[id - 1];
    printf("Updating product: %s\n", p->name);
    
    printf("Enter new price: ");
    scanf("%f", &p->price);
    
    printf("Enter new quantity: ");
    scanf("%d", &p->quantity);
    
    printf("Product updated successfully!\n");
}

void deleteProduct() {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    
    if (id < 1 || id > productCount) {
        printf("Invalid product ID.\n");
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
    scanf("%s", name);
    
    int found = 0;
    printf("\nSearch Results:\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    printf("---------------------------------------\n");
    
    for (int i = 0; i < productCount; i++) {
        if (strstr(inventory[i].name, name) != NULL) {
            printf("%d\t%-15s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No products found with the name '%s'.\n", name);
    }
}

void displayMenu() {
    printf("\nProduct Inventory System\n");
    printf("1. Add Product\n");
    printf("2. Display Products\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Search Product\n");
    printf("6. Exit\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                updateProduct();
                break;
            case 4:
                deleteProduct();
                break;
            case 5:
                searchProduct();
                break;
            case 6:
                printf("Exiting... Thank you for using the Product Inventory System.\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }
    }

    return 0;
}