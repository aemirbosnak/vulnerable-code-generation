//FormAI DATASET v1.0 Category: Product Inventory System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    int quantity;
    double price;
} product;

void addProduct(product products[], int *count) {
    if (*count == MAX_PRODUCTS) {
        printf("The inventory is full!\n");
        return;
    }

    product p;

    printf("Enter the name of the product: ");
    scanf("%s", p.name);

    printf("Enter the quantity of the product: ");
    scanf("%d", &p.quantity);

    printf("Enter the price of the product: ");
    scanf("%lf", &p.price);

    products[*count] = p;
    (*count)++;

    printf("Product successfully added to the inventory!\n");
}

void displayInventory(product products[], int count) {
    if (count == 0) {
        printf("No products in the inventory!\n");
        return;
    }

    printf("%-20s %-10s %-10s\n", "Product Name", "Quantity", "Price");

    for (int i = 0; i < count; i++) {
        printf("%-20s %-10d %-10.2lf\n", products[i].name, products[i].quantity, products[i].price);
    }
}

void searchProduct(product products[], int count) {
    if (count == 0) {
        printf("No products in the inventory!\n");
        return;
    }

    char name[50];

    printf("Enter the name of the product: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("%-20s %-10d %-10.2lf\n", products[i].name, products[i].quantity, products[i].price);
            return;
        }
    }

    printf("Product not found!\n");
}

void updateProduct(product products[], int count) {
    if (count == 0) {
        printf("No products in the inventory!\n");
        return;
    }

    char name[50];

    printf("Enter the name of the product: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("Enter the new quantity of the product: ");
            scanf("%d", &products[i].quantity);

            printf("Enter the new price of the product: ");
            scanf("%lf", &products[i].price);

            printf("Product successfully updated!\n");
            return;
        }
    }

    printf("Product not found!\n");
}

int main() {
    product products[MAX_PRODUCTS];
    int count = 0;
    int choice;

    while (1) {
        printf("\n");
        printf("1. Add product\n");
        printf("2. Display inventory\n");
        printf("3. Search product\n");
        printf("4. Update product\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(products, &count);
                break;
            case 2:
                displayInventory(products, count);
                break;
            case 3:
                searchProduct(products, count);
                break;
            case 4:
                updateProduct(products, count);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}