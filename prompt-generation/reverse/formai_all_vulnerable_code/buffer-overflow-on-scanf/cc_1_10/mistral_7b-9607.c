//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 999

typedef struct Product {
    char name[MAX_NAME_LENGTH];
    int quantity;
} Product;

Product warehouse[MAX_PRODUCTS];
int num_products = 0;

void add_product(char *name, int quantity) {
    if (num_products >= MAX_PRODUCTS) {
        printf("Warehouse is full.\n");
        return;
    }

    strcpy(warehouse[num_products].name, name);
    warehouse[num_products].quantity = quantity;
    num_products++;
}

int main() {
    char name[MAX_NAME_LENGTH];
    int quantity;
    int choice;

    while (1) {
        printf("\n1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter product quantity: ");
                scanf("%d", &quantity);
                add_product(name, quantity);
                break;
            case 2:
                printf("\nProduct List:\n");
                for (int i = 0; i < num_products; i++) {
                    printf("\nProduct %d:\n", i + 1);
                    printf("Name: %s\n", warehouse[i].name);
                    printf("Quantity: %d\n", warehouse[i].quantity);
                }
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}