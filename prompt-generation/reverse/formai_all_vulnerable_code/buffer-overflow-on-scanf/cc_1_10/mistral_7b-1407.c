//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Product {
    char name[50];
    int stock;
    float price;
} Product;

void print_menu() {
    printf("\n*** Peaceful Product Inventory System ***\n");
    printf("1. Add Product\n");
    printf("2. Display Inventory\n");
    printf("3. Search Product\n");
    printf("4. Update Stock\n");
    printf("5. Exit\n");
}

void add_product(Product *inv, int *num_products) {
    Product new_product;

    printf("Enter Product Name: ");
    fgets(new_product.name, sizeof(new_product.name), stdin);
    new_product.name[strcspn(new_product.name, "\n")] = '\0';

    printf("Enter Stock: ");
    scanf("%d", &new_product.stock);

    printf("Enter Price: ");
    scanf("%f", &new_product.price);

    *inv = new_product;
    *num_products += 1;
}

void display_inventory(Product *inv, int num_products) {
    int i;

    printf("\n*** Current Inventory ***\n");
    for(i = 0; i < num_products; i++) {
        printf("%s\tStock: %d\tPrice: %.2f\n", inv[i].name, inv[i].stock, inv[i].price);
    }
}

int search_product(Product *inv, int num_products, char *name) {
    int i;

    for(i = 0; i < num_products; i++) {
        if(strcmp(inv[i].name, name) == 0) {
            return i;
        }
    }

    return -1;
}

void update_stock(Product *inv, int num_products, int index, int new_stock) {
    if(index >= 0 && index < num_products) {
        inv[index].stock = new_stock;
    } else {
        printf("Invalid index\n");
    }
}

int main() {
    int num_products = 0;
    Product inventory[100];
    int choice, search_index;
    char search_name[50];
    int new_stock;

    while(1) {
        print_menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_product(inventory, &num_products);
                break;
            case 2:
                display_inventory(inventory, num_products);
                break;
            case 3:
                printf("Enter Product Name to Search: ");
                scanf("%s", search_name);
                search_index = search_product(inventory, num_products, search_name);
                if(search_index >= 0) {
                    printf("Product Found!\n");
                } else {
                    printf("Product Not Found!\n");
                }
                break;
            case 4:
                printf("Enter Product Index to Update Stock: ");
                scanf("%d", &search_index);
                printf("Enter New Stock: ");
                scanf("%d", &new_stock);
                update_stock(inventory, num_products, search_index, new_stock);
                break;
            case 5:
                printf("Exiting Inventory System...\n");
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}