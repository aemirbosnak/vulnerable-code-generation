//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

typedef struct Product {
    int id;
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
} Product;

typedef struct Inventory {
    Product products[MAX_PRODUCTS];
    int count;
} Inventory;

void initialize_inventory(Inventory *inventory) {
    inventory->count = 0;
}

void add_product(Inventory *inventory) {
    if (inventory->count >= MAX_PRODUCTS) {
        printf("Inventory is full! Cannot add more products.\n");
        return;
    }

    Product new_product;

    printf("Enter Product ID: ");
    scanf("%d", &new_product.id);
    printf("Enter Product Name: ");
    scanf(" %[^\n]", new_product.name);
    printf("Enter Product Price: ");
    scanf("%f", &new_product.price);
    printf("Enter Product Quantity: ");
    scanf("%d", &new_product.quantity);

    inventory->products[inventory->count] = new_product;
    inventory->count++;

    printf("Product added successfully!\n");
}

void view_inventory(Inventory *inventory) {
    if (inventory->count == 0) {
        printf("The inventory is empty.\n");
        return;
    }

    printf("\nCurrent Inventory:\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    for (int i = 0; i < inventory->count; i++) {
        printf("%d\t%s\t%.2f\t%d\n", inventory->products[i].id, inventory->products[i].name, inventory->products[i].price, inventory->products[i].quantity);
    }
}

void update_product(Inventory *inventory) {
    int id, found = 0;

    printf("Enter Product ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < inventory->count; i++) {
        if (inventory->products[i].id == id) {
            found = 1;
            printf("Updating Product - %s:\n", inventory->products[i].name);
            printf("Enter new Price: ");
            scanf("%f", &inventory->products[i].price);
            printf("Enter new Quantity: ");
            scanf("%d", &inventory->products[i].quantity);
            printf("Product updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Product with ID %d not found.\n", id);
    }
}

void delete_product(Inventory *inventory) {
    int id, found = 0;

    printf("Enter Product ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < inventory->count; i++) {
        if (inventory->products[i].id == id) {
            found = 1;
            for (int j = i; j < inventory->count - 1; j++) {
                inventory->products[j] = inventory->products[j + 1];
            }
            inventory->count--;
            printf("Product with ID %d deleted successfully!\n", id);
            break;
        }
    }

    if (!found) {
        printf("Product with ID %d not found.\n", id);
    }
}

void save_inventory_to_file(Inventory *inventory) {
    FILE *file = fopen("inventory.dat", "wb");
    if (file == NULL) {
        printf("Could not open file for writing.\n");
        return;
    }
    
    fwrite(inventory, sizeof(Inventory), 1, file);
    fclose(file);
    printf("Inventory saved to inventory.dat\n");
}

void load_inventory_from_file(Inventory *inventory) {
    FILE *file = fopen("inventory.dat", "rb");
    if (file == NULL) {
        printf("Could not open file for reading. Starting with an empty inventory.\n");
        return;
    }
    
    fread(inventory, sizeof(Inventory), 1, file);
    fclose(file);
    printf("Inventory loaded from inventory.dat\n");
}

int main() {
    Inventory inventory;
    initialize_inventory(&inventory);
    
    load_inventory_from_file(&inventory);

    int choice;
    do {
        printf("\nInventory Management System\n");
        printf("1. Add Product\n");
        printf("2. View Inventory\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Save Inventory\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product(&inventory);
                break;
            case 2:
                view_inventory(&inventory);
                break;
            case 3:
                update_product(&inventory);
                break;
            case 4:
                delete_product(&inventory);
                break;
            case 5:
                save_inventory_to_file(&inventory);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);

    return 0;
}