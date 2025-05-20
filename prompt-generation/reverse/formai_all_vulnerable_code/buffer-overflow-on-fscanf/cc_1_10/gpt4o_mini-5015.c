//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: dynamic
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

void addProduct(Product *inventory, int *count);
void displayProducts(Product *inventory, int count);
void restockProduct(Product *inventory, int count);
void deleteProduct(Product *inventory, int *count);
void searchProduct(Product *inventory, int count);
void saveToFile(Product *inventory, int count);
void loadFromFile(Product *inventory, int *count);

int main() {
    Product inventory[MAX_PRODUCTS];
    int count = 0;
    int choice;

    loadFromFile(inventory, &count);

    do {
        printf("\n---- Product Inventory System ----\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Restock Product\n");
        printf("4. Delete Product\n");
        printf("5. Search Product\n");
        printf("6. Save & Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(inventory, &count);
                break;
            case 2:
                displayProducts(inventory, count);
                break;
            case 3:
                restockProduct(inventory, count);
                break;
            case 4:
                deleteProduct(inventory, &count);
                break;
            case 5:
                searchProduct(inventory, count);
                break;
            case 6:
                saveToFile(inventory, count);
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void addProduct(Product *inventory, int *count) {
    if (*count >= MAX_PRODUCTS) {
        printf("Inventory is full!\n");
        return;
    }
    Product newProduct;
    newProduct.id = *count + 1;

    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);

    inventory[*count] = newProduct;
    (*count)++;
    printf("Product added successfully!\n");
}

void displayProducts(Product *inventory, int count) {
    if (count == 0) {
        printf("No products in inventory.\n");
        return;
    }
    printf("\nID\tName\t\tPrice\tQuantity\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

void restockProduct(Product *inventory, int count) {
    int id, quantity;
    printf("Enter product ID to restock: ");
    scanf("%d", &id);

    if (id < 1 || id > count) {
        printf("Invalid product ID!\n");
        return;
    }

    printf("Enter quantity to add: ");
    scanf("%d", &quantity);
    inventory[id - 1].quantity += quantity;
    printf("Product restocked successfully!\n");
}

void deleteProduct(Product *inventory, int *count) {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > *count) {
        printf("Invalid product ID!\n");
        return;
    }

    for (int i = id - 1; i < *count - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    (*count)--;
    printf("Product deleted successfully!\n");
}

void searchProduct(Product *inventory, int count) {
    char name[50];
    printf("Enter product name to search: ");
    scanf("%s", name);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("\nFound: ID: %d, Name: %s, Price: %.2f, Quantity: %d\n",
                   inventory[i].id, inventory[i].name,
                   inventory[i].price, inventory[i].quantity);
            return;
        }
    }
    printf("Product not found!\n");
}

void saveToFile(Product *inventory, int count) {
    FILE *file = fopen("inventory.txt", "w");
    if (file == NULL) {
        printf("Error opening file to save!\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s %f %d\n", inventory[i].id, inventory[i].name,
                inventory[i].price, inventory[i].quantity);
    }
    fclose(file);
    printf("Inventory saved to file successfully!\n");
}

void loadFromFile(Product *inventory, int *count) {
    FILE *file = fopen("inventory.txt", "r");
    if (file == NULL) {
        printf("No previous inventory found. Starting fresh!\n");
        return;
    }
    
    while (fscanf(file, "%d %s %f %d", &inventory[*count].id, inventory[*count].name,
                  &inventory[*count].price, &inventory[*count].quantity) != EOF) {
        (*count)++;
    }
    fclose(file);
    printf("Inventory loaded successfully!\n");
}