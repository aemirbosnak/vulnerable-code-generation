//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: happy
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

void addProduct(Product* inventory, int* count);
void displayProducts(Product* inventory, int count);
void updateProduct(Product* inventory, int count);
void deleteProduct(Product* inventory, int* count);
void saveInventory(Product* inventory, int count);
void loadInventory(Product* inventory, int* count);

int main() {
    Product inventory[MAX_PRODUCTS];
    int count = 0;
    int choice;

    loadInventory(inventory, &count);

    do {
        printf("\nWelcome to the Happy Product Inventory System!\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Save and Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(inventory, &count);
                break;
            case 2:
                displayProducts(inventory, count);
                break;
            case 3:
                updateProduct(inventory, count);
                break;
            case 4:
                deleteProduct(inventory, &count);
                break;
            case 5:
                saveInventory(inventory, count);
                printf("Thank you for using the Happy Product Inventory System! Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addProduct(Product* inventory, int* count) {
    if (*count >= MAX_PRODUCTS) {
        printf("Inventory is full! Please delete a product before adding a new one.\n");
        return;
    }
    Product newProduct;
    newProduct.id = *count + 1;
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    
    inventory[*count] = newProduct;
    (*count)++;
    printf("Product added successfully!\n");
}

void displayProducts(Product* inventory, int count) {
    if (count == 0) {
        printf("No products in inventory yet!\n");
        return;
    }
    printf("\nCurrent Inventory:\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

void updateProduct(Product* inventory, int count) {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    
    if (id <= 0 || id > count) {
        printf("Invalid product ID! Please try again.\n");
        return;
    }

    Product* product = &inventory[id - 1];
    printf("Updating product: %s, Price: %.2f, Quantity: %d\n", product->name, product->price, product->quantity);
    
    printf("Enter new product name (current: %s): ", product->name);
    scanf("%s", product->name);
    printf("Enter new product price (current: %.2f): ", product->price);
    scanf("%f", &product->price);
    printf("Enter new product quantity (current: %d): ", product->quantity);
    scanf("%d", &product->quantity);
    
    printf("Product updated successfully!\n");
}

void deleteProduct(Product* inventory, int* count) {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    
    if (id <= 0 || id > *count) {
        printf("Invalid product ID! Please try again.\n");
        return;
    }

    for (int i = id - 1; i < *count - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    (*count)--;
    printf("Product deleted successfully!\n");
}

void saveInventory(Product* inventory, int count) {
    FILE* file = fopen("inventory.txt", "w");
    if (file == NULL) {
        printf("Could not save inventory!\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s %.2f %d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }

    fclose(file);
    printf("Inventory saved successfully!\n");
}

void loadInventory(Product* inventory, int* count) {
    FILE* file = fopen("inventory.txt", "r");
    if (file != NULL) {
        while (fscanf(file, "%d %s %f %d", &inventory[*count].id,
                      inventory[*count].name, 
                      &inventory[*count].price, 
                      &inventory[*count].quantity) != EOF) {
            (*count)++;
        }
        fclose(file);
        printf("Inventory loaded successfully!\n");
    } else {
        printf("No previous inventory found. Starting a new one!\n");
    }
}