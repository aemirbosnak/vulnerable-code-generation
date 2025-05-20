//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LEN 50

typedef struct {
    int id;
    char name[NAME_LEN];
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
    new_product.id = product_count + 1;

    printf("Enter product name: ");
    scanf("%s", new_product.name);
    printf("Enter product quantity: ");
    scanf("%d", &new_product.quantity);
    printf("Enter product price: ");
    scanf("%f", &new_product.price);

    inventory[product_count] = new_product;
    product_count++;

    printf("Product added: %s (ID: %d)\n", new_product.name, new_product.id);
}

void display_products() {
    if (product_count == 0) {
        printf("No products in inventory.\n");
        return;
    }

    printf("\nProduct Inventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < product_count; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", 
               inventory[i].id, 
               inventory[i].name, 
               inventory[i].quantity, 
               inventory[i].price);
    }
}

void search_product() {
    int search_id;
    printf("Enter product ID to search: ");
    scanf("%d", &search_id);

    for (int i = 0; i < product_count; i++) {
        if (inventory[i].id == search_id) {
            printf("Product found: %s (ID: %d)\n", inventory[i].name, inventory[i].id);
            printf("Quantity: %d, Price: %.2f\n", inventory[i].quantity, inventory[i].price);
            return;
        }
    }

    printf("Product with ID %d not found.\n", search_id);
}

void menu() {
    int choice;
    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Search Product by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                display_products();
                break;
            case 3:
                search_product();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 4);
}

int main() {
    menu();
    return 0;
}