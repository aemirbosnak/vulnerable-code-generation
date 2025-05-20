//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define PRODUCT_NAME_LENGTH 50
#define FILE_NAME "inventory.txt"

typedef struct {
    char name[PRODUCT_NAME_LENGTH];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void loadInventory();
void saveInventory();
void addProduct();
void deleteProduct();
void displayInventory();

int main() {
    loadInventory();
    
    int choice;

    do {
        printf("\n--- Product Inventory System ---\n");
        printf("1. Add Product\n");
        printf("2. Delete Product\n");
        printf("3. Display Inventory\n");
        printf("4. Save Inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // Clear the input buffer
            continue;
        }
        
        switch(choice) {
            case 1:
                addProduct();
                break;
            case 2:
                deleteProduct();
                break;
            case 3:
                displayInventory();
                break;
            case 4:
                saveInventory();
                break;
            case 5:
                saveInventory();
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void loadInventory() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("File not found. Starting with an empty inventory.\n");
        return;
    }
    
    fread(&productCount, sizeof(int), 1, file);
    fread(inventory, sizeof(Product), productCount, file);
    fclose(file);
}

void saveInventory() {
    FILE *file = fopen(FILE_NAME, "wb");
    if (file == NULL) {
        printf("Error saving inventory to file.\n");
        return;
    }
    
    fwrite(&productCount, sizeof(int), 1, file);
    fwrite(inventory, sizeof(Product), productCount, file);
    fclose(file);
    printf("Inventory saved to %s.\n", FILE_NAME);
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory is full. Cannot add more products.\n");
        return;
    }
    
    printf("Enter product name: ");
    scanf(" %49[^\n]", inventory[productCount].name);
    printf("Enter quantity: ");
    scanf("%d", &inventory[productCount].quantity);
    printf("Enter price: ");
    scanf("%f", &inventory[productCount].price);
    
    productCount++;
    printf("Product added successfully.\n");
}

void deleteProduct() {
    char productName[PRODUCT_NAME_LENGTH];
    int found = 0;
    
    printf("Enter product name to delete: ");
    scanf(" %49[^\n]", productName);
    
    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, productName) == 0) {
            for (int j = i; j < productCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            productCount--;
            found = 1;
            printf("Product deleted successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Product not found.\n");
    }
}

void displayInventory() {
    if (productCount == 0) {
        printf("Inventory is empty.\n");
        return;
    }
    
    printf("\n--- Inventory List ---\n");
    printf("%-20s %-10s %-10s\n", "Product Name", "Quantity", "Price");
    for (int i = 0; i < productCount; i++) {
        printf("%-20s %-10d $%-9.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}