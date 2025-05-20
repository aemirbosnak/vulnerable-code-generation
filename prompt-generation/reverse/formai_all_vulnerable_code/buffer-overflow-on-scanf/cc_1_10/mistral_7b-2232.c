//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define PRODUCT_NAME_LENGTH 50
#define PRODUCT_PRICE_LENGTH 10

typedef struct {
    char name[PRODUCT_NAME_LENGTH];
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int num_products = 0;

void add_product();
void remove_product();
void view_inventory();
void search_product();

int main() {
    int choice;

    while (1) {
        printf("\nStore Management System\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. View Inventory\n");
        printf("4. Search Product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                remove_product();
                break;
            case 3:
                view_inventory();
                break;
            case 4:
                search_product();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void add_product() {
    if (num_products >= MAX_PRODUCTS) {
        printf("Maximum number of products reached!\n");
        return;
    }

    printf("Enter product name: ");
    scanf("%s", inventory[num_products].name);

    printf("Enter product price: ");
    scanf("%f", &inventory[num_products].price);

    num_products++;

    printf("Product added successfully!\n");
}

void remove_product() {
    char name[PRODUCT_NAME_LENGTH];
    int index;

    printf("Enter product name to remove: ");
    scanf("%s", name);

    for (index = 0; index < num_products; index++) {
        if (strcmp(name, inventory[index].name) == 0) {
            for (int i = index; i < num_products - 1; i++) {
                inventory[i] = inventory[i + 1];
            }
            num_products--;
            printf("Product removed successfully!\n");
            return;
        }
    }

    printf("Product not found!\n");
}

void view_inventory() {
    printf("\nProduct Inventory:\n");

    for (int i = 0; i < num_products; i++) {
        printf("%d. %s - $%.2f\n", i + 1, inventory[i].name, inventory[i].price);
    }
}

void search_product() {
    char name[PRODUCT_NAME_LENGTH];
    int index;
    float price;

    printf("Enter product name to search: ");
    scanf("%s", name);

    for (index = 0; index < num_products; index++) {
        if (strcmp(name, inventory[index].name) == 0) {
            printf("Product found!\n");
            printf("Name: %s\n", inventory[index].name);
            printf("Price: $%.2f\n", inventory[index].price);
            return;
        }
    }

    printf("Product not found!\n");
}