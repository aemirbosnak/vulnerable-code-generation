//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int quantity;
    float price;
} Product;

Product products[MAX_SIZE];
int num_products = 0;

void add_product() {
    num_products++;
}

void remove_product(int index) {
    num_products--;
}

void display_products() {
    int i;
    for (i = 0; i < num_products; i++) {
        printf("Product %d:\n", i + 1);
        printf("Name: %s\n", products[i].name);
        printf("Quantity: %d\n", products[i].quantity);
        printf("Price: $%.2f\n\n", products[i].price);
    }
}

int main() {
    int choice, index;

    do {
        printf("Warehouse Management System\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display products\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", products[num_products].name);
                printf("Enter product quantity: ");
                scanf("%d", &products[num_products].quantity);
                printf("Enter product price: $");
                scanf("%f", &products[num_products].price);
                add_product();
                break;
            case 2:
                printf("Enter product index: ");
                scanf("%d", &index);
                remove_product(index - 1);
                break;
            case 3:
                display_products();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}