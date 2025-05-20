//FormAI DATASET v1.0 Category: Product Inventory System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct Product {
    char name[50];
    int id;
    double price;
    int quantity;
};

struct Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    char name[50];
    double price;
    int quantity;

    printf("Enter product name: ");
    scanf("%s", name);
    printf("Enter product price: ");
    scanf("%lf", &price);
    printf("Enter product quantity: ");
    scanf("%d", &quantity);

    int id = num_products + 1;
    struct Product product = {0};
    product.id = id;
    strcpy(product.name, name);
    product.price = price;
    product.quantity = quantity;

    products[num_products++] = product;

    printf("Product added successfully!\n");
}

void delete_product() {
    int id;

    printf("Enter product id: ");
    scanf("%d", &id);

    for (int i = 0; i < num_products; i++) {
        if (products[i].id == id) {
            for (int j = i + 1; j < num_products; j++) {
                products[j - 1] = products[j];
            }
            num_products--;
            printf("Product deleted successfully!\n");
            return;
        }
    }

    printf("Product with id %d not found.\n", id);
}

void view_product() {
    int id;

    printf("Enter product id: ");
    scanf("%d", &id);

    for (int i = 0; i < num_products; i++) {
        if (products[i].id == id) {
            printf("Product details:\n");
            printf("ID: %d\n", products[i].id);
            printf("Name: %s\n", products[i].name);
            printf("Price: %.2lf\n", products[i].price);
            printf("Quantity: %d\n", products[i].quantity);
            return;
        }
    }

    printf("Product with id %d not found.\n", id);
}

void update_product() {
    int id;
    double price;
    int quantity;

    printf("Enter product id: ");
    scanf("%d", &id);

    for (int i = 0; i < num_products; i++) {
        if (products[i].id == id) {
            printf("Enter new product price: ");
            scanf("%lf", &price);
            printf("Enter new product quantity: ");
            scanf("%d", &quantity);

            products[i].price = price;
            products[i].quantity = quantity;

            printf("Product updated successfully!\n");
            return;
        }
    }

    printf("Product with id %d not found.\n", id);
}

void display_products() {
    printf("Product List:\n");
    printf("=================================================\n");
    printf("ID\tName\tPrice\tQuantity\n");
    printf("=================================================\n");

    for (int i = 0; i < num_products; i++) {
        printf("%d\t%s\t%.2lf\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }

    printf("=================================================\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n");
        printf("Product Inventory Management System\n");
        printf("1. Add Product\n");
        printf("2. Delete Product\n");
        printf("3. View Product\n");
        printf("4. Update Product\n");
        printf("5. Display Products\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                delete_product();
                break;
            case 3:
                view_product();
                break;
            case 4:
                update_product();
                break;
            case 5:
                display_products();
                break;
            case 6:
                printf("Thanks for using our system.\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}