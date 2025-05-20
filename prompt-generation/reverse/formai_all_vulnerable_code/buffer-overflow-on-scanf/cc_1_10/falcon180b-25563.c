//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_PRICE 10000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    float price;
} Product;

int num_products = 0;
Product products[MAX_PRODUCTS];

void add_product() {
    if (num_products >= MAX_PRODUCTS) {
        printf("Error: Cannot add more products.\n");
        return;
    }

    printf("Enter product name: ");
    scanf("%s", products[num_products].name);

    printf("Enter product description: ");
    scanf("%s", products[num_products].description);

    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);

    num_products++;
}

void view_products() {
    printf("\nProduct Inventory\n");
    printf("-----------------\n");
    printf("ID\tName\tDescription\tPrice\n");

    for (int i = 0; i < num_products; i++) {
        printf("%d\t%s\t%s\t%.2f\n", i + 1, products[i].name, products[i].description, products[i].price);
    }
}

void search_product() {
    char search_name[MAX_NAME_LENGTH];

    printf("\nEnter product name to search: ");
    scanf("%s", search_name);

    int found = 0;
    for (int i = 0; i < num_products; i++) {
        if (strcmp(search_name, products[i].name) == 0) {
            printf("\nProduct found:\n");
            printf("ID: %d\n", i + 1);
            printf("Name: %s\n", products[i].name);
            printf("Description: %s\n", products[i].description);
            printf("Price: %.2f\n", products[i].price);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nProduct not found.\n");
    }
}

void main() {
    int choice;

    while (1) {
        printf("\nProduct Inventory System\n");
        printf("-------------------------\n");
        printf("1. Add product\n");
        printf("2. View products\n");
        printf("3. Search product\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_product();
            break;
        case 2:
            view_products();
            break;
        case 3:
            search_product();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}