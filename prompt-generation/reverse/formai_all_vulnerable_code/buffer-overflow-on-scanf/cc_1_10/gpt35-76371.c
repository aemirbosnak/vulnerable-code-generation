//FormAI DATASET v1.0 Category: Product Inventory System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    char name[50];
    int quantity;
    float price;
};

struct inventory {
    struct product *products;
    int num_products;
};

void add_product(struct inventory *inv) {
    char name[50];
    int quantity;
    float price;

    printf("Enter the name of the product: ");
    scanf("%s", name);

    printf("Enter the quantity of the product: ");
    scanf("%d", &quantity);

    printf("Enter the price of the product: ");
    scanf("%f", &price);

    // Add the product to the inventory
    inv->num_products++;
    inv->products = realloc(inv->products, sizeof(struct product) * inv->num_products);
    strcpy(inv->products[inv->num_products-1].name, name);
    inv->products[inv->num_products-1].quantity = quantity;
    inv->products[inv->num_products-1].price = price;

    printf("Product added successfully!\n");
}

void list_products(struct inventory *inv) {
    printf("%-30s%-10s%-10s\n", "PRODUCT NAME", "QUANTITY", "PRICE");

    for (int i = 0; i < inv->num_products; i++) {
        printf("%-30s%-10d%-10.2f\n", inv->products[i].name, inv->products[i].quantity, inv->products[i].price);
    }
}

void remove_product(struct inventory *inv) {
    char name[50];

    printf("Enter the name of the product you want to remove: ");
    scanf("%s", name);

    int found = 0;

    for (int i = 0; i < inv->num_products; i++) {
        if (strcmp(inv->products[i].name, name) == 0) {
            // Remove the product from the inventory
            found = 1;
            for (int j = i; j < inv->num_products-1; j++) {
                inv->products[j] = inv->products[j+1];
            }
            inv->num_products--;
            inv->products = realloc(inv->products, sizeof(struct product) * inv->num_products);
            break;
        }
    }

    if (found) {
        printf("Product removed successfully!\n");
    } else {
        printf("Product not found!\n");
    }
}

int main() {
    struct inventory inv = {NULL, 0};

    int choice;

    do {
        printf("\nINVENTORY SYSTEM\n");
        printf("==========================\n");
        printf("1. Add product\n");
        printf("2. List products\n");
        printf("3. Remove product\n");
        printf("4. Quit\n");
        printf("==========================\n");

        printf("Enter your choice [1-4]: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product(&inv);
                break;
            case 2:
                list_products(&inv);
                break;
            case 3:
                remove_product(&inv);
                break;
            case 4:
                printf("Thank you for using the inventory system!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}