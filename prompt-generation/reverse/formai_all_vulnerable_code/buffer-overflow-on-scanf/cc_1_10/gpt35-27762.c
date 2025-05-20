//FormAI DATASET v1.0 Category: Product Inventory System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define structs for product and inventory
typedef struct {
    char name[50];
    int quantity;
    float price;
} product;

typedef struct {
    product *products;
    int num_products;
} inventory;

// function to add a new product to the inventory
void add_product(inventory *inv) {
    product p;
    printf("Enter product name: ");
    scanf("%s", p.name);
    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter product price: ");
    scanf("%f", &p.price);
    inv->num_products++;
    inv->products = (product *) realloc(inv->products, inv->num_products * sizeof(product));
    inv->products[inv->num_products - 1] = p;
    printf("Product added!\n");
}

// function to remove a product from the inventory
void remove_product(inventory *inv, int index) {
    if (index > -1 && index < inv->num_products) {
        for (int i = index; i < inv->num_products - 1; i++) {
            inv->products[i] = inv->products[i + 1];
        }
        inv->num_products--;
        inv->products = (product *) realloc(inv->products, inv->num_products * sizeof(product));
        printf("Product removed!\n");
    } else {
        printf("Invalid index!\n");
    }
}

// function to print the inventory
void print_inventory(inventory *inv) {
    printf("-------------------------\n");
    printf("Name\tQuantity\tPrice\n");
    printf("-------------------------\n");
    for (int i = 0; i < inv->num_products; i++) {
        printf("%s\t%d\t\t%.2f\n", inv->products[i].name, inv->products[i].quantity, inv->products[i].price);
    }
    printf("-------------------------\n");
}

int main() {

    // initialize the inventory
    inventory inv;
    inv.num_products = 0;
    inv.products = NULL;

    // show menu options to the user
    int option = 0;
    while (option != 4) {
        printf("Please select an option:\n");
        printf("1. Add a product\n");
        printf("2. Remove a product\n");
        printf("3. View inventory\n");
        printf("4. Exit\n");
        scanf("%d", &option);
        switch (option) {
            case 1:
                add_product(&inv);
                break;
            case 2:
                printf("Enter product index to remove: ");
                int index;
                scanf("%d", &index);
                remove_product(&inv, index);
                break;
            case 3:
                print_inventory(&inv);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option!\n");
                break;
        }
    }

    // free memory
    free(inv.products);
    
    return 0;
}