//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product {
    int id;
    char name[50];
    int quantity;
    float price;
} product;

void add_product(product **products, int *num_products, int id, char *name, int quantity, float price) {
    *products = realloc(*products, (*num_products + 1) * sizeof(product));
    product *new_product = &(*products)[*num_products];
    new_product->id = id;
    strcpy(new_product->name, name);
    new_product->quantity = quantity;
    new_product->price = price;
    (*num_products)++;
}

void remove_product(product **products, int *num_products, int id) {
    int i;
    for (i = 0; i < *num_products; i++) {
        if ((*products)[i].id == id) {
            break;
        }
    }
    if (i == *num_products) {
        printf("Product not found.\n");
        return;
    }
    for (; i < *num_products - 1; i++) {
        (*products)[i] = (*products)[i + 1];
    }
    (*num_products)--;
    printf("Product removed successfully.\n");
}

void update_product(product **products, int num_products, int id, char *name, int quantity, float price) {
    int i;
    for (i = 0; i < num_products; i++) {
        if ((*products)[i].id == id) {
            break;
        }
    }
    if (i == num_products) {
        printf("Product not found.\n");
        return;
    }
    strcpy((*products)[i].name, name);
    (*products)[i].quantity = quantity;
    (*products)[i].price = price;
    printf("Product updated successfully.\n");
}

void search_product(product **products, int num_products, int id) {
    int i;
    for (i = 0; i < num_products; i++) {
        if ((*products)[i].id == id) {
            break;
        }
    }
    if (i == num_products) {
        printf("Product not found.\n");
        return;
    }
    printf("Product found:\n");
    printf("ID: %d\n", (*products)[i].id);
    printf("Name: %s\n", (*products)[i].name);
    printf("Quantity: %d\n", (*products)[i].quantity);
    printf("Price: %.2f\n", (*products)[i].price);
}

void print_products(product **products, int num_products) {
    int i;
    printf("Products:\n");
    for (i = 0; i < num_products; i++) {
        printf("ID: %d\n", (*products)[i].id);
        printf("Name: %s\n", (*products)[i].name);
        printf("Quantity: %d\n", (*products)[i].quantity);
        printf("Price: %.2f\n\n", (*products)[i].price);
    }
}

int main() {
    int choice, id, quantity;
    char name[50];
    float price;
    product *products = NULL;
    int num_products = 0;

    while (1) {
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Update product\n");
        printf("4. Search product\n");
        printf("5. Print products\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product ID: ");
                scanf("%d", &id);
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter product quantity: ");
                scanf("%d", &quantity);
                printf("Enter product price: ");
                scanf("%f", &price);
                add_product(&products, &num_products, id, name, quantity, price);
                break;
            case 2:
                printf("Enter product ID to remove: ");
                scanf("%d", &id);
                remove_product(&products, &num_products, id);
                break;
            case 3:
                printf("Enter product ID to update: ");
                scanf("%d", &id);
                printf("Enter new product name: ");
                scanf("%s", name);
                printf("Enter new product quantity: ");
                scanf("%d", &quantity);
                printf("Enter new product price: ");
                scanf("%f", &price);
                update_product(&products, num_products, id, name, quantity, price);
                break;
            case 4:
                printf("Enter product ID to search: ");
                scanf("%d", &id);
                search_product(&products, num_products, id);
                break;
            case 5:
                print_products(&products, num_products);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}