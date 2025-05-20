//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_SIZE 50
#define MAX_QUANTITY 1000

struct product {
    char name[MAX_NAME_SIZE];
    int quantity;
};

struct product products[MAX_PRODUCTS];

int num_products = 0;
int num_free_slots = MAX_PRODUCTS;

void add_product() {
    if (num_free_slots == 0) {
        printf("Error: No more free slots for products.\n");
        return;
    }

    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    products[num_products].quantity = 0;
    num_free_slots--;
    num_products++;

    printf("Product added successfully.\n");
}

void remove_product(int index) {
    if (index < 0 || index >= num_products) {
        printf("Error: Invalid product index.\n");
        return;
    }

    printf("Product removed successfully.\n");
    num_free_slots++;
}

void update_product_quantity(int index) {
    if (index < 0 || index >= num_products) {
        printf("Error: Invalid product index.\n");
        return;
    }

    printf("Enter new quantity: ");
    scanf("%d", &products[index].quantity);

    printf("Product quantity updated successfully.\n");
}

void display_products() {
    printf("Product Name\tQuantity\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s\t\t%d\n", products[i].name, products[i].quantity);
    }
}

int main() {
    printf("Welcome to the Product Inventory System!\n");
    int choice;

    do {
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Update product quantity\n");
        printf("4. Display products\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_product();
            break;
        case 2:
            printf("Enter product index: ");
            int index;
            scanf("%d", &index);
            remove_product(index);
            break;
        case 3:
            printf("Enter product index: ");
            int index2;
            scanf("%d", &index2);
            update_product_quantity(index2);
            break;
        case 4:
            display_products();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}