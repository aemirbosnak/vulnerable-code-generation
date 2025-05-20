//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_SIZE 50
#define MAX_DESCRIPTION_SIZE 100

typedef struct {
    char name[MAX_NAME_SIZE];
    char description[MAX_DESCRIPTION_SIZE];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int num_products;

void add_product() {
    char name[MAX_NAME_SIZE];
    char description[MAX_DESCRIPTION_SIZE];
    int quantity;
    float price;

    printf("Enter product name: ");
    scanf("%s", name);

    printf("Enter product description: ");
    scanf("%s", description);

    printf("Enter product quantity: ");
    scanf("%d", &quantity);

    printf("Enter product price: ");
    scanf("%f", &price);

    products[num_products] = (Product) {
       .name = strdup(name),
       .description = strdup(description),
       .quantity = quantity,
       .price = price
    };

    num_products++;
}

void view_products() {
    for (int i = 0; i < num_products; i++) {
        printf("%d. %s\n", i + 1, products[i].name);
    }
}

void search_products(char* search_term) {
    int matches = 0;

    for (int i = 0; i < num_products; i++) {
        if (strstr(products[i].name, search_term) || strstr(products[i].description, search_term)) {
            printf("%d. %s\n", i + 1, products[i].name);
            matches++;
        }
    }

    if (matches == 0) {
        printf("No matches found.\n");
    }
}

int main() {
    num_products = 0;

    while (1) {
        printf("Product Inventory System\n");
        printf("1. Add product\n");
        printf("2. View products\n");
        printf("3. Search products\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_product();
            break;
        case 2:
            view_products();
            break;
        case 3: {
            char search_term[MAX_NAME_SIZE];
            printf("Enter search term: ");
            scanf("%s", search_term);
            search_products(search_term);
            break;
        }
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}