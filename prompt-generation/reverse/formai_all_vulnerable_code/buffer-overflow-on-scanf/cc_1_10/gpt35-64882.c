//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_BATCH_NUMBER_LENGTH 20

typedef struct product {
    char name[MAX_NAME_LENGTH];
    char expiry_date[11];
    char batch_number[MAX_BATCH_NUMBER_LENGTH];
    float quantity;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    if (num_products >= MAX_PRODUCTS) {
        printf("Warehouse capacity has been reached!\n");
        return;
    }

    Product new_product;

    printf("Enter product name: ");
    fgets(new_product.name, MAX_NAME_LENGTH, stdin);
    printf("Enter product expiry date (dd/mm/yyyy): ");
    fgets(new_product.expiry_date, 11, stdin);
    printf("Enter product batch number: ");
    fgets(new_product.batch_number, MAX_BATCH_NUMBER_LENGTH, stdin);
    printf("Enter product quantity: ");
    scanf("%f", &new_product.quantity);

    products[num_products] = new_product;
    num_products++;

    printf("Product added successfully!\n");
}

void list_products() {
    if (num_products == 0) {
        printf("No products in the warehouse!\n");
        return;
    }

    printf("Name\t\tExpiry Date\tBatch Number\tQuantity\n");

    for (int i = 0; i < num_products; i++) {
        Product product = products[i];
        printf("%s\t%s\t%s\t%.2f\n", product.name, product.expiry_date, product.batch_number, product.quantity);
    }
}

void search_by_name() {
    char search_name[MAX_NAME_LENGTH];
    printf("Enter product name to search for: ");
    fgets(search_name, MAX_NAME_LENGTH, stdin);

    for (int i = 0; i < num_products; i++) {
        Product product = products[i];
        if (strcmp(search_name, product.name) == 0) {
            printf("%s\t%s\t%s\t%.2f\n", product.name, product.expiry_date, product.batch_number, product.quantity);
            return;
        }
    }

    printf("Product not found!\n");
}

void search_by_batch_number() {
    char search_batch_number[MAX_BATCH_NUMBER_LENGTH];
    printf("Enter product batch number to search for: ");
    fgets(search_batch_number, MAX_BATCH_NUMBER_LENGTH, stdin);

    for (int i = 0; i < num_products; i++) {
        Product product = products[i];
        if (strcmp(search_batch_number, product.batch_number) == 0) {
            printf("%s\t%s\t%s\t%.2f\n", product.name, product.expiry_date, product.batch_number, product.quantity);
            return;
        }
    }

    printf("Product not found!\n");
}

int main() {
    int choice;
    char temp[10];

    do {
        printf("\nWarehouse Management System\n");
        printf("----------------------------\n");
        printf("1. Add product\n");
        printf("2. List products\n");
        printf("3. Search by name\n");
        printf("4. Search by batch number\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        fgets(temp, 10, stdin);
        choice = atoi(temp);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                list_products();
                break;
            case 3:
                search_by_name();
                break;
            case 4:
                search_by_batch_number();
                break;
            case 5:
                printf("Exiting!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 5);

    return 0;
}