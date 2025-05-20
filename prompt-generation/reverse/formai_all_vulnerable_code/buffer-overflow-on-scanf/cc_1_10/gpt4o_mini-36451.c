//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: mathematical
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

typedef struct {
    Product products[MAX_PRODUCTS];
    int count;
} Inventory;

// Function declarations
void initializeInventory(Inventory *inv);
void addProduct(Inventory *inv);
void removeProduct(Inventory *inv);
void displayInventory(const Inventory *inv);
void updateProduct(Inventory *inv);
void searchProduct(const Inventory *inv);
void saveInventory(const Inventory *inv);
void loadInventory(Inventory *inv);

int main() {
    Inventory inventory;
    initializeInventory(&inventory);
    
    int choice;

    do {
        printf("\n=== Inventory Management System ===\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Display Products\n");
        printf("4. Update Product\n");
        printf("5. Search Product\n");
        printf("6. Save Inventory\n");
        printf("7. Load Inventory\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(&inventory);
                break;
            case 2:
                removeProduct(&inventory);
                break;
            case 3:
                displayInventory(&inventory);
                break;
            case 4:
                updateProduct(&inventory);
                break;
            case 5:
                searchProduct(&inventory);
                break;
            case 6:
                saveInventory(&inventory);
                break;
            case 7:
                loadInventory(&inventory);
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void initializeInventory(Inventory *inv) {
    inv->count = 0;
}

void addProduct(Inventory *inv) {
    if (inv->count < MAX_PRODUCTS) {
        Product newProduct;

        newProduct.id = inv->count + 1; // New id based on current count
        printf("Enter product name: ");
        scanf(" %[^\n]", newProduct.name);
        printf("Enter product price: ");
        scanf("%f", &newProduct.price);
        printf("Enter product quantity: ");
        scanf("%d", &newProduct.quantity);

        inv->products[inv->count] = newProduct;
        inv->count++;
        printf("Product added successfully! ID: %d\n", newProduct.id);
    } else {
        printf("Inventory is full! Cannot add more products.\n");
    }
}

void removeProduct(Inventory *inv) {
    int id;
    printf("Enter product ID to remove: ");
    scanf("%d", &id);

    if (id < 1 || id > inv->count) {
        printf("Product ID not found!\n");
        return;
    }

    for (int i = id - 1; i < inv->count - 1; i++) {
        inv->products[i] = inv->products[i + 1];
    }
    inv->count--;
    printf("Product ID %d removed successfully!\n", id);
}

void displayInventory(const Inventory *inv) {
    printf("\nProduct Inventory:\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < inv->count; i++) {
        printf("%d\t%s\t%.2f\t%d\n", inv->products[i].id, 
            inv->products[i].name, inv->products[i].price, 
            inv->products[i].quantity);
    }
}

void updateProduct(Inventory *inv) {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);

    if (id < 1 || id > inv->count) {
        printf("Product ID not found!\n");
        return;
    }

    Product *p = &inv->products[id - 1];
    printf("Updating product ID %d:\n", id);
    printf("Current Name: %s, Enter new name (leave blank to keep unchanged): ", p->name);
    char newName[50];
    scanf(" %[^\n]", newName);
    if (strlen(newName) > 0) {
        strcpy(p->name, newName);
    }

    printf("Current Price: %.2f, Enter new price (enter -1 to keep unchanged): ", p->price);
    float newPrice;
    scanf("%f", &newPrice);
    if (newPrice >= 0) {
        p->price = newPrice;
    }

    printf("Current Quantity: %d, Enter new quantity (enter -1 to keep unchanged): ", p->quantity);
    int newQuantity;
    scanf("%d", &newQuantity);
    if (newQuantity >= 0) {
        p->quantity = newQuantity;
    }

    printf("Product updated successfully!\n");
}

void searchProduct(const Inventory *inv) {
    char name[50];
    printf("Enter product name to search: ");
    scanf(" %[^\n]", name);

    printf("\nSearch Results:\n");
    for (int i = 0; i < inv->count; i++) {
        if (strstr(inv->products[i].name, name) != NULL) {
            printf("ID: %d, Name: %s, Price: %.2f, Quantity: %d\n", 
                inv->products[i].id, inv->products[i].name, 
                inv->products[i].price, inv->products[i].quantity);
        }
    }
}

void saveInventory(const Inventory *inv) {
    FILE *file = fopen("inventory.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    for (int i = 0; i < inv->count; i++) {
        fprintf(file, "%d,%s,%.2f,%d\n", 
            inv->products[i].id, inv->products[i].name, 
            inv->products[i].price, inv->products[i].quantity);
    }

    fclose(file);
    printf("Inventory saved successfully to inventory.txt!\n");
}

void loadInventory(Inventory *inv) {
    FILE *file = fopen("inventory.txt", "r");
    if (file == NULL) {
        printf("No saved inventory found! Starting with an empty inventory.\n");
        return;
    }

    while (inv->count < MAX_PRODUCTS && fscanf(file, "%d,%49[^,],%f,%d\n", 
        &inv->products[inv->count].id, inv->products[inv->count].name, 
        &inv->products[inv->count].price, &inv->products[inv->count].quantity) == 4) {
        inv->count++;
    }

    fclose(file);
    printf("Inventory loaded successfully! Total products: %d\n", inv->count);
}