//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: curious
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
    if (productCount < MAX_PRODUCTS) {
        Product p;
        p.id = productCount + 1;

        printf("Enter product name: ");
        scanf("%s", p.name);
        printf("Enter product quantity: ");
        scanf("%d", &p.quantity);
        printf("Enter product price: ");
        scanf("%f", &p.price);

        inventory[productCount++] = p;
        printf("Product added successfully!\n");
    } else {
        printf("Inventory full! Cannot add more products.\n");
    }
}

void viewProducts() {
    if (productCount == 0) {
        printf("No products in inventory!\n");
        return;
    }

    printf("\nProduct Inventory:\n");
    printf("ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void updateProduct() {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);

    if (id <= 0 || id > productCount) {
        printf("Product not found!\n");
        return;
    }
    
    int index = id - 1;
    printf("Updating product: %s\n", inventory[index].name);
    printf("Enter new name (or press Enter to keep current): ");
    char newName[NAME_LENGTH];
    fgets(newName, NAME_LENGTH, stdin); // To consume newline from previous scanf
    fgets(newName, NAME_LENGTH, stdin);
    if (strlen(newName) > 1) {
        newName[strcspn(newName, "\n")] = 0; // remove newline
        strcpy(inventory[index].name, newName);
    }

    int newQuantity;
    printf("Enter new quantity (or -1 to keep current): ");
    scanf("%d", &newQuantity);
    if (newQuantity != -1) {
        inventory[index].quantity = newQuantity;
    }

    float newPrice;
    printf("Enter new price (or -1 to keep current): ");
    scanf("%f", &newPrice);
    if (newPrice != -1) {
        inventory[index].price = newPrice;
    }

    printf("Product updated successfully!\n");
}

void deleteProduct() {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    if (id <= 0 || id > productCount) {
        printf("Product not found!\n");
        return;
    }

    for (int i = id - 1; i < productCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }

    productCount--;
    printf("Product deleted successfully!\n");
}

void displayMenu() {
    printf("\n--- Product Inventory System ---\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                viewProducts();
                break;
            case 3:
                updateProduct();
                break;
            case 4:
                deleteProduct();
                break;
            case 5:
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}