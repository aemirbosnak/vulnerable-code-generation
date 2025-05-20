//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: Dennis Ritchie
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

void add_product() {
    if (product_count >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }

    Product p;
    printf("Enter product ID: ");
    scanf("%d", &p.id);
    printf("Enter product name: ");
    scanf(" %[^\n]", p.name);
    printf("Enter quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter price: ");
    scanf("%f", &p.price);

    inventory[product_count++] = p;
    printf("Product added successfully!\n");
}

void update_product() {
    int id, found = 0;
    printf("Enter product ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < product_count; i++) {
        if (inventory[i].id == id) {
            found = 1;
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Product updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Product with ID %d not found.\n", id);
    }
}

void display_products() {
    if (product_count == 0) {
        printf("No products in inventory.\n");
        return;
    }
    printf("Product Inventory:\n");
    printf("%-10s %-30s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    for (int i = 0; i < product_count; i++) {
        printf("%-10d %-30s %-10d $%-10.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void search_product() {
    int id, found = 0;
    printf("Enter product ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < product_count; i++) {
        if (inventory[i].id == id) {
            printf("Product found:\n");
            printf("ID: %d\nName: %s\nQuantity: %d\nPrice: $%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Product with ID %d not found.\n", id);
    }
}

void show_menu() {
    printf("\nProduct Inventory System\n");
    printf("1. Add Product\n");
    printf("2. Update Product\n");
    printf("3. Display All Products\n");
    printf("4. Search Product\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    while (1) {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_product(); break;
            case 2: update_product(); break;
            case 3: display_products(); break;
            case 4: search_product(); break;
            case 5: 
                printf("Exiting the program.\n");
                exit(0);
            default: 
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}