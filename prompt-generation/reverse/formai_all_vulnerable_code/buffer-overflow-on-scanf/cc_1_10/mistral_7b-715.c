//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#define MAX_PRODUCTS 50
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int stock;
} Product;

Product inventory[MAX_PRODUCTS];
int num_products = 0;

void add_product(char *name, int initial_stock);
void print_inventory();

int main() {
    char command[10];
    char product_name[MAX_NAME_LEN];
    int quantity;

    while (1) {
        printf("Enter command (add/print/quit): ");
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            break;
        } else if (strcmp(command, "add") == 0) {
            printf("Enter product name: ");
            scanf("%s", product_name);
            printf("Enter initial stock: ");
            scanf("%d", &quantity);
            add_product(product_name, quantity);
        } else {
            printf("Invalid command.\n");
        }
    }

    print_inventory();

    return 0;
}

void add_product(char *name, int initial_stock) {
    if (num_products >= MAX_PRODUCTS) {
        printf("Inventory is full.\n");
        return;
    }

    strcpy(inventory[num_products].name, name);
    inventory[num_products].stock = initial_stock;
    num_products++;
}

void print_inventory() {
    printf("\nProduct Inventory:\n");

    for (int i = 0; i < num_products; i++) {
        printf("%s: %d\n", inventory[i].name, inventory[i].stock);
    }
}