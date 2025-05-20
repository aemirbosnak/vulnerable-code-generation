//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 1000

struct product {
    char name[MAX_NAME_LEN];
    int quantity;
};

void add_product(struct product* products, int num_products, char* name, int quantity) {
    int i;
    for (i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            products[i].quantity += quantity;
            return;
        }
    }
    strcpy(products[num_products].name, name);
    products[num_products].quantity = quantity;
    num_products++;
}

void display_products(struct product* products, int num_products) {
    int i;
    for (i = 0; i < num_products; i++) {
        printf("%s: %d\n", products[i].name, products[i].quantity);
    }
}

void remove_product(struct product* products, int num_products, char* name) {
    int i;
    for (i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            memmove(&products[i], &products[i+1], sizeof(struct product) * (num_products - i - 1));
            num_products--;
            return;
        }
    }
}

int main() {
    struct product products[MAX_PRODUCTS];
    int num_products = 0;
    char choice;
    do {
        printf("Product Inventory System\n");
        printf("1. Add product\n2. Display products\n3. Remove product\n4. Exit\n");
        scanf("%c", &choice);
        switch (choice) {
            case '1': {
                char name[MAX_NAME_LEN];
                int quantity;
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                add_product(products, num_products, name, quantity);
                break;
            }
            case '2': {
                display_products(products, num_products);
                break;
            }
            case '3': {
                char name[MAX_NAME_LEN];
                printf("Enter product name: ");
                scanf("%s", name);
                remove_product(products, num_products, name);
                break;
            }
            case '4': {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Invalid choice!\n");
            }
        }
    } while (choice!= '4');
    return 0;
}