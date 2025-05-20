//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 50
#define PRODUCT_NAME_LENGTH 50
#define INVALID_PRODUCT_INDEX -1

typedef struct {
    char name[PRODUCT_NAME_LENGTH];
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int free_product_index = 0;

void print_menu() {
    printf("\n===============\n");
    printf("| Product Inventory System |\n");
    printf("===============\n");
    printf("| 1. Add Product     |\n");
    printf("| 2. Remove Product  |\n");
    printf("| 3. List Products   |\n");
    printf("| 4. Search Product  |\n");
    printf("| 5. Quit            |\n");
    printf("===============\n");
}

int add_product(const char* product_name, int initial_quantity) {
    if (free_product_index >= MAX_PRODUCTS) {
        printf("Error: Maximum number of products reached!\n");
        return INVALID_PRODUCT_INDEX;
    }

    strcpy(inventory[free_product_index].name, product_name);
    inventory[free_product_index].quantity = initial_quantity;

    free_product_index++;

    printf("Product added successfully!\n");
    return free_product_index - 1;
}

int remove_product(int product_index) {
    if (product_index < 0 || product_index >= free_product_index) {
        printf("Error: Invalid product index!\n");
        return INVALID_PRODUCT_INDEX;
    }

    memset(&inventory[product_index], 0, sizeof(Product));

    for (int i = product_index; i < free_product_index - 1; i++) {
        inventory[i] = inventory[i + 1];
    }

    free_product_index--;

    printf("Product removed successfully!\n");
    return product_index;
}

void list_products() {
    printf("\n===============\n");
    printf("| Product List |\n");
    printf("===============\n");

    for (int i = 0; i < free_product_index; i++) {
        printf("| %2d. %s - %d |\n", i + 1, inventory[i].name, inventory[i].quantity);
    }

    printf("===============\n");
}

int search_product(const char* product_name) {
    for (int i = 0; i < free_product_index; i++) {
        if (strcmp(inventory[i].name, product_name) == 0) {
            printf("Product found at index %d!\n", i);
            return i;
        }
    }

    printf("Error: Product not found!\n");
    return INVALID_PRODUCT_INDEX;
}

int main() {
    int choice;
    char product_name[PRODUCT_NAME_LENGTH];
    int product_index;
    int initial_quantity;

    do {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", product_name);
                printf("Enter initial quantity: ");
                scanf("%d", &initial_quantity);
                add_product(product_name, initial_quantity);
                break;
            case 2:
                list_products();
                printf("Enter product index to remove: ");
                scanf("%d", &product_index);
                remove_product(product_index - 1);
                break;
            case 3:
                list_products();
                break;
            case 4:
                printf("Enter product name to search: ");
                scanf("%s", product_name);
                product_index = search_product(product_name);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}