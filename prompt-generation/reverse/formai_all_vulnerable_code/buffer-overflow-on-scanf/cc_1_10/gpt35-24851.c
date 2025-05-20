//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000

typedef struct {
    int id;
    char name[20];
    int stock;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product(int id, char *name, int stock, float price) {
    if (num_products < MAX_PRODUCTS) {
        Product product = {id, "", stock, price};
        strncpy(product.name, name, 20);
        products[num_products++] = product;
        printf("Product added successfully!\n");
    }
    else {
        printf("Error: maximum number of products reached!\n");
    }
}

void list_products() {
    printf("ID\tName\tStock\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d\t%s\t%d\t%.2f\n", products[i].id, products[i].name, products[i].stock, products[i].price);
    }
}

void update_product(int id, int stock, float price) {
    for (int i = 0; i < num_products; i++) {
        if (products[i].id == id) {
            products[i].stock = stock;
            products[i].price = price;
            printf("Product updated successfully!\n");
            return;
        }
    }
    printf("Error: product with ID %d not found!\n", id);
}

void sell_product(int id, int quantity) {
    for (int i = 0; i < num_products; i++) {
        if (products[i].id == id) {
            if (products[i].stock >= quantity) {
                products[i].stock -= quantity;
                printf("Sale transaction processed successfully!\n");
                return;
            }
            else {
                printf("Error: insufficient stock for sale!\n");
                return;
            }
        }
    }
    printf("Error: product with ID %d not found!\n", id);
}

int main() {
    int option = 0;
    while (1) {
        printf("\n\n----- Medical Store Management System -----\n");
        printf("1. Add product\n");
        printf("2. List products\n");
        printf("3. Update product\n");
        printf("4. Sell product\n");
        printf("5. Exit program\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1: {
                int id, stock;
                float price;
                char name[20];
                printf("\nEnter the product details...\n");
                printf("ID: ");
                scanf("%d", &id);
                printf("Name: ");
                scanf("%s", name);
                printf("Stock: ");
                scanf("%d", &stock);
                printf("Price: ");
                scanf("%f", &price);
                add_product(id, name, stock, price);
                break;
            }
            case 2: {
                list_products();
                break;
            }
            case 3: {
                int id, stock;
                float price;
                printf("\nEnter the product ID to update: ");
                scanf("%d", &id);
                printf("Enter the new stock: ");
                scanf("%d", &stock);
                printf("Enter the new price: ");
                scanf("%f", &price);
                update_product(id, stock, price);
                break;
            }
            case 4: {
                int id, quantity;
                printf("\nEnter the product ID to sell: ");
                scanf("%d", &id);
                printf("Enter the quantity to sell: ");
                scanf("%d", &quantity);
                sell_product(id, quantity);
                break;
            }
            case 5: {
                printf("\nGoodbye!\n");
                exit(0);
            }
            default: {
                printf("\nError: invalid option!\n");
                break;
            }
        }
    }
    return 0;
}