//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 50

// Struct to hold product information
typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Product;

// Function prototypes
void addProduct(Product **inventory, int *size);
void viewInventory(Product *inventory, int size);
void updateProduct(Product *inventory, int size);
void deleteProduct(Product **inventory, int *size);
void freeInventory(Product *inventory);

int main() {
    int choice;
    Product *inventory = NULL;
    int size = 0;

    do {
        printf("\n--- Product Inventory System ---\n");
        printf("1. Add Product\n");
        printf("2. View Inventory\n");
        printf("3. Update Product Quantity\n");
        printf("4. Delete Product\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                addProduct(&inventory, &size);
                break;
            case 2: 
                viewInventory(inventory, size);
                break;
            case 3: 
                updateProduct(inventory, size);
                break;
            case 4: 
                deleteProduct(&inventory, &size);
                break;
            case 5: 
                break;
            default: 
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 5);
    
    freeInventory(inventory);
    return 0;
}

void addProduct(Product **inventory, int *size) {
    *inventory = realloc(*inventory, (*size + 1) * sizeof(Product));
    if (*inventory == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }

    printf("Enter product name: ");
    scanf("%s", (*inventory)[*size].name);
    printf("Enter product quantity: ");
    scanf("%d", &(*inventory)[*size].quantity);
    printf("Enter product price: ");
    scanf("%f", &(*inventory)[*size].price);
    
    (*size)++;
    printf("Product added successfully!\n");
}

void viewInventory(Product *inventory, int size) {
    printf("\n--- Inventory List ---\n");
    for (int i = 0; i < size; i++) {
        printf("Product Name: %s, Quantity: %d, Price: %.2f\n", 
                inventory[i].name, 
                inventory[i].quantity, 
                inventory[i].price);
    }
}

void updateProduct(Product *inventory, int size) {
    char name[NAME_LENGTH];
    int found = 0;

    printf("Enter product name to update: ");
    scanf("%s", name);
    
    for (int i = 0; i < size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            found = 1;
            printf("Product updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Product not found in inventory.\n");
    }
}

void deleteProduct(Product **inventory, int *size) {
    char name[NAME_LENGTH];
    int found = 0;

    printf("Enter product name to delete: ");
    scanf("%s", name);
    
    for (int i = 0; i < *size; i++) {
        if (strcmp((*inventory)[i].name, name) == 0) {
            found = 1;
            for (int j = i; j < *size - 1; j++) {
                (*inventory)[j] = (*inventory)[j + 1];
            }
            *inventory = realloc(*inventory, (*size - 1) * sizeof(Product));
            (*size)--;
            printf("Product deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Product not found in inventory.\n");
    }
}

void freeInventory(Product *inventory) {
    free(inventory);
}