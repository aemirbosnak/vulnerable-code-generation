//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: expert-level
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

void addProduct(Product* inventory, int* numProducts) {
    if (*numProducts >= MAX_PRODUCTS) {
        printf("Inventory full, cannot add more products.\n");
        return;
    }

    Product newProduct;
    newProduct.id = *numProducts + 1; // Simple ID assignment
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    
    inventory[*numProducts] = newProduct;
    (*numProducts)++;
    printf("Product added successfully!\n");
}

void viewProducts(Product* inventory, int numProducts) {
    if (numProducts == 0) {
        printf("No products in inventory.\n");
        return;
    }

    printf("\nCurrent Inventory:\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%d\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
    printf("\n");
}

void updateProduct(Product* inventory, int numProducts) {
    int id, found = 0;
    printf("Enter product ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < numProducts; i++) {
        if (inventory[i].id == id) {
            found = 1;
            printf("Updating product: %s\n", inventory[i].name);
            printf("Enter new name (or '.' to skip): ");
            char newName[50];
            scanf("%s", newName);
            if (strcmp(newName, ".") != 0) {
                strcpy(inventory[i].name, newName);
            }
            printf("Enter new price (or -1 to skip): ");
            float newPrice;
            scanf("%f", &newPrice);
            if (newPrice >= 0) {
                inventory[i].price = newPrice;
            }
            printf("Enter new quantity (or -1 to skip): ");
            int newQuantity;
            scanf("%d", &newQuantity);
            if (newQuantity >= 0) {
                inventory[i].quantity = newQuantity;
            }
            printf("Product updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Product with ID %d not found.\n", id);
    }
}

void deleteProduct(Product* inventory, int* numProducts) {
    int id, found = 0;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *numProducts; i++) {
        if (inventory[i].id == id) {
            found = 1;
            for (int j = i; j < *numProducts - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            (*numProducts)--;
            printf("Product deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Product with ID %d not found.\n", id);
    }
}

void saveToFile(Product* inventory, int numProducts) {
    FILE* file = fopen("inventory.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < numProducts; i++) {
        fprintf(file, "%d %s %.2f %d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
    fclose(file);
    printf("Inventory saved to inventory.txt\n");
}

void loadFromFile(Product* inventory, int* numProducts) {
    FILE* file = fopen("inventory.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading. Starting with an empty inventory.\n");
        return;
    }

    while (fscanf(file, "%d %s %f %d", &inventory[*numProducts].id, inventory[*numProducts].name,
                  &inventory[*numProducts].price, &inventory[*numProducts].quantity) != EOF) {
        (*numProducts)++;
    }
    fclose(file);
    printf("Inventory loaded from inventory.txt\n");
}

int main() {
    Product inventory[MAX_PRODUCTS];
    int numProducts = 0, choice;

    loadFromFile(inventory, &numProducts);
    
    do {
        printf("\n--- Inventory Menu ---\n");
        printf("1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Save Inventory\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(inventory, &numProducts);
                break;
            case 2:
                viewProducts(inventory, numProducts);
                break;
            case 3:
                updateProduct(inventory, numProducts);
                break;
            case 4:
                deleteProduct(inventory, &numProducts);
                break;
            case 5:
                saveToFile(inventory, numProducts);
                break;
            case 6:
                printf("Exiting the inventory system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}