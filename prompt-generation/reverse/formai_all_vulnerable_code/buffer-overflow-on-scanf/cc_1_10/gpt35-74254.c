//FormAI DATASET v1.0 Category: Product Inventory System ; Style: realistic
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct Product {
    int id;
    char name[50];
    float price;
    int quantity;
};

struct Inventory {
    struct Product products[MAX_PRODUCTS];
    int count;
};

void add_product(struct Inventory *inventory, struct Product product);
void print_products(struct Inventory inventory);
void search_product(struct Inventory inventory, char *name);

int main() {
    struct Inventory inventory;
    inventory.count = 0;
    int choice;
    do {
        printf("\nProduct Inventory System\n");
        printf("------------------------\n");
        printf("1. Add product\n");
        printf("2. Print all products\n");
        printf("3. Search for a product\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                struct Product product;
                product.id = inventory.count + 1;
                printf("Enter product name: ");
                scanf("%s", product.name);
                printf("Enter product price: ");
                scanf("%f", &product.price);
                printf("Enter product quantity: ");
                scanf("%d", &product.quantity);
                add_product(&inventory, product);
                printf("Product added successfully!\n");
                break;
            }
            case 2: {
                print_products(inventory);
                break;
            }
            case 3: {
                char search_name[50];
                printf("Enter product name to search: ");
                scanf("%s", search_name);
                search_product(inventory, search_name);
                break;
            }
            case 4: {
                printf("Exiting program...\n");
                break;
            }
            default: {
                printf("Invalid choice!\n");
                break;
            }
        }
    } while (choice != 4);
    return 0;
}

void add_product(struct Inventory *inventory, struct Product product) {
    if (inventory->count < MAX_PRODUCTS) {
        inventory->products[inventory->count++] = product;
    } else {
        printf("Maximum number of products reached!\n");
    }
}

void print_products(struct Inventory inventory) {
    printf("\nID\tName\tPrice\tQuantity\n");
    printf("----------------------------------\n");
    for (int i = 0; i < inventory.count; i++) {
        struct Product product = inventory.products[i];
        printf("%d\t%s\t%.2f\t%d\n", product.id, product.name, product.price, product.quantity);
    }
}

void search_product(struct Inventory inventory, char *name) {
    bool found = false;
    printf("\nID\tName\tPrice\tQuantity\n");
    printf("----------------------------------\n");
    for (int i = 0; i < inventory.count; i++) {
        struct Product product = inventory.products[i];
        if (strcmp(product.name, name) == 0) {
            printf("%d\t%s\t%.2f\t%d\n", product.id, product.name, product.price, product.quantity);
            found = true;
        }
    }
    if (!found) {
        printf("Product not found!\n");
    }
}