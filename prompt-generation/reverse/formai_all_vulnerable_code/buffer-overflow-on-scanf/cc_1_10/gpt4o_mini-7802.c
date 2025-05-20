//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: rigorous
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
void view_products();
void update_product();
void delete_product();
void display_menu();
int find_product(int id);

int main() {
    int choice;

    while (1) {
        display_menu();
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
                update_product();
                break;
            case 4:
                delete_product();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void display_menu() {
    printf("\n--- Product Inventory System ---\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Exit\n");
}

void add_product() {
    if (product_count >= MAX_PRODUCTS) {
        printf("Unable to add more products. Inventory is full.\n");
        return;
    }

    Product new_product;
    new_product.id = product_count + 1;

    printf("Enter product name: ");
    scanf(" %[^\n]", new_product.name);  // Read string with spaces
    printf("Enter product quantity: ");
    scanf("%d", &new_product.quantity);
    printf("Enter product price: ");
    scanf("%f", &new_product.price);

    inventory[product_count] = new_product;
    product_count++;
    printf("Product added successfully! ID: %d\n", new_product.id);
}

void view_products() {
    printf("\n--- Product List ---\n");
    if (product_count == 0) {
        printf("No products in inventory.\n");
        return;
    }

    for (int i = 0; i < product_count; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", 
               inventory[i].id, 
               inventory[i].name, 
               inventory[i].quantity, 
               inventory[i].price);
    }
}

void update_product() {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);

    int index = find_product(id);
    if (index == -1) {
        printf("Product not found!\n");
        return;
    }

    printf("Updating product ID: %d\n", id);
    printf("Enter new product name (leave blank to keep current): ");
    char new_name[NAME_LENGTH];
    scanf(" %[^\n]", new_name);

    if (strlen(new_name) > 0) {
        strcpy(inventory[index].name, new_name);
    }

    printf("Enter new product quantity (negative number to keep current): ");
    int new_quantity;
    scanf("%d", &new_quantity);
    if (new_quantity >= 0) {
        inventory[index].quantity = new_quantity;
    }

    printf("Enter new product price (negative number to keep current): ");
    float new_price;
    scanf("%f", &new_price);
    if (new_price >= 0) {
        inventory[index].price = new_price;
    }

    printf("Product updated successfully!\n");
}

void delete_product() {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    int index = find_product(id);
    if (index == -1) {
        printf("Product not found!\n");
        return;
    }

    for (int i = index; i < product_count - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    product_count--;
    printf("Product deleted successfully!\n");
}

int find_product(int id) {
    for (int i = 0; i < product_count; i++) {
        if (inventory[i].id == id) {
            return i;
        }
    }
    return -1;  // Not found
}