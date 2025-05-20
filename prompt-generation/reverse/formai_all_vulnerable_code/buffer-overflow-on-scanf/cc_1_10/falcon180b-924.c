//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 100
#define MAX_PRICE 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    float price;
    int quantity;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter product description: ");
    scanf("%s", products[num_products].description);
    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);
    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);
    num_products++;
}

void print_products() {
    printf("\nProduct List:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d. Name: %s, Description: %s, Price: $%.2f, Quantity: %d\n", i+1, products[i].name, products[i].description, products[i].price, products[i].quantity);
    }
}

void search_product() {
    char search_name[MAX_NAME_LEN];
    printf("\nEnter product name to search: ");
    scanf("%s", search_name);
    int found = 0;
    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, search_name) == 0) {
            printf("\nProduct found:\n");
            printf("Name: %s, Description: %s, Price: $%.2f, Quantity: %d\n", products[i].name, products[i].description, products[i].price, products[i].quantity);
            found = 1;
        }
    }
    if (found == 0) {
        printf("\nProduct not found.\n");
    }
}

int main() {
    printf("\nWelcome to the Product Inventory System!\n");
    printf("----------------------------------------\n");
    int choice;
    do {
        printf("\nPlease choose an option:\n");
        printf("1. Add product\n");
        printf("2. Print product list\n");
        printf("3. Search product\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                print_products();
                break;
            case 3:
                search_product();
                break;
            case 4:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice!= 4);
    return 0;
}