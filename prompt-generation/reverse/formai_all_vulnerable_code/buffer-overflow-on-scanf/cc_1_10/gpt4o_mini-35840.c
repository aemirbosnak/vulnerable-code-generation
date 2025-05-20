//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50
#define DESC_LENGTH 200

typedef struct {
    char name[NAME_LENGTH];
    char description[DESC_LENGTH];
    float price;
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int product_count = 0;

// Function declarations
void add_product();
void remove_product();
void list_products();
void display_menu();
void clear_input_buffer();

int main() {
    char choice;

    while (1) {
        display_menu();
        choice = getchar();
        clear_input_buffer();

        switch (choice) {
            case '1':
                add_product();
                break;
            case '2':
                remove_product();
                break;
            case '3':
                list_products();
                break;
            case '4':
                printf("Exiting... Safe travels through the neon-soaked streets of our cyberpunk city.\n");
                exit(0);
            default:
                printf("Invalid option. Please choose again.\n");
        }
    }

    return 0;
}

void display_menu() {
    printf("\n========================\n");
    printf("Cyberpunk Product Inventory\n");
    printf("========================\n");
    printf("1. Add Product\n");
    printf("2. Remove Product\n");
    printf("3. List Products\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

void add_product() {
    if (product_count >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }

    Product new_product;

    printf("Enter product name: ");
    fgets(new_product.name, NAME_LENGTH, stdin);
    new_product.name[strcspn(new_product.name, "\n")] = 0;  // Removing trailing newline

    printf("Enter product description: ");
    fgets(new_product.description, DESC_LENGTH, stdin);
    new_product.description[strcspn(new_product.description, "\n")] = 0;  // Removing trailing newline

    printf("Enter product price: ");
    scanf("%f", &new_product.price);
    clear_input_buffer();  // Clear newline from input buffer

    printf("Enter product quantity: ");
    scanf("%d", &new_product.quantity);
    clear_input_buffer();  // Clear newline from input buffer

    inventory[product_count] = new_product;
    product_count++;

    printf("Product '%s' added to the inventory.\n", new_product.name);
}

void remove_product() {
    if (product_count == 0) {
        printf("No products to remove.\n");
        return;
    }

    char product_name[NAME_LENGTH];
    printf("Enter the product name to remove: ");
    fgets(product_name, NAME_LENGTH, stdin);
    product_name[strcspn(product_name, "\n")] = 0;  // Removing trailing newline

    for (int i = 0; i < product_count; i++) {
        if (strcmp(inventory[i].name, product_name) == 0) {
            for (int j = i; j < product_count - 1; j++) {
                inventory[j] = inventory[j + 1];  // Shift left to remove product
            }
            product_count--;
            printf("Product '%s' removed from the inventory.\n", product_name);
            return;
        }
    }

    printf("Product '%s' not found in the inventory.\n", product_name);
}

void list_products() {
    if (product_count == 0) {
        printf("No products in inventory.\n");
        return;
    }

    printf("\n*** Current Inventory ***\n");
    for (int i = 0; i < product_count; i++) {
        printf("Name: %s\nDescription: %s\nPrice: $%.2f\nQuantity: %d\n", 
               inventory[i].name, inventory[i].description, 
               inventory[i].price, inventory[i].quantity);
        printf("------------------------\n");
    }
}

void clear_input_buffer() {
    while (getchar() != '\n');
}