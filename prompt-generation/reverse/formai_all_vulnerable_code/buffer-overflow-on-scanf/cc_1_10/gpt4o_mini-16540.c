//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: realistic
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

// Function prototypes
void addProduct();
void viewProducts();
void updateProduct();
void deleteProduct();
void searchProduct();
void displayMenu();

int main() {
    int choice;
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addProduct(); break;
            case 2: viewProducts(); break;
            case 3: updateProduct(); break;
            case 4: deleteProduct(); break;
            case 5: searchProduct(); break;
            case 6: printf("Exiting the program.\n"); break;
            default: printf("Invalid choice! Please try again.\n"); break;
        }
    } while (choice != 6);
    
    return 0;
}

void displayMenu() {
    printf("\n");
    printf("=== Product Inventory System ===\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Search Product\n");
    printf("6. Exit\n");
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory is full! Cannot add more products.\n");
        return;
    }
    
    Product p;
    p.id = productCount + 1; // Simple ID assignment
    printf("Enter product name: ");
    scanf("%s", p.name);
    printf("Enter quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter price: ");
    scanf("%f", &p.price);
    
    inventory[productCount] = p;
    productCount++;
    
    printf("Product added successfully! ID: %d\n", p.id);
}

void viewProducts() {
    if (productCount == 0) {
        printf("No products in inventory.\n");
        return;
    }
    
    printf("\nCurrent Inventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < productCount; i++) {
        Product p = inventory[i];
        printf("%d\t%s\t\t%d\t\t%.2f\n", p.id, p.name, p.quantity, p.price);
    }
}

void updateProduct() {
    int id, found = 0;
    
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            found = 1;
            printf("Updating Product ID: %d\n", id);
            printf("Enter new product name: ");
            scanf("%s", inventory[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Product updated successfully!\n");
            break;
        }
    }
    
    if (!found) {
        printf("Product with ID %d not found!\n", id);
    }
}

void deleteProduct() {
    int id, found = 0;
    
    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            found = 1;
            for (int j = i; j < productCount - 1; j++) {
                inventory[j] = inventory[j + 1]; // Shift products down
            }
            productCount--;
            printf("Product with ID %d deleted successfully!\n", id);
            break;
        }
    }
    
    if (!found) {
        printf("Product with ID %d not found!\n", id);
    }
}

void searchProduct() {
    char name[NAME_LENGTH];
    int found = 0;

    printf("Enter product name to search: ");
    scanf("%s", name);
    
    printf("\nSearch Results:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            found = 1;
            Product p = inventory[i];
            printf("%d\t%s\t\t%d\t\t%.2f\n", p.id, p.name, p.quantity, p.price);
        }
    }
    
    if (!found) {
        printf("No products found with the name '%s'.\n", name);
    }
}