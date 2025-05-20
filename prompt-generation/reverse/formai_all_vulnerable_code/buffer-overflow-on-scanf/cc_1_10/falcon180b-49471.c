//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100 // maximum number of products
#define MAX_NAME_LENGTH 50 // maximum length of product name
#define MAX_QUANTITY 1000 // maximum quantity of a product

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    double price;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);
    printf("Enter product price: ");
    scanf("%lf", &products[num_products].price);
    num_products++;
}

void display_products() {
    printf("Product Inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s - %d units - $%.2lf\n", products[i].name, products[i].quantity, products[i].price);
    }
}

void update_quantity() {
    printf("Enter product name: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);
    int index = -1;
    for (int i = 0; i < num_products; i++) {
        if (strcmp(name, products[i].name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Product not found.\n");
        return;
    }
    printf("Enter new quantity: ");
    scanf("%d", &products[index].quantity);
}

void remove_product() {
    printf("Enter product name: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);
    int index = -1;
    for (int i = 0; i < num_products; i++) {
        if (strcmp(name, products[i].name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Product not found.\n");
        return;
    }
    num_products--;
    for (int i = index; i < num_products; i++) {
        products[i] = products[i+1];
    }
}

int main() {
    printf("Welcome to the Product Inventory System.\n");
    while (1) {
        printf("\n");
        printf("1. Add product\n");
        printf("2. Display products\n");
        printf("3. Update quantity\n");
        printf("4. Remove product\n");
        printf("5. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                display_products();
                break;
            case 3:
                update_quantity();
                break;
            case 4:
                remove_product();
                break;
            case 5:
                printf("Thank you for using the Product Inventory System.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}