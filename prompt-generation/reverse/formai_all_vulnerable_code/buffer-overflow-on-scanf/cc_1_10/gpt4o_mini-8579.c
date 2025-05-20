//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: ultraprecise
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

void initialize_inventory(Inventory *inventory) {
    inventory->count = 0;
}

void add_product(Inventory *inventory) {
    if (inventory->count >= MAX_PRODUCTS) {
        printf("Inventory is full. Cannot add more products.\n");
        return;
    }
    
    Product new_product;
    printf("Enter product ID: ");
    scanf("%d", &new_product.id);
    printf("Enter product name: ");
    getchar(); // clear buffer
    fgets(new_product.name, NAME_LENGTH, stdin);
    new_product.name[strcspn(new_product.name, "\n")] = 0; // remove newline
    printf("Enter product quantity: ");
    scanf("%d", &new_product.quantity);
    printf("Enter product price: ");
    scanf("%f", &new_product.price);
    
    inventory->products[inventory->count] = new_product;
    inventory->count++;
    printf("Product added successfully!\n");
}

void view_products(const Inventory *inventory) {
    if (inventory->count == 0) {
        printf("No products in inventory.\n");
        return;
    }

    printf("\nProduct Inventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("-------------------------------------------\n");
    
    for (int i = 0; i < inventory->count; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", 
            inventory->products[i].id, 
            inventory->products[i].name, 
            inventory->products[i].quantity, 
            inventory->products[i].price);
    }
}

void update_product(Inventory *inventory) {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    
    for (int i = 0; i < inventory->count; i++) {
        if (inventory->products[i].id == id) {
            printf("Updating product: %s\n", inventory->products[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &inventory->products[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory->products[i].price);
            printf("Product updated successfully!\n");
            return;
        }
    }
    printf("Product with ID %d not found.\n", id);
}

void delete_product(Inventory *inventory) {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < inventory->count; i++) {
        if (inventory->products[i].id == id) {
            for (int j = i; j < inventory->count - 1; j++) {
                inventory->products[j] = inventory->products[j + 1];
            }
            inventory->count--;
            printf("Product deleted successfully!\n");
            return;
        }
    }
    printf("Product with ID %d not found.\n", id);
}

void save_inventory(const Inventory *inventory) {
    FILE *file = fopen("inventory.txt", "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }

    fwrite(inventory, sizeof(Inventory), 1, file);
    fclose(file);
    printf("Inventory saved to inventory.txt successfully!\n");
}

void load_inventory(Inventory *inventory) {
    FILE *file = fopen("inventory.txt", "r");
    if (!file) {
        printf("No saved inventory found. Starting fresh.\n");
        return;
    }

    fread(inventory, sizeof(Inventory), 1, file);
    fclose(file);
    printf("Inventory loaded from inventory.txt successfully!\n");
}

int main() {
    Inventory inventory;
    initialize_inventory(&inventory);
    load_inventory(&inventory);

    int choice;
    do {
        printf("\n--- Product Inventory System ---\n");
        printf("1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Save Inventory\n");
        printf("6. Exit\n");
        printf("Please select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_product(&inventory); break;
            case 2: view_products(&inventory); break;
            case 3: update_product(&inventory); break;
            case 4: delete_product(&inventory); break;
            case 5: save_inventory(&inventory); break;
            case 6: printf("Exiting the program. Thank you!\n"); break;
            default: printf("Invalid option. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}