//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCT_NAME_LENGTH 50
#define MAX_PRODUCT_DESCRIPTION_LENGTH 100
#define MAX_PRODUCT_PRICE 99999

typedef struct product {
    char name[MAX_PRODUCT_NAME_LENGTH];
    char description[MAX_PRODUCT_DESCRIPTION_LENGTH];
    int price;
} Product;

typedef struct {
    int num_products;
    Product products[100];
} Store;

void create_store() {
    Store store = {0};
    printf("Enter the number of products: ");
    scanf("%d", &store.num_products);

    for (int i = 0; i < store.num_products; i++) {
        printf("Enter product name (%d): ", i+1);
        scanf("%s", store.products[i].name);
        printf("Enter product description: ");
        scanf("%s", store.products[i].description);
        printf("Enter product price: ");
        scanf("%d", &store.products[i].price);
    }
}

void display_products(Store store) {
    printf("\nProduct List:\n");
    for (int i = 0; i < store.num_products; i++) {
        printf("%d. %s\n", i+1, store.products[i].name);
        printf("%s\n", store.products[i].description);
        printf("Price: $%d\n\n", store.products[i].price);
    }
}

void search_product(Store store) {
    char search_name[MAX_PRODUCT_NAME_LENGTH];
    printf("Enter product name to search: ");
    scanf("%s", search_name);

    for (int i = 0; i < store.num_products; i++) {
        if (strcmp(search_name, store.products[i].name) == 0) {
            printf("\nProduct found:\n");
            printf("%s\n", store.products[i].description);
            printf("Price: $%d\n\n", store.products[i].price);
        }
    }
}

int main() {
    Store store;
    create_store();
    display_products(store);

    char choice;
    do {
        printf("\nEnter choice:\n1. Display products\n2. Search product\n3. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                display_products(store);
                break;
            case '2':
                search_product(store);
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= '3');

    return 0;
}