//FormAI DATASET v1.0 Category: Product Inventory System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

// Structs
typedef struct product {
    int id;
    char name[MAX_NAME_LENGTH];
    double price;
    int stock;
} Product;

// Function prototypes
void addProduct(Product, Product[]);
void removeProduct(int, Product[]);
void editProduct(int, Product []);
void displayInventory(Product[]);
void generateReport(Product[]);
void searchProductByName(char[], Product[]);
void searchProductById(int, Product[]);

// Main function
int main() {
    Product inventory[MAX_PRODUCTS];
    int option, id;
    char name[MAX_NAME_LENGTH];

    do {
        // Main menu
        printf("\n====== Product Inventory System ======\n");
        printf("1. Add new product\n");
        printf("2. Remove a product\n");
        printf("3. Edit a product\n");
        printf("4. Display inventory\n");
        printf("5. Generate report\n");
        printf("6. Search product by name\n");
        printf("7. Search product by ID\n");
        printf("8. Exit\n");
        printf("Enter an option (1-8): ");
        scanf("%d", &option);

        switch(option) {
            case 1: // Add product
                printf("\n--- Add New Product ---\n");
                Product newProduct;
                printf("Enter product ID: ");
                scanf("%d", &newProduct.id);
                printf("Enter product name: ");
                scanf("%s", newProduct.name);
                printf("Enter product price: ");
                scanf("%lf", &newProduct.price);
                printf("Enter product stock: ");
                scanf("%d", &newProduct.stock);
                addProduct(newProduct, inventory);
                printf("Product added successfully!\n");
                break;
            case 2: // Remove product
                printf("\n--- Remove A Product ---\n");
                printf("Enter product ID: ");
                scanf("%d", &id);
                removeProduct(id, inventory);
                break;
            case 3: // Edit product
                printf("\n--- Edit A Product ---\n");
                printf("Enter product ID: ");
                scanf("%d", &id);
                editProduct(id, inventory);
                break;
            case 4: // Display inventory
                printf("\n--- Inventory ---\n");
                displayInventory(inventory);
                break;
            case 5: // Generate report
                printf("\n--- Inventory Report ---\n");
                generateReport(inventory);
                break;
            case 6: // Search product by name
                printf("\n--- Search Product By Name ---\n");
                printf("Enter product name: ");
                scanf("%s", name);
                searchProductByName(name, inventory);
                break;
            case 7: // Search product by ID
                printf("\n--- Search Product By ID ---\n");
                printf("Enter product ID: ");
                scanf("%d", &id);
                searchProductById(id, inventory);
                break;
            case 8: // Exit
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    } while(option != 8);

    return 0;
}

// Add product to inventory
void addProduct(Product newProduct, Product inventory[]) {
    int i;
    for(i = 0; i < MAX_PRODUCTS; i++) {
        if(inventory[i].id == 0) { // Empty slot found
            newProduct.id = i + 1; // Assign new ID
            inventory[i] = newProduct; // Add to inventory
            break;
        }
    }
}

// Remove product from inventory
void removeProduct(int id, Product inventory[]) {
    int i;
    for(i = 0; i < MAX_PRODUCTS; i++) {
        if(inventory[i].id == id) { // Product found
            inventory[i].id = 0; // Mark as deleted
            printf("Product removed successfully!\n");
            break;
        }
    }
}

// Edit product in inventory
void editProduct(int id, Product inventory[]) {
    int i;
    for(i = 0; i < MAX_PRODUCTS; i++) {
        if(inventory[i].id == id) { // Product found
            printf("Enter new product name: ");
            scanf("%s", inventory[i].name);
            printf("Enter new product price: ");
            scanf("%lf", &inventory[i].price);
            printf("Enter new product stock: ");
            scanf("%d", &inventory[i].stock);
            printf("Product updated successfully!\n");
            break;
        }
    }
}

// Display inventory
void displayInventory(Product inventory[]) {
    int i;
    for(i = 0; i < MAX_PRODUCTS; i++) {
        if(inventory[i].id != 0) { // Product found
            printf("ID: %d | Name: %s | Price: %.2lf | Stock: %d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].stock);
        }
    }
}

// Generate inventory report
void generateReport(Product inventory[]) {
    int i, totalStock = 0;
    double totalValue = 0;
    for(i = 0; i < MAX_PRODUCTS; i++) {
        if(inventory[i].id != 0) { // Product found
            totalStock += inventory[i].stock;
            totalValue += inventory[i].price * inventory[i].stock;
        }
    }
    printf("Total products: %d\n", MAX_PRODUCTS);
    printf("Total stock: %d\n", totalStock);
    printf("Total value: $%.2lf\n", totalValue);
}

// Search product by name
void searchProductByName(char name[], Product inventory[]) {
    int i, found = 0;
    for(i = 0; i < MAX_PRODUCTS; i++) {
        if(strcmp(inventory[i].name, name) == 0) { // Product found
            printf("ID: %d | Name: %s | Price: %.2lf | Stock: %d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].stock);
            found = 1;
        }
    }
    if(!found) {
        printf("No product found with that name.\n");
    }
}

// Search product by ID
void searchProductById(int id, Product inventory[]) {
    int i, found = 0;
    for(i = 0; i < MAX_PRODUCTS; i++) {
        if(inventory[i].id == id) { // Product found
            printf("ID: %d | Name: %s | Price: %.2lf | Stock: %d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].stock);
            found = 1;
        }
    }
    if(!found) {
        printf("No product found with that ID.\n");
    }
}