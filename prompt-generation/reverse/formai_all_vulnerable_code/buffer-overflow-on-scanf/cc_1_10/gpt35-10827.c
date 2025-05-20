//FormAI DATASET v1.0 Category: Product Inventory System ; Style: retro
#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 50

// Product structure
typedef struct {
    char name[20];
    int code;
    float price;
    int stock;
} Product;

// Inventory structure
typedef struct {
    Product products[MAX_PRODUCTS];
    int num_products;
} Inventory;

// Function to add a product to the inventory
void add_product(Inventory *inv, Product prod) {
    if (inv->num_products < MAX_PRODUCTS) {
        inv->products[inv->num_products++] = prod;
        printf("Product added successfully!\n");
    } else {
        printf("Inventory is full!\n");
    }
}

// Function to print all products in the inventory
void print_inventory(Inventory inv) {
    printf("-----------------------------------------------\n");
    printf("Name\t\tCode\tPrice\tStock\n");
    printf("-----------------------------------------------\n");
    for (int i = 0; i < inv.num_products; i++) {
        printf("%s\t\t%d\t%.2f\t%d\n", inv.products[i].name, inv.products[i].code, inv.products[i].price, inv.products[i].stock);
    }
    printf("-----------------------------------------------\n");
}

// Main function
int main() {
    Inventory inventory = {0};
    char option;
    do {
        printf("*-------------------------*\n");
        printf("| Retro Product Inventory |\n");
        printf("*-------------------------*\n");
        printf("1. Add a product\n");
        printf("2. Print inventory\n");
        printf("3. Quit\n");
        printf("Enter your option (1-3): ");
        scanf(" %c", &option);
        printf("\n");
        switch (option) {
            case '1': {
                Product prod;
                printf("Enter product name: ");
                scanf(" %[^\n]", prod.name);
                printf("Enter product code: ");
                scanf("%d", &prod.code);
                printf("Enter product price: ");
                scanf("%f", &prod.price);
                printf("Enter product stock: ");
                scanf("%d", &prod.stock);
                add_product(&inventory, prod);
                break;
            }
            case '2': {
                print_inventory(inventory);
                break;
            }
            case '3': {
                printf("Goodbye!\n");
                break;
            }
            default: {
                printf("Invalid option!\n");
                break;
            }
        }
        printf("\n");
    } while (option != '3');
    return 0;
}