//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: genius
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

void displayMenu() {
    printf("\n***** Product Inventory System *****\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Search Product\n");
    printf("6. Exit\n");
    printf("*************************************\n");
    printf("Choose an option: ");
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory is full! Cannot add more products.\n");
        return;
    }
    
    Product newProduct;
    newProduct.id = productCount + 1; // Simple ID assignment
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);

    inventory[productCount++] = newProduct;
    printf("Product '%s' added successfully with ID %d.\n", newProduct.name, newProduct.id);
}

void viewProducts() {
    if (productCount == 0) {
        printf("No products in inventory.\n");
        return;
    }

    printf("\nCurrent Inventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void updateProduct() {
    int id;
    printf("Enter the ID of the product to update: ");
    scanf("%d", &id);

    if (id < 1 || id > productCount) {
        printf("Product ID not found.\n");
        return;
    }

    printf("Updating product '%s' (ID: %d)\n", inventory[id - 1].name, id);
    printf("Enter new name (or press ENTER to keep current): ");
    char newName[NAME_LENGTH];
    getchar(); // To consume newline from previous input
    fgets(newName, NAME_LENGTH, stdin);
    if (strcmp(newName, "\n") != 0) {
        newName[strcspn(newName, "\n")] = 0; // Remove newline
        strcpy(inventory[id - 1].name, newName);
    }
    
    printf("Enter new quantity (or -1 to keep current): ");
    int newQuantity;
    scanf("%d", &newQuantity);
    if (newQuantity != -1) {
        inventory[id - 1].quantity = newQuantity;
    }
    
    printf("Enter new price (or -1 to keep current): ");
    float newPrice;
    scanf("%f", &newPrice);
    if (newPrice != -1) {
        inventory[id - 1].price = newPrice;
    }
    
    printf("Product updated successfully.\n");
}

void deleteProduct() {
    int id;
    printf("Enter the ID of the product to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > productCount) {
        printf("Product ID not found.\n");
        return;
    }

    for (int i = id - 1; i < productCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    
    productCount--;
    printf("Product with ID %d deleted successfully.\n", id);
}

void searchProduct() {
    char name[NAME_LENGTH];
    printf("Enter product name to search: ");
    scanf("%s", name);

    printf("\nSearch Results:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("---------------------------------------------\n");
    
    int found = 0;
    for (int i = 0; i < productCount; i++) {
        if (strstr(inventory[i].name, name) != NULL) {
            printf("%d\t%s\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            found = 1;
        }
    }

    if (!found) {
        printf("No products found with the name '%s'.\n", name);
    }
}

int main() {
    int choice;

    while (1) {
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
                searchProduct();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}