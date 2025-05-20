//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: sophisticated
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

typedef struct {
    Product products[MAX_PRODUCTS];
    int count;
} Inventory;

void initializeInventory(Inventory* inventory) {
    inventory->count = 0;
}

void addProduct(Inventory* inventory) {
    if (inventory->count >= MAX_PRODUCTS) {
        printf("Inventory is full! Cannot add more products.\n");
        return;
    }
    
    Product newProduct;
    newProduct.id = inventory->count + 1;

    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    
    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);
    
    printf("Enter price: ");
    scanf("%f", &newProduct.price);
    
    inventory->products[inventory->count] = newProduct;
    inventory->count++;
    
    printf("Product %s added successfully!\n", newProduct.name);
}

void displayInventory(const Inventory* inventory) {
    if (inventory->count == 0) {
        printf("No products in inventory.\n");
        return;
    }

    printf("\nProduct Inventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("---------------------------------------------\n");

    for (int i = 0; i < inventory->count; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", 
               inventory->products[i].id, 
               inventory->products[i].name, 
               inventory->products[i].quantity, 
               inventory->products[i].price);
    }
    printf("---------------------------------------------\n");
}

void updateProduct(Inventory* inventory) {
    int id;
    printf("Enter the product id to update: ");
    scanf("%d", &id);

    if (id < 1 || id > inventory->count) {
        printf("Invalid product ID!\n");
        return;
    }

    Product* product = &inventory->products[id - 1];

    printf("Updating %s:\n", product->name);
    
    printf("Enter new quantity: ");
    scanf("%d", &product->quantity);

    printf("Enter new price: ");
    scanf("%f", &product->price);
    
    printf("Product %s updated successfully!\n", product->name);
}

void deleteProduct(Inventory* inventory) {
    int id;
    printf("Enter the product id to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > inventory->count) {
        printf("Invalid product ID!\n");
        return;
    }

    for (int i = id - 1; i < inventory->count - 1; i++) {
        inventory->products[i] = inventory->products[i + 1];
    }

    inventory->count--;
    printf("Product ID %d removed successfully!\n", id);
}

void menu() {
    printf("\nProduct Inventory System\n");
    printf("1. Add Product\n");
    printf("2. Display Inventory\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Inventory inventory;
    initializeInventory(&inventory);
    
    int choice;

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(&inventory);
                break;
            case 2:
                displayInventory(&inventory);
                break;
            case 3:
                updateProduct(&inventory);
                break;
            case 4:
                deleteProduct(&inventory);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}