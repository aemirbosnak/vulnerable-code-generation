//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: thoughtful
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
void display_products();
void update_product();
void delete_product();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    do {
        printf("\n--- Product Inventory System ---\n");
        printf("1. Add Product\n");
        printf("2. Display All Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                display_products();
                break;
            case 3:
                update_product();
                break;
            case 4:
                delete_product();
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}

void add_product() {
    if (product_count >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }
    Product new_product;

    printf("Enter product ID: ");
    scanf("%d", &new_product.id);
    printf("Enter product name: ");
    getchar(); // consume newline character
    fgets(new_product.name, NAME_LENGTH, stdin);
    new_product.name[strcspn(new_product.name, "\n")] = 0; // remove newline
    printf("Enter product quantity: ");
    scanf("%d", &new_product.quantity);
    printf("Enter product price: ");
    scanf("%f", &new_product.price);

    inventory[product_count] = new_product;
    product_count++;
    printf("Product added successfully!\n");
}

void display_products() {
    if (product_count == 0) {
        printf("No products in inventory.\n");
        return;
    }
    printf("\n--- Product List ---\n");
    for (int i = 0; i < product_count; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
               inventory[i].id, inventory[i].name,
               inventory[i].quantity, inventory[i].price);
    }
}

void update_product() {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < product_count; i++) {
        if (inventory[i].id == id) {
            printf("Updating product '%s'.\n", inventory[i].name);
            printf("Enter new product name: ");
            getchar(); // consume newline character
            fgets(inventory[i].name, NAME_LENGTH, stdin);
            inventory[i].name[strcspn(inventory[i].name, "\n")] = 0; // remove newline
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Product updated successfully!\n");
            return;
        }
    }
    printf("Product with ID %d not found.\n", id);
}

void delete_product() {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < product_count; i++) {
        if (inventory[i].id == id) {
            printf("Deleting product '%s'.\n", inventory[i].name);
            for (int j = i; j < product_count - 1; j++) {
                inventory[j] = inventory[j + 1]; // shift products left
            }
            product_count--;
            printf("Product deleted successfully!\n");
            return;
        }
    }
    printf("Product with ID %d not found.\n", id);
}