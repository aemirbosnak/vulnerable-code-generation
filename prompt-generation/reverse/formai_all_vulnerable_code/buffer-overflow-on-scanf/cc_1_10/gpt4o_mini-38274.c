//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: active
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
        printf("Inventory is full. Cannot add more products.\n");
        return;
    }
    Product new_product;
    new_product.id = product_count + 1; // Set product ID
    printf("Enter product name: ");
    scanf(" %[^\n]", new_product.name);
    printf("Enter product quantity: ");
    scanf("%d", &new_product.quantity);
    printf("Enter product price: ");
    scanf("%f", &new_product.price);
    inventory[product_count++] = new_product;
    printf("Product added successfully!\n");
}

void remove_product() {
    int id;
    printf("Enter product ID to remove: ");
    scanf("%d", &id);
    
    if (id < 1 || id > product_count) {
        printf("Invalid product ID.\n");
        return;
    }

    for (int i = id - 1; i < product_count - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    product_count--;
    printf("Product removed successfully!\n");
}

void view_products() {
    printf("\nProduct Inventory:\n");
    printf("%-5s %-30s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    printf("------------------------------------------------\n");
    for (int i = 0; i < product_count; i++) {
        printf("%-5d %-30s %-10d %-10.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void search_product() {
    char name[NAME_LENGTH];
    printf("Enter product name to search: ");
    scanf(" %[^\n]", name);
    
    int found = 0;
    for (int i = 0; i < product_count; i++) {
        if (strstr(inventory[i].name, name) != NULL) {
            printf("Product found: ID=%d, Name=%s, Quantity=%d, Price=%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            found = 1;
        }
    }
    if (!found) {
        printf("No product found with that name.\n");
    }
}

void display_menu() {
    printf("\nProduct Inventory System\n");
    printf("1. Add Product\n");
    printf("2. Remove Product\n");
    printf("3. View Products\n");
    printf("4. Search Product\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_product();
                break;
            case 2:
                remove_product();
                break;
            case 3:
                view_products();
                break;
            case 4:
                search_product();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}