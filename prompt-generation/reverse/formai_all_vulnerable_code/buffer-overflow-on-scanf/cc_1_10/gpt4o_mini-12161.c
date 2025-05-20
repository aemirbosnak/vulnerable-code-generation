//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

// Struct to hold product information
typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

// Function prototypes
void addProduct();
void viewProducts();
void updateProduct();
void deleteProduct();
void saveToFile();
void loadFromFile();
void clearInputBuffer();

int main() {
    loadFromFile();
    int choice;

    while (1) {
        printf("\n===== Product Inventory System =====\n");
        printf("1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Save and Exit\n");
        printf("=====================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

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
                saveToFile();
                printf("Exiting the system... Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory is full! Cannot add more products.\n");
        return;
    }

    Product newProduct;
    newProduct.id = productCount + 1;  // Simple way to assign ID
    printf("Enter product name: ");
    fgets(newProduct.name, NAME_LENGTH, stdin);
    newProduct.name[strcspn(newProduct.name, "\n")] = 0; // Remove newline
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    clearInputBuffer();

    inventory[productCount++] = newProduct;
    printf("Product added successfully! Product ID: %d\n", newProduct.id);
}

void viewProducts() {
    if (productCount == 0) {
        printf("No products in the inventory!\n");
        return;
    }

    printf("\nProduct Inventory:\n");
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d | Name: %s | Quantity: %d | Price: %.2f\n", 
                inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void updateProduct() {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    clearInputBuffer();

    if (id < 1 || id > productCount) {
        printf("Invalid product ID!\n");
        return;
    }

    Product* p = &inventory[id - 1];
    printf("Updating product ID %d (%s)\n", p->id, p->name);
    printf("Enter new name (leave empty to keep current): ");
    char newName[NAME_LENGTH];
    fgets(newName, NAME_LENGTH, stdin);
    newName[strcspn(newName, "\n")] = 0; // Remove newline

    if (strlen(newName) > 0) {
        strcpy(p->name, newName);
    }

    printf("Enter new quantity (-1 to keep current): ");
    int newQuantity;
    scanf("%d", &newQuantity);
    clearInputBuffer();

    if (newQuantity >= 0) {
        p->quantity = newQuantity;
    }

    printf("Enter new price (-1 to keep current): ");
    float newPrice;
    scanf("%f", &newPrice);
    clearInputBuffer();

    if (newPrice >= 0) {
        p->price = newPrice;
    }

    printf("Product updated successfully!\n");
}

void deleteProduct() {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    clearInputBuffer();

    if (id < 1 || id > productCount) {
        printf("Invalid product ID!\n");
        return;
    }

    for (int i = id - 1; i < productCount - 1; i++) {
        inventory[i] = inventory[i + 1]; // Shift products
    }
    productCount--;
    printf("Product deleted successfully!\n");
}

void saveToFile() {
    FILE* file = fopen("inventory.txt", "w");
    if (file == NULL) {
        printf("Error while saving the file.\n");
        return;
    }
    for (int i = 0; i < productCount; i++) {
        fprintf(file, "%d,%s,%d,%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    fclose(file);
    printf("Inventory saved successfully!\n");
}

void loadFromFile() {
    FILE* file = fopen("inventory.txt", "r");
    if (file == NULL) {
        return; // File not found, just start with empty inventory
    }
    while (fscanf(file, "%d,%49[^,],%d,%f\n", 
                  &inventory[productCount].id, inventory[productCount].name, 
                  &inventory[productCount].quantity, &inventory[productCount].price) == 4) {
        productCount++;
    }
    fclose(file);
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}