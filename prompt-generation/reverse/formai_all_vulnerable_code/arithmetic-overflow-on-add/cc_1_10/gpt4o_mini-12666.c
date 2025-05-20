//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float price;
    int quantity;
} Product;

typedef struct {
    Product products[MAX_PRODUCTS];
    int totalProducts;
} Inventory;

void addProduct(Inventory *inventory);
void listProducts(const Inventory *inventory);
void updateProduct(Inventory *inventory);
void deleteProduct(Inventory *inventory);
void saveToFile(const Inventory *inventory);
void loadFromFile(Inventory *inventory);
void displayMenu();

int main() {
    Inventory inventory = { .totalProducts = 0 };
    loadFromFile(&inventory);

    int choice;
    do {
        displayMenu();
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(&inventory);
                break;
            case 2:
                listProducts(&inventory);
                break;
            case 3:
                updateProduct(&inventory);
                break;
            case 4:
                deleteProduct(&inventory);
                break;
            case 5:
                saveToFile(&inventory);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

void displayMenu() {
    printf("\n--- Product Inventory System ---\n");
    printf("1. Add Product\n");
    printf("2. List Products\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Save Inventory to File\n");
    printf("6. Exit\n");
}

void addProduct(Inventory *inventory) {
    if (inventory->totalProducts >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }
    Product newProduct;
    newProduct.id = inventory->totalProducts + 1;

    printf("Enter product name: ");
    scanf(" %[^\n]", newProduct.name);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);

    inventory->products[inventory->totalProducts] = newProduct;
    inventory->totalProducts++;
    printf("Product added successfully.\n");
}

void listProducts(const Inventory *inventory) {
    printf("\n--- Product List ---\n");
    if (inventory->totalProducts == 0) {
        printf("No products in inventory.\n");
        return;
    }
    for (int i = 0; i < inventory->totalProducts; i++) {
        Product p = inventory->products[i];
        printf("ID: %d, Name: %s, Price: %.2f, Quantity: %d\n", p.id, p.name, p.price, p.quantity);
    }
}

void updateProduct(Inventory *inventory) {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    if (id < 1 || id > inventory->totalProducts) {
        printf("Invalid ID!\n");
        return;
    }
    Product *p = &inventory->products[id - 1];
    
    printf("Updating Product ID %d\n", p->id);
    printf("Current Name: %s\n", p->name);
    printf("Enter new name (or '-' to keep current): ");
    char newName[NAME_LENGTH];
    scanf(" %[^\n]", newName);
    if (strcmp(newName, "-") != 0) {
        strcpy(p->name, newName);
    }
    
    printf("Current Price: %.2f\n", p->price);
    printf("Enter new price (or -1 to keep current): ");
    float newPrice;
    scanf("%f", &newPrice);
    if (newPrice >= 0) {
        p->price = newPrice;
    }
    
    printf("Current Quantity: %d\n", p->quantity);
    printf("Enter new quantity (or -1 to keep current): ");
    int newQuantity;
    scanf("%d", &newQuantity);
    if (newQuantity >= 0) {
        p->quantity = newQuantity;
    }
    
    printf("Product updated successfully.\n");
}

void deleteProduct(Inventory *inventory) {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    if (id < 1 || id > inventory->totalProducts) {
        printf("Invalid ID!\n");
        return;
    }
    
    for (int i = id - 1; i < inventory->totalProducts - 1; i++) {
        inventory->products[i] = inventory->products[i + 1];
    }
    
    inventory->totalProducts--;
    printf("Product deleted successfully.\n");
}

void saveToFile(const Inventory *inventory) {
    FILE *file = fopen("inventory.txt", "w");
    if (!file) {
        printf("Error saving to file!\n");
        return;
    }
    for (int i = 0; i < inventory->totalProducts; i++) {
        Product p = inventory->products[i];
        fprintf(file, "%d,%s,%.2f,%d\n", p.id, p.name, p.price, p.quantity);
    }
    fclose(file);
    printf("Inventory saved to file successfully.\n");
}

void loadFromFile(Inventory *inventory) {
    FILE *file = fopen("inventory.txt", "r");
    if (!file) {
        printf("No existing inventory file found.\n");
        return;
    }
    while (fscanf(file, "%d,%49[^,],%f,%d\n", &inventory->products[inventory->totalProducts].id,
                  inventory->products[inventory->totalProducts].name,
                  &inventory->products[inventory->totalProducts].price,
                  &inventory->products[inventory->totalProducts].quantity) == 4) {
        inventory->totalProducts++;
    }
    fclose(file);
    printf("Inventory loaded from file successfully.\n");
}