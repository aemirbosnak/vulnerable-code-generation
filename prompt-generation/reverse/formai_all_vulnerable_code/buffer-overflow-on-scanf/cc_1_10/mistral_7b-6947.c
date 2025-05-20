//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define PRODUCT_NAME_SIZE 50
#define PRODUCT_QUANTITY_SIZE 10

typedef struct {
    char name[PRODUCT_NAME_SIZE];
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int num_products = 0;

void add_product(char *name, int quantity) {
    if (num_products >= MAX_PRODUCTS) {
        printf("Inventory is full!\n");
        return;
    }
    strcpy(inventory[num_products].name, name);
    inventory[num_products].quantity = quantity;
    num_products++;
}

void delete_product(char *name) {
    int i;
    for (i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < num_products - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            num_products--;
            printf("Product '%s' deleted successfully.\n", name);
            return;
        }
    }
    printf("Product '%s' not found.\n", name);
}

void display_inventory() {
    int i;
    printf("\nCurrent Inventory:\n");
    for (i = 0; i < num_products; i++) {
        printf("%d. %s - %d\n", i + 1, inventory[i].name, inventory[i].quantity);
    }
}

void search_product(char *name) {
    int i;
    for (i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Product '%s' found. Quantity: %d\n", name, inventory[i].quantity);
            return;
        }
    }
    printf("Product '%s' not found.\n", name);
}

void modify_product(char *name, int new_quantity) {
    int i;
    for (i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            inventory[i].quantity = new_quantity;
            printf("Product '%s' quantity modified successfully.\n", name);
            return;
        }
    }
    printf("Product '%s' not found.\n", name);
}

int main() {
    char command[10], name[PRODUCT_NAME_SIZE];
    int quantity, index, choice;

    while (1) {
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n");
        printf("2. Delete Product\n");
        printf("3. Display Inventory\n");
        printf("4. Search Product\n");
        printf("5. Modify Product Quantity\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%s", command);

        switch (command[0]) {
            case '1':
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter product quantity: ");
                scanf("%d", &quantity);
                add_product(name, quantity);
                break;
            case '2':
                printf("Enter product name to delete: ");
                scanf("%s", name);
                delete_product(name);
                break;
            case '3':
                display_inventory();
                break;
            case '4':
                printf("Enter product name to search: ");
                scanf("%s", name);
                search_product(name);
                break;
            case '5':
                printf("Enter product name to modify: ");
                scanf("%s", name);
                printf("Enter new quantity: ");
                scanf("%d", &quantity);
                modify_product(name, quantity);
                break;
            case '6':
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}