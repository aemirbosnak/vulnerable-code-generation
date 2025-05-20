//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_PRODUCTS 1000

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
} Product;

void addProduct(Product **inventory, int *current_count, int *capacity) {
    if (*current_count >= *capacity) {
        *capacity *= 2;
        *inventory = realloc(*inventory, *capacity * sizeof(Product));
    }
    
    Product p;
    p.id = *current_count + 1; // Simple ID assignment
    printf("Enter product name: ");
    scanf("%s", p.name);
    printf("Enter quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter price: ");
    scanf("%f", &p.price);
    
    (*inventory)[*current_count] = p;
    (*current_count)++;
    printf("Product added successfully!\n");
}

void viewInventory(Product *inventory, int count) {
    printf("\nProduct Inventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("---------------------------------------------\n");
}

void searchProduct(Product *inventory, int count) {
    char name[MAX_NAME_LEN];
    printf("Enter product name to search for: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Product found: ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Product not found!\n");
    }
}

void freeInventory(Product *inventory) {
    free(inventory);
    printf("Inventory memory freed.\n");
}

int main() {
    Product *inventory = malloc(MAX_PRODUCTS * sizeof(Product));
    int current_count = 0;
    int capacity = MAX_PRODUCTS;

    if (inventory == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    int choice;
    do {
        printf("\n--- Product Inventory System ---\n");
        printf("1. Add Product\n2. View Inventory\n3. Search Product\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(&inventory, &current_count, &capacity);
                break;
            case 2:
                viewInventory(inventory, current_count);
                break;
            case 3:
                searchProduct(inventory, current_count);
                break;
            case 4:
                printf("Exiting the system...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    freeInventory(inventory);
    return 0;
}