//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for product information
typedef struct {
    int id;
    char name[50];
    char description[100];
    int quantity;
    float price;
} Product;

// Function prototypes
void displayMenu();
void addProduct(Product *inventory, int *productCount);
void displayProducts(Product *inventory, int productCount);
void updateProduct(Product *inventory, int productCount);
void deleteProduct(Product *inventory, int *productCount);
void saveInventory(Product *inventory, int productCount);
void loadInventory(Product *inventory, int *productCount);

int main() {
    Product inventory[100];
    int productCount = 0;
    int choice;

    // Load existing inventory from file
    loadInventory(inventory, &productCount);

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(inventory, &productCount);
                break;
            case 2:
                displayProducts(inventory, productCount);
                break;
            case 3:
                updateProduct(inventory, productCount);
                break;
            case 4:
                deleteProduct(inventory, &productCount);
                break;
            case 5:
                saveInventory(inventory, productCount);
                printf("Inventory saved successfully.\n");
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

// Function to display menu options
void displayMenu() {
    printf("\n--- Product Inventory System ---\n");
    printf("1. Add Product\n");
    printf("2. Display All Products\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Save Inventory\n");
    printf("6. Exit\n");
}

// Function to add a product
void addProduct(Product *inventory, int *productCount) {
    Product newProduct;
    printf("Enter product ID: ");
    scanf("%d", &newProduct.id);
    printf("Enter product name: ");
    scanf(" %[^\n]", newProduct.name); // Read string with spaces
    printf("Enter product description: ");
    scanf(" %[^\n]", newProduct.description);
    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter price: ");
    scanf("%f", &newProduct.price);

    inventory[*productCount] = newProduct;
    (*productCount)++;
    printf("Product added successfully.\n");
}

// Function to display all products
void displayProducts(Product *inventory, int productCount) {
    if (productCount == 0) {
        printf("No products in inventory.\n");
        return;
    }

    printf("\n--- Product List ---\n");
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d, Name: %s, Description: %s, Quantity: %d, Price: %.2f\n",
               inventory[i].id, inventory[i].name, inventory[i].description, 
               inventory[i].quantity, inventory[i].price);
    }
}

// Function to update a product
void updateProduct(Product *inventory, int productCount) {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            printf("Updating Product ID %d:\n", id);
            printf("Enter new product name: ");
            scanf(" %[^\n]", inventory[i].name);
            printf("Enter new product description: ");
            scanf(" %[^\n]", inventory[i].description);
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Product updated successfully.\n");
            return;
        }
    }
    printf("Product ID not found.\n");
}

// Function to delete a product
void deleteProduct(Product *inventory, int *productCount) {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *productCount; i++) {
        if (inventory[i].id == id) {
            for (int j = i; j < *productCount - 1; j++) {
                inventory[j] = inventory[j + 1]; // Shift products left
            }
            (*productCount)--;
            printf("Product deleted successfully.\n");
            return;
        }
    }
    printf("Product ID not found.\n");
}

// Function to save inventory to a file
void saveInventory(Product *inventory, int productCount) {
    FILE *file = fopen("inventory.txt", "w");
    if (!file) {
        printf("Could not open file for writing.\n");
        return;
    }

    for (int i = 0; i < productCount; i++) {
        fprintf(file, "%d;%s;%s;%d;%.2f\n", 
                inventory[i].id, inventory[i].name, 
                inventory[i].description, 
                inventory[i].quantity, 
                inventory[i].price);
    }
    fclose(file);
}

// Function to load inventory from a file
void loadInventory(Product *inventory, int *productCount) {
    FILE *file = fopen("inventory.txt", "r");
    if (!file) {
        printf("No inventory file found. Starting with an empty inventory.\n");
        return;
    }

    while (!feof(file)) {
        fscanf(file, "%d;%[^;];%[^;];%d;%f\n", 
               &inventory[*productCount].id, 
               inventory[*productCount].name, 
               inventory[*productCount].description, 
               &inventory[*productCount].quantity, 
               &inventory[*productCount].price);
        (*productCount)++;
    }
    fclose(file);
}