//FormAI DATASET v1.0 Category: Product Inventory System ; Style: beginner-friendly
#include <stdio.h>

#define MAX_PRODUCTS 10 // maximum number of products allowed in the inventory

/*
 * Struct to store information about a product
 */
struct Product {
    int product_code;
    char name[20];
    float price;
    int quantity;
};

/*
 * Function to add a new product to the inventory
 */
void add_product(struct Product inventory[], int *num_products) {
    if (*num_products >= MAX_PRODUCTS) {
        printf("Cannot add more products. Maximum capacity reached.\n");
        return;
    }

    printf("\nEnter details for new product:\n");

    struct Product new_product;

    printf("Product Code: ");
    scanf("%d", &new_product.product_code);

    printf("Name: ");
    scanf("%s", new_product.name);

    printf("Price: ");
    scanf("%f", &new_product.price);

    printf("Quantity: ");
    scanf("%d", &new_product.quantity);

    inventory[*num_products] = new_product;
    *num_products += 1;

    printf("\nNew Product Added to Inventory Successfully!\n");
}

/*
 * Function to display all products in the inventory
 */
void display_products(struct Product inventory[], int num_products) {
    if (num_products == 0) {
        printf("\nNo products in inventory.\n");
        return;
    }

    printf("\n%-10s %-20s %-10s %-10s\n", "Code", "Name", "Price", "Quantity");

    for (int i = 0; i < num_products; i++) {
        printf("%-10d %-20s %-10.2f %-10d\n", inventory[i].product_code, inventory[i].name,
               inventory[i].price, inventory[i].quantity);
    }
}

/*
 * Function to search for a product by product code
 */
void search_product(struct Product inventory[], int num_products) {
    if (num_products == 0) {
        printf("\nNo products in inventory.\n");
        return;
    }

    int code_to_search;
    printf("Enter product code to search: ");
    scanf("%d", &code_to_search);

    for (int i = 0; i < num_products; i++) {
        if (inventory[i].product_code == code_to_search) {
            printf("\n%-10s %-20s %-10s %-10s\n", "Code", "Name", "Price", "Quantity");
            printf("%-10d %-20s %-10.2f %-10d\n", inventory[i].product_code, inventory[i].name,
                   inventory[i].price, inventory[i].quantity);
            return;
        }
    }

    printf("\nProduct with code %d not found in inventory.\n", code_to_search);
}

int main() {
    struct Product inventory[MAX_PRODUCTS];
    int num_products = 0;
    int choice;

    while (1) {
        printf("\n----------PRODUCT INVENTORY SYSTEM----------\n");
        printf("1. Add Product\n");
        printf("2. Display All Products\n");
        printf("3. Search for a Product\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product(inventory, &num_products);
                break;
            case 2:
                display_products(inventory, num_products);
                break;
            case 3:
                search_product(inventory, num_products);
                break;
            case 4:
                printf("\nExiting Inventory System. Thank You!\n");
                return 0;
            default:
                printf("\nInvalid Choice. Please Try Again.\n");
        }
    }
}