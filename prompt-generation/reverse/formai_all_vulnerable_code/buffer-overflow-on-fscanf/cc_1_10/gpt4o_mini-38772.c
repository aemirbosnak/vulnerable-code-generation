//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50
#define CODE_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    char code[CODE_LENGTH];
    int quantity;
    float price;
} Product;

void addProduct(Product *inventory, int *count);
void viewProducts(Product *inventory, int count);
void saveInventory(Product *inventory, int count);
void loadInventory(Product *inventory, int *count);
void searchProduct(Product *inventory, int count);
void updateProduct(Product *inventory, int count);
void deleteProduct(Product *inventory, int *count);
void displayMenu();

int main() {
    Product inventory[MAX_PRODUCTS];
    int count = 0;
    int choice;
    
    loadInventory(inventory, &count);

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addProduct(inventory, &count);
                break;
            case 2:
                viewProducts(inventory, count);
                break;
            case 3:
                saveInventory(inventory, count);
                break;
            case 4:
                searchProduct(inventory, count);
                break;
            case 5:
                updateProduct(inventory, count);
                break;
            case 6:
                deleteProduct(inventory, &count);
                break;
            case 7:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);
    
    return 0;
}

void displayMenu() {
    printf("\n--- Product Inventory System ---\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Save Inventory\n");
    printf("4. Search Product\n");
    printf("5. Update Product\n");
    printf("6. Delete Product\n");
    printf("7. Exit\n");
}

void addProduct(Product *inventory, int *count) {
    if (*count >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }
    Product newProduct;
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product code: ");
    scanf("%s", newProduct.code);
    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter price: ");
    scanf("%f", &newProduct.price);
    
    inventory[*count] = newProduct;
    (*count)++;
    printf("Product added successfully!\n");
}

void viewProducts(Product *inventory, int count) {
    if (count == 0) {
        printf("No products in inventory!\n");
        return;
    }
    
    printf("\n--- Product List ---\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Code: %s, Quantity: %d, Price: %.2f\n",
               inventory[i].name, inventory[i].code,
               inventory[i].quantity, inventory[i].price);
    }
}

void saveInventory(Product *inventory, int count) {
    FILE *file = fopen("inventory.txt", "w");
    if (!file) {
        printf("Error opening file for saving.\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s %d %.2f\n", inventory[i].name, inventory[i].code, 
                inventory[i].quantity, inventory[i].price);
    }
    fclose(file);
    printf("Inventory saved successfully!\n");
}

void loadInventory(Product *inventory, int *count) {
    FILE *file = fopen("inventory.txt", "r");
    if (!file) {
        printf("No previous inventory found, starting fresh.\n");
        return;
    }
    
    while (fscanf(file, "%s %s %d %f", inventory[*count].name, 
                  inventory[*count].code, &inventory[*count].quantity,
                  &inventory[*count].price) != EOF) {
        (*count)++;
    }
    fclose(file);
}

void searchProduct(Product *inventory, int count) {
    char searchCode[CODE_LENGTH];
    printf("Enter product code to search: ");
    scanf("%s", searchCode);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].code, searchCode) == 0) {
            printf("Product found: Name: %s, Quantity: %d, Price: %.2f\n", 
                   inventory[i].name, 
                   inventory[i].quantity, 
                   inventory[i].price);
            return;
        }
    }
    printf("Product not found!\n");
}

void updateProduct(Product *inventory, int count) {
    char updateCode[CODE_LENGTH];
    printf("Enter product code to update: ");
    scanf("%s", updateCode);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].code, updateCode) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Product updated successfully!\n");
            return;
        }
    }
    printf("Product not found!\n");
}

void deleteProduct(Product *inventory, int *count) {
    char deleteCode[CODE_LENGTH];
    printf("Enter product code to delete: ");
    scanf("%s", deleteCode);
    
    for (int i = 0; i < *count; i++) {
        if (strcmp(inventory[i].code, deleteCode) == 0) {
            for (int j = i; j < *count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            (*count)--;
            printf("Product deleted successfully!\n");
            return;
        }
    }
    printf("Product not found!\n");
}