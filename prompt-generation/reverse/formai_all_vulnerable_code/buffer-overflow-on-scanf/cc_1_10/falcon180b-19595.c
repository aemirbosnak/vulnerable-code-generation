//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 1000

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product(char* name, int quantity) {
    if (num_products >= MAX_PRODUCTS) {
        printf("Error: Too many products!\n");
        return;
    }

    strcpy(products[num_products].name, name);
    products[num_products].quantity = quantity;
    num_products++;

    printf("Product '%s' added with quantity %d.\n", name, quantity);
}

void remove_product(char* name) {
    int i;

    for (i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("Product '%s' removed.\n", name);
            num_products--;

            if (i < num_products) {
                products[i] = products[num_products];
            }

            return;
        }
    }

    printf("Error: Product '%s' not found!\n", name);
}

void update_product(char* name, int quantity) {
    int i;

    for (i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            products[i].quantity = quantity;
            printf("Product '%s' updated with quantity %d.\n", name, quantity);
            return;
        }
    }

    printf("Error: Product '%s' not found!\n", name);
}

void display_products() {
    int i;

    printf("Product Inventory:\n");
    for (i = 0; i < num_products; i++) {
        printf("%s - %d\n", products[i].name, products[i].quantity);
    }
}

int main() {
    char command[100];
    int quantity;

    while (1) {
        printf("Enter command (add/remove/update/display/exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter product name: ");
            scanf("%s", command);
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            add_product(command, quantity);
        } else if (strcmp(command, "remove") == 0) {
            printf("Enter product name: ");
            scanf("%s", command);
            remove_product(command);
        } else if (strcmp(command, "update") == 0) {
            printf("Enter product name: ");
            scanf("%s", command);
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            update_product(command, quantity);
        } else if (strcmp(command, "display") == 0) {
            display_products();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command!\n");
        }
    }

    return 0;
}