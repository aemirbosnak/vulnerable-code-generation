//FormAI DATASET v1.0 Category: Product Inventory System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME 50

typedef struct {
    int id;
    char name[MAX_NAME];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    Product new_product;
    new_product.id = num_products + 1;

    printf("Enter the name of the product: ");
    scanf("%s", new_product.name);

    printf("Enter the quantity of the product: ");
    scanf("%d", &new_product.quantity);

    printf("Enter the price of the product: ");
    scanf("%f", &new_product.price);

    inventory[num_products] = new_product;
    num_products++;

    printf("Product added successfully with id %d\n", new_product.id);
}

void display_products() {
    if (num_products == 0) {
        printf("No products in inventory\n");
        return;
    }

    printf("%-10s %-20s %-10s %-10s\n", "ID", "NAME", "QUANTITY", "PRICE");
    for (int i = 0; i < num_products; i++) {
        printf("%-10d %-20s %-10d %-10.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void search_product() {
    char search_term[MAX_NAME];

    printf("Enter the name of the product to search for: ");
    scanf("%s", search_term);

    for (int i = 0; i < num_products; i++) {
        if (strcmp(search_term, inventory[i].name) == 0) {
            printf("Product found:\n");
            printf("ID: %d\n", inventory[i].id);
            printf("Name: %s\n", inventory[i].name);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price: %.2f\n", inventory[i].price);
            return;
        }
    }

    printf("Product not found\n");
}

void update_product() {
    int id;

    printf("Enter the id of the product to update: ");
    scanf("%d", &id);

    for (int i = 0; i < num_products; i++) {
        if (inventory[i].id == id) {
            printf("Enter the new quantity of the product: ");
            scanf("%d", &inventory[i].quantity);

            printf("Enter the new price of the product: ");
            scanf("%f", &inventory[i].price);

            printf("Product updated successfully\n");
            return;
        }
    }

    printf("Product not found\n");
}

void delete_product() {
    int id;

    printf("Enter the id of the product to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < num_products; i++) {
        if (inventory[i].id == id) {
            for (int j = i; j < num_products - 1; j++) {
                inventory[j] = inventory[j+1];
            }
            num_products--;
            printf("Product deleted successfully\n");
            return;
        }
    }

    printf("Product not found\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n");
        printf("PRODUCT INVENTORY SYSTEM\n");
        printf("------------------------\n");
        printf("1. Add product\n");
        printf("2. Display products\n");
        printf("3. Search product\n");
        printf("4. Update product\n");
        printf("5. Delete product\n");
        printf("6. Exit\n");
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
                update_product();
                break;
            case 5:
                delete_product();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}