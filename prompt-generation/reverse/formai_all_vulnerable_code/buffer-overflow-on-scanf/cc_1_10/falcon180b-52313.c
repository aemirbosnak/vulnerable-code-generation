//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter quantity: ");
    scanf("%d", &products[num_products].quantity);
    num_products++;
}

void remove_product() {
    printf("Enter product name to remove: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);
    int i;
    for (i = 0; i < num_products; i++) {
        if (strcmp(name, products[i].name) == 0) {
            num_products--;
            break;
        }
    }
}

void display_products() {
    printf("Product inventory:\n");
    printf("=================\n");
    printf("Name\tQuantity\n");
    printf("-----------------\n");
    int i;
    for (i = 0; i < num_products; i++) {
        printf("%s\t%d\n", products[i].name, products[i].quantity);
    }
}

void main() {
    int choice;
    while (1) {
        printf("Product inventory system\n");
        printf("------------------------\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display products\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add_product();
            break;
        case 2:
            remove_product();
            break;
        case 3:
            display_products();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
}