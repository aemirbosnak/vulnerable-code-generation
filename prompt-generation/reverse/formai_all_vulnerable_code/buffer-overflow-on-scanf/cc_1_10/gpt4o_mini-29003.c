//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: detailed
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

// Function prototypes
void add_product();
void view_products();
void delete_product();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;

    while (1) {
        printf("\n--- Product Inventory System ---\n");
        printf("1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Delete Product\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                view_products();
                break;
            case 3:
                delete_product();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

void add_product() {
    if (product_count >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }

    Product new_product;
    new_product.id = product_count + 1; // Simple unique ID
    printf("Enter product name: ");
    scanf("%s", new_product.name);
    printf("Enter quantity: ");
    scanf("%d", &new_product.quantity);
    printf("Enter price: ");
    scanf("%f", &new_product.price);

    inventory[product_count] = new_product;
    product_count++;
    printf("Product added successfully!\n");
}

void view_products() {
    if (product_count == 0) {
        printf("No products in inventory.\n");
        return;
    }

    printf("\n--- Product Inventory ---\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("---------------------------------------\n");
    for (int i = 0; i < product_count; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void delete_product() {
    if (product_count == 0) {
        printf("No products to delete.\n");
        return;
    }

    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > product_count) {
        printf("Product not found!\n");
        return;
    }

    for (int i = id - 1; i < product_count - 1; i++) {
        inventory[i] = inventory[i + 1]; // Shift products left
    }
    product_count--;
    printf("Product deleted successfully!\n");
}