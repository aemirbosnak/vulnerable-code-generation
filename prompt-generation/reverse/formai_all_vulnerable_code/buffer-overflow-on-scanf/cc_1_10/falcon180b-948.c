//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[100];
    char brand[100];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);

    printf("Enter product brand: ");
    scanf("%s", products[num_products].brand);

    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);

    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);

    num_products++;
}

void display_products() {
    printf("\nProduct Inventory:\n");
    printf("---------------------\n");

    for (int i = 0; i < num_products; i++) {
        printf("%d. %s - %s - %d - $%.2f\n", i+1, products[i].name, products[i].brand, products[i].quantity, products[i].price);
    }
}

void search_product() {
    char search_name[100];

    printf("\nEnter product name to search: ");
    scanf("%s", search_name);

    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, search_name) == 0) {
            printf("\nProduct found:\n");
            printf("-----------------\n");

            printf("Name: %s\n", products[i].name);
            printf("Brand: %s\n", products[i].brand);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Price: $%.2f\n", products[i].price);
        }
    }
}

int main() {
    int choice;

    do {
        printf("\nProduct Inventory System\n");
        printf("-------------------------\n");

        printf("1. Add product\n");
        printf("2. Display products\n");
        printf("3. Search product\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_product();
                break;

            case 2:
                display_products();
                break;

            case 3:
                search_product();
                break;

            case 4:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while(choice!= 4);

    return 0;
}