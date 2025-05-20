//FormAI DATASET v1.0 Category: Product Inventory System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    int id;
    char name[50];
    float price;
    int stock;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void addProduct() {
    if (num_products >= MAX_PRODUCTS) {
        printf("Maximum number of products reached.\n");
        return;
    }

    printf("Enter product name: ");
    scanf("%s", products[num_products].name);

    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);

    printf("Enter product stock: ");
    scanf("%d", &products[num_products].stock);

    products[num_products].id = num_products + 1;
    num_products++;
}

void displayProducts() {
    printf("Product Inventory\n");
    printf("---------------------------------------------\n");
    printf("%-10s %-30s %-10s %-10s\n", "ID", "Name", "Price", "Stock");
    printf("---------------------------------------------\n");

    for (int i = 0; i < num_products; i++) {
        printf("%-10d %-30s $%-9.2f %-10d\n",
            products[i].id, products[i].name, products[i].price, products[i].stock);
    }
}

void updateProduct() {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < num_products; i++) {
        if (products[i].id == id) {
            printf("Enter new stock for %s: ", products[i].name);
            scanf("%d", &products[i].stock);
            return;
        }
    }

    printf("Product with ID %d not found.\n", id);
}

void sellProduct() {
    int id;
    printf("Enter product ID to sell: ");
    scanf("%d", &id);

    for (int i = 0; i < num_products; i++) {
        if (products[i].id == id) {
            if (products[i].stock <= 0) {
                printf("Product out of stock.\n");
                return;
            }

            products[i].stock--;
            printf("Product sold. %d %s in stock.\n", products[i].stock, products[i].name);
            return;
        }
    }

    printf("Product with ID %d not found.\n", id);
}

int main() {
    char input[20];
    while (1) {
        printf("\nEnter command: ");
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            addProduct();
        } else if (strcmp(input, "display") == 0) {
            displayProducts();
        } else if (strcmp(input, "update") == 0) {
            updateProduct();
        } else if (strcmp(input, "sell") == 0) {
            sellProduct();
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}