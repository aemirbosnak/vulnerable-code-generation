//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: genius
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
        printf("Inventory full! Cannot add more products.\n");
        return;
    }
    
    Product newProduct;
    newProduct.id = productCount + 1;  // Simple ID assignment
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    
    inventory[productCount] = newProduct;
    productCount++;
    printf("Product added successfully!\n");
}

void displayProducts() {
    printf("\n--- Product Inventory ---\n");
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d\n", inventory[i].id);
        printf("Name: %s\n", inventory[i].name);
        printf("Price: $%.2f\n", inventory[i].price);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("-------------------------\n");
    }
}

void updateProduct() {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    
    if (id <= 0 || id > productCount) {
        printf("Invalid product ID!\n");
        return;
    }
    
    Product *p = &inventory[id - 1];
    printf("Updating product: %s\n", p->name);
    printf("Enter new name (current: %s): ", p->name);
    scanf("%s", p->name);
    printf("Enter new price (current: $%.2f): ", p->price);
    scanf("%f", &p->price);
    printf("Enter new quantity (current: %d): ", p->quantity);
    scanf("%d", &p->quantity);
    
    printf("Product updated successfully!\n");
}

void deleteProduct() {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    
    if (id <= 0 || id > productCount) {
        printf("Invalid product ID!\n");
        return;
    }
    
    for (int i = id - 1; i < productCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    productCount--;
    
    printf("Product deleted successfully!\n");
}

void saveToFile() {
    FILE *file = fopen("inventory.txt", "w");
    if (!file) {
        printf("Unable to open file for writing!\n");
        return;
    }
    
    for (int i = 0; i < productCount; i++) {
        fprintf(file, "%d %s %.2f %d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
    
    fclose(file);
    printf("Inventory saved to file.\n");
}

void loadFromFile() {
    FILE *file = fopen("inventory.txt", "r");
    if (!file) {
        printf("No inventory file found.\n");
        return;
    }
    
    while (fscanf(file, "%d %s %f %d", &inventory[productCount].id, inventory[productCount].name, &inventory[productCount].price, &inventory[productCount].quantity) != EOF) {
        productCount++;
        if (productCount >= MAX_PRODUCTS) break;
    }
    
    fclose(file);
    printf("Inventory loaded from file.\n");
}

int main() {
    int choice;
    loadFromFile();
    
    do {
        printf("\n--- Product Inventory System ---\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Save Inventory\n");
        printf("6. Load Inventory\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
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
                saveToFile();
                break;
            case 6:
                loadFromFile();
                break;
            case 7:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);
    
    return 0;
}