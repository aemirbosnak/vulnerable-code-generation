//FormAI DATASET v1.0 Category: Product Inventory System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct product {
    char name[50];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int num_products = 0;

void addProduct() {
    if (num_products == MAX_PRODUCTS) {
        printf("Inventory is full. Cannot add more products.\n");
        return;
    }

    Product new_product;

    printf("\nEnter Product Name: ");
    scanf(" %[^\n]s", new_product.name);

    printf("Enter Product Quantity: ");
    scanf("%d", &new_product.quantity);

    printf("Enter Product Price: ");
    scanf("%f", &new_product.price);

    inventory[num_products] = new_product;
    num_products++;

    printf("\nProduct added successfully!\n");
}

void listProducts() {
    if (num_products == 0) {
        printf("Inventory is empty. No products to display.\n");
        return;
    }

    printf("\nPRODUCT INVENTORY\n");
    printf("--------------------------------------------------\n");
    printf("|%20s |%10s |%10s |\n", "NAME", "QUANTITY", "PRICE");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < num_products; i++) {
        printf("|%20s |%10d |%10.2f |\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }

    printf("--------------------------------------------------\n");
}

void searchProduct() {
    if (num_products == 0) {
        printf("Inventory is empty. No products to search.\n");
        return;
    }

    char search_name[50];
    printf("\nEnter Product Name: ");
    scanf(" %[^\n]s", search_name);

    int found = 0;
    for (int i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, search_name) == 0) {
            printf("\n--------------------------------------------------\n");
            printf("|%20s |%10s |%10s |\n", "NAME", "QUANTITY", "PRICE");
            printf("--------------------------------------------------\n");
            printf("|%20s |%10d |%10.2f |\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
            printf("--------------------------------------------------\n");

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nProduct not found in inventory.\n");
    }
}

void sellProduct() {
    if (num_products == 0) {
        printf("Inventory is empty. No products to sell.\n");
        return;
    }

    char sell_name[50];
    printf("\nEnter Product Name: ");
    scanf(" %[^\n]s", sell_name);

    int found = 0;
    for (int i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, sell_name) == 0) {
            int sell_qty;
            printf("Enter Quantity to Sell: ");
            scanf("%d", &sell_qty);

            if (inventory[i].quantity < sell_qty) {
                printf("\nInsufficient Quantity. Cannot sell the product.\n");
                return;
            }

            inventory[i].quantity -= sell_qty;

            printf("\nProduct sold successfully!\n");
            printf("Total Amount: %.2f\n", sell_qty * inventory[i].price);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nProduct not found in inventory.\n");
    }
}

int main() {
    while (1) {
        printf("\n---------------------------\n");
        printf("         MENU\n");
        printf("----------------------------\n");
        printf("1. Add Product\n");
        printf("2. List Products\n");
        printf("3. Search Product\n");
        printf("4. Sell Product\n");
        printf("5. Exit\n");
        printf("----------------------------\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct();
                break;
            case 2:
                listProducts();
                break;
            case 3:
                searchProduct();
                break;
            case 4:
                sellProduct();
                break;
            case 5:
                printf("\nThank you for using our Product Inventory System!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}