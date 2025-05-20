//FormAI DATASET v1.0 Category: Product Inventory System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    Product product;
    printf("Enter product id: ");
    scanf("%d", &product.id);
    printf("Enter product name: ");
    scanf("%s", product.name);
    printf("Enter product quantity: ");
    scanf("%d", &product.quantity);
    printf("Enter product price: ");
    scanf("%f", &product.price);

    products[num_products++] = product;
    printf("Product added successfully!\n");
}

void display_products() {
    printf("ID\tNAME\tQUANTITY\tPRICE\n");
    for(int i=0; i<num_products; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
}

void search_product() {
    char name[50];
    printf("Enter product name to search: ");
    scanf("%s", name);

    int found = 0;
    for(int i=0; i<num_products; i++) {
        if(strcmp(products[i].name, name) == 0) {
            printf("ID\tNAME\tQUANTITY\tPRICE\n");
            printf("%d\t%s\t%d\t\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Product not found!\n");
    }
}

void sell_product() {
    int id, quantity;
    printf("Enter product id to sell: ");
    scanf("%d", &id);
    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);

    int found = 0;
    for(int i=0; i<num_products; i++) {
        if(products[i].id == id) {
            if(products[i].quantity >= quantity) {
                products[i].quantity -= quantity;
                printf("%d units of %s sold successfully for %.2f!\n", quantity, products[i].name, quantity * products[i].price);
            } else {
                printf("Sorry, insufficient quantity!\n");
            }
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Product not found!\n");
    }
}

void quit() {
    printf("Goodbye!\n");
    exit(0);
}

void menu() {
    printf("Welcome to Product Inventory System!\n");
    printf("1. Add Product\n");
    printf("2. Display Products\n");
    printf("3. Search Product\n");
    printf("4. Sell Product\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    while(1) {
        menu();
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
                sell_product();
                break;
            case 5:
                quit();
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}