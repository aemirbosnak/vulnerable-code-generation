//FormAI DATASET v1.0 Category: Product Inventory System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    int id;
    char name[50];
    double price;
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int product_count = 0;

void addProduct() {
    Product new_product;

    printf("\nEnter product name: ");
    scanf("%s", new_product.name);

    printf("Enter product price: ");
    scanf("%lf", &new_product.price);

    printf("Enter product quantity: ");
    scanf("%d", &new_product.quantity);

    new_product.id = product_count + 1;

    inventory[product_count] = new_product;
    product_count++;

    printf("\nProduct added successfully.\n");
}

void viewProducts() {
    printf("\nID\tNAME\t\tPRICE\t\tQUANTITY\n");

    for (int i = 0; i < product_count; i++) {
        printf("%d\t%s\t\t%.2lf\t\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

int findProduct(int id) {
    int index = -1;

    for (int i = 0; i < product_count; i++) {
        if (inventory[i].id == id) {
            index = i;
            break;
        }
    }

    return index;
}

void updateProduct() {
    int id;
    printf("\nEnter product ID: ");
    scanf("%d", &id);

    int index = findProduct(id);

    if (index == -1) {
        printf("\nProduct not found.\n");
        return;
    }

    Product updated_product = inventory[index];

    printf("\nCurrent Name: %s", updated_product.name);
    printf("\nEnter new Name: ");
    scanf("%s", updated_product.name);

    printf("\nCurrent Price: %.2lf", updated_product.price);
    printf("\nEnter new Price: ");
    scanf("%lf", &updated_product.price);

    printf("\nCurrent Quantity: %d", updated_product.quantity);
    printf("\nEnter new Quantity: ");
    scanf("%d", &updated_product.quantity);

    inventory[index] = updated_product;

    printf("\nProduct updated successfully.\n");
}

void deleteProduct() {
    int id;
    printf("\nEnter product ID: ");
    scanf("%d", &id);

    int index = findProduct(id);

    if (index == -1) {
        printf("\nProduct not found.\n");
        return;
    }

    for (int i = index; i < product_count - 1; i++) {
        inventory[i] = inventory[i+1];
    }

    product_count--;

    printf("\nProduct deleted successfully.\n");
}

int main() {
    int choice;

    do {
        printf("\n\n===================\n");
        printf("Product Inventory System\n");
        printf("===================\n");
        printf("1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Exit\n\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                viewProducts();
                break;
            case 3:
                updateProduct();
                break;
            case 4:
                deleteProduct();
                break;
            case 5:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}