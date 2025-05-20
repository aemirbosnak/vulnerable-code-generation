//FormAI DATASET v1.0 Category: Product Inventory System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct product {
    int id;
    char name[50];
    int quantity;
    float price;
} products[MAX_PRODUCTS];

int num_products = 0;

void add_product();
void remove_product();
void view_products();

int main() {
    int choice;
    printf("- - - Welcome to the Product Inventory System! - - -\n");
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a product\n");
        printf("2. Remove a product\n");
        printf("3. View all products\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
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
                printf("Exiting program.");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    return 0;
}

void add_product() {
    if (num_products == MAX_PRODUCTS) {
        printf("The inventory is full. Cannot add more products.\n");
        return;
    }
    struct product new_product;
    printf("\nEnter Product ID: ");
    scanf("%d", &new_product.id);
    printf("Enter Product Name: ");
    scanf("%s", new_product.name);
    printf("Enter Product Quantity: ");
    scanf("%d", &new_product.quantity);
    printf("Enter Product Price: ");
    scanf("%f", &new_product.price);
    products[num_products++] = new_product;
    printf("\nProduct added successfully!\n");
}

void remove_product() {
    int id_to_remove, found = 0;
    printf("\nEnter Product ID to remove: ");
    scanf("%d", &id_to_remove);
    int i;
    for (i = 0; i < num_products; i++) {
        if (products[i].id == id_to_remove) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (int j = i; j < num_products - 1; j++) {
            products[j] = products[j + 1];
        }
        num_products--;
        printf("Product removed successfully.\n");
    } else {
        printf("Product with ID %d not found.\n", id_to_remove);
    }
}

void view_products() {
    printf("\nAll Products in Inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("\nID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
}