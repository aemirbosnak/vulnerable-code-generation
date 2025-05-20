//FormAI DATASET v1.0 Category: Product Inventory System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct product {
    char name[20];
    int quantity;
    double price;
} product_t;

product_t inventory[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    if (num_products == MAX_PRODUCTS) {
        printf("Inventory is full\n");
        return;
    }

    product_t new_product;

    printf("Enter the name of the product: ");
    scanf("%s", new_product.name);

    printf("Enter the quantity of the product: ");
    scanf("%d", &new_product.quantity);

    printf("Enter the price of the product: ");
    scanf("%lf", &new_product.price);

    inventory[num_products] = new_product;
    num_products++;

    printf("Product added successfully\n");
}

void delete_product() {
    int product_index;
    char product_name[20];

    printf("Enter the name of the product you want to delete: ");
    scanf("%s", product_name);

    for (int i = 0; i < num_products; i++) {
        if (!strcmp(inventory[i].name, product_name)) {
            product_index = i;
            break;
        }

        if (i == num_products - 1) {
            printf("Product not found\n");
            return;
        }
    }

    for (int i = product_index; i < num_products - 1; i++) {
        inventory[i] = inventory[i+1];
    }

    num_products--;
    printf("Product deleted successfully\n");
}

void display_all_products() {
    if (num_products == 0) {
        printf("Inventory is empty\n");
        return;
    }

    printf("Name\t\tQuantity\t\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s\t\t%d\t\t\t%.2lf\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    int choice;
    char menu[] = "\n1. Add new product\n2. Delete product\n3. Display all products\n4. Exit\n";

    do {
        printf("%s", menu);
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
                display_all_products();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
        }

        printf("\n");
    } while (choice != 4);

    return 0;
}