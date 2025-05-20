//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: safe
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

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory is full! Cannot add more products.\n");
        return;
    }

    Product newProduct;
    printf("Enter product ID: ");
    scanf("%d", &newProduct.id);
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    
    inventory[productCount++] = newProduct;
    printf("Product added successfully!\n");
}

void viewProducts() {
    if (productCount == 0) {
        printf("No products in the inventory!\n");
        return;
    }

    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void updateProduct() {
    int id;
    printf("Enter the product ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            printf("Updating product: %s\n", inventory[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Product updated successfully!\n");
            return;
        }
    }
    printf("Product not found!\n");
}

void deleteProduct() {
    int id;
    printf("Enter the product ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            for (int j = i; j < productCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            productCount--;
            printf("Product deleted successfully!\n");
            return;
        }
    }
    printf("Product not found!\n");
}

void saveToFile() {
    FILE *file = fopen("inventory.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    
    for (int i = 0; i < productCount; i++) {
        fprintf(file, "%d %s %d %.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    
    fclose(file);
    printf("Inventory saved to file successfully!\n");
}

void loadFromFile() {
    FILE *file = fopen("inventory.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading! File may not exist.\n");
        return;
    }
    
    while (fscanf(file, "%d %s %d %f", &inventory[productCount].id, inventory[productCount].name, &inventory[productCount].quantity, &inventory[productCount].price) != EOF) {
        productCount++;
        if (productCount >= MAX_PRODUCTS) {
            printf("Reached product limit while loading from file!\n");
            break;
        }
    }
    
    fclose(file);
    printf("Inventory loaded from file successfully!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Save to File\n");
        printf("6. Load from File\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addProduct(); break;
            case 2: viewProducts(); break;
            case 3: updateProduct(); break;
            case 4: deleteProduct(); break;
            case 5: saveToFile(); break;
            case 6: loadFromFile(); break;
            case 7: 
                printf("Exiting the program.\n");
                exit(0);
            default: printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}