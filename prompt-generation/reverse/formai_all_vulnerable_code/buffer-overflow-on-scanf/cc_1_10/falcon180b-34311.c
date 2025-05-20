//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product(char* name, int quantity) {
    if (num_products >= MAX_PRODUCTS) {
        printf("Error: No more space for products.\n");
        return;
    }

    strcpy(products[num_products].name, name);
    products[num_products].quantity = quantity;
    num_products++;
}

void remove_product(char* name) {
    int i;

    for (i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            num_products--;
            memmove(&products[i], &products[i+1], sizeof(Product) * (num_products - i));
            break;
        }
    }
}

void display_products() {
    int i;

    for (i = 0; i < num_products; i++) {
        printf("%s: %d\n", products[i].name, products[i].quantity);
    }
}

int main() {
    char name[MAX_NAME_LENGTH];
    int quantity;

    while (1) {
        printf("Enter product name (or 'quit' to exit): ");
        scanf("%s", name);

        if (strcmp(name, "quit") == 0) {
            break;
        }

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        add_product(name, quantity);
    }

    printf("\nProduct inventory:\n");
    display_products();

    while (1) {
        printf("\nEnter command: ");
        scanf("%s", name);

        if (strcmp(name, "remove") == 0) {
            printf("Enter product name: ");
            scanf("%s", name);
            remove_product(name);
        } else if (strcmp(name, "display") == 0) {
            display_products();
        } else if (strcmp(name, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}