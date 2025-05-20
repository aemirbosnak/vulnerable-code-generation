//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int product_count = 0;

void add_product();
void view_inventory();
void update_product();
void delete_product();
void search_product();
void menu();
void clear_buffer();

int main() {
    menu();
    return 0;
}

void menu() {
    int option;
    do {
        printf("\n=== Product Inventory System ===\n");
        printf("1. Add Product\n");
        printf("2. View Inventory\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Search Product\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);
        clear_buffer();

        switch (option) {
            case 1:
                add_product();
                break;
            case 2:
                view_inventory();
                break;
            case 3:
                update_product();
                break;
            case 4:
                delete_product();
                break;
            case 5:
                search_product();
                break;
            case 6:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != 6);
}

void clear_buffer() {
    while (getchar() != '\n'); // Clear input buffer
}

void add_product() {
    if (product_count >= MAX_PRODUCTS) {
        printf("Inventory Full! Cannot add more products.\n");
        return;
    }
    Product new_product;
    new_product.id = product_count + 1;  // Simple id assignment
    printf("Enter product name: ");
    fgets(new_product.name, NAME_LENGTH, stdin);
    new_product.name[strcspn(new_product.name, "\n")] = 0; // Remove newline
    printf("Enter quantity: ");
    scanf("%d", &new_product.quantity);
    printf("Enter price: ");
    scanf("%f", &new_product.price);
    clear_buffer();

    inventory[product_count++] = new_product;
    printf("Product added successfully!\n");
}

void view_inventory() {
    if (product_count == 0) {
        printf("Inventory is empty!\n");
        return;
    }
    printf("\n=== Current Inventory ===\n");
    for (int i = 0; i < product_count; i++) {
        printf("ID: %d | Name: %s | Quantity: %d | Price: %.2f\n",
            inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void update_product() {
    int id;
    printf("Enter the product ID to update: ");
    scanf("%d", &id);
    clear_buffer();

    if (id < 1 || id > product_count) {
        printf("Invalid product ID!\n");
        return;
    }

    Product *product = &inventory[id - 1];
    printf("Updating Product: %s\n", product->name);
    printf("Current Quantity: %d. Enter new quantity: ", product->quantity);
    scanf("%d", &product->quantity);
    printf("Current Price: %.2f. Enter new price: ", product->price);
    scanf("%f", &product->price);
    clear_buffer();

    printf("Product updated successfully!\n");
}

void delete_product() {
    int id;
    printf("Enter the product ID to delete: ");
    scanf("%d", &id);
    clear_buffer();

    if (id < 1 || id > product_count) {
        printf("Invalid product ID!\n");
        return;
    }

    for (int i = id - 1; i < product_count - 1; i++) {
        inventory[i] = inventory[i + 1];  // Shift products left
    }
    product_count--;
    printf("Product deleted successfully!\n");
}

void search_product() {
    char name[NAME_LENGTH];
    printf("Enter product name to search: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline

    printf("\n=== Search Results ===\n");
    int found = 0;
    for (int i = 0; i < product_count; i++) {
        if (strstr(inventory[i].name, name) != NULL) {
            printf("ID: %d | Name: %s | Quantity: %d | Price: %.2f\n",
                inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            found = 1;
        }
    }
    if (!found) {
        printf("No products found matching the name '%s'.\n", name);
    }
}