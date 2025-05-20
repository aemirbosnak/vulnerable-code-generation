//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_PRODUCTS 100
#define MAX_CHAR 256

typedef struct {
    char name[MAX_CHAR];
    int stock;
} Product;

typedef struct {
    Product products[MAX_PRODUCTS];
    int capacity;
    int count;
} Inventory;

bool is_valid_product_name(char* name) {
    int i;
    for (i = 0; name[i] != '\0'; i++) {
        if (isdigit(name[i])) return false;
    }
    return true;
}

void add_product(Inventory* inv, char* name, int stock) {
    if (inv->count == inv->capacity) {
        printf("Inventory is full.\n");
        return;
    }
    strcpy(inv->products[inv->count].name, name);
    inv->products[inv->count].stock = stock;
    inv->count++;
}

void display_inventory(Inventory inv) {
    int i;
    printf("\nProduct Name\tStock\n");
    for (i = 0; i < inv.count; i++) {
        printf("%s\t\t%d\n", inv.products[i].name, inv.products[i].stock);
    }
}

int main() {
    Inventory inv = {0};
    inv.capacity = MAX_PRODUCTS;

    char command[MAX_CHAR], product_name[MAX_CHAR], temp[MAX_CHAR];
    int quantity;

    while (1) {
        printf("\nEnter command (add <product_name> <quantity>|display|quit): ");
        fgets(command, sizeof(command), stdin);
        command[strlen(command) - 1] = '\0';

        if (strstr(command, "add") != NULL) {
            sscanf(command, "add %s %d", product_name, &quantity);
            if (is_valid_product_name(product_name)) {
                add_product(&inv, product_name, quantity);
            } else {
                printf("Invalid product name.\n");
            }
        } else if (strcmp(command, "display") == 0) {
            display_inventory(inv);
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}