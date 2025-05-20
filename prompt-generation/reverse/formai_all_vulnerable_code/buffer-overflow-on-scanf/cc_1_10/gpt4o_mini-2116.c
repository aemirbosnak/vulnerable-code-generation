//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: retro
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

void display_menu() {
    printf("\n=== Product Inventory System ===\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

void add_product() {
    if (product_count >= MAX_PRODUCTS) {
        printf("Error: Inventory full!\n");
        return;
    }

    Product p;
    p.id = product_count + 1; // Simplified ID assignment
    printf("Enter product name: ");
    scanf("%s", p.name);
    printf("Enter quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter price: ");
    scanf("%f", &p.price);

    inventory[product_count] = p;
    product_count++;
    printf("Product added successfully!\n");
}

void view_products() {
    if (product_count == 0) {
        printf("No products in inventory!\n");
        return;
    }

    printf("\n=== Current Inventory ===\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    for (int i = 0; i < product_count; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void update_product() {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);

    if (id <= 0 || id > product_count) {
        printf("Error: Invalid product ID!\n");
        return;
    }

    Product *p = &inventory[id - 1];
    printf("Updating product: %s\n", p->name);
    printf("Enter new quantity: ");
    scanf("%d", &p->quantity);
    printf("Enter new price: ");
    scanf("%f", &p->price);
    
    printf("Product updated successfully!\n");
}

void delete_product() {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    if (id <= 0 || id > product_count) {
        printf("Error: Invalid product ID!\n");
        return;
    }

    for (int i = id - 1; i < product_count - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    product_count--;
    printf("Product deleted successfully!\n");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                view_products();
                break;
            case 3:
                update_product();
                break;
            case 4:
                delete_product();
                break;
            case 5:
                printf("Exiting the system. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}