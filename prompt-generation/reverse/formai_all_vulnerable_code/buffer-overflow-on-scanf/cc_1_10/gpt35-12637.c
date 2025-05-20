//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct product {
    char name[50];
    int quantity;
    float price;
} product;

product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    // Code to add a new product to the warehouse inventory
    printf("\n\nAdd a new product\n\n");

    if (num_products < MAX_PRODUCTS) {
        printf("Enter the name of the product: ");
        scanf("%s", products[num_products].name);
        printf("Enter the quantity of the product: ");
        scanf("%d", &products[num_products].quantity);
        printf("Enter the price of the product: ");
        scanf("%f", &products[num_products].price);

        num_products++;
        printf("Product added successfully!\n");
    } else {
        printf("Cannot add more products. Maximum limit reached.\n");
    }
}

void remove_product() {
    // Code to remove an existing product from the warehouse inventory
    printf("\n\nRemove an existing product\n\n");

    if (num_products > 0) {
        int index = -1;

        printf("Enter the name of the product to remove: ");
        char name[50];
        scanf("%s", name);

        for (int i = 0; i < num_products; i++) {
            if (strcmp(name, products[i].name) == 0) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            printf("Product not found!\n");
        } else {
            printf("Product removed successfully!\n");
            for (int i = index; i < num_products - 1; i++) {
                products[i] = products[i+1];
            }
            num_products--;
        }
    } else {
        printf("No products to remove.\n");
    }
}

void display_products() {
    // Code to display all products currently in the warehouse inventory
    printf("\n\nDisplay all products\n\n");

    if (num_products > 0) {
        printf("%-30s %-10s %-10s\n", "Product Name", "Quantity", "Price");
        for (int i = 0; i < num_products; i++) {
            printf("%-30s %-10d $%.2f\n", products[i].name, products[i].quantity, products[i].price);
        }
    } else {
        printf("No products to display.\n");
    }
}

void update_product_quantity() {
    // Code to update the quantity of an existing product in the warehouse inventory
    printf("\n\nUpdate product quantity\n\n");

    if (num_products > 0) {
        printf("Enter the name of the product to update: ");
        char name[50];
        scanf("%s", name);

        int index = -1;
        for (int i = 0; i < num_products; i++) {
            if (strcmp(name, products[i].name) == 0) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            printf("Product not found!\n");
        } else {
            printf("Enter the new quantity of the product: ");
            int new_quantity;
            scanf("%d", &new_quantity);
            products[index].quantity = new_quantity;

            printf("Quantity updated successfully!\n");
        }
    } else {
        printf("No products to update.\n");
    }
}

int main() {
    printf("Welcome to the Warehouse Management System!\n");

    while (1) {
        printf("\n\nSelect an option from below:\n");
        printf("1. Add a new product\n");
        printf("2. Remove an existing product\n");
        printf("3. Display all products\n");
        printf("4. Update product quantity\n");
        printf("5. Exit\n");

        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_product();
                break;
            case 2:
                remove_product();
                break;
            case 3:
                display_products();
                break;
            case 4:
                update_product_quantity();
                break;
            case 5:
                printf("Exiting the Warehouse Management System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}