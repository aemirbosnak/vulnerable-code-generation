//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of products
#define MAX_PRODUCTS 100

// Define the structure for a product
typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

// Define the global array of products
Product products[MAX_PRODUCTS];

// Define the number of products currently in the inventory
int num_products = 0;

// Define the main menu options
int main_menu() {
    printf("Product Inventory System\n");
    printf("1. Add Product\n");
    printf("2. Remove Product\n");
    printf("3. View Products\n");
    printf("4. Exit\n");
    return 0;
}

// Define the add product function
void add_product() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);
    num_products++;
    printf("Product added successfully!\n");
}

// Define the remove product function
void remove_product() {
    int id;
    printf("Enter product ID to remove: ");
    scanf("%d", &id);
    for (int i = 0; i < num_products; i++) {
        if (id == i) {
            num_products--;
            printf("Product removed successfully!\n");
            break;
        }
    }
}

// Define the view products function
void view_products() {
    printf("Product Inventory\n");
    printf("ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d\t%s\t%d\t%.2f\n", i, products[i].name, products[i].quantity, products[i].price);
    }
}

// Define the main function
int main() {
    while (1) {
        main_menu();
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                remove_product();
                break;
            case 3:
                view_products();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}