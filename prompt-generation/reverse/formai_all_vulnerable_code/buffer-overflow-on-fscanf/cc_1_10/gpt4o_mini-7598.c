//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50
#define CATEGORY_LENGTH 30

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char category[CATEGORY_LENGTH];
    float price;
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct();
void viewProducts();
void searchProduct();
void removeProduct();
void saveInventoryToFile();
void loadInventoryFromFile();

int main() {
    int choice;

    loadInventoryFromFile();

    do {
        printf("\n--- Product Inventory System ---\n");
        printf("1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Search Product\n");
        printf("4. Remove Product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                viewProducts();
                break;
            case 3:
                searchProduct();
                break;
            case 4:
                removeProduct();
                break;
            case 5:
                saveInventoryToFile();
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }

    Product newProduct;
    newProduct.id = productCount + 1;

    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product category: ");
    scanf("%s", newProduct.category);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);

    inventory[productCount++] = newProduct;
    printf("Product added successfully!\n");
}

void viewProducts() {
    if (productCount == 0) {
        printf("No products in inventory.\n");
        return;
    }

    printf("\n--- Product List ---\n");
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d, Name: %s, Category: %s, Price: %.2f, Quantity: %d\n",
               inventory[i].id, inventory[i].name, inventory[i].category, inventory[i].price, inventory[i].quantity);
    }
}

void searchProduct() {
    char searchName[NAME_LENGTH];
    printf("Enter product name to search: ");
    scanf("%s", searchName);

    printf("\n--- Search Results ---\n");
    int found = 0;
    for (int i = 0; i < productCount; i++) {
        if (strcasecmp(inventory[i].name, searchName) == 0) {
            printf("ID: %d, Name: %s, Category: %s, Price: %.2f, Quantity: %d\n",
                   inventory[i].id, inventory[i].name, inventory[i].category, inventory[i].price, inventory[i].quantity);
            found = 1;
        }
    }

    if (!found) {
        printf("No products found with the name '%s'.\n", searchName);
    }
}

void removeProduct() {
    int id;
    printf("Enter product ID to remove: ");
    scanf("%d", &id);

    if (id < 1 || id > productCount) {
        printf("Invalid product ID.\n");
        return;
    }

    for (int i = id - 1; i < productCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    productCount--;
    printf("Product removed successfully!\n");
}

void saveInventoryToFile() {
    FILE *file = fopen("inventory.txt", "w");
    if (!file) {
        printf("Error saving inventory to file.\n");
        return;
    }
    for (int i = 0; i < productCount; i++) {
        fprintf(file, "%d %s %s %.2f %d\n", inventory[i].id, inventory[i].name, inventory[i].category,
                inventory[i].price, inventory[i].quantity);
    }
    fclose(file);
    printf("Inventory saved successfully!\n");
}

void loadInventoryFromFile() {
    FILE *file = fopen("inventory.txt", "r");
    if (!file) {
        return;  // If the file doesn't exist, we can start with an empty inventory
    }

    while (fscanf(file, "%d %s %s %f %d", 
                  &inventory[productCount].id, 
                  inventory[productCount].name, 
                  inventory[productCount].category, 
                  &inventory[productCount].price, 
                  &inventory[productCount].quantity) != EOF) {
        productCount++;
    }

    fclose(file);
}