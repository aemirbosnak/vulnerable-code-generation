//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PRODS 20

struct Product {
    char name[50];
    int quantity;
    float price;
};

struct Product products[MAX_PRODS];

int no_of_products = 0;

void add_product() {
    struct Product p;

    printf("Enter the name of the product: ");
    scanf("%s", p.name);

    printf("Enter the quantity of the product: ");
    scanf("%d", &p.quantity);

    printf("Enter the price of the product: ");
    scanf("%f", &p.price);

    products[no_of_products++] = p;
}

void delete_product() {
    char name[50];
    printf("Enter the name of the product to be deleted: ");
    scanf("%s", name);

    int i, j;
    for (i = 0; i < no_of_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            for (j = i; j < no_of_products-1; j++) {
                products[j] = products[j+1];
            }
            no_of_products--;
            printf("Product deleted successfully!\n");
            return;
        }
    }

    printf("Product not found!\n");
}

void show_inventory() {
    int i;
    float total = 0.0;

    printf("Inventory:\n");
    printf("%-20s%-10s%-10s\n", "Product", "Quantity", "Price");
    for (i = 0; i < no_of_products; i++) {
        printf("%-20s%-10d%.2f\n", products[i].name, products[i].quantity, products[i].price);
        total += products[i].price * products[i].quantity;
    }

    printf("Total: $%.2f\n", total);
}

int main() {
    int choice;

    while (1) {
        printf("\nInventory Management System\n");
        printf("1. Add product\n");
        printf("2. Delete product\n");
        printf("3. Show inventory\n");
        printf("4. Exit\n");

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
                show_inventory();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}