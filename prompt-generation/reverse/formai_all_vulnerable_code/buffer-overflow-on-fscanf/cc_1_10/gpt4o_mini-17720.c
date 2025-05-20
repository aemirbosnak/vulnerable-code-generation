//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LEN 50

typedef struct {
    int id;
    char name[NAME_LEN];
    int quantity;
    float price;
} Product;

void addProduct(Product *inventory, int *count) {
    if (*count >= MAX_PRODUCTS) {
        printf("Inventory is full. Cannot add more products.\n");
        return;
    }
    Product newProduct;
    newProduct.id = *count + 1; // simple increment id
    printf("Enter product name: ");
    fgets(newProduct.name, NAME_LEN, stdin);
    newProduct.name[strcspn(newProduct.name, "\n")] = 0; // Removing newline character
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    while (getchar() != '\n'); // clear buffer after scanf
    inventory[*count] = newProduct;
    (*count)++;
    printf("Product added successfully!\n\n");
}

void displayInventory(Product *inventory, int count) {
    if (count == 0) {
        printf("Inventory is empty.\n\n");
        return;
    }
    printf("Current Inventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("----------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("\n");
}

void updateProduct(Product *inventory, int count) {
    int id;
    printf("Enter the product ID to update: ");
    scanf("%d", &id);
    while (getchar() != '\n'); // clear buffer after scanf

    if (id < 1 || id > count) {
        printf("Invalid product ID!\n\n");
        return;
    }
    
    Product *product = &inventory[id - 1]; // Adjusting index
    printf("Updating product: %s\n", product->name);
    printf("Enter new quantity: ");
    scanf("%d", &product->quantity);
    printf("Enter new price: ");
    scanf("%f", &product->price);
    while (getchar() != '\n'); // clear buffer after scanf
    printf("Product updated successfully!\n\n");
}

void deleteProduct(Product *inventory, int *count) {
    int id;
    printf("Enter the product ID to delete: ");
    scanf("%d", &id);
    while (getchar() != '\n'); // clear buffer after scanf

    if (id < 1 || id > *count) {
        printf("Invalid product ID!\n\n");
        return;
    }

    *count -= 1;
    for (int i = id - 1; i < *count; i++) {
        inventory[i] = inventory[i + 1];
    }
    printf("Product deleted successfully!\n\n");
}

void saveInventory(Product *inventory, int count) {
    FILE *file = fopen("inventory.txt", "w");
    if (file == NULL) {
        printf("Could not open file for writing.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%d,%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }

    fclose(file);
    printf("Inventory saved to inventory.txt.\n\n");
}

void loadInventory(Product *inventory, int *count) {
    FILE *file = fopen("inventory.txt", "r");
    if (file == NULL) {
        printf("No saved inventory found.\n");
        return;
    }

    while (fscanf(file, "%d,%49[^,],%d,%f\n", &inventory[*count].id, inventory[*count].name, &inventory[*count].quantity, &inventory[*count].price) == 4) {
        (*count)++;
    }

    fclose(file);
    printf("Inventory loaded successfully.\n\n");
}

int main() {
    Product inventory[MAX_PRODUCTS];
    int count = 0;
    int choice;

    loadInventory(inventory, &count);

    do {
        printf("Product Inventory System\n");
        printf("1. Add Product\n");
        printf("2. Display Inventory\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Save Inventory\n");
        printf("6. Load Inventory\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n'); // clear buffer after scanf

        switch (choice) {
            case 1:
                addProduct(inventory, &count);
                break;
            case 2:
                displayInventory(inventory, count);
                break;
            case 3:
                updateProduct(inventory, count);
                break;
            case 4:
                deleteProduct(inventory, &count);
                break;
            case 5:
                saveInventory(inventory, count);
                break;
            case 6:
                loadInventory(inventory, &count);
                break;
            case 0:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n\n");
                break;
        }
    } while (choice != 0);

    return 0;
}