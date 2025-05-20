//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Product;

typedef struct {
    Product items[MAX_ITEMS];
    int count;
} Inventory;

void initializeInventory(Inventory *inv) {
    inv->count = 0;
}

void addProduct(Inventory *inv) {
    if (inv->count >= MAX_ITEMS) {
        printf("Inventory is full! Cannot add more products.\n");
        return;
    }
    Product newProduct;
    
    printf("Enter Product ID: ");
    scanf("%d", &newProduct.id);
    
    printf("Enter Product Name: ");
    getchar(); // to clear the newline character from previous input
    fgets(newProduct.name, NAME_LENGTH, stdin);
    newProduct.name[strcspn(newProduct.name, "\n")] = 0; // Remove newline

    printf("Enter Product Quantity: ");
    scanf("%d", &newProduct.quantity);
    
    printf("Enter Product Price: ");
    scanf("%f", &newProduct.price);
    
    inv->items[inv->count] = newProduct;
    inv->count++;
    
    printf("Product added successfully!\n");
}

void viewProducts(const Inventory *inv) {
    if (inv->count == 0) {
        printf("Inventory is empty!\n");
        return;
    }
    
    printf("\nProduct List:\n");
    for (int i = 0; i < inv->count; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", 
            inv->items[i].id, inv->items[i].name, inv->items[i].quantity, inv->items[i].price);
    }
}

void updateProduct(Inventory *inv) {
    int id;
    printf("Enter Product ID to update: ");
    scanf("%d", &id);
    
    for (int i = 0; i < inv->count; i++) {
        if (inv->items[i].id == id) {
            printf("Update Product Name (current: %s): ", inv->items[i].name);
            getchar(); // To clear newline
            fgets(inv->items[i].name, NAME_LENGTH, stdin);
            inv->items[i].name[strcspn(inv->items[i].name, "\n")] = 0; // Remove newline

            printf("Update Product Quantity (current: %d): ", inv->items[i].quantity);
            scanf("%d", &inv->items[i].quantity);
            
            printf("Update Product Price (current: %.2f): ", inv->items[i].price);
            scanf("%f", &inv->items[i].price);
            
            printf("Product updated successfully!\n");
            return;
        }
    }
    printf("Product with ID %d not found!\n", id);
}

void deleteProduct(Inventory *inv) {
    int id;
    printf("Enter Product ID to delete: ");
    scanf("%d", &id);
    
    for (int i = 0; i < inv->count; i++) {
        if (inv->items[i].id == id) {
            for (int j = i; j < inv->count - 1; j++) {
                inv->items[j] = inv->items[j + 1]; // Shift items left
            }
            inv->count--;
            printf("Product deleted successfully!\n");
            return;
        }
    }
    printf("Product with ID %d not found!\n", id);
}

int main() {
    Inventory inventory;
    initializeInventory(&inventory);
    
    int choice;

    while (1) {
        printf("\n--- Inventory System ---\n");
        printf("1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addProduct(&inventory);
                break;
            case 2:
                viewProducts(&inventory);
                break;
            case 3:
                updateProduct(&inventory);
                break;
            case 4:
                deleteProduct(&inventory);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }
    }
    
    return 0;
}