//FormAI DATASET v1.0 Category: Product Inventory System ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char product_name[50];
    int quantity;
    float price;
} Product;

int main() {
    int size, choice, i, found_index;
    float total_price = 0;
    char search_name[50];

    printf("Enter the number of products: ");
    scanf("%d", &size);

    Product* products = (Product*) malloc(size * sizeof(Product));

    printf("\n-----Enter the product details-----\n");

    for(i = 0; i < size; i++) {
        printf("\nEnter the name of product %d: ", i+1);
        scanf("%s", products[i].product_name);
        printf("Enter the quantity of product %d: ", i+1);
        scanf("%d", &products[i].quantity);
        printf("Enter the price of product %d: ", i+1);
        scanf("%f", &products[i].price);
    }

    printf("\n-----Product List-----\n");
    printf("No.\tProduct Name\tQuantity\tPrice\n");

    for(i = 0; i < size; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", i+1, products[i].product_name, products[i].quantity, 
        products[i].price);
        total_price += products[i].quantity * products[i].price;
    }

    printf("\nTotal Inventory Value: %.2f\n\n", total_price);

    do {
        printf("Enter your choice:\n1. Search for a product\n2. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the name of the product: ");
                scanf("%s", search_name);
                found_index = -1;

                for(i = 0; i < size; i++) {
                    if(strcmp(products[i].product_name, search_name) == 0) {
                        found_index = i;
                        break;
                    }
                }

                if(found_index != -1) {
                    printf("Product found!\n");
                    printf("Product Name: %s\nQuantity: %d\nPrice: %.2f\n\n", 
                    products[found_index].product_name, products[found_index].quantity, products[found_index].price);
                } else {
                    printf("Product not found!\n\n");
                }
                break;
            case 2:
                printf("Exiting Program... Thank you for using!\n");
                break;
            default:
                printf("\nInvalid Choice! Try again.\n");
                break;
        }
    } while(choice != 2);

    free(products);

    return 0;
}