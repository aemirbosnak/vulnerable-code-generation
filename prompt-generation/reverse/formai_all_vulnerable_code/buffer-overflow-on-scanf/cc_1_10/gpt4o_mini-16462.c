//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_SIZE 50

typedef struct Product {
    int id;
    char name[NAME_SIZE];
    int quantity;
    float price;
} Product;

void addProduct(Product *inventory, int *count) {
    if (*count >= MAX_PRODUCTS) {
        printf("Inventory is full, cannot add more products.\n");
        return;
    }
    Product newProduct;
    newProduct.id = *count + 1;

    printf("Enter product name: ");
    scanf(" %[^\n]", newProduct.name);

    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);

    printf("Enter price: ");
    scanf("%f", &newProduct.price);

    inventory[*count] = newProduct;
    (*count)++;
    printf("Product added successfully!\n");
}

void displayInventory(Product *inventory, int count) {
    if (count == 0) {
        printf("The inventory is currently empty.\n");
        return;
    }

    printf("\nProduct Inventory:\n");
    printf("ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void updateProduct(Product *inventory, int count) {
    int id;
    printf("Enter the product ID to update: ");
    scanf("%d", &id);

    if (id < 1 || id > count) {
        printf("Invalid product ID.\n");
        return;
    }

    Product *product = &inventory[id - 1];
    
    printf("Updating product: %s\n", product->name);
    printf("Enter new quantity (current: %d): ", product->quantity);
    scanf("%d", &product->quantity);

    printf("Enter new price (current: %.2f): ", product->price);
    scanf("%f", &product->price);
    
    printf("Product updated successfully!\n");
}

void removeProduct(Product *inventory, int *count) {
    int id;
    printf("Enter the product ID to remove: ");
    scanf("%d", &id);

    if (id < 1 || id > *count) {
        printf("Invalid product ID.\n");
        return;
    }

    for (int i = id - 1; i < *count - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    (*count)--;
    printf("Product removed successfully!\n");
}

void saveToFile(Product *inventory, int count) {
    FILE *file = fopen("inventory.txt", "w");
    if (!file) {
        printf("Could not open file to save inventory.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%d,%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    fclose(file);
    printf("Inventory saved to inventory.txt successfully!\n");
}

void loadFromFile(Product *inventory, int *count) {
    FILE *file = fopen("inventory.txt", "r");
    if (!file) {
        printf("No previous inventory file found. Starting with an empty inventory.\n");
        return;
    }
    while (fscanf(file, "%d,%49[^,],%d,%f\n", &inventory[*count].id, inventory[*count].name, &inventory[*count].quantity, &inventory[*count].price) == 4) {
        (*count)++;
    }
    fclose(file);
    printf("Inventory loaded successfully! Total products: %d\n", *count);
}

int main() {
    Product inventory[MAX_PRODUCTS];
    int productCount = 0;
    loadFromFile(inventory, &productCount);

    int choice;
    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n");
        printf("2. Display Inventory\n");
        printf("3. Update Product\n");
        printf("4. Remove Product\n");
        printf("5. Save Inventory to File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(inventory, &productCount);
                break;
            case 2:
                displayInventory(inventory, productCount);
                break;
            case 3:
                updateProduct(inventory, productCount);
                break;
            case 4:
                removeProduct(inventory, &productCount);
                break;
            case 5:
                saveToFile(inventory, productCount);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}