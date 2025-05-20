//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);
    num_products++;
}

void remove_product() {
    int index;
    printf("Enter product index to remove: ");
    scanf("%d", &index);
    if (index >= 0 && index < num_products) {
        num_products--;
        for (int i = index; i < num_products; i++) {
            products[i] = products[i+1];
        }
    } else {
        printf("Invalid product index.\n");
    }
}

void update_product() {
    int index;
    printf("Enter product index to update: ");
    scanf("%d", &index);
    if (index >= 0 && index < num_products) {
        printf("Enter new product name: ");
        scanf("%s", products[index].name);
        printf("Enter new product quantity: ");
        scanf("%d", &products[index].quantity);
        printf("Enter new product price: ");
        scanf("%f", &products[index].price);
    } else {
        printf("Invalid product index.\n");
    }
}

void display_products() {
    printf("Product Inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d. %s - %d units - $%.2f\n", i+1, products[i].name, products[i].quantity, products[i].price);
    }
}

int main() {
    int choice;
    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Update product\n");
        printf("4. Display products\n");
        printf("5. Exit\n");
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
                update_product();
                break;
            case 4:
                display_products();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 5);
    return 0;
}