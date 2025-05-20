//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 100

struct product {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
};

int main() {
    struct product products[MAX_PRODUCTS];
    int num_products = 0;
    char choice;

    do {
        printf("Welcome to the Post-Apocalyptic Product Inventory System!\n");
        printf("Please choose an option:\n");
        printf("A - Add product\n");
        printf("R - Remove product\n");
        printf("L - List products\n");
        printf("Q - Quit\n");
        scanf(" %c", &choice);

        switch(choice) {
            case 'A':
                if(num_products >= MAX_PRODUCTS) {
                    printf("Error: Inventory is full.\n");
                } else {
                    printf("Enter product name (up to %d characters): ", MAX_NAME_LENGTH);
                    scanf("%s", products[num_products].name);
                    printf("Enter product quantity: ");
                    scanf("%d", &products[num_products].quantity);
                    printf("Enter product price: ");
                    scanf("%f", &products[num_products].price);
                    num_products++;
                    printf("Product added successfully!\n");
                }
                break;
            case 'R':
                if(num_products == 0) {
                    printf("Error: Inventory is empty.\n");
                } else {
                    printf("Enter product name to remove (up to %d characters): ", MAX_NAME_LENGTH);
                    scanf("%s", products[num_products-1].name);
                    if(strcmp(products[num_products-1].name, "") == 0) {
                        printf("Error: Product name cannot be empty.\n");
                    } else {
                        num_products--;
                        printf("Product removed successfully!\n");
                    }
                }
                break;
            case 'L':
                printf("Product List:\n");
                for(int i = 0; i < num_products; i++) {
                    printf("%s - Quantity: %d - Price: $%.2f\n", products[i].name, products[i].quantity, products[i].price);
                }
                break;
            case 'Q':
                printf("Exiting program...\n");
                break;
            default:
                printf("Error: Invalid option.\n");
        }
        printf("\n");
    } while(choice!= 'Q');

    return 0;
}