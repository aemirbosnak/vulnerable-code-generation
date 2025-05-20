//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: automated
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

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct();
void displayProducts();
void updateProduct();
void deleteProduct();
void saveToFile();
void loadFromFile();
void menu();

int main() {
    loadFromFile();
    menu();
    return 0;
}

void menu() {
    int choice;
    do {
        printf("\n--- Product Inventory System ---\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Save and Exit\n");
        printf("6. Load Data\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addProduct(); break;
            case 2: displayProducts(); break;
            case 3: updateProduct(); break;
            case 4: deleteProduct(); break;
            case 5: saveToFile(); printf("Data saved.\n"); break;
            case 6: loadFromFile(); break;
            case 0: printf("Exiting the program...\n"); break;
            default: printf("Invalid choice, please try again.\n");
        }
    } while (choice != 0);
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory is full, cannot add more products.\n");
        return;
    }
    Product newProduct;
    newProduct.id = productCount + 1; // Simple ID assignment
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    
    inventory[productCount++] = newProduct;
    printf("Product added successfully!\n");
}

void displayProducts() {
    if (productCount == 0) {
        printf("No products in inventory.\n");
        return;
    }
    printf("\n--- Product List ---\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

void updateProduct() {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    
    if (id < 1 || id > productCount) {
        printf("Product ID not found.\n");
        return;
    }
    
    printf("Update name (current: %s): ", inventory[id - 1].name);
    scanf("%s", inventory[id - 1].name);
    printf("Update price (current: %.2f): ", inventory[id - 1].price);
    scanf("%f", &inventory[id - 1].price);
    printf("Update quantity (current: %d): ", inventory[id - 1].quantity);
    scanf("%d", &inventory[id - 1].quantity);
    
    printf("Product updated successfully!\n");
}

void deleteProduct() {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    
    if (id < 1 || id > productCount) {
        printf("Product ID not found.\n");
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
        printf("Unable to open file for writing.\n");
        return;
    }
    for (int i = 0; i < productCount; i++) {
        fprintf(file, "%d %s %f %d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
    fclose(file);
}

void loadFromFile() {
    FILE *file = fopen("inventory.txt", "r");
    if (!file) {
        printf("No previous inventory data found.\n");
        return;
    }
    productCount = 0;
    while (fscanf(file, "%d %s %f %d", &inventory[productCount].id, inventory[productCount].name, &inventory[productCount].price, &inventory[productCount].quantity) != EOF) {
        productCount++;
    }
    fclose(file);
    printf("Data loaded successfully!\n");
}