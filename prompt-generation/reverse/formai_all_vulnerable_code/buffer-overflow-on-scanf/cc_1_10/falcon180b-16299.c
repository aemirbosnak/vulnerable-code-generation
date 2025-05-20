//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200
#define MAX_QUANTITY 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter product description: ");
    scanf("%s", products[num_products].description);
    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);
    num_products++;
}

void display_products() {
    printf("\nProduct Name\tProduct Description\tQuantity\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s\t\t%s\t\t%d\n", products[i].name, products[i].description, products[i].quantity);
    }
}

int main() {
    int choice = 0;
    while (choice!= 4) {
        printf("\nProduct Inventory System\n");
        printf("1. Add product\n");
        printf("2. Display products\n");
        printf("3. Search product by name\n");
        printf("4. Exit\n");
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
                printf("Enter product name to search: ");
                char search_name[MAX_NAME_LENGTH];
                scanf("%s", search_name);
                int found = 0;
                for (int i = 0; i < num_products; i++) {
                    if (strcmp(products[i].name, search_name) == 0) {
                        printf("\nProduct found:\n");
                        printf("Name: %s\n", products[i].name);
                        printf("Description: %s\n", products[i].description);
                        printf("Quantity: %d\n", products[i].quantity);
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    printf("\nProduct not found.\n");
                }
                break;
            case 4:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice.\n");
        }
    }
    return 0;
}