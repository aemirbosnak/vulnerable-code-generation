//FormAI DATASET v1.0 Category: Product Inventory System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
    char description[100];
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void display_menu();
void add_product();
void remove_product();
void search_product();
void list_products();
void sort_products();

int main() {
    int choice;
    do {
        display_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                remove_product();
                break;
            case 3:
                search_product();
                break;
            case 4:
                list_products();
                break;
            case 5:
                sort_products();
                break;
            case 6:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);
    return 0;
}

void display_menu() {
    printf("\nPRODUCT INVENTORY SYSTEM\n");
    printf("1. Add a new product\n");
    printf("2. Remove a product\n");
    printf("3. Search for a product\n");
    printf("4. List all products\n");
    printf("5. Sort products by price\n");
    printf("6. Exit program\n");
}

void add_product() {
    if (num_products == MAX_PRODUCTS) {
        printf("\nMaximum number of products reached. Cannot add any more products.\n");
        return;
    }

    printf("\nAdding new product:\n");
    Product product;

    printf("Enter product ID: ");
    scanf("%d", &product.id);

    printf("Enter product name: ");
    scanf("%s", product.name);

    printf("Enter product quantity: ");
    scanf("%d", &product.quantity);

    printf("Enter product price: ");
    scanf("%f", &product.price);

    printf("Enter product description: ");
    scanf("%s", product.description);

    products[num_products] = product;
    num_products++;

    printf("\nProduct successfully added!\n");
}

void remove_product() {
    if (num_products == 0) {
        printf("\nNo products to remove.\n");
        return;
    }

    int id;
    printf("\nEnter ID of product to remove: ");
    scanf("%d", &id);

    int index = -1;
    for (int i = 0; i < num_products; i++) {
        if (products[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("\nProduct not found.\n");
        return;
    }

    for (int i = index; i < num_products - 1; i++) {
        products[i] = products[i + 1];
    }
    num_products--;

    printf("\nProduct successfully removed!\n");
}

void search_product() {
    if (num_products == 0) {
        printf("\nNo products to search.\n");
        return;
    }

    int id;
    printf("\nEnter ID of product to search: ");
    scanf("%d", &id);

    int index = -1;
    for (int i = 0; i < num_products; i++) {
        if (products[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("\nProduct not found.\n");
        return;
    }

    Product product = products[index];
    printf("\nProduct found:\n");
    printf("ID: %d\n", product.id);
    printf("Name: %s\n", product.name);
    printf("Quantity: %d\n", product.quantity);
    printf("Price: %.2f\n", product.price);
    printf("Description: %s\n", product.description);
}

void list_products() {
    if (num_products == 0) {
        printf("\nNo products to list.\n");
        return;
    }

    printf("\nListing all products:\n");
    for (int i = 0; i < num_products; i++) {
        Product product = products[i];
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f, Description: %s\n", product.id, product.name, product.quantity, product.price, product.description);
    }
}

void sort_products() {
    if (num_products == 0) {
        printf("\nNo products to sort.\n");
        return;
    }

    for (int i = 0; i < num_products - 1; i++) {
        for (int j = 0; j < num_products - i - 1; j++) {
            if (products[j].price > products[j + 1].price) {
                Product temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }

    printf("\nProducts successfully sorted by price!\n");
}