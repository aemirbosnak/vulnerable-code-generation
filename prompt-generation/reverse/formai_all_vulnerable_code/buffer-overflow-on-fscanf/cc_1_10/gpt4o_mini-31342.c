//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50
#define DESCRIPTION_LENGTH 200

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char description[DESCRIPTION_LENGTH];
    float price;
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct();
void displayProducts();
void editProduct();
void deleteProduct();
void saveToFile();
void loadFromFile();

int main() {
    int choice;

    loadFromFile();

    while (1) {
        printf("\n--- Product Inventory System ---\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Edit Product\n");
        printf("4. Delete Product\n");
        printf("5. Save to File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                editProduct();
                break;
            case 4:
                deleteProduct();
                break;
            case 5:
                saveToFile();
                break;
            case 6:
                saveToFile();
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }

    Product newProduct;
    newProduct.id = productCount + 1;  // ID is sequential
    printf("Enter product name: ");
    scanf(" %[^\n]", newProduct.name);
    printf("Enter product description: ");
    scanf(" %[^\n]", newProduct.description);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);

    inventory[productCount++] = newProduct;
    printf("Product added successfully!\n");
}

void displayProducts() {
    if (productCount == 0) {
        printf("No products in the inventory.\n");
        return;
    }

    printf("\n--- Product List ---\n");
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d\n", inventory[i].id);
        printf("Name: %s\n", inventory[i].name);
        printf("Description: %s\n", inventory[i].description);
        printf("Price: %.2f\n", inventory[i].price);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("--------------------\n");
    }
}

void editProduct() {
    int id;
    printf("Enter product ID to edit: ");
    scanf("%d", &id);

    if (id < 1 || id > productCount) {
        printf("Invalid product ID.\n");
        return;
    }

    Product *product = &inventory[id - 1];
    printf("Editing product: %s\n", product->name);
    printf("Re-enter product name (or press ENTER to keep current): ");
    char buffer[NAME_LENGTH];
    fgets(buffer, NAME_LENGTH, stdin);
    if (strlen(buffer) > 1) {
        sscanf(buffer, "%[^\n]", product->name);
    }
    printf("Re-enter product description (or press ENTER to keep current): ");
    fgets(buffer, DESCRIPTION_LENGTH, stdin);
    if (strlen(buffer) > 1) {
        sscanf(buffer, "%[^\n]", product->description);
    }
    printf("Re-enter product price (or -1 to keep current): ");
    float newPrice;
    scanf("%f", &newPrice);
    if (newPrice >= 0) {
        product->price = newPrice;
    }
    printf("Re-enter product quantity (or -1 to keep current): ");
    int newQuantity;
    scanf("%d", &newQuantity);
    if (newQuantity >= 0) {
        product->quantity = newQuantity;
    }

    printf("Product updated successfully!\n");
}

void deleteProduct() {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > productCount) {
        printf("Invalid product ID.\n");
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
        printf("Unable to save inventory.\n");
        return;
    }

    for (int i = 0; i < productCount; i++) {
        fprintf(file, "%d\n%s\n%s\n%.2f\n%d\n",
                inventory[i].id,
                inventory[i].name,
                inventory[i].description,
                inventory[i].price,
                inventory[i].quantity);
    }
    fclose(file);
    printf("Inventory saved to file successfully!\n");
}

void loadFromFile() {
    FILE *file = fopen("inventory.txt", "r");
    if (!file) {
        return; // File doesn't exist yet, ignore
    }

    while (fscanf(file, "%d\n%[^\n]\n%[^\n]\n%f\n%d\n",
                  &inventory[productCount].id,
                  inventory[productCount].name,
                  inventory[productCount].description,
                  &inventory[productCount].price,
                  &inventory[productCount].quantity) != EOF) {
        productCount++;
    }
    fclose(file);
    printf("Inventory loaded from file successfully!\n");
}