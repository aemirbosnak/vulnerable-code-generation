//FormAI DATASET v1.0 Category: Product Inventory System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100 // maximum number of products allowed in the inventory system
#define MAX_NAME_LENGTH 50 // maximum length of product name
#define MAX_DESC_LENGTH 100 // maximum length of product description
#define MAX_CATEGORY_LENGTH 20 // maximum length of product category
#define MAX_QUANTITY 1000 // maximum quantity of each product
#define MAX_PRICE 10000.0f // maximum price of each product

struct Product {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESC_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    int quantity;
    float price;
};

struct Inventory {
    struct Product products[MAX_PRODUCTS];
    int count; // number of products in the inventory
};

// function prototypes
void displayMenu();
void addProduct(struct Inventory* inventory);
void removeProduct(struct Inventory* inventory);
void displayInventory(struct Inventory* inventory);
void saveInventory(struct Inventory* inventory);

int main() {
    struct Inventory inventory = { .count = 0 };
    char choice;

    printf("Welcome to the Product Inventory System!\n");

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                addProduct(&inventory);
                break;

            case '2':
                removeProduct(&inventory);
                break;

            case '3':
                displayInventory(&inventory);
                break;

            case '4':
                saveInventory(&inventory);
                break;

            case '5':
                printf("Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0; 
}

void displayMenu() {
    printf("\n\n");
    printf("Product Inventory System Menu\n");
    printf("-----------------------------\n");
    printf("1. Add a product\n");
    printf("2. Remove a product\n");
    printf("3. Display inventory\n");
    printf("4. Save inventory\n");
    printf("5. Quit\n");
}

void addProduct(struct Inventory* inventory) {
    if (inventory->count == MAX_PRODUCTS) {
        printf("Error: maximum number of products reached (%d)\n", MAX_PRODUCTS);
        return;
    }

    struct Product product;

    printf("\n\n");
    printf("Add a product\n");
    printf("--------------\n");

    // get the name of the product
    printf("Enter the name of the product: ");
    scanf(" %[^\n]s", product.name);

    // get the description of the product
    printf("Enter the description of the product: ");
    scanf(" %[^\n]s", product.description);

    // get the category of the product
    printf("Enter the category of the product: ");
    scanf(" %[^\n]s", product.category);

    // get the quantity of the product
    printf("Enter the quantity of the product: ");
    scanf(" %d", &product.quantity);

    // get the price of the product
    printf("Enter the price of the product: ");
    scanf(" %f", &product.price);

    inventory->products[inventory->count++] = product;

    printf("\nProduct added successfully!\n");
}

void removeProduct(struct Inventory* inventory) {
    char name[MAX_NAME_LENGTH];
    int i, j;

    printf("\n\n");
    printf("Remove a product\n");
    printf("-----------------\n");

    // get the name of the product to remove
    printf("Enter the name of the product to remove: ");
    scanf(" %[^\n]s", name);

    // search for the product in the inventory
    for (i = 0; i < inventory->count; i++) {
        if (strcmp(name, inventory->products[i].name) == 0) {
            // product found, move all products after this one up by one
            for (j = i; j < inventory->count - 1; j++) {
                inventory->products[j] = inventory->products[j+1];
            }

            inventory->count--;

            printf("\nProduct removed successfully!\n");
            return;
        }
    }

    printf("\nError: product not found.\n");
}

void displayInventory(struct Inventory* inventory) {
    int i;

    printf("\n\n");
    printf("Inventory (%d product%s)\n", inventory->count, inventory->count == 1 ? "" : "s");
    printf("-----------------------------\n");

    if (inventory->count == 0) {
        printf("No products in inventory.\n");
        return;
    }

    printf("%-20s %-20s %-20s %-10s %-10s\n", "Name", "Description", "Category", "Quantity", "Price");
    printf("-------------------- -------------------- -------------------- ---------- ----------\n");

    for (i = 0; i < inventory->count; i++) {
        printf("%-20s %-20s %-20s %10d %10.2f\n", inventory->products[i].name, inventory->products[i].description,
               inventory->products[i].category, inventory->products[i].quantity, inventory->products[i].price);
    }
}

void saveInventory(struct Inventory* inventory) {
    char filename[100];
    FILE* fp;
    int i;

    printf("\n\n");
    printf("Save inventory to file\n");
    printf("-----------------------\n");

    // get the filename to save the inventory to
    printf("Enter the filename to save the inventory to: ");
    scanf(" %[^\n]s", filename);

    // open the file for writing
    fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("\nError: could not open file for writing.\n");
        return;
    }

    // write the inventory to the file
    for (i = 0; i < inventory->count; i++) {
        fprintf(fp, "%s\n%s\n%s\n%d\n%f\n", inventory->products[i].name, inventory->products[i].description,
                inventory->products[i].category, inventory->products[i].quantity, inventory->products[i].price);
    }

    fclose(fp);

    printf("\nInventory saved successfully!\n");
}