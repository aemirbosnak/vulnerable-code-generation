//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROD_NAME 50
#define MAX_PROD_ID 10
#define MAX_PROD_QTY 10000
#define MAX_PROD_EXP 20

typedef struct Product {
    char name[MAX_PROD_NAME];
    char id[MAX_PROD_ID];
    int quantity;
    char expiry[MAX_PROD_EXP];
} Product;

void add_product(Product**, int*);
void remove_product(Product**, int*);
void display_products(Product*, int);
int find_product(Product*, int, char*);
void update_product(Product*, int);

int main() {
    Product *products = NULL;
    int num_products = 0, choice;
    char search_id[MAX_PROD_ID];

    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display products\n");
        printf("4. Update product information\n");
        printf("5. Exit\n");

        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product(&products, &num_products);
                break;
            case 2:
                remove_product(&products, &num_products);
                break;
            case 3:
                display_products(products, num_products);
                break;
            case 4:
                printf("Enter the product ID to update: ");
                scanf("%s", search_id);
                update_product(products, find_product(products, num_products, search_id));
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    if (products != NULL) {
        free(products);
    }

    return 0;
}

void add_product(Product **products, int *num_products) {
    *num_products += 1;
    *products = (Product*)realloc(*products, *num_products * sizeof(Product));

    printf("Enter product name: ");
    scanf("%s", (*products)[*num_products-1].name);

    printf("Enter product ID: ");
    scanf("%s", (*products)[*num_products-1].id);

    printf("Enter product quantity: ");
    scanf("%d", &(*products)[*num_products-1].quantity);

    printf("Enter product expiry date (YYYY-MM-DD): ");
    scanf("%s", (*products)[*num_products-1].expiry);

    printf("Product added successfully.\n");
}

void remove_product(Product **products, int *num_products) {
    char search_id[MAX_PROD_ID];
    int index;

    printf("Enter the product ID to remove: ");
    scanf("%s", search_id);

    index = find_product(*products, *num_products, search_id);

    if (index == -1) {
        printf("Product not found.\n");
        return;
    }

    (*num_products)--;
    for (int i = index; i < *num_products; i++) {
        (*products)[i] = (*products)[i+1];
    }
    *products = (Product*)realloc(*products, *num_products * sizeof(Product));

    printf("Product removed successfully.\n");
}

void display_products(Product *products, int num_products) {
    if (num_products == 0) {
        printf("No products to display.\n");
        return;
    }

    printf("\n%-10s%-20s%-10s%-20s", "ID", "Name", "Quantity", "Expiry date");
    for (int i = 0; i < num_products; i++) {
        printf("\n%-10s%-20s%-10d%-20s", products[i].id, products[i].name, products[i].quantity, products[i].expiry);
    }
}

int find_product(Product *products, int num_products, char *search_id) {
    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].id, search_id) == 0) {
            return i;
        }
    }
    return -1;
}

void update_product(Product *products, int index) {
    if (index == -1) {
        printf("Product not found.\n");
        return;
    }

    printf("Enter new product name: ");
    scanf("%s", products[index].name);

    printf("Enter new product quantity: ");
    scanf("%d", &products[index].quantity);

    printf("Enter new product expiry date (YYYY-MM-DD): ");
    scanf("%s", products[index].expiry);

    printf("Product updated successfully.\n");
}