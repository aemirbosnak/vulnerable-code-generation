//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    int stock;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    if (num_products >= MAX_PRODUCTS) {
        printf("Inventory is full.\n");
        return;
    }

    printf("Enter product name: ");
    scanf("%s", inventory[num_products].name);

    printf("Enter stock: ");
    scanf("%d", &inventory[num_products].stock);

    printf("Enter price: ");
    scanf("%f", &inventory[num_products].price);

    num_products++;
}

void remove_product() {
    char name[50];
    int i;

    printf("Enter product name to remove: ");
    scanf("%s", name);

    for (i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < num_products - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            num_products--;
            printf("Product removed successfully.\n");
            return;
        }
    }

    printf("Product not found.\n");
}

void display_inventory() {
    int i;

    printf("\nProduct Inventory\n");
    printf("------------------\n");

    for (i = 0; i < num_products; i++) {
        printf("%s\tStock: %d\tPrice: %.2f\n", inventory[i].name, inventory[i].stock, inventory[i].price);
    }
}

void search_product() {
    char name[50];
    int i;

    printf("Enter product name to search: ");
    scanf("%s", name);

    for (i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Product found:\n");
            printf("%s\tStock: %d\tPrice: %.2f\n", inventory[i].name, inventory[i].stock, inventory[i].price);
            return;
        }
    }

    printf("Product not found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nProduct Inventory System\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display inventory\n");
        printf("4. Search product\n");
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
                display_inventory();
                break;
            case 4:
                search_product();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}