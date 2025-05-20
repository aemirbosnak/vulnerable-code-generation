//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
} product;

product product_list[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    if (num_products >= MAX_PRODUCTS) {
        printf("Error: Too many products in system\n");
        return;
    }

    product new_prod;

    printf("Enter product name: ");
    scanf("%s", new_prod.name);

    printf("Enter product price: ");
    scanf("%f", &new_prod.price);

    printf("Enter product quantity: ");
    scanf("%d", &new_prod.quantity);

    new_prod.id = num_products + 1;

    product_list[num_products] = new_prod;

    num_products++;

    printf("Product added successfully!\n\n");
}

void display_products() {
    if (num_products == 0) {
        printf("No products in system\n");
        return;
    }

    printf("%-5s %-20s %-10s %-10s\n", "ID", "Product Name", "Quantity", "Price");
    printf("------------------------------------------------------\n");

    int i;
    for (i = 0; i < num_products; i++) {
        printf("%-5d %-20s %-10d %-10.2f\n", product_list[i].id, product_list[i].name,
            product_list[i].quantity, product_list[i].price);
    }

    printf("\n");
}

void search_product_by_name() {
    char name[MAX_NAME_LEN];
    printf("Enter name to search: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < num_products; i++) {
        if (strcmp(product_list[i].name, name) == 0) {
            printf("%-5s %-20s %-10s %-10s\n", "ID", "Product Name", "Quantity", "Price");
            printf("------------------------------------------------------\n");

            printf("%-5d %-20s %-10d %-10.2f\n", product_list[i].id, product_list[i].name,
                product_list[i].quantity, product_list[i].price);
            return;
        }
    }

    printf("No product found with name %s\n", name);
}

void search_product_by_id() {
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);

    int i;
    for (i = 0; i < num_products; i++) {
        if (product_list[i].id == id) {
            printf("%-5s %-20s %-10s %-10s\n", "ID", "Product Name", "Quantity", "Price");
            printf("------------------------------------------------------\n");

            printf("%-5d %-20s %-10d %-10.2f\n", product_list[i].id, product_list[i].name,
                product_list[i].quantity, product_list[i].price);
            return;
        }
    }

    printf("No product found with ID %d\n", id);
}

void delete_product() {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    int i;
    for (i = 0; i < num_products; i++) {
        if (product_list[i].id == id) {
            int j;
            for (j = i; j < num_products - 1; j++) {
                product_list[j] = product_list[j+1];
            }

            num_products--;

            printf("Product with ID %d has been deleted\n", id);
            return;
        }
    }

    printf("No product found with ID %d\n", id);
}

int main() {
    int choice;

    do {
        printf("Welcome to Medical Store Management System\n");
        printf("1. Add product to system\n");
        printf("2. Display all products\n");
        printf("3. Search for product by name\n");
        printf("4. Search for product by ID\n");
        printf("5. Delete product by ID\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                display_products();
                break;
            case 3:
                search_product_by_name();
                break;
            case 4:
                search_product_by_id();
                break;
            case 5:
                delete_product();
                break;
            case 0:
                printf("Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (1);

    return 0;
}